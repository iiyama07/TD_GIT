#include <stdio.h>

int main() {
    int a;
    int b = 10;
    printf("%d\n", b);
    return 0;
}
/*
error: 'b' undeclared (first use in this function)
     b = 10;
     ^
Il faut déclarer la variable 'b' avant de l'utiliser. Donc mettre un int car b est un entier.
*/