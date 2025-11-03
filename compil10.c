#include <stdio.h>

int main() {
    int abc1 = 5;
    printf("%d\n", abc1);
    return 0;
}
/*
error: invalid suffix "abc" on integer constant
     int 1abc = 5;
         ^~~~
error: expected identifier or '(' before numeric constant
error: invalid suffix "abc" on integer constant
     printf("%d\n", 1abc);
                    ^~~~
Il faut renommer la variable pour qu'elle commence par une lettre ou un underscore, par exemple en "abc1".
*/