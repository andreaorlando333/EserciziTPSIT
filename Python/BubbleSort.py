
# Bubble sort convertito da linguaggio C.


array = []

numElementi = int(input("Inserisci il numero di elementi: "))
cont = 0

print(f"Inserisci {numElementi} valori.")

while(cont < numElementi):
        inputValore = int(input("Inserisci valore: "))
        
        
        array.append(inputValore)
        cont = cont + 1

cont = 0
cont2 = 0
for n in range(numElementi - 1):
        for cont2 in range(numElementi - cont - 1):	
                if(array[cont2]>array[cont2+1]):
                        swap = array[cont2]
                        array[cont2] = array[cont2+1]
                        array[cont2+1] = swap

print("Operazione completata:")
print(array)



