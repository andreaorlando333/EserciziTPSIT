
import csv 

dizionario_posizioni = {0:[0,0], 1:[10,0], 2:[20,0], 3:[20,-10]}

csvfile = open("file.csv", "w")
csvwriter = csv.writer(csvfile)

for chiave, valore in dizionario_posizioni.items():
	lista = [chiave, valore[0], valore[1]]
	csvwrite.writerow(lista)

csvfile.close()


