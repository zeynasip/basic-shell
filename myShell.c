#include<stdlib.h>
#include<stdio.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>

void girdiAyir(char *grd, char **dizi){
    int i = 0, sayac = 0;
    const char *ayrac = " ";
    char *kelime;
    kelime = strtok(grd, ayrac);
    while(kelime != NULL){
        dizi[i] = kelime;
        i++;
        sayac++;
        kelime = strtok(NULL, ayrac);
    } 
}

void komutAyir(char **dizi, char **dizi1, char **dizi2){
    int i;
    for(i = 0; i < 3; i++){
        dizi1[i] = (char*)malloc(10 * sizeof(char));
        dizi2[i] = (char*)malloc(10 * sizeof(char));
    }
    if(strcmp(dizi[2], '&') == 0){
        strcpy(dizi1[0], dizi[0]);
        strcpy(dizi1[1], dizi[1]);
        strcpy(dizi2[0], dizi[3]);
        strcpy(dizi2[1], dizi[4]); 
        komutCalistir(dizi1);
        komutCalistir(dizi2);   
    }
    else if(strcmp(dizi[3], '&') == 0){
        strcpy(dizi1[0], dizi[0]);
        strcpy(dizi1[1], dizi[1]);
        strcpy(dizi1[2], dizi[2]);
        strcpy(dizi2[0], dizi[4]);
        strcpy(dizi2[1], dizi[5]);
        strcpy(dizi2[2], dizi[6]);
        komutCalistir(dizi1);
        komutCalistir(dizi2);
    }
    else{
        komutCalistir(dizi);
    }
}

void komutCalistir(char *dizi[]){
    int i;
    char *argumanlar[3];
    int fv;
    if(strcmp(dizi[0], "rakam") == 0){
        argumanlar[0] = (char*)malloc(5 * sizeof(char));
        strcpy(argumanlar[0], dizi[1]);
        argumanlar[1] = NULL;
        argumanlar[2] = NULL;
        fv = fork();
        if(fv == 0){
            i = execv("rakam", argumanlar);
        }
    }
    else if(strcmp(dizi[0], "div") == 0){
        argumanlar[0] = (char*)malloc(5 * sizeof(char));
        argumanlar[1] = (char*)malloc(5 * sizeof(char));
        strcpy(argumanlar[0], dizi[1]);
        strcpy(argumanlar[1], dizi[2]);
        argumanlar[2] = NULL;
        int fv = fork();
        if(fv == 0){      
            i = execv("div", argumanlar);        
        }
        else
            wait(&i);
    }
    else if(strcmp(dizi[0], "mul") == 0){
        argumanlar[0] = (char*)malloc(5 * sizeof(char));
        argumanlar[1] = (char*)malloc(5 * sizeof(char));
        strcpy(argumanlar[0], dizi[1]);
        strcpy(argumanlar[1], dizi[2]);
        argumanlar[2] = NULL;
        fv = fork();
        if(fv == 0){
            i = execv("mul", argumanlar);
        }    
        else
            wait(&i);
    }
    else if(strcmp(dizi[0], "cat") == 0){
        printf("cat : %s\n", dizi[1]);
    }
    else if(strcmp(dizi[0], "clear") == 0){
        system("clear");
    }
    else if(strcmp(dizi[0], "exit") == 0){
        exit(0);
    }
    else
        printf("yanlis bir komut girdiniz\n");
}

int main(){
    while(1){
        char girdi[50];
        char *kelimeler[10];
        char *dizi1[4], *dizi2[4];
        int fv;
        printf("myShell >> ");
        gets(girdi);
        girdiAyir(girdi, kelimeler);
        //komutAyir(kelimeler, dizi1, dizi2);
        komutCalistir(kelimeler);
    }
    return 0;
}

