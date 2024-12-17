
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../headers/ALGraph.h"
#include "../headers/Stack.h"

int main() 
{
    SqStack S;

    AutoInitStack_Sq(S);

    srand(time(NULL));

    for (int i = 0; i < 10; i++) 
    {
        if (Push_Sq(S, i) == ERROR) printf("ERROR!\n");
    }

    PrintStack_Sq(S);

    int cache;
    for (int i = 0; i < 5; i++)
    {
        Pop_Sq(S, cache);
    }

    PrintStack_Sq(S);

    return 0;
}