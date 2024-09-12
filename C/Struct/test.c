#include <stdio.h>
#include "SqList.h"

int main()
{
    SqList L = InitSqList();
    L.insert(&L, 0, 100);
    printf("%d\n", L.at(&L, 0));
    L.erase(&L, 0);
    printf("%d\n", L.at(&L, 0));
    L.insert(&L, 0, 100);
    L.revise(&L, 0, 10);
    printf("%d\n", L.at(&L, 0));
}