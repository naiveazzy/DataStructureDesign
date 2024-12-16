
#include <stdio.h>
#include <stdlib.h>
#include "../headers/ALGraph.h"

int main() {

    VexType vexs[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
    ArcInfo arcs[12] = {    {'A', 'B'}, {'A', 'D'}, 
                            {'B', 'A'}, {'B', 'C'}, {'B', 'E'},
                            {'C', 'B'}, {'C', 'D'}, {'C', 'E'},
                            {'D', 'A'}, {'D', 'C'},

                            {'F', 'B'}, {'F', 'C'}
                        };

    int num_vexs = 6;
    int num_arcs = 12;

    ALGraph G;
    createDG(G, vexs, num_vexs, arcs, num_arcs);

    DEBUG_printDG(G);

    return 0;
}