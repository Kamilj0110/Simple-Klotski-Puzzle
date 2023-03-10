//POP_2020_12_06_projekt_1_Jankowski_Kamil_AIR_3_184932 DEV-C++ MinGW GCC
#include <iostream>
#include <iomanip>
using namespace std;

const int N = 5;
const int M = 4;

struct Blok
{
    int x1, x2, y1, y2, indeks;
};

void ZapiszLiczbami(int Plansza[][M], Blok Bloki)  ///Zapisanie obszaru zajmowanego przez bloczek numerem jego indeksu
{
    Plansza[Bloki.x1][Bloki.y1] = Bloki.indeks;
    Plansza[Bloki.x1][Bloki.y2] = Bloki.indeks;
    Plansza[Bloki.x2][Bloki.y1] = Bloki.indeks;
    Plansza[Bloki.x2][Bloki.y2] = Bloki.indeks;
}
void PlanszaPoczatek(int Plansza[][M], Blok *Bloki)  ///Wpisanie danych do tablicy
{
    
    Bloki[0].x1 = 4; Bloki[0].y1 = 1; Bloki[0].x2 = 4; Bloki[0].y2 = 2;
    Bloki[1].x1 = 0; Bloki[1].y1 = 0; Bloki[1].x2 = 1; Bloki[1].y2 = 0;
    Bloki[2].x1 = 0; Bloki[2].y1 = 1; Bloki[2].x2 = 1; Bloki[2].y2 = 2;
    Bloki[3].x1 = 0; Bloki[3].y1 = 3; Bloki[3].x2 = 1; Bloki[3].y2 = 3;
    Bloki[4].x1 = 2; Bloki[4].y1 = 0; Bloki[4].x2 = 3; Bloki[4].y2 = 0;
    Bloki[5].x1 = 2; Bloki[5].y1 = 1; Bloki[5].x2 = 2; Bloki[5].y2 = 2;
    Bloki[6].x1 = 2; Bloki[6].y1 = 3; Bloki[6].x2 = 3; Bloki[6].y2 = 3;
    Bloki[7].x1 = 3; Bloki[7].y1 = 1; Bloki[7].x2 = 3; Bloki[7].y2 = 1;
    Bloki[8].x1 = 3; Bloki[8].y1 = 2; Bloki[8].x2 = 3; Bloki[8].y2 = 2;
    Bloki[9].x1 = 4; Bloki[9].y1 = 0; Bloki[9].x2 = 4; Bloki[9].y2 = 0;
    Bloki[10].x1 = 4; Bloki[10].y1 = 3; Bloki[10].x2 = 4; Bloki[10].y2 = 3;
    
    //PRZED OSTATNI RUCH PRZED WYGRANA      V  

    /*Bloki[0].x1 = 3; Bloki[0].y1 = 2; Bloki[0].x2 = 4; Bloki[0].y2 = 2;
    Bloki[1].x1 = 0; Bloki[1].y1 = 0; Bloki[1].x2 = 1; Bloki[1].y2 = 0;
    Bloki[2].x1 = 3; Bloki[2].y1 = 0; Bloki[2].x2 = 4; Bloki[2].y2 = 1;
    Bloki[3].x1 = 0; Bloki[3].y1 = 1; Bloki[3].x2 = 1; Bloki[3].y2 = 1;
    Bloki[4].x1 = 0; Bloki[4].y1 = 2; Bloki[4].x2 = 1; Bloki[4].y2 = 2;
    Bloki[5].x1 = 2; Bloki[5].y1 = 2; Bloki[5].x2 = 2; Bloki[5].y2 = 3;
    Bloki[6].x1 = 0; Bloki[6].y1 = 3; Bloki[6].x2 = 1; Bloki[6].y2 = 3;
    Bloki[7].x1 = 2; Bloki[7].y1 = 0; Bloki[7].x2 = 2; Bloki[7].y2 = 0;
    Bloki[8].x1 = 2; Bloki[8].y1 = 1; Bloki[8].x2 = 2; Bloki[8].y2 = 1;
    Bloki[9].x1 = 3; Bloki[9].y1 = 3; Bloki[9].x2 = 3; Bloki[9].y2 = 3;
    Bloki[10].x1 = 4; Bloki[10].y1 = 3; Bloki[10].x2 = 4; Bloki[10].y2 = 3;*/
    
    for (int i = 0; i < 11; i++)
    {
        Bloki[i].indeks = i;
        ZapiszLiczbami(Plansza, Bloki[i]);
    }
}

