#include <stdlib.h>
#include <stdio.h>
#define e(a) a + 65
main()
{
    int v, e;
    printf("Enter no. of vertices : ");
    scanf("%d", &v);

    printf("Enter no. of edges : ");
    scanf("%d", &e);

    int mat[v][e];
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < e; j++)
        {
            mat[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int a = 0, b = 0;
        printf("\n For edge %c : ", e(i));
        scanf("%d %d", &a, &b);
        mat[a - 1][i] = 1;
        mat[b - 1][i] = -1;
    }
    printf("Incidence Matrix : \n");
    printf("\t");
    for (int i = 0; i < e; i++)
    {
        printf("e%d  ", i);
    }
    printf("\n");
    for (int i = 0; i < v; i++)
    {

        printf("v%d  \t", i + 1);
        for (int j = 0; j < e; j++)
        {
            printf("%d   ", mat[i][j]);
        }
        printf("\n");
    }
}