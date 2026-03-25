#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

struct Node* rotateRight(struct Node* head, int k, int n) {
    if (head == NULL || head->next == NULL || k == 0) {
        return head;
    }

    k = k % n;
    if (k == 0) {
        return head;
    }

    struct Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    tail->next = head;

    int steps = n - k;
    struct Node* temp = head;

    for (int i = 1; i < steps; i++) {
        temp = temp->next;
    }

    head = temp->next;
    temp->next = NULL;

    return head;
}

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" ");
        }
        temp = temp->next;
    }
}

int main() {
    int n, k, value;
    struct Node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    scanf("%d", &k);

    head = rotateRight(head, k, n);
    display(head);

    return 0;
}