#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// delete the first node
struct Node *deleteAtFirst(struct Node *head) //big O of 1
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    printf("Delete at first\n");
    return head;
}

// node delete in between at some index
struct Node *deleteAtIndex(struct Node *head, int index) //big O of n
{
    int i = 0;
    if (index == 0)
    {
        struct Node *ptr = head->next;
        free(head);
        return ptr;
    }
    struct Node *ptr = head;
    while (i < index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    struct Node *q = ptr->next;
    ptr->next = q->next;
    free(q);
    return head;
}

// Delete at the END
struct Node *deleteAtEnd(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *p;
    while (ptr->next != NULL)
    {
        p = ptr;
        ptr = ptr->next;
    }
    p->next = NULL;
    free(ptr);
}

// Delete a node with given value
struct Node *deleteByFirstValue(struct Node *head, int value)
{

    struct Node *ptr = head;
    struct Node *p;
    if (head->data == value)
    {
        if (head->next == NULL)
        {
            free(head);
            return 0;
        }
        p->next = head->next;
        free(head);
        return p->next;
    }
    while (ptr->data != value && ptr->next != NULL)
    {
        p = ptr;
        ptr = ptr->next;
    }
    if (ptr->next == NULL && ptr->data != value)
    {
        return head;
    }
    p->next = ptr->next;
    free(ptr);
    return head;

    // -------------------------------------------------------- CODE WITH HARRY

    // struct Node *p = head;
    // struct Node *q = head->next;
    // while (q->data != value && q->next != NULL)
    // {
    //     p = q->next;
    //     q = q->next;
    // }

    // if (q->data == value)
    // {
    //     p->next = q->next;
    //     free(q);
    // }
    // return head;
}

// Delete a all node with given value  //ERROR code
struct Node *deleteByValue(struct Node *head, int value)
{
    //
}

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

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;

    // Allocate memory for nodes in the linked list
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));

    // Linked first and Second nodes
    head->data = 7;
    head->next = second;

    // Linked second and third nodes
    second->data = 67;
    second->next = third;

    // Linked third and fourth nodes
    third->data = 87;
    third->next = fourth;

    // Linked fourth nodes and terminate node
    fourth->data = 54;
    fourth->next = fifth;

    // Linked fifth nodes and terminate node
    fifth->data = 546;
    fifth->next = NULL;

    linkedListTraversal(head);
    printf("deleteAtIndex\n");
    head = deleteAtIndex(head, 0); //delete at Index
    linkedListTraversal(head);

    printf("deleteAtFirst\n");
    head = deleteAtFirst(head); //delete at First
    linkedListTraversal(head);

    printf("deleteAtEnd\n");
    deleteAtEnd(head); //delete at End
    linkedListTraversal(head);

    printf("deleteBy First Value\n");
    head = deleteByFirstValue(head, 7); //delete by value at node data
    linkedListTraversal(head);

    // printf("deleteByValue\n");
    // head = deleteByValue(head, 7); //delete by value at node data
    // linkedListTraversal(head);

    return 0;
}