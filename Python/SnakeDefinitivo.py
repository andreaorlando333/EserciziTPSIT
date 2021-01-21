import turtle 
import time 
import random 
  
delay = 0.1
score = 0
high_score = 0

pen = turtle.Turtle() 
pen.speed(0) 
pen.color("white") 
pen.penup() 
pen.hideturtle() 
pen.goto(0, 250) 
pen.write("Score : 0  Record : 0", align="center", 
          font=("impact", 26, "bold")) 

win = turtle.Screen() 
win.title("Snake Game") 
win.bgcolor("blue") 
win.setup(width=600, height=600) 
win.tracer(0) 
   
head = turtle.Turtle() 
head.shape("square") 
head.color("white") 
head.penup() 
head.goto(0, 0) 
head.direction = "Stop"
  
food = turtle.Turtle() 
food.speed(0) 
food.shape("circle") 
food.color("red") 
food.penup() 
food.goto(0, 120) 
  
def up(): 
    if head.direction != "down": 
        head.direction = "up"
  
  
def down(): 
    if head.direction != "up": 
        head.direction = "down"
  
  
def left(): 
    if head.direction != "right": 
        head.direction = "left"
  
  
def right(): 
    if head.direction != "left": 
        head.direction = "right"
  
  
def move(): 
    if head.direction == "up": 
        y = head.ycor() 
        head.sety(y+20) 
    if head.direction == "down": 
        y = head.ycor() 
        head.sety(y-20) 
    if head.direction == "left": 
        x = head.xcor() 
        head.setx(x-20) 
    if head.direction == "right": 
        x = head.xcor() 
        head.setx(x+20) 
  
  
          
win.listen() 
win.onkeypress(up, "w") 
win.onkeypress(down, "s") 
win.onkeypress(left, "a") 
win.onkeypress(right, "d") 
  
tail = [] 
  
  
  
# Principale
while True: 
    win.update() 
    if head.xcor() > 290 or head.xcor() < -290 or head.ycor() > 290 or head.ycor() < -290: 
        time.sleep(1) 
        head.goto(0, 0) 
        head.direction = "Stop"
        for ind in range(0,len(tail)): 
            tail[ind].goto(610, 610) 
        tail.clear() 
        score = 0
        pen.clear() 
        pen.write("Score : {} High Score : {} ".format( 
            score, high_score), align="center", font=("impact", 26, "bold")) 
    if head.distance(food) < 20: 
        x = random.randint(-270, 270) 
        y = random.randint(-270, 270) 
        food.goto(x, y) 
  
        # Adding segment 
        new_block = turtle.Turtle() 
        new_block.speed(0) 
        new_block.shape("square") 
        new_block.color("gray")  # tail colour 
        new_block.penup() 
        tail.append(new_block) 
        score += 10
        if score > high_score: 
            high_score = score 
        pen.clear() 
        pen.write("Score : {} High Score : {} ".format( 
            score, high_score), align="center", font=("impact", 26, "bold")) 
    # Controllo collisione
    for index in range(len(tail)-1, 0, -1): 
        x = tail[index-1].xcor() 
        y = tail[index-1].ycor() 
        tail[index].goto(x, y) 
    if len(tail) > 0: 
        x = head.xcor() 
        y = head.ycor() 
        tail[0].goto(x, y) 
    move() 
    for segment in tail: 
        if segment.distance(head) < 20: 
            time.sleep(1) 
            head.goto(0, 0) 
            head.direction = "stop"
            for ind in range(0,len(tail)): 
                tail[ind].goto(610, 610) 
            tail.clear() 
            score = 0
            pen.clear() 
            pen.write("Score : {} High Score : {} ".format( 
                score, high_score), align="center", font=("impact", 26, "bold")) 
    time.sleep(delay) 
  
win.mainloop()
