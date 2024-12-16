
#include <stdio.h>
#include <stdlib.h>


#define TRUE 1
#define FALSE 0
#define SUCCESS 1
#define ERROR -1

#define NOTFOUND -1

#define UNVISITED 0
#define VISITED 1

typedef int Status;

typedef char VexType;

typedef struct ArcInfo {
    VexType head, tail;
} ArcInfo;

typedef struct AdjVexNode {
    int adjvex;
    struct AdjVexNode* next;
} AdjVexNode, *AdjVexNodeP;

typedef struct VexNode {
    VexType data;
    struct AdjVexNode* firstArc;
} VexNode;

typedef struct ALGraph {
    VexNode* vexs;
    int num_vexs;
    int num_arcs;
    int *tags;
} ALGraph;



int LocateVex(ALGraph G, VexType v);
Status createDG(ALGraph& G, VexType* vexs, int num_node, ArcInfo* arcs, int num_arcs);
Status DEBUG_printDG(ALGraph& G);
