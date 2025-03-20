#include <stdio.h>
#include <stdlib.h>

// Definition of linked list node
struct Node {
    int data;
    struct Node* next;
};

// Global head pointer
struct Node* head = NULL;

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to print the linked list
void printList() {
    struct Node* temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to rearrange the linked list
void rearrangeOddEven() {
    if (head == NULL || head->next == NULL) return; // No need to rearrange if 0 or 1 node

    struct Node* odd = head;         // Points to first node (odd index)
    struct Node* even = odd->next;   // Points to second node (even index)
    struct Node* evenHead = even;    // Stores the starting point of even list

    while (even && even->next) {
        odd->next = even->next; // Link odd nodes
        odd = odd->next;

        even->next = odd->next; // Link even nodes
        even = even->next;
    }

    odd->next = evenHead; // Connect odd list to even list
}

// Function to insert a node at the end of the linked list
void insertNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Driver code
int main() {
    // Creating linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    for (int i = 1; i <= 6; i++)
        insertNode(i);

    printf("Original List:\n");
    printList();

    rearrangeOddEven();

    printf("Rearranged List (Odd-Indexed Nodes First, Then Even-Indexed):\n");
    printList();

    return 0;
}
