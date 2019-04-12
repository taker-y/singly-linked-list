#ifndef LIST_H
#define LIST_H

typedef struct node{
    long data;
    struct node *next;
} node_t;

int list_import(node_t **list, char *path);
unsigned int get_num(node_t *list);
void print_list(node_t *list);
int insert_at(node_t **list, unsigned int th, long data);
int delete_at(node_t **list, unsigned int th);
void sort_list(node_t **list);

node_t *get_node_address(node_t *root, unsigned int num);

#endif
