
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

Node *removeRepeatedNodes(Node *head){
    Node *temp = head;
    int f = 0, i = 0;
    while(temp->next!=NULL || f==1){
        if(temp->next!=NULL && temp->data == temp->next->data){
            Node *a = temp->next->next;
            free(temp->next);
            temp->next = a;
            f = 1;
        }
        else if (f == 1){
            if(temp == head){
                head = temp->next;
                f = 0;
                continue;
            }
            Node *temp2 = head;
            while(temp2->next!=temp){
                temp2 = temp2->next;
            }
            Node *b = temp->next;
            free(temp2->next);
            temp2->next = b;
            temp = temp2;
            i--;
            f = 0;
        }
        else{
            temp = temp->next;
            i++;
        }
    }
    return head;
}

int main(void) {
    Node *head = readList();
    Node *newList = removeRepeatedNodes(head);
    printList(newList);
    //freeList(head);
    freeList(newList);
    return 0;
}