void Linia(int Plansza[][M],int i)          /// Funkcja do tworzenia lini pomiedzy bloczkami i w bloczkach
{
    if (i == N - 1)
    {
        cout << "+-------+ w y j s c i e +-------+";
    }
    else
    {


        if (Plansza[i][0] != Plansza[i + 1][0])
        {
            cout << "+-------";
        }
        if (Plansza[i][0] == Plansza[i + 1][0])
        {
            cout << "|       ";
        }


        for (int j = 1; j < M; j++)
        {
            if (Plansza[i][j] != Plansza[i + 1][j])
            {
                cout << "+-------";
            }
            if (Plansza[i][j] == Plansza[i + 1][j] && Plansza[i][j] != Plansza[i][j - 1])
            {
                if (Plansza[i][j - 1] != Plansza[i + 1][j - 1])
                    cout << "+       ";
                else
                cout << "|       ";
            }
            if (Plansza[i][j] == Plansza[i + 1][j] && Plansza[i][j] == Plansza[i][j - 1])
            {
                cout << "        ";
            }
        }
        if (Plansza[i][M-1] != Plansza[i + 1][M-1])
        {
            cout << "+";
        }
        if (Plansza[i][M-1] == Plansza[i + 1][M-1])
        {
            cout << "| ";
        }
    }
}

void PierwszaLinijkaTablicy(int Plansza[][M])
{
    cout << "+";
    for (int j = 0; j < M-1; j++)
    {
        if (Plansza[0][j] != Plansza[0][j + 1])
            cout << "-------+";
        else
            cout << "--------";
    }
    cout << "-------+";
}
void WypiszTablice(int Plansza[][M])
{
    PierwszaLinijkaTablicy(Plansza);
    for (int i = 0; i < N; i++)
    {   
        cout << "\n|";
        for (int j = 0; j < M-1; j++)
        {
            if (Plansza[i][j] != 0)
                cout << " " << setw(2) << Plansza[i][j] << "    ";
            else
                cout << "\t";

            if (Plansza[i][j + 1] != Plansza[i][j])
				cout << "|";
            else
                cout << " ";
            
        }
        if (Plansza[i][M-1] != 0)
         cout << " " << setw(2) << Plansza[i][M-1] << "    |";
        else
            cout << "\t|";
        cout << endl << "|";

        for (int j = 0; j < M-1; j++)
        {
            if (Plansza[i][j] != 0)
                cout << "    "<<setw(2) << Plansza[i][j] << " ";
            else
                cout << "\t";

            if (Plansza[i][j + 1] != Plansza[i][j])cout << "|";
            else
                cout << " ";

        }
        if (Plansza[i][M-1] != 0)
            cout << "    " << setw(2) << Plansza[i][M-1] << " |";
        else
            cout << "\t|";

        cout << endl;
        Linia(Plansza, i);
    }
        
}

void wGore(int Plansza[][M], Blok &Bloki, int& IloscRuchow)
{
    if (Bloki.x1 - 1 >= 0 && Plansza[Bloki.x1 - 1][Bloki.y1] == 0 && Plansza[Bloki.x1 - 1][Bloki.y2] == 0)
    {
        Plansza[Bloki.x2][Bloki.y2] = 0;
        Plansza[Bloki.x2][Bloki.y1] = 0;
        Bloki.x2 = Bloki.x2 - 1;
        Bloki.x1 = Bloki.x1 - 1;
        ZapiszLiczbami(Plansza, Bloki);
        IloscRuchow++;

    }
    else
        cout << "\nNiemozliwy ruch ";
}
void wDol(int Plansza[][M], Blok &Bloki, int& IloscRuchow)
{
    if (Bloki.x2+1<=4 && Plansza[Bloki.x2+1][Bloki.y1]==0   &&  Plansza[Bloki.x2+1][Bloki.y2]==0)
    {
        Plansza[Bloki.x1][Bloki.y1] = 0;
        Plansza[Bloki.x1][Bloki.y2] = 0;
        Bloki.x1 = Bloki.x1 + 1;
        Bloki.x2 = Bloki.x2 + 1;
        ZapiszLiczbami(Plansza, Bloki);
        IloscRuchow++;
    }
    else
        cout << "\nNiemozliwy ruch ";
}

