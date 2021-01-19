
# Esercizio 2

import random

def genera_mac():
    char_set = "ABCDEF0123456789"
    mac_addr = ""
    due_punti = 0

    for _ in range(6):
        for _ in range(2):
            mac_addr += random.choice(char_set)
        if due_punti < 5:
          mac_addr += ":"
          due_punti += 1

    print(mac_addr)
    return mac_addr

def main():
    genera_mac()
    
if __name__ == "__main__":
   main()