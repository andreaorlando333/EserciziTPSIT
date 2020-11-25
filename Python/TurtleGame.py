# Versione base

import turtle

robot = turtle.Turtle 
win = turtle.Screen

win.title("Gioco 1")
win.bgcolor("green")
win.setup(width=800, height=800)

def jump:
	robot.forward(50)
	print("Jump")

win.listen()
win.onkey(jump, "space")

win.mainloop()
