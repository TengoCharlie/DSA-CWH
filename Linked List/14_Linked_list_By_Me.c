#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Linked list traversal function
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("element %d\n", ptr->data);
        ptr = ptr->next;
    }

    printf("The End\n");
}

// Linked List insertion function
struct Node *linkedListInsertion(struct Node *ptr, int data)
{
    struct Node *new;
    new = (struct Node *)malloc(sizeof(struct Node));

    new->data = data;
    new->next = ptr->next;
    ptr->next = new;

    return new;
}
// Linked List deletion function
void linkedListDelete(struct Node *ptrToDelete, struct Node *ptrJustBefore)
{
    ptrJustBefore->next = ptrToDelete->next;
    free(ptrToDelete);
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Linked first and Second nodes
    head->data = 7;
    head->next = second;

    // Linked second and third nodes
    second->data = 54;
    second->next = third;

    // Linked third and fourth nodes
    third->data = 87;
    third->next = fourth;

    // Linked fourth nodes and terminate node
    fourth->data = 57;
    fourth->next = NULL;

    linkedListTraversal(head);
    struct Node *new = linkedListInsertion(second, 100);
    linkedListDelete(third, new);
    linkedListTraversal(head);

    return 0;
}