
# Esercizio con Dizionario Funzioni

def somma(a, b):
	return a+b
def moltiplicazione(a, b):
	return a*b

dizionario_funzioni = {0: somma, 1: moltiplicazione} 

def main():
	print("Seleziona un'opzione:")
	
	val_utente = int(input("0. Somma \n1. Moltiplicazione:\n\nInput: "))
	a = int(input("Primo numero: "))
	b = int(input("Secondo numero: "))

	x = dizionario_funzioni[val_utente](a, b)
	print(x)


if __name__ == "__main__":
	main()

