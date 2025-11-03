#include <stdio.h>

int main() {
    char nom[50];
    printf("Nom ? ");
    scanf("%s", nom); 
    printf("Bonjour %s\n", nom);
    return 0;
}
/*
Le problème dans ce code est que le tableau de caractères 'nom' n'est pas suffisamment grand
 Si l'utilisateur saisit un nom plus long que 3 caractères, cela entraînera un dépassement
 Pour corriger le code il faut augmenter la taille du tableau 'nom' pour qu'il puisse contenir des noms plus longs
 */