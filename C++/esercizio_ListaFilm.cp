#include <iostream>

using namespace std;

public class film {

private:
    int id;
    char titolo[250];
    int anno;
    char genere[100];
    char stato[50];
public:
    void set_id(int valore);
    int get_id();
    void set_anno(int valore);
    int get_anno();
    void set_stato(char *valore);
    char get_stato(char *valore);
    void set_titolo(char *valore);
    char get_titolo(char *valore);
    void set_genere(char *valore);
    char get_genere(char *valore);

};

film::film(){

    id = 0;
    anno = 0;
    strcpy(titolo, "");
    strcpy(genere, "");
    strcpy(stato, "");
}
void film::set_id(int valore){
    id = valore;
}
void film::set_anno(int valore){
    anno = valore;
}
void film::set_titolo(char *valore){
    strcpy(titolo, valore);
}
void film::set_genere(char *valore){
    strcpy(genere, valore);
}
void film::set_stato(char *valore){
    strcpy(stato, valore);
}


int main()
{
    film Movie;
    Movie.set_id(1);
    Movie.set_titolo("Tenet");
    Movie.set_anno(2020);
    Movie.set_genere("Fantascienza, thriller");
    Movie.set_stato("Disponibile");

    film Movies[100];

    Movies[1].set_id(2);
    Movies[1].set_titolo("1917");
    Movies[1].set_anno(2019);
    Movies[1].set_genere("Guerra");
    Movies[1].set_stato("Esaurito");


    cout << "Hello world!" << endl;
    return 0;

}
