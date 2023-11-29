#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <math.h>
using namespace std;
class Proces
{
protected:
  int nrProces;
  string reclamant;
  string reclamat;
public:
    Proces ()
  {
    this->nrProces = 0;
    this->reclamant = "";
    this->reclamat = "";
  }
  Proces (int nrProces, string reclamant, string reclamat)
  {
    this->nrProces = nrProces;
    this->reclamant = reclamant;
    this->reclamat = reclamat;
  }
  ~Proces ()
  {
  }
  Proces (const Proces & proces)
  {
    this->nrProces = proces.nrProces;
    this->reclamant = proces.reclamant;
    this->reclamat = proces.reclamat;
  }
  friend ostream & operator<< (ostream & out, const Proces & proces);
  friend istream & operator>> (istream & in, Proces & proces);
  Proces & operator= (const Proces & proces)
  {
    if (this != &proces)
      {
	this->nrProces = proces.nrProces;
	this->reclamant = proces.reclamant;
	this->reclamat = proces.reclamat;
      }
    return *this;
  }
void
set_nrProces (int nrProces)
{
  this->nrProces = nrProces;
}

int
get_nrProces ()
{
  return this->nrProces;
}

void
set_reclamant (string reclamant)
{
  this->reclamant = reclamant;
}

string
get_reclamant ()
{
  return this->reclamant;
}

void
set_reclamat (string)
{
  this->reclamat = reclamat;
}

string
get_reclamat ()
{
  return this->reclamat;
}

};

istream& operator>>(istream& in, Proces& proces)
{
    cout<<"Numarul procesului: ";
    in>>proces.nrProces;
    cout<<"Nume reclamant: ";
    in>>proces.reclamant;
    cout<<"Nume reclamat: ";
    in>>proces.reclamat;
    return in;
}
ostream& operator<<(ostream& out, const Proces& proces)
{
    out<<"Numarul procesului este: "<<proces.nrProces<<"\n";
    out<<"Numele reclamantului este "<<proces.reclamant<<"\n";
    out<<"Numele reclamatului este: "<<proces.reclamat<<"\n";
    return out;
}
void meniu(Proces *vector_de_procese, int nr_procese);


class Proces_civil:protected Proces
{
private:
  double dauneMorale;
  double dauneMateriale;
  int nrMartori;
  bool stadiu;
  double taxa_de_timbru;
public:
    Proces_civil ()
  {
    this->dauneMorale = 0.0;
    this->dauneMateriale = 0.0;
    this->nrMartori = 0;
    this->stadiu=0;
    this->taxa_de_timbru=0;
  }
  Proces_civil (double dauneMorale, double dauneMateriale, int nrMartori, bool stadiu, double taxa_de_timbru)
  {
    this->dauneMorale = dauneMorale;
    this->dauneMateriale = dauneMateriale;
    this->nrMartori = nrMartori;
    if(nrMartori>5){this->stadiu==1;};
    this->stadiu = stadiu;
    this->taxa_de_timbru=1/10*dauneMorale+1/10*dauneMateriale;
  }
  ~Proces_civil ()
  {
  }
  Proces_civil (const Proces_civil & proces_civil)
  {
    this->dauneMorale = proces_civil.dauneMorale;
    this->dauneMateriale = proces_civil.dauneMateriale;
    this->nrMartori = proces_civil.nrMartori;
    this->stadiu = proces_civil.stadiu;
  }
  friend ostream & operator<< (ostream & out, const Proces_civil & proces_civil);
  friend istream & operator>> (istream & in, Proces_civil & proces_civil);
  Proces & operator= (const Proces_civil & proces_civil)
  {
    if (this != &proces_civil)
      {
	this->dauneMorale = proces_civil.dauneMorale;
	this->dauneMateriale = proces_civil.dauneMateriale;
	this->nrMartori = proces_civil.nrMartori;
	this->stadiu = proces_civil.stadiu;
      }
    return *this;
  }

void
set_dauneMorale (double dauneMorale)
{
  this->dauneMorale = dauneMorale;
}

double
get_dauneMorale ()
{
  return this->dauneMorale;
}

void
set_dauneMateriale (double dauneMateriale)
{
  this->dauneMateriale = dauneMateriale;
}

double
get_dauneMateriale ()
{
  return this->dauneMateriale;
}

void
set_nrMartori (int nrMartori)
{
  this->nrMartori = nrMartori;
}

int
get_nrMartori ()
{
  return this->nrMartori;
}

void
set_stadiu(bool stadiu)
{
    this->stadiu = stadiu;
}

bool
get_stadiu ()
{
    return this-> stadiu;
}



};

istream& operator>>(istream& in, Proces_civil& proces_civil)
{
    cout<<"Valoarea daunelor morale: ";
    in>>proces_civil.dauneMorale;
    cout<<"Valoarea daunelor materiale: ";
    in>>proces_civil.dauneMateriale;
    cout<<"Numarul martorilor: ";
    in>>proces_civil.nrMartori;
    cout<<"Stadiul procesului civil: ";
    in>>proces_civil.stadiu;
    if(proces_civil.nrMartori>5){proces_civil.stadiu=1;};
    return in;
}
ostream& operator<<(ostream& out, const Proces_civil& proces_civil)
{
    out<<"Valoarea daunelor morale este: "<<proces_civil.dauneMorale<<"\n";
    out<<"Valoarea daunelor materiale este: "<<proces_civil.dauneMateriale<<"\n";
    out<<"Numarul martorilor este: "<<proces_civil.nrMartori<<"\n";
    out<<"Stadiul procesului civil este: "<<proces_civil.stadiu<<"\n";
    return out;
}

