# Versione completa

import turtle

win = Screen()
t = Turtle()
l = 50

win.bgcolor("green")
win.setup(width=800, height=800)

def controllo():
    if(t.ycor()+l) > win.window_height()/2:
        return 1
    elif(t.ycor()-l) < -1 * win.window_height()/2:
        return 2
    elif(t.xcor()+l) > win.window_width()/2:
        return 3 
    elif(t.xcor()-l) < -1 * win.window_width()/2: 
        return 4
    else:
        return 0



def up():
    if controllo() != 1:
        t.setheading(90)
        t.forward(l)
    else:
        pass    

def down():
    if controllo() != 2:
        t.setheading(270)
        t.forward(l) 
    else:
        pass           

def right():
    if controllo() != 3:
        t.setheading(0)
        t.forward(l)
    else:
        pass    
        

def left():
    if controllo() != 4:
        t.setheading(180)
        t.forward(l)
    else:
        pass    

win.listen()    
win.onkey(up, "Up")   
win.onkey(down, "Down")  
win.onkey(left, "Left")   
win.onkey(right, "Right")   
win.mainloop()
