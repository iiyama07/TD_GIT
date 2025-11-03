#include <stdio.h>

int main() {
    int t[3] = {10, 20, 30};
    int i = 0;
    printf("%d\n", t[i]); 
    return 0;
}
/*
Le problème dans ce code est que l'indice 'i' est initialisé à -1 ce qui est en dehors des limites valides du tableau 't'.
 Pour corriger ce code, il faut initialiser 'i' avec une valeur valide, par exemple 'int i = 0;' pour accéder au premier élément du tableau.
*/