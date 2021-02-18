#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    int sayi = atoi(argv[0]);
    switch(sayi){
        case 0: printf("0 >> sifir\n"); break;
        case 1: printf("1 >> bir\n"); break;
        case 2: printf("2 >> iki\n"); break;
        case 3: printf("3 >> uc\n"); break;
        case 4: printf("4 >> dort\n"); break;
        case 5: printf("5 >> bes\n"); break;
        case 6: printf("6 >> alti\n"); break;
        case 7: printf("7 >> yedi\n"); break;
        case 8: printf("8 >> sekiz\n"); break;
        case 9: printf("9 >> dokuz\n"); break;
        default: printf("hatali deger girdiniz\n");
    }
    return 0;
    exit(0);
}
