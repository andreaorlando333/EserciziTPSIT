
# Esercizio 1

import random
import string

def psw_generator():
    print("Il programma genera delle password.")

    ascii_chars = string.digits + string.ascii_letters + string.punctuation
    alphanum_chars = string.digits + string.ascii_letters

    if input("Desideri una password Semplice o Complessa? S/C ") == "c":
        lunghezza = 20
        tipo = ascii_chars
    else :
        lunghezza = 8
        tipo = alphanum_chars

    psw = ""
    counter = 0

    while counter < lunghezza:
        char = random.choice(tipo)
        psw += char
        counter += 1

    print(f"La password generata è: {psw}")

def main():
    psw_generator()
    
if __name__ == "__main__":
   main()