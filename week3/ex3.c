#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node* next;
}node_t;


void insert_node(node_t *head, int data){
    node_t* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    node_t * temp = (node_t *) malloc(sizeof(node_t));
    temp->data = data;
    temp->next = NULL;
    current->next = temp;

}

int delete_node(node_t * head, int n) {
    int i = 0;
    int retval = -1;
    node_t * current = head;
    node_t * temp_node = NULL;

    if(n==0){
        temp_node = head->next;
        free(&head);
        head=temp_node;
    }

    for (i = 0; i < n-1; i++) {
        if (current->next == NULL) {
            return -1;
        }
        current = current->next;
    }

    temp_node = current->next;
    retval = temp_node->data;
    current->next = temp_node->next;
    free(temp_node);

    return retval;

}

void print_list(node_t* head) {
    node_t * current = head;

    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int main()
{
    node_t *head = (node_t *) malloc(sizeof(node_t));
    if (head == NULL) {
        return 1;
    }

    head->data = 0;
    head->next = NULL;
    insert_node(head, 2);
    insert_node(head, 2);
    delete_node(head,1);
    print_list(head);


  return 0;
}
