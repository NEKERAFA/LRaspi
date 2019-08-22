quit = false

img = image.load("hello.png")
img:setBlendMode("blend")
print(img:getRealWidth(), img:getRealHeight())
img:setCenter(img:getWidth()/2, img:getHeight()/2)
img:tint(color.new(255,0,0))

red = color.new(255, 128, 64)

rot = 0
alp = 255
alp_inc = -1

repeat
    screen.clear(red)

    screen.blit(img, screen.getWidth()/2-img:getWidth()/2, screen.getHeight()/2-img:getWidth()/2)

    quit = screen.update()

    rot = rot+0.1
    if rot > 360 then
        rot = rot - 360
    end

    alp = alp + alp_inc
    if alp < 0 or alp > 255 then
        if alp < 0 then
            alp = 0
        else
            alp = 255
        end
        alp_inc = -alp_inc
    end

    img:setAlpha(alp)
    img:rotate(rot)
until quit

color.free(blue)
image.free(img)