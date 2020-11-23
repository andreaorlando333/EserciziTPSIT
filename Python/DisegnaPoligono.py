import turtle 
  
t = turtle.Turtle() 
  
n = int(input("Inserisci numero di lati : ")) 
   
for k in range(n): 
    turtle.forward(100) 
    turtle.right(360 / n)