#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "pathfinder.h"

int main() {
    Graph *graph = loadGraph("terrain.txt");
    while (1) {  
        int start;
        int end;
        
        printf("start and end\n");
        scanf("%d %d", &start, &end);
        if (start < 0 || start >= graph->numNodes || end < 0 || end >= graph->numNodes) {
            printf("error.\n");
            continue;
        }
        
        int *path = findPath(graph, start, end);

        int pathSize = 0;
        int NodesV = 0;
        double EdgeW = 0;
        printf("Path: ");
        for (int i = 0; path[i] != -1; i++) {
            printf(" %d -", path[i]);
            NodesV += graph->nodes[path[i]].v;
            if (i > 0) {
                for (int j = 0; j < graph->numEdges; j++) {
                    if (graph->edges[j].startN == path[i - 1] && graph->edges[j].endN == path[i]) {
                        EdgeW += graph->edges[j].weight;
                        break;
                    }
                }
            }
            pathSize++;
        }
        printf("\n%d %.2lf %d\n", pathSize - 1, EdgeW, NodesV);
        free(path);
    }
    
    freeG(graph);
    return 0;
} 