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
    for (int j = i; j < v; j++) {

      printf("Does vertex %d have an edge to vertex %d? (Enter cost for yes, 0 "
             "for no): ",
             i, j);
      int edge;
      scanf("%d", &edge);
      mat[i][j] = edge;
      mat[j][i] = edge;
    }
  }
}