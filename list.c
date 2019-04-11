#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "file_reader.h"

int list_import(node_t **list, char *path)
{
    FILE *fp;
    node_t *root;
    node_t *head;
    char read_string[20];
    
    fp = open_file(path);

    if (fgets(read_string, 20, fp) == NULL) {
        printf("can't read file\n");
        return -1;
    } else {
        root = malloc(sizeof(node_t));
        root->data = strtol(read_string, NULL, 10);
        head = root;
        *list = root;

        while (fgets(read_string, 20, fp) != NULL) {
            head->next = malloc(sizeof(node_t));
            head = head->next;

            head->data = strtol(read_string, NULL, 10);
        }
    }

    fclose(fp);

    return 0;
}
