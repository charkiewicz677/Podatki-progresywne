#include <stdio.h>
#include <stdlib.h>

float licz_podatek(float dochod);

int main()
{

    FILE *fptr;
    fptr = fopen("podatek_wzgledny.txt", "w");
    for(float i = 1000; i<150000; i += 50){
        fprintf(fptr, "%.2f, %.2f\n", i, (licz_podatek(i)/12)/i);
    }
    //printf("Podatek przy zarobkach %.2f zl miesiecznie wynosi %.2f zl rocznie\n", miesiecznie, licz_podatek(miesiecznie));

    fclose(fptr);
    return 0;
}

float licz_podatek(float dochod_miesieczny){
    float podatek = 0;
    float dochod_roczny = 12*dochod_miesieczny;
    if (dochod_roczny > 500000){
            podatek += (dochod_roczny - 500000)*0.75;
            dochod_roczny = 500000;
    }
    if (dochod_roczny > 250000) {
        podatek += (dochod_roczny - 250000)*0.55;
        dochod_roczny = 250000;
    }
    if (dochod_roczny > 120000) {
        podatek += (dochod_roczny - 120000)*0.44;
        dochod_roczny = 120000;
    }
    if (dochod_roczny > 60000) {
        podatek += (dochod_roczny - 60000)*0.33;
        dochod_roczny = 60000;
    }
    if (dochod_roczny > 12000) {
        podatek += (dochod_roczny - 12000)*0.22;
        dochod_roczny = 12000;
    }

    return podatek;
}
