#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM_STR 2000

typedef struct song{
	int  n;
	char name[50];
	char artist[50];
} song;


int main() {
  FILE *fd;
  char buf[200];
  char *res;

    printf("Apro il file...\n");
    printf("\n");
    
    fd=fopen("/Users/andreaorlando/desktop/programmi_c/playlist.csv", "r");
     if( fd==NULL ) {
        perror("Errore in apertura del file\n");
        exit(1);
  }

  while(1) {
    res=fgets(buf, 200, fd);
    if( res==NULL )
      break;
    printf("%s", buf);
  }

    printf("\n\n");
    fclose(fd);

  return 0;
}

    void randomPlay(song *Playlist){
        int k,n,w=0;
        srand(time(NULL));
        printf("\n");
        printf("riproduzione\n");
        for (w=0;w<10;w++){
            
        }
        for (k=0;k<10;k++){
            do {
            n = rand() % 10;
            }
            while(Playlist[n].rip==true);
            printf("titolo: %s, autore: %s\n", Playlist[n].name, Playlist[n].artist);
            

        }
    }
