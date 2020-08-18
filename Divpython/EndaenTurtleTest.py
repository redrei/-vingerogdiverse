import turtle, math, time
def circle(aurelius, radius):
    aurelius.sety(-(radius))
    aurelius.pendown()
    aurelius.circle(radius)
    aurelius.penup()
def calc(aurelius, point, angle, radius, factor):
    travel(aurelius, point*angle, radius)
    p1 = aurelius.pos()
    travel(aurelius, point*factor*angle, radius)
    p2 = aurelius.pos()
    line(aurelius, p1, p2)
def travel(aurelius, angle, radius):
    aurelius.home()
    aurelius.setheading(angle)
    aurelius.forward(radius)
def line(aurelius, p1, p2):
    aurelius.color('red')
    aurelius.pendown()
    aurelius.goto(p1)
    aurelius.penup()
def main(dots, radius, factor):
    aurelius = turtle.Turtle()
    vindu = turtle.Screen()
    aurelius.penup()
    aurelius.speed(0)
    angle = math.degrees(2 * math.pi/dots)
    circle(aurelius, radius)
    starttime = time.time()
    for i in range(0, dots):
        calc(aurelius, i, angle, radius, factor)
    print(time.time() - starttime)
    vindu.exitonclick()
main(500,200, 20) 