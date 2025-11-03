#include <stdio.h>

int main() {
    char s[5];
    s[0] = 'H';
    s[1] = 'e';
    s[2] = 'y';
    s[3] = '!';
    s[4] = '\0';
    printf("%s\n", s); 
    return 0;
}
/*
Le problème dans ce code est que le tableau de caractères 's' n'est pas correctement terminé par un caractère nul ('\0').
 Dans ce cas, le tableau 's' a une taille de 5, mais seuls les 4 premiers éléments sont utilisés pour stocker les caractères 'H', 'e', 'y', et '!'.
 Pour corriger le code il faut ajouter le caractère nul à la fin du tableau par exemple en ajoutant 's[4] = '\0';'
*/