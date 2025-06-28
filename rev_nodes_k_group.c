#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode* next;
};

// Helper function to create a new ListNode.
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Helper function to append a node to the end of the list.
void appendNode(struct ListNode** head_ref, int val) {
    struct ListNode* newNode = createNode(val);
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    struct ListNode* temp = *head_ref;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Helper function to print the linked list.
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d", head->val);
        if (head->next != NULL)
            printf("->");
        head = head->next;
    }
    printf("\n");
}

// Helper function to free the linked list.
void freeList(struct ListNode* head) {
    while (head != NULL) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

// Reverse the nodes from 'head' up to 'tail' (exclusive).
// Returns the new head of the reversed segment.
struct ListNode* reverse(struct ListNode* head, struct ListNode* tail) {
    struct ListNode* prev = tail;
    while (head != tail) {
        struct ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

// Reverse nodes in k-group.
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode* node = head;
    // Check if there are at least k nodes remaining.
    for (int i = 0; i < k; ++i) {
        if (!node)
            return head; // Less than k nodes remain; no reversal.
        node = node->next;
    }
    
    // Reverse first k nodes.
    struct ListNode* newHead = reverse(head, node);
    // Recursively call for the list starting from 'node' and attach.
    head->next = reverseKGroup(node, k);
    return newHead;
}

int main() {
    // Create a linked list from an array.
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2; // Change k here as needed

    struct ListNode* head = NULL;
    for (int i = 0; i < n; i++) {
        appendNode(&head, arr[i]);
    }
    
    printf("Original list :\n");
    printList(head);
    
    // Reverse nodes in k-group.
    head = reverseKGroup(head, k);
    
    printf("List after reversing in groups of %d :\n", k);
    printList(head);
    
    // Free the allocated memory.
    freeList(head);
    
    return 0;
}
