/*!
 * Modeluje pojecie statystyki poprawnych i blednych odpowiedzi
 */
struct  Statystyka {
  int   p;    /*! Pole repezentuje liczbe odpowiedzi poprawnych. */
  int   b;    /*! Pole repezentuje liczbe odpowiedzi blednych. */
};



Statystyka Inicjuj (Statystyka & Stats);
void Poprawna (Statystyka & Stats);
void Bledna (Statystyka & Stats);

int Wszystkie (Statystyka & Stats);
double Procent (Statystyka & Stats);

std::ostream & operator << (std::ostream & strm, Statystyka & Stats);
