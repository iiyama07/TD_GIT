#include <stdio.h>

int main() {
    char c = 'A';
    printf("c = %c\n", c);
    return 0;
}
/*
    expected '%s' directive argument is 'char *', but argument 2 has type 'int'
        printf("c = %s\n", c);
                        ^
    Il faut utiliser %c pour afficher un caractère au lieu de %s qui est utilisé pour les chaînes de caractères.
*/