//liked list insert and traversal
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int Data;
    struct Node *pointer;
};

struct Node *head; // Global head pointer

// insert the data at the beginning of the list
void insert(int data) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    if (newnode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newnode->Data = data;
    newnode->pointer = head;
    head = newnode;
}

//print the list
void printlist(){
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->Data);
        temp = temp->pointer;
    }
    printf("NULL\n");
}


void deleteNode(int key) {
    struct Node *temp = head;
    struct Node *prev = NULL;

    // Case 1: Empty list
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    // Case 2: Delete head
    if (temp->Data == key) {
        head = temp->pointer;   // move head
        free(temp);          // free memory
        return;
    }

 // Case 3: Search for node
    while (temp != NULL && temp->Data != key) {
        prev = temp;
        temp = temp->pointer;
    }

 // Case 4: Not found
    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }

    prev->pointer = temp->pointer;
    free(temp);
}
// Reverse the linked list
void reverse() {
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *Pointer = NULL;

    while (current != NULL) {
        printf("curr=%d\n", current->Data);
        Pointer = current->pointer;  // Store the next node
        current->pointer = prev;  // Reverse the link
        prev = current;           // Move prev to current node
        current = Pointer;           // Move to the next node
    }
    head = prev;
    void printlist();  // Update the head to the new first node
}
findMiddle(){
    struct Node *slow = head;
    struct Node *fast = head;
    while(fast != NULL && fast->pointer != NULL){
        printf("slow=%d fast=%d\n", slow->Data, fast->Data);
        slow = slow->pointer;
        fast = fast->pointer->pointer;
    }
}

int main() {
    head = NULL; // Initialize the head of the list
    int n;
    printf("Enter the number of elements to insert: \n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int data;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data); // Read the data to insert
        insert(data); // Insert the data into the linked list
    }
    printf("Linked List: ");
    printlist();
    printf("what kind of operation do you want to perform? (insert/delete/reverse/): (i/d/r) \n");
    char operation;
    scanf(" %c", &operation);
    if (operation == 'i') {
        int data;
        printf("Enter the element to insert: ");
        scanf("%d", &data);
        insert(data);
        printf("Linked List after insertion: ");
        printlist();
    } else if (operation == 'd') {
        int key;
        printf("Enter the element to delete: ");
        scanf("%d", &key);
        deleteNode(key);
        printf("Linked List after deletion: ");
        printlist();
    } else if (operation == 'r') {
        reverse();
        printf("Linked List after reversal: ");
        printlist();
    } else {
        printf("Invalid operation selected.\n");
    }

}
