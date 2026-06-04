#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for singly-linked list node
 struct ListNode{
    int val;
    struct ListNode *next;
};

// Function to merge two sorted linked lists
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    // Create a dummy node to act as the temporary head
    struct ListNode dummy;
    struct ListNode* current = &dummy;
    dummy.next = NULL;

    // Traverse both lists and attach the smaller value
    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    // Attach the remaining nodes of whichever list is left
    if (list1 != NULL) {
        current->next = list1;
    } else {
        current->next = list2;
    }

    return dummy.next;
}

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* current = head;

    while (current != NULL && current->next != NULL) {
        if (current->val == current->next->val) {
            struct ListNode* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }

    return head;
}   
// Helper function to create a node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Helper function to build a list from user input
struct ListNode* buildList(int count) {
    if (count <= 0) return NULL;

    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    int val;

    for (int i = 0; i < count; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &val);
        struct ListNode* newNode = createNode(val);
        
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// Helper function to print the linked list
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

// Helper function to free allocated memory
void freeList(struct ListNode* head) {
    struct ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

bool hasCycle(struct ListNode *head) {
    // If the list is empty or has only one node, no cycle is possible
    if (head == NULL || head->next == NULL) {
        return false;
    }
    
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    
    // Move fast by two steps and slow by one step
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        // If they meet, a cycle exists
        if (slow == fast) {
            return true;
        }
    }
    
    // If fast reaches the end, there is no cycle
    return false;
}

int main() {
    int count1, count2;

    // Get input for the first list
    printf("Enter the number of elements for List 1: ");
    scanf("%d", &count1);
    printf("Enter sorted elements for List 1:\n");
    struct ListNode* list1 = buildList(count1);

    // Get input for the second list
    printf("\nEnter the number of elements for List 2: ");
    scanf("%d", &count2);
    printf("Enter sorted elements for List 2:\n");
    struct ListNode* list2 = buildList(count2);

    // Merge the lists
    struct ListNode* mergedHead = mergeTwoLists(list1, list2);

    // Output result
    printf("\nMerged Sorted Linked List:\n");
    printList(mergedHead);

    // Remove duplicates from the merged list
    mergedHead = deleteDuplicates(mergedHead);
    printf("\nMerged Sorted Linked List after removing duplicates:\n");
    printList(mergedHead);
    
    struct ListNode* current = head;
    bool result = hasCycle(head);
    
    if (result) {
        printf("\nResult: true (The linked list HAS a cycle)\n");
    } else {
        printf("\nResult: false (The linked list does NOT have a cycle)\n");
    }
    // Clean up memory
    freeList(mergedHead);

    return 0;
}