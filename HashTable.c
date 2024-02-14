#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#define HASHGROUPS 10

enum INSERT_SIGNAL{
    DUPLICATE_KEYS,
    INSERT_SUCCESS
};

typedef struct HashNodes
{
    char* key;
    int value;
    struct HashNodes* next;
} HashNodes;


typedef struct HashTable{
    HashNodes* hashNodes[HASHGROUPS];
} HashTable;

HashTable* initHashTable(){
    HashTable* table=(HashTable*)malloc(sizeof(HashTable));
    for(int i=0;i<HASHGROUPS;i++){
        table->hashNodes[i]=NULL;
    }
    return table;
}

bool isEmpty(HashTable* table){
    for(int i=0;i<HASHGROUPS;i++){
        if(table->hashNodes[i]!=NULL){
            return false;
        }
    }
    return true;
}

int hashFunction(char* key){
    char c='a';
    int i=0;
    int count;
    while(c!='\0'){
        c=key[i];
        count+=(int)c;
        i++;
    }
    return count%HASHGROUPS;
}

enum INSERT_SIGNAL insertItem(HashTable* table, char* key, int value){
    int hashedKey=hashFunction(key);
    HashNodes* p=table->hashNodes[hashedKey];
    
    while(p!=NULL){
        if(strcmp(p->key,key)==0){
            return DUPLICATE_KEYS;
        }
        p=p->next;
    }
    
    HashNodes* tmp=(HashNodes*)malloc(sizeof(HashNodes));
    tmp->key=key;
    tmp->value=value;
    tmp->next=table->hashNodes[hashedKey];
    table->hashNodes[hashedKey]=tmp;
    return INSERT_SUCCESS;
}

void removeItem(HashTable* table, char* key){
    int hashedKey=hashFunction(key);
    HashNodes* p=table->hashNodes[hashedKey];
    HashNodes* prev=NULL;

    while(p!=NULL){
        if(strcmp(p->key,key)==0){
            break;
        }
        prev=p;
        p=p->next;
    }

    if(p==NULL){
        printf("[WARNING] key cannot be found.\n");
        return;
    }
    else if(prev==table->hashNodes[hashedKey]){
        table->hashNodes[hashedKey]=p;
        free(prev);
    }
    else{
        prev->next=p->next;
        free(p);
    }
}

int searchTable(HashTable* table, char* key){
    int hashedKey=hashFunction(key);
    HashNodes* p=table->hashNodes[hashedKey];

    while(p!=NULL){
        if(strcmp(p->key,key)==0){
            return p->value;
        }
        p=p->next;
    }

    return -1;
}

void printTable(HashTable* table){
    for(int i=0;i<HASHGROUPS;i++){
        printf("%d: ",i);
        HashNodes* p=table->hashNodes[i];
        while(p!=NULL){
            printf("%s -> %d",p->key,p->value);
            p=p->next;
        }
        printf("\n");
    }
}

int main(){
    HashTable* table=initHashTable();
    insertItem(table, "bar", 0);
    insertItem(table, "foo", 1);
    insertItem(table, "the", 2);

    printTable(table);
    return 0;
}