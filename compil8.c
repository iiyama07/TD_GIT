#include <stdio.h>

int main() {
    int x = 10;
    printf("x = %d\n", x);
    return 0;
}
/* 
error: 'y' undeclared (first use in this function)
     printf("x = %d\n", y);
                        ^
Il faudraist remplacer 'y' par 'x' dans le printf pour corriger l'erreur.
*/
