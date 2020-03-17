#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"
#include "Stack.h"

char maze[6][6];
int x;  //x, y start position
int y;

void get_maze(char* file_name); //get start point and maze
void path(char M[6][6]);

int main()
{
    int i, j;
    get_maze("maze.txt");

    printf("%d, %d\n", x, y);

    for(i = 0; i < 6; i++) {
        for(j = 0; j < 6; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
    path(maze);
    return 0;
}


void get_maze(char* file_name)
{
    char c;
    char row_s[3] = {'\0'};
    char cols[3] = {'\0'};
    int rows_i = 0;
    int cols_i = 0;
    int swap = 0;
    int i;
    int j;

    FILE* file = fopen( file_name, "r");    //"r": open a file for read

    if(file) {
        while((c = getc(file)) != EOF) {
            if(c == '\n') {
                break;
            } else if(c == ',') {
                swap = 1;
            } else if(!swap) {
                row_s[rows_i] = c;
                rows_i++;
            } else {
                cols[cols_i] = c;
                cols_i++;
            }
        }
    }
    x = atoi(row_s);
    y = atoi(cols);

    for(i = 0; i < 6; i++) { // ftiaxnw ton labirintho
        for(j = 0; j < 6; j++) {
            c = getc(file);     
           
            if(c == '\n') {
                c = getc(file);
            }

            maze[i][j] = c;
        }
    }

    fclose(file);
}

void path(char M[6][6])
{
    int i = x , j = y;  
    Stack S;
    InitializeStack(&S);
    NodeType* L = NULL;
    Push(&S, i, j);     //arxiki thesh
   
    while(1) {
  //   printf("Eimai sto : %d %d\n", i, j);
      Pop(&S, &i, &j);
      M[i][j] = '+';
      InsertNewLastNode(i, j, &L);

     if(M[i+1][j] == 'G' || M[i-1][j] == 'G' || M[i][j+1] == 'G' || M[i][j-1] == 'G') {  //'G' is the goal

      if(M[i+1][j] == 'G') 
        InsertNewLastNode(i+1, j, &L);
      

      if(M[i][j+1] == 'G') 
        InsertNewLastNode(i, j+1, &L);
      

      if(M[i-1][j] == 'G') 
        InsertNewLastNode(i-1, j, &L);

      if(M[i][j-1] == 'G')
        InsertNewLastNode(i-1, j, &L);

   //   printf("I found the goal\n");
      break;
      }  


     if(M[i+1][j] == '.' || M[i+1][j] == 'G') //katw
      Push(&S, i+1, j);

     if(M[i][j+1] == '.' )  //dexia
      Push(&S, i, j+1);

     if(M[i][j-1] == '.' ) //aristera
      Push(&S, i, j-1);  

     if(M[i-1][j] == '.' ) //panw
      Push(&S, i-1, j);



     while(M[i+1][j] != '.' &&  M[i][j+1] != '.' && M[i][j-1] != '.' && M[i-1][j] != '.') //an uparxei adiexodo opisthodromise
     {
        if(M[i][j-1] == '+' && M[i][j+1] != '.' && M[i+1][j] != '.' && M[i-1][j] != '.') {
         M[i][j] = 'x';
         DeleteLastNode(&L);
         j--;
        }

        if(M[i+1][j] == '+' && M[i][j+1] != '.' && M[i][j-1] != '.' && M[i-1][j] != '.') {
          M[i][j] = 'x';
          DeleteLastNode(&L);
          i++;
        }


        if(M[i-1][j] == '+' && M[i][j+1] != '.' && M[i][j-1] != '.' && M[i+1][j] != '.') {
          M[i][j] = 'x';
          DeleteLastNode(&L);
          i--;
        }
        
        if(M[i][j+1] == '+' && M[i+1][j] != '.' && M[i][j-1] != '.' && M[i-1][j] != '.') {
          M[i][j] = 'x';
          DeleteLastNode(&L);
          j++;
        }
      }
    }

   
    for(i = 0; i < 6; i++)  //the new array
    {
      for(j = 0; j < 6; j++)
      {
        printf("%c\t",M[i][j] );
      }
      printf("\n");
    }
  PrintList(L);
}

