#include "ListType.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void InsertNewLastNode(int R, int C, NodeType **L)
{
      NodeType *N, *P;

      N=(NodeType *)malloc(sizeof(NodeType));
      N->row = R;
      N->column = C;    
      N->Link=NULL;

      if (*L == NULL) {
         *L=N;
      } else {
         P=*L;
         while (P->Link != NULL) P=P->Link;
         P->Link=N;
      }

}



void PrintList(NodeType *L)
{
      NodeType *N;

      printf("Path: \n");
      N=L;
      while(N != NULL) {
         printf("(%d,%d)", N->row, N->column);
         N=N->Link;
         if (N!=NULL) printf("->");
      }
      printf("\n");
}


void DeleteLastNode(NodeType **L)
{
      NodeType *PreviousNode, *CurrentNode;

      if (*L != NULL) {
         if ((*L)->Link == NULL){
            free(*L);
            *L=NULL;
         } else {
            PreviousNode=*L;
            CurrentNode=(*L)->Link;
            while (CurrentNode->Link != NULL){
               PreviousNode=CurrentNode;
               CurrentNode=CurrentNode->Link;
            }
            PreviousNode->Link=NULL;
            free(CurrentNode);
         }
      }
}


void Delete_Select_List(int R, int C, NodeType **L)
{
      NodeType *N;
      NodeType* Temp;

      N=*L;
      while (N != NULL){   //briskei ton kombo
        if (N->row == R && N->column == C){
           break;
        } else {
           N=N->Link;
        }
      }
      Temp = N->Link;
      N->Link = NULL;
      while(Temp != NULL){
         DeleteLastNode(&Temp);
      }

     
}