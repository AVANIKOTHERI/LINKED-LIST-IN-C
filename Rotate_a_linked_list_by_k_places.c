#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
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
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to rotate the linked list by k places
struct Node* rotateLinkedList(struct Node* head, int k) {
    if (!head || k == 0)
        return head;

    // Compute the length of the linked list
    struct Node* temp = head;
    int length = 1;
    while (temp->next) {
        temp = temp->next;
        length++;
    }

    // If k is greater than length, take modulo
    k = k % length;
    if (k == 0)
        return head;

    // Traverse to the (length - k)th node
    temp->next = head;  // Make it circular temporarily
    struct Node* newTail = head;
    for (int i = 1; i < length - k; i++)
        newTail = newTail->next;

    // Update head and break the loop
    struct Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

// Driver code to test the function
int main() {
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    printf("Original List:\n");
    printList(head);

    int k = 2;
    head = rotateLinkedList(head, k);

    printf("Rotated List by %d places:\n", k);
    printList(head);

    return 0;
}
