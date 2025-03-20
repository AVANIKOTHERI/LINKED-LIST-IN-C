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

// Function to sort linked list of 0s, 1s, and 2s in O(N) time and O(1) space
struct Node* sortLinkedList(struct Node* head) {
    if (!head || !head->next) return head; // Edge case: Empty list or single element

    // Dummy nodes for 0s, 1s, and 2s
    struct Node zeroDummy, oneDummy, twoDummy;
    struct Node *zeroTail = &zeroDummy, *oneTail = &oneDummy, *twoTail = &twoDummy;
    zeroDummy.next = oneDummy.next = twoDummy.next = NULL;

    // Traverse and distribute nodes into separate lists
    struct Node* temp = head;
    while (temp) {
        if (temp->data == 0) {
            zeroTail->next = temp;
            zeroTail = zeroTail->next;
        } else if (temp->data == 1) {
            oneTail->next = temp;
            oneTail = oneTail->next;
        } else {
            twoTail->next = temp;
            twoTail = twoTail->next;
        }
        temp = temp->next;
    }

    // Merge the three partitions
    zeroTail->next = (oneDummy.next) ? oneDummy.next : twoDummy.next;
    oneTail->next = twoDummy.next;
    twoTail->next = NULL; // End the final list

    return zeroDummy.next; // New head of sorted list
}

// Driver code
int main() {
    // Creating an unsorted linked list: 1 -> 2 -> 0 -> 2 -> 1 -> 0
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(0);
    head->next->next->next = newNode(2);
    head->next->next->next->next = newNode(1);
    head->next->next->next->next->next = newNode(0);

    printf("Original List:\n");
    printList(head);

    // Sort the linked list
    head = sortLinkedList(head);

    printf("Sorted List:\n");
    printList(head);

    return 0;
}
