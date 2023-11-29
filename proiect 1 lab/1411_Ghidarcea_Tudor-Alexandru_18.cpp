/*Ghidarcea Tudor-Alexandru - 141
Szmeteanca Eduard Gabriel
G++
*/





#include <iostream>
#include <cstring>
#include <string.h>
#include <stdlib.h>
#include <fstream>

using namespace std;
///Obiect = instanta a clasei (i.e. declarare a unei variabile de tipul clasei pe care am definit-o ulterior)
///clasa este DEFINITA si obiectele sunt DECLARATE
///clasa = tip definit de programator


class Film
{

private:
    ///Date membre:
    char *Titlu;
    char *Gen;
    char *Regizor;
    float Rating;

public:
     ///Metode:
    ///(Constructor = prima metoda care se apeleaza atunci cand este declarat un obiect)
    Film();///constructor de initializare FARA parametri
    Film (char*, char*, char*, float);///constructor initializare CU parametri
    Film (Film&);///constructor copiere
    ~Film();///destructor
    ///destructorul este metoda care se apeleaza atunci cand un obiect nu mai este "folosit"
    void set_titlu(char*);///set
    void set_gen(char*);///set
    void set_regizor(char*);///set
    void set_rating(float);///set
    char* get_titlu();///get
    char* get_regizor();///get
    char* get_gen();///get
    float get_rating();///get
    void afisare (ostream &out);
    friend ostream& operator<<(ostream &out, Film& z);///supraincarcare pe <<
    void citire (istream &in);
    friend istream& operator>>(istream &in, Film& z);///supraincarcare pe >>
    Film& operator=(Film &f);///supraincarcarea operatorului de atribuire (doar ca metoda, nu ca functie friend)
    friend bool operator==(Film &f1, Film &f2);///supraincarcare operator ==
    friend bool operator>(Film &f1, Film &f2);///supraincarcare operator >
    friend bool operator<(Film &f1, Film &f2);///supraincarcare operator <
};

Film::Film()
{
    this->Titlu=NULL;
    this->Gen=NULL;
    this->Regizor=NULL;
    this->Rating=0.0;
}

Film::Film(char *Titlu, char *Gen, char *Regizor, float Rating)
{
    this->Titlu= new char[strlen(Titlu)];
    strcpy(this->Titlu, Titlu);
    this->Gen=new char[strlen(Gen)];
    strcpy(this->Gen, Gen);
    this->Regizor=new char[strlen(Regizor)];
    strcpy(this->Regizor, Regizor);
    this->Rating=Rating;
}

Film::Film(Film &cpy)
{
    this->Titlu=new char[strlen(cpy.Titlu)];
    strcpy(this->Titlu, cpy.Titlu);
    this->Gen=new char[strlen(cpy.Gen)];
    strcpy(this->Gen, cpy.Gen);
    this->Regizor=new char[strlen(cpy.Regizor)];
    strcpy(this->Regizor, cpy.Regizor);
    this->Rating=cpy.Rating;
}

Film::~Film()
{
    delete this->Titlu;
    delete this->Gen;
    delete this->Regizor;
    this->Rating=0.0;
}
///implementarea unei functii in afara clasei
///TIPUL_FUNCTIEI NUMELE_CLASEI :: NUMELE_FUNCTIEI (PARAMETRI)
void Film::set_titlu(char* a)
{
    strcpy(this->Titlu, a);
}
char* Film::get_titlu()
{
    return Titlu;
}
void Film::set_gen(char* a)
{
    strcpy(this->Gen, a);
}
char* Film::get_gen()
{
    return Gen;
}
void Film::set_regizor(char* a)
{
  strcpy(this->Regizor, a);
}
char* Film::get_regizor()
{
    return Regizor;
}
void Film::set_rating(float a)
{
    this->Rating=a;
}

float Film::get_rating()
{
    return Rating;
}

 Film& Film::operator=(Film& f1)
{
        this -> Titlu = f1.Titlu;
        this -> Gen = f1.Gen;
        this -> Regizor = f1.Regizor;
        this -> Rating = f1.Rating;
        return *this;
}

void Film::citire(istream& in)
{
    char titlu[20];
    float rating;
    cout<<"Titlu film: ";
    in.get();
    in.getline(titlu, 20);
    this->Titlu=new char[strlen(titlu)];
    this->set_titlu(titlu);
    cout<<"Genul filmului: ";
    char gen[20];
    in.getline(gen, 20);
    this->Gen=new char[strlen(gen)];
    this->set_gen(gen);
    cout<<"Regizor film: ";
    char regizor[20];
    in.getline(regizor, 20);
    this->Regizor=new char [strlen(regizor)];
    this->set_regizor(regizor);
    cout<<"Rating IMDB: ";
    in>>rating;
    this->set_rating(rating);
    cout<<'\n';
}

istream& operator>>(istream& in, Film &f1)
{
    f1.citire(in);
    return in;
}


void Film::afisare(ostream& out)
{
    out<<"Titlu film: "<<this->Titlu<<'\n';
    out<<"Gen film: "<<this->Gen<<'\n';
    out<<"Regizor film: "<<this->Regizor<<'\n';
    out<<"Rating film: "<<this->Rating<<'\n';
    cout<<'\n';
}

ostream& operator<<(ostream& out, Film& f1)
{
   f1.afisare(out);
   return out;
}

bool operator==(Film &f1, Film &f2)
{
    if(f1.Rating==f2.Rating)
        return true;
    return false;
}

bool operator<(Film &f1, Film &f2){

        if(f1.Rating<f2.Rating)
            return true;
        return false;
}

bool operator>(Film& f1, Film &f2)
{
        if(f1.Rating>f2.Rating)
            return true;
        return false;
}


