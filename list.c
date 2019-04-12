#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "file_reader.h"

int list_import(node_t **list, char *path)
{
    FILE *fp;
    node_t *head;
    char read_string[20];
    long obtained_data;
    
    *list = NULL;

    fp = open_file(path);
    if (fp == NULL)
        return -1;

    if (fgets(read_string, 20, fp) == NULL) {
        printf("can't read file\n");
        return -1;
    } else {
        obtained_data = strtol(read_string, NULL, 10);
        head = create_new_node(obtained_data, NULL);
        *list = head;

        while (fgets(read_string, 20, fp) != NULL) {
            obtained_data = strtol(read_string, NULL, 10);
            head->next = create_new_node(obtained_data, NULL);
            head = head->next;
        }
    }

    fclose(fp);
    return 0;
}

unsigned int get_num(node_t *list)
{
    int node_cnt = 1;
    node_t *head = list;

    if (list == NULL) {
        return 0;
    } else {
        while (head->next != NULL) {
            head = head->next;
            node_cnt++;
        }
    }

    return node_cnt;
}

void print_list(node_t *list)
{
    int node_cnt = 1;
    node_t *head = list;

    if (list != NULL) {
        printf("%d: %ld\n", node_cnt, head->data);

        while (head->next != NULL) {
            head = head->next;
            node_cnt++;

            printf("%d: %ld\n", node_cnt, head->data);
        }
    }
}

int insert_at(node_t **list, unsigned int th, long data)
{
    unsigned int i;
    node_t *head = NULL;
    node_t *new_node = NULL;

    if (th <= 0) {
        new_node = create_new_node(data, *list);
        *list = new_node;

        return 0;
    } else {
        head = get_node_address(*list, th-1);
        if (head == NULL)
            return -1;
        else {
            new_node = create_new_node(data, head->next);
            head->next = new_node;
        }
    }

    return 0;
}

node_t *get_node_address(node_t *root, unsigned int num)
{
    unsigned int i;
    node_t *head = root;

    if (num <= 0) {
        return NULL;
    } else {
        for (i=num-1; i>0; i--) {
            if (head->next == NULL)
                return NULL;
            else
                head = head->next;
        }
    }

    return head;
}

node_t *create_new_node(long data, node_t *next)
{
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = next;

    return new_node;
}
