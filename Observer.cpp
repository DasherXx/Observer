#include<iostream>
#include<string>
#include<vector>

using namespace std;
//__________________________________ KLASY ABSTRAKCYJNE ________________
class Naukowiec{

    public:
        virtual void zmianaTemperatury(float temeperatura)=0;
};
class Termometr{
    public:
        virtual void ustawTemperature(float temperatura)=0;
        virtual void dodajNaukowca(Naukowiec* naukowiec)=0;
        virtual void usunNaukowca(Naukowiec* naukowiec)=0;

};
//___________________________________KLASY______________________________
class KonkretnyNaukowiec: public Naukowiec{
    private:
        string imie;

    public:
        void zmianaTemperatury(float temeperatura){
            cout << "Zmiana temperatury na: " << temeperatura <<" zlasza: "<<imie<<endl;
        };
        KonkretnyNaukowiec(string imie){
            this->imie = imie;
        };
};

class KonkretnyTermometr: public Termometr{
private:
    vector<Naukowiec*> naukowcy;
    float temperatura; 
public:
    void ustawTemperature(float temperatura){

        this->temperatura = temperatura;
        cout << "Ustawiono temperature na: " << temperatura << endl;
        for (Naukowiec* naukowiec : naukowcy){
            naukowiec->zmianaTemperatury(temperatura);
        }
    };
    void dodajNaukowca(Naukowiec* naukowiec){
        naukowcy.push_back(naukowiec);
        cout << "Dodano naukowca!"<< endl;
    };
    void usunNaukowca(Naukowiec* naukowiec){

    };
};

//__________________________________ MAIN ______________________________
int main(void)
{
    KonkretnyTermometr* termometrA = new KonkretnyTermometr();
    KonkretnyNaukowiec* naukowiec1 = new KonkretnyNaukowiec("Jan Kowalski");
    KonkretnyNaukowiec* naukowiec2 = new KonkretnyNaukowiec("Anna Nowak");

    KonkretnyTermometr* termometrB = new KonkretnyTermometr();
    KonkretnyNaukowiec* naukowiec3 = new KonkretnyNaukowiec("Piotr Wiśniewski");
    KonkretnyNaukowiec* naukowiec4 = new KonkretnyNaukowiec("Katarzyna Wójcik");

    termometrA->dodajNaukowca(naukowiec1);
    termometrA->dodajNaukowca(naukowiec3);
    termometrB->dodajNaukowca(naukowiec2);
    termometrB->dodajNaukowca(naukowiec4);

    termometrA->ustawTemperature(25.0);
    termometrB->ustawTemperature(30.0);

    delete termometrA;
    delete termometrB;
    delete naukowiec1;
    delete naukowiec2;
    delete naukowiec3;
    delete naukowiec4;

    return 0;
}
