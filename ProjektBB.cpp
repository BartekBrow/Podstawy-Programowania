#include <stdio.h>
#include <string.h>

#define MAX_GRACZY 11


// DEKLARACJA ZMIENNYCH

struct Gracz {
    char imie[30];
    char nazwisko[30];
    int numer;
};



struct Druzyna {
    char nazwa[50];
    struct Gracz zawodnicy[MAX_GRACZY];
    int numer_zawodnikow;
};

// ZAPIS NA DYSK PLIK druzyna.txt

void zapiszDruzyne(struct Druzyna druzyna) {
    FILE *plik = fopen("druzyna.txt", "w");
    if (plik == NULL) {
        printf("Nie mozna otworzyc pliku.\n");
        return;
    }
    fprintf(plik, "Nazwa druzyny: %s\n", druzyna.nazwa);
    fprintf(plik, "Ilosc zawodnikow: %d\n", druzyna.numer_zawodnikow);
    for (int i = 0; i < druzyna.numer_zawodnikow; i++) {
        fprintf(plik, "%d. %s %s\n", druzyna.zawodnicy[i].numer, druzyna.zawodnicy[i].imie, druzyna.zawodnicy[i].nazwisko);
    }
    fclose(plik);
    printf("Druzyna zostala zapisana na dysku.\n");
}

// ODCZYT Z DYSKU PLIK druzyna.txt

struct Druzyna wczytajDruzyne() {
    struct Druzyna druzyna;
    FILE *plik = fopen("druzyna.txt", "r");
    if (plik == NULL) {
        printf("Nie znaleziono pliku z druzyna.\n");
        druzyna.numer_zawodnikow = 0;
        return druzyna;
    }
    fscanf(plik, "Nazwa druzyny: %s\n", druzyna.nazwa);
    fscanf(plik, "Ilosc zawodnikow: %d\n", &druzyna.numer_zawodnikow);
    for (int i = 0; i < druzyna.numer_zawodnikow; i++) {
        fscanf(plik, "%d. %s %s\n", &druzyna.zawodnicy[i].numer, druzyna.zawodnicy[i].imie, druzyna.zawodnicy[i].nazwisko);
    }
    fclose(plik);
    printf("Druzyna zostala wczytana z dysku.\n");
    return druzyna;
}


// PROGRAM GLOWNY


int main() {
    struct Druzyna druzyna;
    druzyna.numer_zawodnikow = 0;
   
    printf("Witaj w menedzerze pilkarskim!\n");
printf("\nZwiazek np. PZPS ?\n");
    printf("Podaj nazwe druzyny: ");
    scanf("%s", druzyna.nazwa);
   
    while (1) {


        printf("\nCo chcesz zrobic?\n");
        printf("1. Dodaj zawodnika\n");
        printf("2. Wyswietl sklad druzyny\n");
        printf("3. Zapisz druzyne na dysk\n");
        printf("4. Wczytaj druzyne z dysku\n");
        printf("5. Wyjdz\n");
        printf("Wybierz opcje (1/2/3/4/5): ");
       
        int opcja;
        scanf("%d", &opcja);
       
        switch (opcja) {
            case 1:
                if (druzyna.numer_zawodnikow < MAX_GRACZY) {
                    printf("Podaj imie zawodnika: ");
                    scanf("%s", druzyna.zawodnicy[druzyna.numer_zawodnikow].imie);
                    printf("Podaj nazwisko zawodnika: ");
                    scanf("%s", druzyna.zawodnicy[druzyna.numer_zawodnikow].nazwisko);
                    druzyna.zawodnicy[druzyna.numer_zawodnikow].numer = druzyna.numer_zawodnikow + 1;
                    druzyna.numer_zawodnikow++;
                    printf("Zawodnik dodany do druzyny!\n");
                } else {
                    printf("Druzyna jest juz pelna!\n");
                }
                break;
            case 2:
                printf("Sklad druzyny %s:\n", druzyna.nazwa);
                for (int i = 0; i < druzyna.numer_zawodnikow; i++) {
                    printf("%d. %s %s\n", druzyna.zawodnicy[i].numer, druzyna.zawodnicy[i].imie, druzyna.zawodnicy[i].nazwisko);
                }
                break;
            case 3:
                zapiszDruzyne(druzyna);
                break;
            case 4:
                druzyna = wczytajDruzyne();
                break;
            case 5:
                printf("Dziekujemy za korzystanie z menedzera pilkarskiego!\n");
                return 0;
            default:
                printf("Nieprawidlowa opcja. Sprobuj ponownie.\n");
        }
    }
   
    return 0;
}
