#include <stdio.h>

int main() {
    int a = 10;
    int b = 20;
    printf("a=%d b=%d\n", a, b); 
    return 0;
}
/*
Le problème dans ce code est que dans l'instruction printf, seule la variable 'b' est passée en argument, alors que le format spécifie deux entiers (%d %d).
 Par conséquent, la valeur de 'a' n'est pas affichée correctement.
 Pour corriger ce code, il faut ajouter la variable 'a' comme deuxième argument dans l'appel à printf
 */