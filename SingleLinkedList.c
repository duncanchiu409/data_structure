#include <stdio.h>
#include <stdlib.h>

typedef struct List{
    struct List* next;
    int i;
} List;

List* search_list(List* node, int item) {
    if(!node){
        return NULL;
    }

    if(node->i == item){
        return node;
    }
    
    return search_list(node->next, item);
}

void insert_list(List** node, int item){
    List* tmp = malloc(sizeof(List));
    tmp->i = item;
    if(node != NULL){
        tmp->next = *node;
    }
    else{
        tmp->next = NULL;
    }
    *node = tmp;
}

List* predecessor_list(List* node, int item){
    if(!node || !node->next){
        printf("Error: item not found in the List");
        return NULL;
    }

    if(node->next->i == item){
        return node;
    }

    return predecessor_list(node->next, item);
}

void delete_list(List** node, int item){
    List* pred;
    List* p = search_list(*node, item);

    if(p){
        pred = predecessor_list(*node, item);
        if(pred){
            pred->next = p->next;   
        }
        else{
            *node = p->next;
        }
        free(p);
    }
}

void print_list(List* node){
    List* p = node;
    printf("List: ");
    while(p != NULL){
        printf("%d ", p->i);
        p = p->next;
    }
    printf("\n");
}

int main (int argv, char** args){
    List* root = NULL;
    insert_list(&root, 1);

    delete_list(&root, 1);

    print_list(root);

    return 0;
}
