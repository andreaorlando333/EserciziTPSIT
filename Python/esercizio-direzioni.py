
import random
import csv

dizionario_direzioni = {0:["Nord"], 1:["Sud"], 2:["Est"], 3:["Ovest"]}
valore = (random.randint(1,4))
csvfile = open("registro.csv", "w")
csvwriter = csv.writer(csvfile)

if(valore == 1):
	direzione = "Nord"
	lista = [chiave, valore["Nord"]
	csvwrite.writerow(lista)

else if(valore == 2):
	direzione = "Sud"
	lista = [chiave, valore["Sud"]
	csvwrite.writerow(lista)

else if(valore == 3):
	direzione = "Est"
	lista = [chiave, valore["Est"]
	csvwrite.writerow(lista)

else:
	direzione = "Ovest"
	lista = [chiave, valore["Ovest"]
	csvwrite.writerow(lista)

csvfile.close()
