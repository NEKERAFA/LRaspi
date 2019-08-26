--- Image Example

-- Loads an image
local img = image.load("res/logo.png")
-- Sets the blend mode
img:blendmode("blend")
-- Sets the center of the image to rotate in the center
img:center(img:width()/2, img:height()/2)
-- Tints the image as blue
img:tint(color.new(0,0,255))

-- Creates a blue color
local blue = color.new(64, 128, 255)

local rot = 0
local alp = 255
local alp_inc = -1

local quit = false

repeat
    -- Clears the screen as blue color
    screen.clear(blue)

    -- Blits the image
    screen.blit(img, screen.width()/2, screen.height()/2)

    -- Rotates the image
    rot = rot+0.1
    if rot > 360 then
        rot = rot - 360
    end

    img:rotate(rot)

    -- Changes the alpha value
    alp = alp + alp_inc
    if alp < 0 or alp > 255 then
        if alp < 0 then
            alp = 0
        else
            alp = 255
        end
        alp_inc = -alp_inc
    end

    img:alpha(alp)

    -- Updates the screen and check if the program was exited
    quit = screen.update()
until quit

-- Destroys the image object
image.free(img)