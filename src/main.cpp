#include <iostream>
#include <fstream>
#include "BazaTestu.hh"
#include "Statystyka.hh"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::showpos;
using std::noshowpos;



int main(int argc, char **argv)
{
  Statystyka Stats;
  Inicjuj(Stats);

  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }


  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;
  
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) 
  {
    LZespolona Skl, Wynik = Oblicz(WyrZ_PytanieTestowe); bool flag = true; int i = 1;

    cout <<"  :? Oblicz: " << WyrZ_PytanieTestowe << endl;

    do
    {
      if (!flag)
      {
        cout << "  :! Blad zapisu liczby zespolonej. Sprobuj jeszcze raz."<<endl<<endl;
        cin.clear( ); cin.ignore(10000,'\n');
        i++;
      } 
      cout << "  :o Twoja odpowiedz: "; 
      cin >> Skl;
      flag = cin.good();
    } while(!flag && i < 3);

    if (flag)
    {
      if(Skl == Wynik)
      {
        Poprawna(Stats);
        cout<<"  :) Odpowiedz poprawna"<<endl<<endl;
      }
      else 
      {
        Bledna(Stats);
        cout << "  :( Blad. Prawidlowym wynikiem jest: " << Wynik << endl << endl;
      }
    } 
    else
    {
      cout << "  :! Blad zapisu liczby zespolonej po raz 3. Brak mozliwosci poprawy" << endl << endl;
      Bledna(Stats);
    }

    cout<<endl;
    cin.clear( ); cin.ignore(10000,'\n');
  }
  
  cout<<Stats;

  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

}
