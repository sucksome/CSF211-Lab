#include <stdio.h>
#include <stdlib.h>

struct node{
  struct node *prev;
  int val;
  struct node *next;
};

typedef struct node node;

node *createNode(int v){
  node *new = malloc(sizeof(node));
  if(new!=NULL){
    new->prev = NULL;
    new->val = v;
    new->next = NULL;
    return new;
  }
}

node *addToList(node *head, int val) {
    node *newNode = createNode(val);
    if (head == NULL) {
        return newNode;
    }
    node *cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = newNode;
    newNode->prev = cur;
    return newNode;
}

node *readList( int n ) {
    node *head = NULL;
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

int main(){
  int n,k;
  scanf("%d %d",&n,&k);
  node *head = readList(n);
  node *tail = head;
  while(tail->next!=NULL){
    tail = tail->next;
  }
  for(int i = 0; i < k ; i++){
    node *h = head;
    node *t = tail;
    tail = tail->prev;
    tail->next = NULL;
    head->prev = t;
    head = t;
    head->prev = NULL;
    head->next = h;
  }
  node *temp = head;
  for(int i = 0; i < n; i++){
    printf("%d ",temp->val);
    temp = temp->next;
  }
  printf("\n");
  return 0;
}
