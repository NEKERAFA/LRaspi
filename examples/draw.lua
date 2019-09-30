-- Drawing example

-- Loads the palette
colors = color.getpalette()

arc = 0

-- This function draws all arcs types
function drawArcs(x, y)
    draw.rectangle('outline', x, y, 180, 100, colors.black)
    screen.print(x, y, "Mode: Outline, Type: Pie", colors.white)
    draw.gradarc('outline', 'pie', x+75, y+55, 35, 35, 0, math.rad(arc), colors.yellow, colors.green, 16)

    draw.rectangle('outline', x+190, y, 180, 100, colors.black)
    screen.print(x+190, y, "Mode: Outline, Type: Open", colors.white)
    draw.gradarc('outline', 'open', x+75+190, y+55, 35, 35, 0, math.rad(arc), colors.blue, colors.violet, 16)

    draw.rectangle('outline', x+190+190, y, 180, 100, colors.black)
    screen.print(x+190+190, y, "Mode: Outline, Type: Closed", colors.white)
    draw.gradarc('outline', 'closed', x+75+190+190, y+55, 35, 35, 0, math.rad(arc), colors.red, colors.yellow, 16)

    draw.rectangle('outline', x, y+110, 180, 100, colors.black)
    screen.print(x, y+110, "Mode: Fill, Type: Pie", colors.white)
    draw.gradarc('fill', 'pie', x+75, y+55+110, 35, 35, 0, math.rad(arc), colors.yellow, colors.green, 16)

    draw.rectangle('outline', x+190, y+110, 180, 100, colors.black)
    screen.print(x+190, y+110, "Mode: Fill, Type: Open", colors.white)
    draw.gradarc('fill', 'open', x+75+190, y+55+110, 35, 35, 0, math.rad(arc), colors.blue, colors.violet, 16)

    draw.rectangle('outline', x+190+190, y+110, 180, 100, colors.black)
    screen.print(x+190+190, y+110, "Mode: Fill, Type: Closed", colors.white)
    draw.gradarc('fill', 'closed', x+75+190+190, y+55+110, 35, 35, 0, math.rad(arc), colors.red, colors.yellow, 16)

    arc = arc + 1
    if arc > 360 then
        arc = arc - 360
    end
end

function caculateSecArrow(x, y, sec)
    return {
        -- Calculates the maximun position of the seconds arrow
        a = {
            x = x + math.cos(math.rad(6*t.sec - 90)) * 100,
            y = y + math.sin(math.rad(6*t.sec - 90)) * 100
        },

        -- Calculates the base of the arrow
        b = {
            x = x + math.cos(math.rad(6*t.sec)) * 5,
            y = y + math.sin(math.rad(6*t.sec)) * 5
        },

        c = {
            x = x + math.cos(math.rad(6*t.sec + 180)) * 5,
            y = y + math.sin(math.rad(6*t.sec + 180)) * 5
        }
    }
end

function caculateMinArrow(x, y, min, sec)
    return {
        -- Calculates the maximun position of the minutes arrow
        a = {
            x = x + math.cos(math.rad(6*t.min + 0.1*t.sec - 90)) * 100,
            y = y + math.sin(math.rad(6*t.min + 0.1*t.sec - 90)) * 100
        },

        -- Calculates the base of the arrow
        b = {
            x = x + math.cos(math.rad(6*t.min + 0.1*t.sec)) * 5,
            y = y + math.sin(math.rad(6*t.min + 0.1*t.sec)) * 5
        },

        c = {
            x = x + math.cos(math.rad(6*t.min + 0.1*t.sec + 180)) * 5,
            y = y + math.sin(math.rad(6*t.min + 0.1*t.sec + 180)) * 5
        }
    }
end

function caculateHourArrow(x, y, hour, min)
    return {
        -- Calculates the maximun position of the hours arrow
        a = {
            x = x + math.cos(math.rad(30*t.hour + 0.5*t.min - 90)) * 50,
            y = y + math.sin(math.rad(30*t.hour + 0.5*t.min - 90)) * 50
        },

        -- Calculates the base of the arrow
        b = {
            x = x + math.cos(math.rad(30*t.hour + 0.5*t.min)) * 5,
            y = y + math.sin(math.rad(30*t.hour + 0.5*t.min)) * 5
        },

        c = {
            x = x + math.cos(math.rad(30*t.hour + 0.5*t.min + 180)) * 5,
            y = y + math.sin(math.rad(30*t.hour + 0.5*t.min + 180)) * 5
        }
    }
end

-- This functions draws a clock
function drawClock(x, y)
    screen.print(x, y, os.date(), colors.white)
    t = os.date("*t")

    -- Draws the background
    draw.gradellipse('fill', x+100, y+125, 100, 100, colors.white, colors.gray, 32)

    for div = 0, 60 do
        xmax = x+100 + math.cos(math.rad(6*div - 90)) * 100
        ymax = y+125 + math.sin(math.rad(6*div - 90)) * 100

        if (div % 5) == 0 then
            xmin = x+100 + math.cos(math.rad(6*div - 90)) * 90
            ymin = y+125 + math.sin(math.rad(6*div - 90)) * 90
    
            draw.line(xmin, ymin, xmax, ymax, colors.blue)
        else
            xmin = x+100 + math.cos(math.rad(6*div - 90)) * 95
            ymin = y+125 + math.sin(math.rad(6*div - 90)) * 95
    
            draw.line(xmin, ymin, xmax, ymax, colors.red)
        end
    end

    draw.ellipse('outline', x+100, y+125, 100, 100, colors.black, 32)

    -- Draws seconds arrow
    secArrow = caculateSecArrow(x+100, y+125, t.sec)
    draw.gradtriangle('fill', secArrow.a.x, secArrow.a.y, secArrow.b.x, secArrow.b.y, secArrow.c.x, secArrow.c.y, colors.marron, colors.red, colors.red)

    -- Draws minutes arrow
    minArrow = caculateMinArrow(x+100, y+125, t.min, t.sec)
    draw.triangle('outline', minArrow.a.x, minArrow.a.y, minArrow.b.x, minArrow.b.y, minArrow.c.x, minArrow.c.y, colors.black)

    -- Draws hours arrow
    hourArrow = caculateHourArrow(x+100, y+125, t.hour, t.min)
    draw.gradtriangle('outline', hourArrow.a.x, hourArrow.a.y, hourArrow.b.x, hourArrow.b.y, hourArrow.c.x, hourArrow.c.y, colors.blue, colors.navy, colors.navy)

    -- Draws center circle
    draw.ellipse('fill', x+100, y+125, 5, 5, colors.red, 8)
    draw.ellipse('outline', x+100, y+125, 5, 5, colors.black, 8)
end

function main()
    quit = false
    bg = color.new(32, 128, 255)

    while not quit do
        screen.clear(bg)
        drawArcs(10, 10)
        draw.line(0, 230, screen.getwidth(), 230, colors.white)
        drawClock(10, 240)
        quit = screen.update()
    end
end

main()