void menu_output()
{
    cout<<"\n Ghidarcea Tudor-Alexandru Gr141 - Proiect - Clasa 'film"<<"\n";
    cout<<"\n\t MENIU:";
    cout<<"\n===========================================\n";
    cout<<"\n";
    cout<<"1. Comparare 2 filme"; cout<<"\n";
    cout<<"2. Modificare date film"; cout<<"\n";
    cout<<"3. Afisare cele n filme citite"; cout<<"\n";
    cout<<"4. Afisare film cu cel mai mare rating"; cout<<"\n";
    cout<<"0. Iesire."; cout<<"\n";
}

int nr_filme;
Film *vector_de_filme=new Film[nr_filme+1];

void menu(Film *vector_de_filme, int nr_filme)
{
    int option;///optiunea aleasa din meniu
    option=0;

    do
    {
        menu_output();
        cout<<'\n'<<'\n';
        cout<<"Introduceti numarul actiunii: ";
        cin>>option;
        cout<<'\n';

        if (option==1)
        {
            int alegere1, alegere2;
            cout<<"Introduceti numerele corespunzatoare filmelor: ";
            cin.get();
            cin>>alegere1>>alegere2;
            if(alegere1>nr_filme||alegere2>nr_filme||alegere1<1||alegere2<0)
                cout<<"Nu exista film memorat corespunzator numarului unei alegeri."<<'\n';
            if(vector_de_filme[alegere1]==vector_de_filme[alegere2])
                cout<<"Filmele "<<alegere1<<" si "<<alegere2<<" au acelasi rating pe imdb"<<'\n';
            else
            {
                 if(vector_de_filme[alegere1]<vector_de_filme[alegere2])
                     cout<<"Filmul "<<alegere1<<" are rating mai mic pe imdb decat "<<alegere2<<'\n';
                 else
                     cout<<"Filmul "<<alegere1<<" are rating mai mare pe imdb decat "<<alegere2<<'\n';
            }
        }

        if (option==2)
        {
            bool ok;
            int alegere;
            cin.get();
            cout<<"Alegeti numarul filmului caruia vreti sa-i modificati detaliile: ";
            cin>>alegere;
            cout<<"Ati ales filmul cu: "<<vector_de_filme[alegere]<<'\n'<<'\n';

            cout<<"Doriti sa modificati titlul filmului? Introduceti '1' daca doriti si '0' daca nu doriti."<<'\n';
            cin.get();
            cin>>ok;
            if(ok==1)
            {
                cin.get();
                char titlu[20];
                cout<<"Introduceti noul titlu: ";
                cin.getline(titlu, 20);
                vector_de_filme[alegere].set_titlu(titlu);
            }

            cout<<"Doriti sa modificati genul filmului? Introduceti '1' daca doriti si '0' daca nu doriti."<<'\n';
            cin>>ok;
            if(ok==1)
            {
                cin.get();
                char gen[20];
                cout<<"Introduceti noul gen: ";
                cin.getline(gen, 20);
                vector_de_filme[alegere].set_gen(gen);
            }
            cout<<"Doriti sa modificati regizorul filmului? Introduceti '1' daca doriti si '0' daca nu doriti."<<'\n';
            cin>>ok;
            if(ok==1)
            {
                cin.get();
                char regizor[20];
                cout<<"Introduceti noul regizor: ";
                cin.getline(regizor, 20);
                vector_de_filme[alegere].set_regizor(regizor);
            }
            cout<<"Doriti sa modificati ratingul filmului? Introduceti '1' daca doriti si '0' daca nu doriti."<<'\n';
            cin>>ok;
            if(ok==1)
            {
                cin.get();
                float rating;
                cin>>rating;
                vector_de_filme[alegere].set_rating(rating);
            }
        }
        if (option==3)
        {
            int i;
            cout<<"Detaliile celor "<<nr_filme<<" filme memorate sunt: "<<'\n'<<'\n';
            for(i=1; i<=nr_filme; i++)
            {
                cout<<"Pentru filmul cu numarul: "<<i<<'\n';
                cout<<vector_de_filme[i];
                cout<<'\n';
            }
        }

        if(option==4)
        {
            int maxr, i;
            maxr=1;
            for(i=2; i<=nr_filme; i++)
                if(vector_de_filme[i]>vector_de_filme[maxr])
                    maxr=i;
            cout<<"Filmul cu cel mai mare rating pe imdb este filmul cu numarul: "<<maxr<<'\n';
            cout<<"Detaliile filmului sunt: "<<'\n';
            cout<<vector_de_filme[maxr];
            cout<<'\n';
        }

        if (option==0)
        {
            cout<<"\nEXIT!\n";
        }
        if (option<0||option>4)
        {
            cout<<"\nSelectie invalida\n";
        }
        cout<<"\n";
        system("pause"); ///Pauza - Press any key to continue...
        system("cls");   ///Sterge continutul curent al consolei
        }
    while(option!=0);
}

int main ()///se intra in functia main
{
   int nr_filme, i;
   cout<<"Introduceti numarul filmelor pe care vreti sa le memorati: ";
   cin>>nr_filme;
   cin.get();
   cout<<'\n';
   Film vector_de_filme[nr_filme+1];
   for(i=1; i<=nr_filme; i++)///se creeaza vectorul de filme
   {
       cout<<"Pentru filmul cu numarul "<<i<<" :"<<'\n';
       cin>>vector_de_filme[i];
       cout<<'\n';
   }
   //cin.get();
   menu(vector_de_filme, nr_filme);///se apeleaza meniul
   ofstream fisier;
fisier.open("obiect.txt");
fisier<<vector_de_filme[i]<<endl;
fisier.close();

   return 0;
}
