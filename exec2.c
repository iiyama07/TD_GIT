#include <stdio.h>

int main() {
    int tab[10];
    
    for (int i = 0; i < 11; i++) {
        tab[i] = i;  
    }
    for (int i = 0; i < 11; i++) {
        printf("%d\n",tab[i]);  
    }
    printf("fait\n");
    return 0;
}
/*
Pour afficher correctement les valeurs de 1 à 10, il faut déclarer le tableau tab avec une taille de 10 au lieu de 5.
Il faut également modifier les boucles for pour qu'elles itèrent de 0 à 9 (soit 10 itérations) au lieu de 0 à 10 (soit 11 itérations), car les indices des tableaux en C commencent à 0.
*/