#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM_STR 2000

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
