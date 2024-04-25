#include <stdio.h>
#define v 4

int factorial(int n) {
  int fact = 1;
  for (int i = 1; i <= n; i++) {
    fact = fact * i;
  }
  return fact;
}
int null_graph(int mat[v][v]) {
  int flag = 0;
  for (int i = 0; i < v; i++) {
    for (int j = i; j < v; j++) {
      if (mat[i][j] == 0) {
        flag = 1;
      }
    }
  }
  if (flag == 1)
    return 1;
  return 0;
}

int trivial_graph(int mat[v][v]) {
  if (v == 1)
    return 1;
  return 0;
}

int simple_graph(int mat[v][v]) {
  int flag = 0;
  for (int i = 0; i < v; i++) {
    if (mat[i][i] == 1) {
      flag = 1;
      break;
    }
  }
  if (flag == 1)
    return 1;
  return 0;
}

int regular_graph(int mat[v][v]) {
  int c1 = 0, c2 = 0, flag = 0;

  for (int i = 0; i < v; i++) {
    c1 = 0;

    for (int j = 0; j < v; j++) {
      if (mat[i][j] == 1) {
        c1++;
      }
    }
    c2 = c1;
    if (c1 != c2) {
      flag = 1;
      break;
    }
  }
  if (flag == 1)
    return 1; // not a regular graph
  return 0;
}

int complete_graph(int mat[v][v]) {
  int c = 0;
  for (int i = 0; i < v; i++) {
    for (int j = 0; j < v; j++) {
      if (mat[i][j] == 1) {
        c++;
      }
    }
  }
  int nc2 = 0;
  nc2 = factorial(v) / (2 * factorial(v - 2));
  if (c == nc2)
    return 1; // a complete graph
  return 0;
}

main() {

  int mat[v][v];

  for (int i = 0; i < v; i++) {
    for (int j = 0; j < v; j++) {
      mat[i][j] = 0;
    }
  }
  for (int i = 0; i < v; i++) {
    for (int j = i; j < v; j++) {

      printf("Does vertex %d have an edge to vertex %d? (Enter 1 for yes, 0 "
             "for no): ",
             i, j);
      int edge;
      scanf("%d", &edge);
      mat[i][j] = edge;
      mat[j][i] = edge;
    }
  }

  printf("Adjacency Matrix : \n");
  for (int i = 0; i < v; i++) {
    for (int j = 0; j < v; j++) {
      printf("%d ", mat[i][j]);
    }
    printf("\n");
  }
  int ch;
  printf("1. Null Graph");
  printf("\n2. Trivial graph");
  printf("\n3. Simple Graph");
  printf("\n4. Regular Graph");
  printf("\n5. Complete Graph");
  printf("\n6. Exit");
  printf("\nEnter choice : ");
  scanf("%d", &ch);

  int result;
  switch (ch) {
  case 1:
    result = null_graph(mat);
    if (result == 1) {
      printf("\nA Null graph");
    } else {
      printf("\nNot a Null graph");
    }
    break;
  case 2:
    result = trivial_graph(mat);
    if (result == 1) {
      printf("\nA trivial graph");
    } else {
      printf("\nNot a trivial graph");
    }
    break;
  case 3:
    result = simple_graph(mat);
    if (result == 1) {
      printf("\nA simple graph");
    } else {
      printf("\nNot a simple graph");
    }
    break;
  case 4:
    result = regular_graph(mat);
    if (result == 1) {
      printf("\nNot a regular graph");
    } else {
      printf("\nRegular graph");
    }
    break;
  case 5:
    result = complete_graph(mat);
    if (result == 1) {
      printf("\n a complete graph");
    } else {
      printf("\nnot a Complete graph");
    }
    break;
  case 6:
    return 0;
    break;
  }
}