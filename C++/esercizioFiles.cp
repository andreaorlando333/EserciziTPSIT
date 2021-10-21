#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
typedef struct{
    char carattere[255];
}Stringa;

class Gestione_Files {
    // Variabili di Classe)
private:
    char NomeFIle_[255];
    char Path[255];

public:
     Gestione_Files(); // costruttore
     void SetNomeFile(char nomefile[255]); //SET -> assegna un valore x = 3
     void GetNomeFile(char *nome); // GET -> return x
     int AggiungiRiga(char riga[255]);
     int LeggiPrimaRiga(char *Riga);
     int LeggiRigaN(char *Riga, int pos);
     int ContaRigheFile();
    int leggiTuttoFile(Stringa *strl, int nRighe);
    int split(char *s,Stringa *strl);
};


Gestione_Files::Gestione_Files()
{
    strcpy(NomeFIle_, "");
}


void Gestione_Files::SetNomeFile(char nomefile[255])
{
    strcpy(NomeFIle_, nomefile);
}


void Gestione_Files::GetNomeFile(char *nome)
{
    strcpy(nome, NomeFIle_);
}

int Gestione_Files::LeggiPrimaRiga(char *riga)
{
    FILE* Fp;
    int err = -1;
    char st1[255];
    int nCaratteri = 0;

    Fp = fopen(NomeFIle_, "r"); // "a" scrive sul file gia esistente al fondo, mentre "w" cancella e riscrive

    if(Fp != NULL){
        err = 0;
        nCaratteri = fscanf(Fp, "%s", st1);
        if(nCaratteri < 0)
            {
                err = -2;
            }
        else
            {
                err = strlen(st1);
                strcpy(riga, st1);
            }
        fclose(Fp);
    }
    return err;
}


int Gestione_Files::AggiungiRiga(char riga[255])
{
    FILE* Fp;
    int err = -1;


    Fp = fopen(NomeFIle_, "a"); // "a" scrive sul file gia esistente al fondo, mentre "w" cancella e riscrive

    if(Fp != NULL){
        err = 0;
        fprintf(Fp, "%s\n", riga);
        fclose(Fp);
    }

    return err;
}

int Gestione_Files::LeggiRigaN(char Riga[255], int pos)
{
    FILE* Fp;
    int err = -1;
    int Nriga=0;
    char st1[255];
    int nCaratteri = 0;

    Fp = fopen(NomeFIle_, "r"); // "a" scrive sul file gia esistente al fondo, mentre "w" cancella e riscrive

    if(Fp != NULL){
        err = 0;
        nCaratteri = fscanf(Fp, "%s", st1);
        while((Nriga!=pos) && (nCaratteri>0)){
            nCaratteri = fscanf(Fp, "%s", st1);
            printf("%s\n", st1);
            Nriga++;
        }
        if(nCaratteri < 0)
            {
                err = -2;
            }
        else
            {
                err = strlen(st1);
                strcpy(Riga, st1);
            }
        fclose(Fp);
    }
    return err;
}

int Gestione_Files::ContaRigheFile(){
    FILE* Fp;
    int err = -1;
    int Nriga=0;
    char st1[255];
    int nCaratteri=0;

    Fp = fopen(NomeFIle_, "r"); // "a" scrive sul file gia esistente al fondo, mentre "w" cancella e riscrive

    if(Fp != NULL){
        err = 0;
        nCaratteri = fscanf(Fp, "%s", st1);
        while(nCaratteri>0){
            Nriga++;
            nCaratteri = fscanf(Fp, "%s", st1);
        }
        err =Nriga;
        fclose(Fp);
    }
    return err;
}

int Gestione_Files::leggiTuttoFile(Stringa *strl, int nRighe){
    FILE* Fp;
    int err = -1;
    int Nriga=0;
    char st1[255];
    int nCaratteri=0;

    Fp = fopen(NomeFIle_, "r"); // "a" scrive sul file gia esistente al fondo, mentre "w" cancella e riscrive

    if(Fp != NULL){
        err = 0;
        nCaratteri = fscanf(Fp, "%s", st1);
        while(nCaratteri>0){
            strcpy(strl[Nriga].carattere,st1);
            printf("%d %s\n",Nriga,st1);
            Nriga++;
            nCaratteri = fscanf(Fp, "%s", st1);
        }
        err =Nriga;
        fclose(Fp);
    }
    return err;
}
int Gestione_Files::split(char *s,Stringa *strl){

}


int main()
{
    int nC = 0;
    int nR = 0;
    char stringa[255];
    Gestione_Files F;
    F.SetNomeFile("dati.csv");
    F.AggiungiRiga("data,ora,temp");
    F.AggiungiRiga("1:1:2021,8:47,23");
    F.AggiungiRiga("2:1:2021,8:50,25");
    nC = F.LeggiPrimaRiga(stringa);
    nC = F.LeggiRigaN(stringa,1);
    nR = F.ContaRigheFile();
    Stringa vet[nR];
    F.leggiTuttoFile(vet,nR);
    cout << nC << " " << stringa << endl;
    cout << "\n programma terminato" << endl;
    return 0;
}
