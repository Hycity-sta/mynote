#include <stdlib.h>
#include <stdio.h>

//邻接矩阵的实现
typedef char VertexType;
typedef int EdgeType;
#define MAXVEX 100
#define INFINITY 65535
typedef struct {
    VertexType vexs[MAXVEX];
    EdgeType arc[MAXVEX][MAXVEX];
    int numVertexes, numEdges;
}MGragh;

void CreateMGraph(MGragh * G) {
    int i,j,k,w;
    printf("输入顶点数和边数:\n");
    scanf("%d,%d",&G->numVertexes, &G->numEdges);
    for (i=0;i<G->numVertexes;i++) {
        scanf("%c",&G->vexs[i]);
    }
    for (i=0;i<G->numVertexes;i++) {
        for (j=0;j<G->numVertexes;j++)
            G->arc[i][j] = INFINITY;
    }
    for (k=0;k<G->numEdges;k++) {
        printf("输入变(vi,vj)上的下标i, 下标j和权w: \n");
        scanf("%d,%d,%d",&i,&j,&w);
        G->arc[i][j] = w;
        G->arc[j][i] = G->arc[i][j];
    }
}
