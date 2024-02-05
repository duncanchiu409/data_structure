#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 1000

typedef struct{
    int y;
    int weight;
    struct EdgeNode* next;
} EdgeNode;

typedef struct{
    EdgeNode* edgeNodes[SIZE + 1];
    int degree[SIZE + 1];
    int nvertices;
    int nedges;
    bool directed;
} Graph;

Graph* root;

void initialise_graph(Graph* g, bool directed){
    g->nvertices = 0;
    g->nedges = 0;
    g->directed = directed;

    for(int i = 0; i <= SIZE; i++){
        g->degree[i] = 0;
        g->edgeNodes[i] = NULL;
    }
}

void read_graph(Graph* g, bool directed){
    int m;
    int x; 
    int y; 

    initialise_graph(g, directed);

    scanf("%d %d", &(g->nvertices), &m);
    for(int i = 1; i <= m; i++){
        scanf("%d %d", &x, &y);
        insert_edge(g, x, y, directed);
    }
}

void insert_edge(Graph* g, int x, int y, bool directed){
    EdgeNode* p = malloc(sizeof(EdgeNode));
    p->y = y;
    p->weight = 0;
    p->next = g->edgeNodes[x];
    g->edgeNodes[x] = p;

    g->degree[x]++;

    if(directed == false){
        insert_edge(g, y , x, true);
    }
    else{
        g->nedges++;
    }
}

void print_graph(Graph* g){
    for(int i = 1; i <= SIZE; i++){
        if(g->edgeNodes[i]!=NULL){
            printf("Vertix %d : ", i);
            EdgeNode* tmp = g->edgeNodes[i];
            while(tmp != NULL){
                printf("%d ", tmp->y);
                tmp = tmp->next;
            }
            printf("\n");
        }
    }
}

int main (int argc, char** args){
    root = malloc(sizeof(Graph));
    read_graph(root, false);
    print_graph(root);

    return 0;
}