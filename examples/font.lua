--- Font Example

-- Creates a new font using default
local fnt = font.newdefault(24)

-- Black color
local black = color.new(0, 0, 0)

-- Creates a text
local hello = draw.newtext(fnt, "hello world")

local quit = false

repeat
    -- Clears the text
    screen.clear(black)

    -- Blits the text
    screen.blit(hello, 10, 10)

    -- Updates the screen and check if the program was exited
    quit = screen.update()
until quit