class Proces_penal: protected Proces
{
protected:
  int dovezi;
  bool stadiu;
public:
    Proces_penal ()
  {
    this->dovezi = 0;
    this->stadiu = 0;
  }
  Proces_penal (int dovezi, bool stadiu)
  {
    this->dovezi = dovezi;
    this->stadiu = stadiu;
  }
  ~Proces_penal ()
  {
  }
  Proces_penal (const Proces_penal & proces_penal)
  {
    this->dovezi = proces_penal.dovezi;
    this->stadiu = proces_penal.stadiu;
  }
  friend ostream & operator<< (ostream & out, const Proces_penal & proces_penal);
  friend istream & operator>> (istream & in, Proces_penal & proces_penal);
  Proces & operator= (const Proces_penal & proces_penal)
  {
    if (this != &proces_penal)
      {
	this->dovezi = proces_penal.dovezi;
	this->stadiu = proces_penal.stadiu;
      }
    return *this;
  }
void
set_dovezi (int dovezi)
{
  this->dovezi = dovezi;
}

int
get_dovezi ()
{
  return this->dovezi;
}

void
set_stadiu (bool stadiu)
{
  this->stadiu = stadiu;
}

bool
get_stadiu ()
{
  return this->stadiu;
};

friend istream& operator>>(istream& in, Proces_penal& proces_penal)
{
    cout<<"Numarul dovezilor: ";
    in>>proces_penal.dovezi;
    cout<<"Stadiul procesului penal: ";
    in>>proces_penal.stadiu;
    if(proces_penal.dovezi>25){proces_penal.stadiu=1;};
    return in;
}
friend ostream& operator<<(ostream& out, const Proces_penal& proces_penal)
{
    out<<"Numarul dovezilor este: "<<proces_penal.dovezi<<"\n";
    out<<"Stadiul procesului penal este: "<<proces_penal.stadiu<<"\n";
    return out;
}
};
void meniu_output()
{

   cout<<"\n Ghidarcea Tudor-Alexandru Gr141 - Proiect - Clasa Proces"<<"\n";
    cout<<"\n\t MENIU:";
    cout<<"\n===========================================\n";
    cout<<"\n";
    cout<<"1. Memorati Proces";cout<<"\n";
    cout<<"2. Memorati Proces Civil";cout<<"\n";
    cout<<"3. Memorati Proces Penal";cout<<"\n";
    cout<<"4. Afisare proces civil cu cea mai mare taxa timbru(nefunctionala)"; cout<<"\n";
    cout<<"5. Modificare stadiu proces"; cout<<"\n";
    cout<<"6. Afisare cele n procese citite"; cout<<"\n";
    cout<<"0. Iesire."; cout<<"\n";
}

int nr_procese;



void meniu(Proces *vector_de_procese, int nr_procese)

{

    int option;///optiunea aleasa din meniu
    option=0;

    do
    {
        meniu_output();
        cout<<'\n'<<'\n';
        cout<<"Introduceti numarul actiunii: ";
        cin>>option;
        cout<<'\n';

      if(option==1)
      {
          Proces *vector_de_procese=new Proces[nr_procese+1];
          cin>>static_cast<Proces&>((vector_de_procese[nr_procese]));



      }

      if(option==2)
      {
        Proces_civil *vector_de_procese=new Proces_civil[nr_procese+1];
        cin>>static_cast<Proces_civil&>((vector_de_procese[nr_procese]));


      }

      if(option==3)
      {
          Proces_penal *vector_de_procese=new Proces_penal[nr_procese+1];
          cin>>static_cast<Proces_penal&>((vector_de_procese[nr_procese]));

      }

     if (option==4)
        {




        }

        if (option==5)
        {
            bool ok;
            int alegere;
            cin.get();
            cout<<"Alegeti numarul procesului caruia vreti sa-i modificati stadiul: ";
            cin>>alegere;
            cout<<"Ati ales procesul cu: "<<vector_de_procese[alegere]<<'\n'<<'\n';

            cout<<"Doriti sa modificati stadiul procesului? Introduceti '1' daca doriti si '0' daca nu doriti."<<'\n';
            cin.get();
            cin>>ok;
            if(ok==1)
            {
                cin.get();
                bool stadiu;
                cout<<"Introduceti noul stadiu: ";
                cin.get();
                cout<<vector_de_procese[alegere];


            }
        }


        if(option==6)
        {
for(int j=1; j<=nr_procese; j++)
    cout<<vector_de_procese[j];
        }

        if (option==0)
        {
            cout<<"\nEXIT!\n";
        }
        if (option!=0&&option!=1&&option!=2&&option!=3&&option!=4&&option!=5&&option!=6)
        {
            cout<<"\nSelectie invalida\n";
        }
        cout<<"\n";
        system("pause"); ///Pauza - Press any key to continue...
        system("cls");   ///Sterge continutul curent al consolei
        }
    while(option!=0);
}
int main()
{




    int nr_procese, i;
   cout<<"Introduceti numarul proceselor pe care vreti sa le memorati: ";
   cin>>nr_procese;
   cin.get();
   cout<<'\n';
    Proces vector_de_procese[nr_procese+1];
   for(i=1; i<=nr_procese; i++)///se creeaza vectorul de procese
   {

       cout<<"Pentru procesul cu numarul "<<i<<" :"<<'\n';
       cin>>vector_de_procese[i];

   }
   cin.get();

   meniu(vector_de_procese, nr_procese);

}
