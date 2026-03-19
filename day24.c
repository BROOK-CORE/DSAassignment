#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Delete first occurrence of key
struct Node* deleteKey(struct Node* head, int key) {
    if (head == NULL)
        return head;

    // If head needs to be deleted
    if (head->data == key) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* curr = head;
    struct Node* prev = NULL;

    while (curr != NULL && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    // If key found
    if (curr != NULL) {
        prev->next = curr->next;
        free(curr);
    }

    return head;
}

// Print list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Main
int main() {
    int n, key, x;
    struct Node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insertEnd(head, x);
    }

    scanf("%d", &key);

    head = deleteKey(head, key);

    printList(head);

    return 0;
}