void wLewo(int Plansza[][M], Blok &Bloki, int& IloscRuchow)
{
    if (Bloki.y1 - 1 >= 0 && Plansza[Bloki.x1][Bloki.y1 - 1] == 0 && Plansza[Bloki.x2][Bloki.y1 - 1] == 0)
    {
        
        Plansza[Bloki.x1][Bloki.y2] = 0;
        Plansza[Bloki.x2][Bloki.y2] = 0;
        Bloki.y2 = Bloki.y2 - 1;
        Bloki.y1 = Bloki.y1 - 1;
        ZapiszLiczbami(Plansza, Bloki);
        IloscRuchow++;

    }
    else
        cout << "\nNiemozliwy ruch ";
}

void wPrawo(int Plansza[][M], Blok &Bloki, int& IloscRuchow)
{
    if (Bloki.y2 + 1 <= 3 && Plansza[Bloki.x1][Bloki.y2 + 1] == 0 && Plansza[Bloki.x2][Bloki.y2 + 1] == 0)
    {
        Plansza[Bloki.x1][Bloki.y1] = 0;
        Plansza[Bloki.x2][Bloki.y1] = 0;
        Bloki.y2 = Bloki.y2 + 1;
        Bloki.y1 = Bloki.y1 + 1;
        ZapiszLiczbami(Plansza, Bloki);
        IloscRuchow++;

    }
    else
        cout << "\nNiemozliwy ruch ";
}
void MenuRuchow(int Plansza[][M], Blok* Bloki,char Kierunek,int indeks, int& IloscRuchow)
{
    switch(Kierunek)
    {
    case 'd':
    
        wDol(Plansza, Bloki[indeks], IloscRuchow);
        break;
    
        
    case 'g':
    
        wGore(Plansza, Bloki[indeks], IloscRuchow);
        break;
   
    case 'l':
    
        wLewo(Plansza, Bloki[indeks], IloscRuchow);
        break;
    
    case 'p':
    
        wPrawo(Plansza, Bloki[indeks], IloscRuchow);
        break;
    
    default:
        cout << "\nZla litera";
        break;
    }
}
void Menu(int Plansza[][M], Blok* Bloki,int &IloscRuchow)
{
    char Ruch[3], znak[1];
    int indeks;
    znak[0] = 'x';
    while (Bloki[2].x1!=3||Bloki[2].y1!=1)
    {
        WypiszTablice(Plansza);
        cout << "\nWpisz 'R' aby zresetowac\n";
        cout << "\nIlosc Ruchow: " << IloscRuchow;
        cout << "\nPodaj ruch: "; cin >> Ruch;
        if (Ruch[0] == 'r' || Ruch[0] == 'R')
        {
            PlanszaPoczatek(Plansza, Bloki);				///Reset Tablicy
        }
        else
        {


            if ((Ruch[0] > '0' && Ruch[0] <= '9') && ((Ruch[1] >= 'a' && Ruch[1] <= 'z') || (Ruch[1] >= 'A' && Ruch[1] <= 'Z')) && Ruch[2]=='\0') ///1 Czesc sprawdzania wpisanych danych
            {
                indeks = Ruch[0] - '0';
                znak[0] = Ruch[1];
                MenuRuchow(Plansza, Bloki, znak[0], indeks, IloscRuchow);
            }
            else
            {
                if ((Ruch[0] == '1' && Ruch[1] == '0') && ((Ruch[2] >= 'a' && Ruch[2] <= 'z') || (Ruch[2] >= 'A' && Ruch[2] <= 'Z')))	///2 Czesc sprawdzania wpisanych danych
                {
                    indeks = 10;
                    znak[0] = Ruch[2];
                    MenuRuchow(Plansza, Bloki, znak[0], indeks, IloscRuchow);
                }
                else
                {
                    cout << "\nZle podane dane ";
                }
            }


        }
    }
    WypiszTablice(Plansza);
    cout << "\nIlosc Ruchow: " << IloscRuchow;
    cout << "\n WYGRALES !!!";
}
int main()
{
    int LicznikRuchow = 0, Plansza[N][M];
    Blok Bloki[11];
    PlanszaPoczatek(Plansza, Bloki);
    Menu(Plansza, Bloki,LicznikRuchow);
}


