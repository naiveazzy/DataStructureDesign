#include "../headers/ALGraph.h"


/*  
    @name:          LocateVex
    @description:   返回图G中v对应的节点的序号
    @param          G：邻接表表示的图
    @param          v：需要查找的节点v
    @return: 
*/
int LocateVex(ALGraph G, VexType v) {
    for (int i = 0; i < G.num_vexs; i++) 
        if (G.vexs[i].data == v) 
            return i;

    return NOTFOUND;
}

/*  
    @name:          createDG
    @description:   创建一个邻接表表示的有向无权图
    @param          G：邻接表表示的有向图
    @param          vexs：图的顶点数组
    @param          num_node：顶点数
    @param          arcs：图的边数组
    @param          num_arcs：边数
    @return:        若初始化成功，返回 SUCCESS ，否则返回 ERROR
 */
Status createDG(ALGraph& G, VexType* vexs, int num_node, ArcInfo* arcs, int num_arcs) {


    // 写入顶点数和边数
    G.num_vexs = num_node;
    G.num_arcs = num_arcs;

    G.vexs = (VexNode*)malloc(sizeof(VexNode) * num_node);
    G.tags = (int*)malloc(sizeof(int) * num_node);

    // 初始化顶点数组、标示数组
    for (int i = 0; i < G.num_vexs; i++) {
        G.vexs[i].data = vexs[i];
        G.vexs[i].firstArc = NULL;
        G.tags[i] = UNVISITED;
    }

    // 建立邻接链表
    for (int i = 0; i < G.num_arcs; i++) {

        // 读出边(head, tail)
        VexType head = arcs[i].head;
        VexType tail = arcs[i].tail;

        // 返回 head 和 tail 在图中对应的序号
        int seq_head = LocateVex(G, head);
        int seq_tail = LocateVex(G, tail);

        if (seq_head < 0 || seq_tail < 0) 
            return ERROR;

        AdjVexNodeP nodep = (AdjVexNodeP)malloc(sizeof(AdjVexNode));
        if (nodep == NULL)
            return ERROR;
        
        // 将nodep节点插入至head节点的邻接链表后
        nodep->adjvex = seq_tail;
        nodep->next = G.vexs[seq_head].firstArc;
        G.vexs[seq_head].firstArc = nodep;
    }

    return SUCCESS;

}

/*  
    @name:          DEBUG_printDG
    @description:   以邻接表的形式输出图G
    @param          G：邻接表表示的有向图
    @return:        若成功输出，返回 SUCCESS ，否则返回 ERROR
 */
Status DEBUG_printDG(ALGraph& G) {
    
    // 若图不合法，返回错误
    if (G.vexs == NULL || G.num_vexs < 0 || G.num_arcs < 0)
        return ERROR;
    
    printf("Node  Arcs--------\n");

    // 输出邻接表
    for (int i = 0; i < G.num_vexs; i++) {
        
        printf(" %c ", G.vexs[i].data);

        AdjVexNodeP nodep = G.vexs[i].firstArc;
        while (nodep != NULL) {
            printf("-->");
            printf(" %c ", G.vexs[nodep->adjvex].data);
            nodep = nodep->next;
        }

        printf(" ^ \n");
    }

    return SUCCESS;

}
