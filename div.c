#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    int bolunen = atoi(argv[0]);
    int bolen = atoi(argv[1]);    
    int bolum = bolunen / bolen;
    printf("%d / %d = %d\n", bolunen, bolen, bolum);
    return 0;
}
