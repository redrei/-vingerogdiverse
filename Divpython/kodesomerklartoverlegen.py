import turtle
import math
import random
import time

radius = 300
#creating instance of a turtle
turtle = turtle.Turtle()
#set colour to viridian because it is a beautiful colour
turtle.pencolor("#40826d")

#a function that draws a circle with ennumerated points
def drawcirclepoints(points, radius):
        #lifting pen to avoid drawing unnecessary lines
        turtle.penup()
        #moving the turtle down by one radius, so that the middle of the window will be the middle of the circle
        turtle.setpos(0,-radius)
        #putting the pen down to draw
        turtle.pendown()
        #a circle with a radius of the users choice
        turtle.circle(radius)
        turtle.penup()
        turtle.home()
        turtle.pendown()
        #high end of range is points+1 so that the highest point will be equivalent to points
        #for point in range(1,points+1):
                #turning the turtle around so that it will place the points in a circle
         #       turtle.setheading(int(360/points * point))
          #      turtle.penup()
                #moving the turtle to the periphery so that it can place a point
           #     turtle.forward(radius)
                #point placed
            #    turtle.dot()
                #ennumerating
             #   turtle.write(point)
                #turtle go home
              #  turtle.home()
               # turtle.pendown()

def drawtimetable(points, times, radius):
        #calling my other function
        drawcirclepoints(points, radius)
        #making sure the turtle is headed northwards
        turtle.setheading(0)
        turtle.penup()
        turtle.setpos(int(radius*math.cos(2*math.pi/points)),int(radius*math.sin(2*math.pi/points)))
        turtle.pendown()
        starttime = time.time()
        for point in range(1,points+1):
                turtle.penup()
                #making the turtle jump to the next point in the list
                turtle.setpos(int(radius*math.cos(point*2*math.pi/points)),int(radius*math.sin(point*2*math.pi/points)))
                #making the turtle jump to the point * times, while leaving a line behind
                turtle.pendown()
                turtle.setpos(int(radius*math.cos(times*point*2*math.pi/points)),int(radius*math.sin(times*point*2*math.pi/points)))
        print(time.time()- starttime)
        while True:
                turtle.penup()
                #just keeping the window open
                turtle.home()
#making the turtle run
turtle.speed("fastest")

drawtimetable(5000,int(13),int(300))