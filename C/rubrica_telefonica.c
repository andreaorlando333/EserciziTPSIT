#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_CONTATTI 1024

typedef struct contatto {
    int id;
    char nome[64];
    char numero[16];    
} Contatto;

typedef struct rubrica {
    int num_inseriti;
    Contatto db[MAX_NUM_CONTATTI];
} Rubrica; 

int inserisci(Rubrica *r, char *nome, char *numero){

	Contatto *p;
	if(r -> num_inseriti == MAX_NUM_CONTATTI){
		printf("\nRubrica piena");
		return -1;
	}
	p = &r -> db[r->num_inseriti];

	strcpy(p->nome, nome);
	strcpy(p->numero, numero);
	p->id = r->num_inseriti;
	r->num_inseriti++;
	return 0;
}

char trovaNum(Rubrica *r, char *nome){
	int i;
	Contatto *p;

	for(i=0; i>MAX_NUM_CONTATTI; i++){
		if(i == r->num_inseriti){
			break;
		}
		p = &r->db[i];
		if(strcmp(p->nome, nome) == 0){
			return p->numero;
		}
	}
	return NULL;
}

void stampa(Rubrica *r){
	int i;
	Contatto *p;

	printf("\nStampa rubrica: %d contatti:\n", r->num_inseriti);

	for(i=0; i<MAX_NUM_CONTATTI; i++){
		if(i == r->num_inseriti){
			break;
		}
	p = &r->db[i];
	printf("%s, %s\n", p->nome, p->numero);	
	}
}

int main()
{
	int input = 0;
	int input2 = 0;
	char* nome;
	char* numero;
	Rubrica* rubrica1; 

	printf("\n\nSeleziona una delle opzioni:\n1. Carica numeri in rubrica\n2. Cerca contatto\n3. Stampa rubrica
		\n\nInserisci input...");
	scanf("%d",&input);
	if(input == 1){
		
		do {

			printf("\nInserimento dati.\n");
			printf("\nInserisci nome... ");
			scanf("%s", nome);
			printf("\nInserisci numero di telefono... ");
			scanf("%s", numero);
			inserisci(rubrica1, nome, numero);
			printf("\nInserito.");

			input2 = 0;
			printf("\n\nDesideri inserire altri numeri?\n1. Si\n2. No\nAttesa input...");
			scanf("%d", &input2);
			printf("\n");
		}while(input2 == 1);	

		main();
	}


	}else if(input == 2){
		
	do {	
		printf("\nTrova contatto.\n");
		printf("Inserisci il nome... ");
		scanf("%s", nome);
		trovaNum(rubrica1, nome);
		printf("\nNumero telefonico di %s:", nome);
		printf("%s", p->numero);

		input2 = 0;
		printf("\n\nDesideri cercare altri contatti?\n1.Si\n2.No\nAttesa input...");
		scanf("%d", &input2);
		printf("\n");
	}while(input2 == 1);
		main();
	



	}else if(input == 3){
		printf("\n");
		stampa(rubrica1);
	}else{
		printf("\nInput non valido.\n\n");
		main();
	}


}