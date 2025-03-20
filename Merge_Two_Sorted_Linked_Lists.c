#include <stdio.h>
#include <stdlib.h>

// Definition of a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to merge two sorted linked lists
struct Node* mergeSortedLists(struct Node* l1, struct Node* l2) {
    struct Node dummy;  // Dummy node to simplify merging
    struct Node* temp = &dummy;  // Pointer to track the last node
    dummy.next = NULL;  // Initialize dummy node's next to NULL

    // Merge both lists
    while (l1 && l2) {
        if (l1->data < l2->data) {
            temp->next = l1;
            l1 = l1->next;
        } else {
            temp->next = l2;
            l2 = l2->next;
        }
        temp = temp->next;  // Move temp to the last node
    }

    // Attach the remaining nodes from the non-empty list
    if (l1)
        temp->next = l1;
    else
        temp->next = l2;

    return dummy.next;  // Return merged list starting from dummy.next
}

// Driver code
int main() {
    // Creating first sorted linked list: 1 -> 3 -> 5
    struct Node* l1 = newNode(1);
    l1->next = newNode(3);
    l1->next->next = newNode(5);

    // Creating second sorted linked list: 2 -> 4 -> 6
    struct Node* l2 = newNode(2);
    l2->next = newNode(4);
    l2->next->next = newNode(6);

    printf("List 1: ");
    printList(l1);
    printf("List 2: ");
    printList(l2);

    // Merging both lists
    struct Node* mergedHead = mergeSortedLists(l1, l2);

    printf("Merged List: ");
    printList(mergedHead);

    return 0;
}
