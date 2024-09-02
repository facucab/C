#include <stdio.h>
#include <stdlib.h>
#define TAM 5
int main()
{
    int vec [TAM] = {2,4,6,8,10};

    int pos = 0;
    int * pr = vec;
    int e = 5;
    while( *pr  <= e )
    {
        pr++;
        pos++;
    }

    int *pr_final = vec+ TAM - 1;

    for(int i = TAM; i>pos; i--)
    {
        *pr_final = * (pr_final -1);
        pr_final--;
    }

    vec[pos] = e;

    for(int x = 0; x<TAM; x++)
    {
        printf("\n%d", vec[x]);
    }

}
