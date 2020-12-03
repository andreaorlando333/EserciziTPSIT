#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define max 200
#define N 10


typedef struct {
 int numero;
 char titolo[max];
 char artista[max];    
} Canzone;

void Memorizzazione(Canzone* playlist, FILE* file1);
void Casuale(Canzone* playlist);

int main() {
  FILE *file1;
  int nrighe,c;
  file1=fopen("esercizio.csv", "r");   // conta righe
  for (c = getc(file1); c != EOF; c = getc(file1)){
      if (c == '\n')
        nrighe = nrighe + 1;
  }

  Canzone *playlist ;
  playlist= (Canzone *)malloc(nrighe*sizeof(Canzone));
  
  printf("Apro il file...\n");
  printf("\n");
    
  file1=fopen("esercizio.csv", "r");
    if( file1==NULL ) {
      perror("Errore in apertura del file\n");
      exit(1);
    } 
      else{
        Memorizzazione(playlist,file1);
        printf("\n................................................\n");
        Casuale(playlist);
      }
   fclose(file1);
   free(playlist);

  return 0;
}

void Memorizzazione(Canzone* playlist, FILE* file1){
 char riga[max];
 char* field;
 int counter=0;
  while(fgets(riga, max, file1)) {

   field=strtok(riga,",");
   (playlist+counter)->numero =atoi(field);

   field=strtok(NULL,",");
   strcpy((playlist+counter)->titolo,field);

   field=strtok(NULL,",");
   strcpy((playlist+counter)->artista,field);
    

   printf("numero: %d\n",(playlist+counter)->numero);
   printf("titolo: %s\n",(playlist+counter)->titolo);
   printf("artista: %s\n",(playlist+counter)->artista);

   counter++;
  }
}


void Casuale(Canzone* playlist){

 int num[N];
 int i,n=0,j;
 srand(time(0)); 
  
 for(i=0;i<N;i++) {
    num[i] = rand()%10;
    for(j=0;j<i;j++) {
       if((num+i)==(num+j)) {
         i--;
         break;
        }
      }
   printf("numero: %d\n",(playlist+ *(num+i))->numero);
   printf("titolo: %s\n",(playlist+ *(num+i))->titolo);
   printf("artista: %s\n",(playlist+ *(num+i))->artista);
  }
}