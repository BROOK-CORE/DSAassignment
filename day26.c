#include <stdio.h>
#include <stdlib.h>

// Doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Create node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Insert at end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    // If list is empty
    if (head == NULL)
        return newNode;

    struct Node* temp = head;

    // Traverse to last node
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Traverse forward
void printForward(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Main
int main() {
    int n, x;
    struct Node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insertEnd(head, x);
    }

    printForward(head);

    return 0;
}