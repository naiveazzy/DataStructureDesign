
#include <stdio.h>
#include <stdlib.h>
#include "PreDefines.h"


#define NOTFOUND -1

#define UNVISITED 0
#define VISITED 1

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
int FirstAdjVex(ALGraph G, int k, AdjVexNodeP& p);
int NextAdjVex(ALGraph G, int k, AdjVexNodeP& p);
Status createDG(ALGraph& G, VexType* vexs, int num_node, ArcInfo* arcs, int num_arcs);
Status DEBUG_printDG(ALGraph& G);
