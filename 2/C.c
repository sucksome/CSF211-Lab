
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Node_t {
    int data;
    struct Node_t *next;
};

typedef struct Node_t Node;

// Creates a new node with given value and returns a pointer to it
Node *createNode(int value) {
    Node *newNode = malloc(sizeof(Node));
    assert(newNode != NULL);
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Creates a new node with given value and adds it to
// the back of the given singly linked list,
// returns a pointer to the newly created node
Node *addToList(Node *head, int val) {
    Node *newNode = createNode(val);
    if (head == NULL) {
        return newNode;
    }
    Node *cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = newNode;
    return newNode;
}

// Creates a singly linked list by reading input and
// returns a pointer the head of the newly created linked list

Node *readList() {
    int n;
    scanf("%d", &n);
    Node *head = NULL;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        if (head == NULL) {
            head = addToList(head, x);
        } else {
            addToList(head, x);
        }
    }
    return head;
}

// Prints the values stored in the nodes of the given singly linked list
void printList(Node *head) {
    Node *ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return;
}

// Frees the memory dynamically allocated to
// all the nodes of the given singly linked list
void freeList(Node *head) {
    Node *cur, *nxt;
    cur = head;
    while (cur != NULL) {
        nxt = cur->next;
        free(cur);
        cur = nxt;
    }
}


Node *mergeLists(Node *head1, Node *head2){
    Node *head = createNode(0);
    Node *temp1, *temp2;
    temp1 = head1;
    temp2 = head2;
    while(temp1!=NULL || temp2!=NULL){
        if(temp2==NULL || temp1!=NULL && temp1->data <= temp2->data){
            addToList(head,temp1->data);
            temp1 = temp1->next;
        }
        else if(temp1==NULL || temp2!=NULL && temp2->data < temp1->data){
            addToList(head,temp2->data);
            temp2 = temp2->next;
        }
    }
    Node *r = head->next;
    free(head);
    return r;
}

Node *sortList(Node *head){
    Node *temp = head;
    int i = 0;
    while(temp!=NULL){
        temp = temp->next;
        i++;
    }
    temp = head;
    if(i>1){
        for(int k = 0; k < i/2 -1; k++){
            temp = temp->next;
        }
        Node *l1, *l2;
        l2 = sortList(temp->next);
        temp->next = NULL;
        l1 = sortList(head);
        return mergeLists(l1,l2);
    }
    else if (i==1){
        return head;
    }
}



int main(void) {
    Node *head = readList();
    Node *sorted = sortList(head);
    printList(sorted);
    freeList(head);
    freeList(sorted);
    return 0;
}
