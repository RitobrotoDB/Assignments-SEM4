#include <stdio.h>
#define v 4

main() {

  int mat[v][v];


  for (int i = 0; i < v; i++) {
    for (int j = 0; j < v; j++) {
      mat[i][j] = 0;
    }
  }
  for (int i = 0; i < v; i++) {
    for (int j = 0; j < v; j++) {
        if(i!=j){
      printf("Does vertex %d have an edge to vertex %d? (Enter 1 for yes, 0 "
             "for no): ",
             i, j);
      int edge;
      scanf("%d", &edge);
      mat[i][j] = edge;
    }
    }
  }
    printf("D0 : \n");
  for (int i = 0; i < v; i++) {
    for (int j = 0; j < v; j++) {
      printf("%d ", mat[i][j]);
    }
    printf("\n");
  }
  

    int i,j,k;
  for(k=0;k<v;k++)
  {
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            
            mat[i][j]=mat[i][j] || (mat[i][k] && mat[k][j]);
        }
    }
      printf("Adjacency Matrix : \n");
  for (i = 0; i < v; i++) {
    for (j = 0; j < v; j++) {
      printf("%d ", mat[i][j]);
    }
    printf("\n");
  }
  }
}