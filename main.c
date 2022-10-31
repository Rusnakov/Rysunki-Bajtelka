#include <stdio.h>
#include <stdlib.h>
/*#define BUFSIZE 1000000
int wektor_wierzcholkow_pola[BUFSIZE], dlugosc_wektora_wierzcholkow_pola;
long long int pole_zadruku_czarne=0, pole_zadruku_szare=0;
void bufClear (char *buf)
{
    int i;
    for (i=0; i<BUFSIZE; i++)
    {
        buf[i]='\0';
    }
}
void clear_buf_string (char *buf)
{
    int i;
    for (i=0; i<8; i++)
    {
        buf[i]=' ';
    }
}
int dlugosc_slowa_w_buforze (char *wektor_danych)
{
    int i;
    if (*wektor_danych)
    {
        for (i=0; i<BUFSIZE; i++)
        {
            if (wektor_danych[i]=='\n' || wektor_danych[i]=='\0') return i;
        }
    }
    return -1;
}
void zamianaSlowaNaLiczy (char *wektor_danych)
{
    int iloscCyfrWLiczbie=8;
    int i, licznikLiczbyIntowej=0, l, licznik_cyfry_liczby_w_stringu=iloscCyfrWLiczbie;
    char buforNaLiczbeWSringu[]= {"        "};
    l = dlugosc_slowa_w_buforze(wektor_danych);
    for (i=l-1; i>-1; i--)
    {
        if (wektor_danych[i]!=0x20 )
        {
            buforNaLiczbeWSringu[licznik_cyfry_liczby_w_stringu]=wektor_danych[i];
            licznik_cyfry_liczby_w_stringu--;
            if (i==0)
            {
                wektor_wierzcholkow_pola[licznikLiczbyIntowej]=atoi(buforNaLiczbeWSringu);
                //printf("Liczba wpisana w wektor = %i\n",wektor_wierzcholkow_pola[licznikLiczbyIntowej]);
                licznikLiczbyIntowej++;
                licznik_cyfry_liczby_w_stringu=iloscCyfrWLiczbie;
                clear_buf_string(buforNaLiczbeWSringu);
            }
        }
        else if (wektor_danych[i]==0x20 && wektor_danych[i-1]!=0x20)//// flage o spacje
        {
            wektor_wierzcholkow_pola[licznikLiczbyIntowej]=atoi(buforNaLiczbeWSringu);
            //printf("Liczba wpisana w wektor = %i\n",wektor_wierzcholkow_pola[licznikLiczbyIntowej]);
            licznikLiczbyIntowej++;
            licznik_cyfry_liczby_w_stringu=iloscCyfrWLiczbie;
            clear_buf_string(buforNaLiczbeWSringu);
        }
    }
    dlugosc_wektora_wierzcholkow_pola=licznikLiczbyIntowej;
}*/

char wczytywanie_danych (void)
{
    int bufor[2][100000];
    int licznik_wczytywanego_wierzcholka=0;
    scanf("%d", &bufor[0][0]);
    scanf("%d", &bufor[1][0]);
    do
    {
        licznik_wczytywanego_wierzcholka++;
        scanf("%d", &bufor[0][licznik_wczytywanego_wierzcholka]);
        scanf("%d", &bufor[1][licznik_wczytywanego_wierzcholka]);
    }
    while ((bufor[0][0]!=bufor[0][licznik_wczytywanego_wierzcholka]) || (bufor[1][0]!=bufor[1][licznik_wczytywanego_wierzcholka]));
    return &bufor[0][0];
}




