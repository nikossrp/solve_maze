#include<stdio.h>
#include<stdlib.h>
#include "Stack.h"

void InitializeStack(Stack* S) 
{
    S->ItemList = NULL;
}

int Empty(Stack* S)
{
    return S->ItemList == NULL;
}

int Full(Stack* S) 
{
    return 0;
}

void Push(Stack* S, ItemType X, ItemType Y)
{
    StackNode* Temp;
    Temp = (StackNode* )malloc(sizeof(StackNode));

    if(Temp == NULL) printf("Den exoume xwro");
    else{
        Temp->Link = S->ItemList;
        Temp->Item1 = X;
        Temp->Item2 = Y;
        S->ItemList = Temp;
    }
}

void Pop(Stack* S, ItemType* X, ItemType* Y)
{
    StackNode* Temp;

    if(S->ItemList == NULL) printf("H stoiva einai kenh den uparxei stoixeio na bgaleis");
    else{
        Temp =S->ItemList;
        *X = Temp->Item1;
        *Y = Temp->Item2;
        S->ItemList = Temp->Link;
        free(Temp);
    }
}
