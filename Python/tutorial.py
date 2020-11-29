
#Dichiarazione intero e print
numero = 7
print("Hello world")

#Esempio di f-string
print(f"Valore di numero: {numero}")

#Concatenazione di stringhe
print("Valore di numero: " + str(numero))

#Inizializzare una stringa
s1 = 'stringa'
s2 = "stringa"
s3 = "altra sringa"
s4 = 'questa è una "citazione"'
s5 = "un'altra stringa"

#Stampa valore booleano
print(s1==s2)
print(s2==s3)

#COLLEZIONI: liste, tuple, dizionari. 
#Python è orientato agli oggetti. Tutto è un oggetto

num = 8 #è un oggetto ovvero un'istanza della classe int

#Liste. In qualche maniera "simile" agli array di C

lista = [1, 3, 5, 6, 9] #inizializzazione lista
print(f"la lista è: {lista}") #stampa con print ed f-string

#Ciclo for (python style)
for elemento in lista:
	print(elemento)

#in python il ciclo for funziona in modo autonomo
#in automatico passa tutti gli elementi della lista e li stampa. 

#Secondo metodo: (c style)
lunghezza = len(lista)
for indice in range(0, lunghezza):
	print(lista[indice]) #print classica
	print(f"indice: {indice} - elemento; {lista[indice]}") #print con f-string

for indice, elemento in enumerate(lista): #print con funzione enumerate
	print(f"indice: {indice} - elemento: {lista[indice]}")

#Funzioni
def funzione1(argomento1, argomento2):
	#codice della funzione indentato
	return argomento1 + argomento2

print(funzione1) #Stampa indirizzo funzione (puntatore)

#Richiamare funzione e stamparla
valore = funzione1(1,5) 
print(valore)

#Funzionamento con stringhe:
print(funzione1("ciao","mario"))

