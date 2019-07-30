image.init()
print("screen dimensions", screen.getWidth(), screen.getHeight())

img = image.new("hello.png")
print(img)

screen.clear()
screen.blit(img, 0, 0)
screen.update()