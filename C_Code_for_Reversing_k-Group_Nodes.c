#include <stdio.h>
#include <stdlib.h>

// Definition of linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to reverse k nodes
struct Node* reverseKGroup(struct Node* head, int k) {
    struct Node* curr = head;
    struct Node* prev = NULL;
    struct Node* next = NULL;
    int count = 0;

    // Count k nodes
    struct Node* temp = head;
    for (int i = 0; i < k; i++) {
        if (temp == NULL)
            return head;  // Not enough nodes, return as is
        temp = temp->next;
    }

    // Reverse k nodes
    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // Recursively process the next part of the list
    if (next != NULL) {
        head->next = reverseKGroup(next, k);
    }

    return prev; // New head after reversing
}

// Function to insert a node at the end of the linked list
void insertNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int k = 3;

    // Creating a linked list: 1->2->3->4->5->6->7->8->9
    for (int i = 1; i <= 9; i++)
        insertNode(&head, i);

    printf("Original List:\n");
    printList(head);

    head = reverseKGroup(head, k);

    printf("Reversed in k-groups:\n");
    printList(head);

    return 0;
}
