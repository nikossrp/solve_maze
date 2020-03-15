#include<stdio.h>
#include <stdlib.h>
#include "List.h"
#include "Stack.h"
//To monopati to krataw se lista bazontas kathe fora sto telos ths listas to stoixeio



void path(char M[6][6]);   //sunarthsh gia na brhskei to monimo monopath


int main()
{
    
 char   Maze[6][6] = {
        {'S','#','#','#','#','#'},
        {'.','.','.','.','.','#'},
        {'#','.','#','#','#','#'},
        {'#','.','#','#','#','#'},
        {'.','.','.','#','.','G'},
        {'#','#','.','.','.','#'}
        };
    
    path(Maze);
}

void path(char M[6][6])
{
    int i = 0 , j = 0;
    Stack S;
    InitializeStack(&S);
    NodeType* L = NULL;
    Push(&S, i, j);
   
    while(1) {
   //   printf("Eimai sto : %d %d\n", i, j);
      Pop(&S, &i, &j);
      M[i][j] = '+';

    if(M[i+1][j] == 'G' || M[i-1][j] == 'G' || M[i][j+1] == 'G' || M[i][j-1] == 'G') {  //'G' is the goal
      printf("I found the goal\n");
      break;
      }    


     if(M[i+1][j] == '.') //katw
      Push(&S, i+1, j);

     if(M[i][j+1] == '.')  //dexia
      Push(&S, i, j+1);

     if(M[i][j-1] == '.') //aristera
      Push(&S, i, j-1);  

     if(M[i-1][j] == '.') //panw
      Push(&S, i-1, j);



     if(M[i+1][j] != '.' &&  M[i][j+1] != '.' && M[i][j-1] != '.' && M[i-1][j] != '.')
     {
        while(M[i][j-1] == '+' && M[i][j+1] != '.' && M[i+1][j] != '.' && M[i-1][j] != '.') {
         M[i][j] = 'x';
         j--;
        }

        while(M[i+1][j] == '+' && M[i][j+1] != '.' && M[i][j-1] != '.' && M[i-1][j] != '.') {
          M[i][j] = 'x';
          i++;
        }


        while(M[i-1][j] == '+' && M[i][j+1] != '.' && M[i][j-1] != '.' && M[i+1][j] != '.') {
          M[i][j] = 'x';
          i--;
        }
        
        while(M[i][j+1] == '+' && M[i+1][j] != '.' && M[i][j-1] != '.' && M[i-1][j] != '.') {
          M[i][j] = 'x';
          j++;
        }
      }

    }

    for(i = 0; i < 6; i++)
    {
      for(j = 0; j < 6; j++)
      {
        printf("%c\t",M[i][j] );
      }
      printf("\n");
    }
    PrintList(L);

}


