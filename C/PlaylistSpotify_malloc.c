#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX 100

typedef struct s_canzone{
	int  num;
	char nome[20];
	char autore[20];
	bool rip;
} canzone;

void Memorizzazione(canzone* Playlist, FILE* ptr);
void RiproduzioneCasuale(canzone* Playlist);

int main()
{
    canzone *Playlist;
    FILE *ptr;
    FILE *fp;
    int c,count=0;
    fp=fopen("playlist.csv", "r");
    if (fp){
        for (c = getc(fp); c != EOF; c = getc(fp)){
        if (c == '\n')
        count = count + 1;
        }
    }
    fclose(fp);
    Playlist = (canzone *) malloc(sizeof(canzone) * count);
    ptr=fopen("playlist.csv", "r");
    if (ptr){
            printf("file ok!\n");
            Memorizzazione(Playlist,ptr);
            RiproduzioneCasuale(Playlist);
            fclose(ptr);
    }
    else {
        printf("errore sul file!");
    }
    free(Playlist);
    return 0;
}
void Memorizzazione(canzone* Playlist, FILE* ptr){
            int i=0;
            char vet[MAX];
            const char *c = ",";
            char *field;
            while (fgets(vet,MAX,ptr)){

            field = strtok(vet, c);

            Playlist[i].num = atoi(field);
            printf("numero: %d\n",Playlist[i].num);


            strcpy(Playlist[i].nome, strtok(NULL, c));
            printf("titolo: %s\n",Playlist[i].nome);

            strcpy(Playlist[i].autore, strtok(NULL, c));
            Playlist[i].autore[strlen(Playlist[i].autore)-1] = '\0';
            printf("autore: %s\n",Playlist[i].autore);

            i++;
            }

    }

    void RiproduzioneCasuale(canzone *Playlist){
        int k,n,w=0;
        srand(time(NULL));
        printf("\n");
        printf("riproduzione\n");
        for (w=0;w<10;w++){
            Playlist[w].rip=false;
        }
        for (k=0;k<10;k++){
            do {
            n = rand() % 10;
            }
            while(Playlist[n].rip==true);
            printf("titolo: %s, autore: %s\n", Playlist[n].nome, Playlist[n].autore);
            Playlist[n].rip=true;

        }
    }
