#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main(int argc, char *argumanlar[]){
    
    int sayi1 = atoi(argumanlar[0]);
    int sayi2 = atoi(argumanlar[1]);    
    int carpim = sayi1 * sayi2;
    printf("%d * %d = %d\n", sayi1, sayi2, carpim);
    return 0;

}
