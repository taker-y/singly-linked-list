#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "file_reader.h"

int list_import(node_t **list, char *path)
{
    FILE *fp;
    node_t *head;
    char read_string[20];
    
    fp = open_file(path);
    *list = NULL;

    if (fgets(read_string, 20, fp) == NULL) {
        printf("can't read file\n");
        return -1;
    } else {
        head = malloc(sizeof(node_t));
        *list = head;

        head->next = NULL;
        head->data = strtol(read_string, NULL, 10);

        while (fgets(read_string, 20, fp) != NULL) {
            head->next = malloc(sizeof(node_t));
            head = head->next;

            head->next = NULL;
            head->data = strtol(read_string, NULL, 10);
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
