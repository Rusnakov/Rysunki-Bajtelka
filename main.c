#include <stdio.h>
#include <stdlib.h>

long long int wczytanie_wiersza_danych ()
{
    long long int pole=0, bufor[2][100000]={0}, p1, p2;
    int ilosc_wierzcholkow=0;
    scanf("%I64u", &bufor[0][0]);
    scanf("%I64u", &bufor[1][0]);

    do    {
        ilosc_wierzcholkow++;
        scanf("%I64u", &bufor[0][ilosc_wierzcholkow]);
        scanf("%I64u", &bufor[1][ilosc_wierzcholkow]);
    }
    while ((bufor[0][0]!=bufor[0][ilosc_wierzcholkow]) || (bufor[1][0]!=bufor[1][ilosc_wierzcholkow]));

    for (int i=0; i<ilosc_wierzcholkow; i++)    {
        p1=bufor[0][i]*bufor[1][i+1];
        p2=bufor[0][i+1]*bufor[1][i];
        pole = (pole+(p1-p2));
    }

    if (pole < 0){
        pole = pole*(-1);
    };

    return pole;
}

int main() {

    int ilosc_testow;
    scanf("%d", &ilosc_testow);

    for (int i=0; i<ilosc_testow; i++) {
        long long int pole1=0, pole2=0, tuszokule=0;
        pole1 = wczytanie_wiersza_danych();
        pole2 = wczytanie_wiersza_danych();

        if (pole1 < pole2) {
						tuszokule = (pole2-pole1)*3+pole1*5;
        }

        else {
						tuszokule = (pole1-pole2)*3+pole2*5;
        }

        printf ("%I64u\n",tuszokule);
    }
}
