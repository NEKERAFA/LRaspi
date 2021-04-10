devices = usb.list()

while true do
	screen.clear()

	if #devices > 0 then
		y = 10
		for file in files.dir(devices[1]) do
			if not (file == '.' or file == '..') then 
				screen.print(file, 10, y)
				y = y + 20
			end
		end
	end

	screen.flip()
end
