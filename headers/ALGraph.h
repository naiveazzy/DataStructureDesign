
#define TRUE 1
#define FALSE 0

typedef int Status;

typedef char VexType;

typedef struct ArcInfo {
    VexType v, w;
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
    int n, e;
    int *tags;
} ALGraph;