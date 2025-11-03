#include <stdio.h>

int main() {
    char s[25] = "Hello";
    printf("%s\n", s);
    return 0;
}
/*
 initializer-string for array of chars is too long
     char s[3] = "Hello";
                 ^~~~~~~
Il faut augmenter la taille du tableau s pour qu'il puisse contenir la chaîne "Hello" et le caractère nul de fin de chaîne.
*/