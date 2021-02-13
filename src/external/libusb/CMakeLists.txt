set(EXTERNAL_LIBUSB_1_0
	${CMAKE_CURRENT_LIST_DIR}/libusb/libusbi.h
	${CMAKE_CURRENT_LIST_DIR}/libusb/version.h
	${CMAKE_CURRENT_LIST_DIR}/libusb/version_nano.h
	${CMAKE_CURRENT_LIST_DIR}/libusb/core.c
	${CMAKE_CURRENT_LIST_DIR}/libusb/descriptor.c
	${CMAKE_CURRENT_LIST_DIR}/libusb/hotplug.h
	${CMAKE_CURRENT_LIST_DIR}/libusb/hotplug.c
	${CMAKE_CURRENT_LIST_DIR}/libusb/io.c
	${CMAKE_CURRENT_LIST_DIR}/libusb/strerror.c
	${CMAKE_CURRENT_LIST_DIR}/libusb/sync.c
	${CMAKE_CURRENT_LIST_DIR}/libusb/os/events_posix.h
	${CMAKE_CURRENT_LIST_DIR}/libusb/os/events_posix.c
	${CMAKE_CURRENT_LIST_DIR}/libusb/os/threads_posix.h
	${CMAKE_CURRENT_LIST_DIR}/libusb/os/threads_posix.c
	${CMAKE_CURRENT_LIST_DIR}/libusb/os/linux_usbfs.h
	${CMAKE_CURRENT_LIST_DIR}/libusb/os/linux_usbfs.c
)

set(EXTERNAL_LIBUSB_HEADERS
	${CMAKE_CURRENT_LIST_DIR}/libusb/libusb.h
)

add_library("usb-1.0" STATIC ${EXTERNAL_LIBUSB_1_0})

target_include_directories("usb-1.0" PUBLIC ${CMAKE_CURRENT_LIST_DIR} ${CMAKE_CURRENT_LIST_DIR}/libusb)
