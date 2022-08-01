#ifndef LISTNODE_H
#define LISTNODE_H
#include<stdlib.h>

typedef struct list_node {
    char * function_name;
    struct listNode * next;
}list_node;

list_node * create_new_list_node(char * function_name)
{
    list_node * new_node=(list_node*)malloc(sizeof(list_node));
}

#endif // LISTNODE_H
