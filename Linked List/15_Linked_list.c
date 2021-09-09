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

// Linked List insertion function at begginning
struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    ptr->data = data;
    ptr->next = head;

    return ptr;
}

// Linked List insertion function at Index
struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
// Linked list insert at ends
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;

    return head;
}

// Linked List insertion function after the node
struct Node *insertAfterNode(struct Node *prevNode, int data)
{

    struct Node *new = (struct Node *)malloc(sizeof(struct Node));

    new->data = data;
    new->next = prevNode->next;
    prevNode->next = new;

    return new;
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
    head = insertAtFirst(head, 100);   //Insert at First
    head = insertAtIndex(head, 75, 2); //Insert at Index
    head = insertAtEnd(head, 70);      //Insert at End
    insertAfterNode(second, 500);      //Insert after Node
    linkedListTraversal(head);

    return 0;
}