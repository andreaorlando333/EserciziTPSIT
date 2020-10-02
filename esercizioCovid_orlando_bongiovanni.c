
#include <stdio.h>
#define MAX 100000

int main()
{
	int a[MAX];
	int Nalunni;
	
	int G;
	float contagiati = 1;
	
	float R;

	
		printf("inserire il numero di alunni presenti nella classe:\n");
		scanf_s("%d", &Nalunni);
		printf("inserire l'indice di contagio(R):\n");
		scanf_s("%f", &R);
		printf("nel giorno 0 ci sono %f contagiati\n", contagiati);

		
		G = 0;
		while (contagiati < Nalunni)
		{	
			contagiati = contagiati * R;
			a[G] = contagiati;
			if (a[G] > Nalunni)
				{
					printf("nel giorno numero %d ci sono %d contagiati\n", G, Nalunni);

				}
				else
				{
					printf("nel giorno numero %d ci sono %d contagiati \n", G, a[G]);
				}
				G = G++;
		
		}

		printf("la classe si e' infettata in %d giorni\n", G);

		return 0;
}