int main()
{
    int ilosc_testow, bufor[0][0];
    scanf("%d", &ilosc_testow);
    for (int i=0; i<ilosc_testow; i++)
    {
        *bufor = wczytywanie_danych;
    }
    for (int i=0; i<2; i++)
    {
        for (int j=0; j<=licznik_wczytywanego_wierzcholka; j++)
        {
            printf ("%i ", bufor[i][j]);
        }
    }

    /*
    int i, j, k, l, m, t;
    long long int tuszokule, pole1, pole2, true_pole_szare, true_pole_czarne;
    char buforSz[BUFSIZE]= {0};
    char buforCz[BUFSIZE]= {0};
    scanf("%i", &t);			                                // wczytanie ilo�ci zestaw�w danych
    for (i=0; i<t; i++)
    {
        k = fgetc(stdin);                                       // zczytanie znaku pustej linii mi�dzy danymi (a w pierwszym przebiegu pozostawionego przez funkcj� scanf)
        //printChar (k);		                                // wy�wietlenie znaku specjalnego
        for (j=0; j<2; j++)
        {
            if (j==0) fgets(buforCz, sizeof buforCz, stdin);
            if (j==1) fgets(buforSz, sizeof buforSz, stdin);
        }
        zamianaSlowaNaLiczy (buforCz);
        for (k=1; k<=(dlugosc_wektora_wierzcholkow_pola-2)/2; k++)
        {
            int y1, x0, x2;
            y1=dlugosc_wektora_wierzcholkow_pola-2*k;
            x2=dlugosc_wektora_wierzcholkow_pola-2*k-1;
            x0=dlugosc_wektora_wierzcholkow_pola-2*k+3;
            if ( x0>dlugosc_wektora_wierzcholkow_pola) x0=-2*k+5;
            pole_zadruku_czarne += (long long) wektor_wierzcholkow_pola[y1]*(wektor_wierzcholkow_pola[x2]-wektor_wierzcholkow_pola[x0]);
    //            printf("Licznik k = %i, Indeksy:   y1 = %i, x2 = %i, x0 = %i\n",k,y1,x2,x0);
    //            printf("                Wartosci:  %i,      %i,      %i\n",wektor_wierzcholkow_pola[y1],wektor_wierzcholkow_pola[x2],wektor_wierzcholkow_pola[x0]);
    //            printf("Pole zadruku czarne = %i\n",pole_zadruku_czarne);
        }
        bufClear(wektor_wierzcholkow_pola);
        dlugosc_wektora_wierzcholkow_pola=0;
        zamianaSlowaNaLiczy (buforSz);
        for (k=1; k<=(dlugosc_wektora_wierzcholkow_pola-2)/2; k++)
        {
            int y1, x0, x2;
            y1=dlugosc_wektora_wierzcholkow_pola-2*k;
            x2=dlugosc_wektora_wierzcholkow_pola-2*k-1;
            x0=dlugosc_wektora_wierzcholkow_pola-2*k+3;
            if ( x0>dlugosc_wektora_wierzcholkow_pola) x0=-2*k+5;
            pole_zadruku_szare += (long long) wektor_wierzcholkow_pola[y1]*(wektor_wierzcholkow_pola[x2]-wektor_wierzcholkow_pola[x0]);
    //            printf("Licznik k = %i, Indeksy:   y1 = %i, x2 = %i, x0 = %i\n",k,y1,x2,x0);
    //            printf("                Wartosci:  %i,      %i,      %i\n",wektor_wierzcholkow_pola[y1],wektor_wierzcholkow_pola[x2],wektor_wierzcholkow_pola[x0]);
    //            printf("Pole zadruku szare = %i\n",pole_zadruku_czarne);
        }
        pole1=fabs(pole_zadruku_czarne);
        pole2=fabs(pole_zadruku_szare);

        if (pole1>pole2)
        {
            true_pole_szare=pole1;
            true_pole_czarne=pole2;
        }
        else
        {
            true_pole_szare=pole2;
            true_pole_czarne=pole1;
        }

        tuszokule=((true_pole_szare-true_pole_czarne)*3+true_pole_czarne*5);
        printf("%lld\n", tuszokule);
        bufClear(wektor_wierzcholkow_pola);
        dlugosc_wektora_wierzcholkow_pola=0;
        bufClear(buforSz);
        pole_zadruku_szare=0;
        bufClear(buforCz);
        pole_zadruku_czarne=0;
    }*/
    return 0;
}
