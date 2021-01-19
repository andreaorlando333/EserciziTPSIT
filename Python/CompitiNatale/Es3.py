
# Esercizio 3

def fibonacci(n):
    if n <= 1:
        return n
    else:
        return fibonacci(n-1) + fibonacci(n-2)

limite = int(input("Inserisci il numero di valori della serie che desideri vedere: "))

for num in range(1, limite+1):
    print(fibonacci(num))

def main():
    n = 1
    Fibonacci(n)

if __name__ == "__main__":
    main()