
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{       

    int input = 0;
    printf("Seleziona un'opzione:\n1.Encoding\n2.Decoding\n\n\nAttesa input... ");
    scanf("%d", &input);  // Menu iniziale
    if(input==1){
        // ENCODING
    char str[100];
    int cont = 1;
    printf("\n");
    printf("Inserire la stringa da comprimere... (max. 100 caratteri) ");
    scanf("%s", str);  // chiedo in input una stringa di caratteri e salvo in str

    
    int n = strlen(str);  // conto il numero di caratteri e li salvo in n

    for (int i = 0; i < n; i++){  // for che stampa un carattere per volta
    while(i < n - 1 && str[i] == str[i+1]){  // while che conta il numero di char uguali
        cont = cont + 1; 
        i = i + 1;
    }
    

    printf("%d", cont); // stampa del numero
    cont = 1;  // azzera contatore per il numero
    printf("%c", str[i]);  // stampa del carattere
    
}

    printf("\n\n");
    printf("Encode completato.\n");
}

        else if(input==2){
            printf("Non ancora sviluppata\n");

        }
        else{
            printf("Input errato.\n");
        }
    }

    
    
   
