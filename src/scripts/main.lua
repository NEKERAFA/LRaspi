local white = colour.new(255, 255, 255)
local logo = image.new("lua_logo.png")

while not screen.isclosing() do
    logo:rotate((logo:getrotation() + 0.5) % 360)
    screen.clear()

    -- Draw text
    draw.print("Hello world from " .. _LRASPI_VERSION, 10, 10)
    draw.print(tostring(screen.getfps()) .. " FPS", screen.getwidth() - 60, 10)

    -- Draw image
    colour.setforeground(white)
    draw.blit(logo, screen.getwidth() / 2, screen.getheight() / 2)
    colour.setforeground()

    screen.flip()
end

