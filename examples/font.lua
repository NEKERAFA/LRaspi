--- Font Example

local dftfnt = screen.getdefaultfont()

-- Creates a new font using default
local fnt = font.newdefault(24)

-- Creates fonts with styles
local ubuntu_b = font.new('res/ubuntu.ttf')
ubuntu_b:setstyle({'bold'})
local ubuntu_i = font.new('res/ubuntu.ttf')
ubuntu_i:setstyle({'italic'})
local ubuntu_u = font.new('res/ubuntu.ttf')
ubuntu_u:setstyle({'underline'})
local ubuntu_s = font.new('res/ubuntu.ttf')
ubuntu_s:setstyle({'strikethrough'})

-- Colors
local black = color.new(0, 0, 0)
local white = color.new(255, 255, 255)

-- Creates a text
local hello = image.newtext(fnt, "Hello world!")
local btext = image.newtext(ubuntu_b, "Text in bold")
local itext = image.newtext(ubuntu_i, "Text in italic")
local utext = image.newtext(ubuntu_u, "Text with underline")
local stext = image.newtext(ubuntu_s, "Text with throughline")

local quit = false
local y

repeat
    -- Clears the text
    screen.clear(black)

    y = 10

    -- Prints the current version of lua
    screen.print(10, y, "Lua Raspi " .. lraspi.version(), white)

    y = y + dftfnt:getheight()

    -- Blits the text
    screen.blit(10, y, hello)

    y = y + fnt:getheight()

    screen.blit(10, y, btext)

    y = y + ubuntu_b:getheight()

    screen.blit(10, y, itext)

    y = y + ubuntu_i:getheight()

    screen.blit(10, y, utext)

    y = y + ubuntu_u:getheight()

    screen.blit(10, y, stext)

    -- Updates the screen and check if the program was exited
    quit = screen.update()
until quit
