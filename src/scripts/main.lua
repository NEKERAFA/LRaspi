continue = true

while continue do
    screen.clear()
    screen.print("Hello world", 10, 10)
    continue = not screen.flip()
end

