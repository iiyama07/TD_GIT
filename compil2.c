#include <stdio.h>

int main() {
    int x = 42;
    printf("%d\n", x);
    return 0;
}

 /* initialization makes integer from pointer without a cast [-Wint-conversion]
     int x = "42";
             ^~~~
Il faut enlever les guillemets pour initialiser x avec une valeur entière. */
 