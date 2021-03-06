/**
 * devices.cpp - NEKERAFA - 15th january 2021
 * Implements USB devices functions
 *
 * References:
 * - https://gavv.github.io/articles/libudev-usb/
 * - https://stackoverflow.com/a/9290177
 *
 * See "lraspi.h" for license information
 */

#include <exception>
#include <system_error>
#include <string>
#include <iostream>
#include <vector>
#include <cerrno>
#include <mntent.h>
#include <libudev.h>
#include "../lraspi.h"

static udev* ctx = nullptr;

std::vector<std::string> get_mount_points(std::vector<std::string> devnode_list) {
	std::vector<std::string> mount_points;

	FILE* mounts = setmntent("/proc/mounts", "r");
	if (mounts == nullptr) {
		std::error_code errc (errno, std::generic_category());
		throw std::system_error(errc, "cannot read /proc/mounts");
	}

	mntent* ent;
	std::string mnt_point = "";
	while ((ent = getmntent(mounts)) != nullptr) {
		std::string fspath(ent->mnt_fsname);
		
		for (auto devnode_ptr = devnode_list.begin(); devnode_ptr != devnode_list.end(); ++devnode_ptr) {
			if (fspath.find(*devnode_ptr) != std::string::npos) {
				mount_points.push_back(std::string(ent->mnt_dir));
			}
		}
	}

	return mount_points;
}

udev_device* get_child(udev* ctx, udev_device* parent, std::string subsystem) {
	auto enumerate = udev_enumerate_new(ctx);

	udev_enumerate_add_match_parent(enumerate, parent);
	udev_enumerate_add_match_subsystem(enumerate, subsystem.c_str());
	udev_enumerate_scan_devices(enumerate);

	auto devices = udev_enumerate_get_list_entry(enumerate);

	udev_list_entry* entry = nullptr;
	udev_device* child = nullptr;

	udev_list_entry_foreach(entry, devices) {
		auto path = udev_list_entry_get_name(entry);
		child = udev_device_new_from_syspath(ctx, path);
		break;	
	}

	udev_enumerate_unref(enumerate);

	return child;
}

void lraspi::usb::init() {
	ctx = udev_new();
}

std::vector<std::string> lraspi::usb::list() {
	auto enumerate = udev_enumerate_new(ctx);

	udev_enumerate_add_match_subsystem(enumerate, "scsi");
	udev_enumerate_add_match_property(enumerate, "DEVTYPE", "scsi_device");
	udev_enumerate_scan_devices(enumerate);

	udev_list_entry* entry;
	auto devices = udev_enumerate_get_list_entry(enumerate);

	std::vector<std::string> devnode_list;

	udev_list_entry_foreach(entry, devices) {
		auto path = udev_list_entry_get_name(entry);

		auto scsi = udev_device_new_from_syspath(ctx, path);
		auto block = get_child(ctx, scsi, "block");
		auto scsi_disk = get_child(ctx, scsi, "scsi_disk");
		
		auto usb = udev_device_get_parent_with_subsystem_devtype(scsi, "usb", "usb_device");

		if (block && scsi_disk && usb) {
			auto devnode = udev_device_get_devnode(block);
			devnode_list.push_back(std::string(devnode));
		}

		if (block) {
			udev_device_unref(block);
		}

		if (scsi_disk) {
			udev_device_unref(scsi_disk);
		}

		udev_device_unref(scsi);
	}

	udev_enumerate_unref(enumerate);

	auto device_list = get_mount_points(devnode_list);

	return device_list;
}

void lraspi::usb::close() {
	udev_unref(ctx);
}
