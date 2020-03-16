#include <iostream>
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
  
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    Wyswietl(WyrZ_PytanieTestowe);

    LZespolona Skl; bool flag;

    flag = Wczytaj(Skl);
    if (!flag){
      cout<<"Blad zapisu liczby zespolonej. Sprobuj jeszcze raz."<<endl<<endl;
      flag = Wczytaj(Skl);
    }

    if (flag){
      if(Skl == Oblicz(WyrZ_PytanieTestowe)){
        Poprawna(Stats);
        cout<<":) Odpowiedz poprawna"<<endl;
      }
      else {
        Bledna(Stats);
        cout<<":( Blad. Prawidlowym wynikiem jest: "; Wyswietl(Skl); cout<<endl;
      }
    } 
    else
    cout<<"Blad zapisu liczby zespolonej po raz 2. Brak mozliwosci poprawy"<<endl;
 
    cout<<endl;
    cin.clear( );
    cin.ignore(10000,'\n');
  }
  Wyswietl(Stats);

  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

}
