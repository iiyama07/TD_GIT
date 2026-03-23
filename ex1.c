#include "ex1.h"


void fonction(int i)
{
    printf("Bonjour\n");
    i = 5;
}

void fonction2(int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i == 2)
        {
            return;
        }
        fonction(0);
    }
}

int fonction3(char tab[])
{
    int i = 0;
    while (tab[i] != '\0')
    {
        i++;
    }
    return i;
}