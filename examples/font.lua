--- Font Example

-- Creates a new font using default
local fnt = font.create(24)

-- Black color
local black = color.new(0, 0, 0)

local quit = false

-- Creates a text
local hello = image.newtext(fnt, "hello world")

repeat
    -- Clears the text
    screen.clear(black)

    -- Blits the text
    screen.blit(hello, 10, 10)

    -- Updates the screen and check if the program was exited
    quit = screen.update()
until quit

-- Destroys the objects
image.free(hello)
font.free(fnt)
color.free(black)