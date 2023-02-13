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

node *readList() {
    int n;
    scanf("%d", &n);
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

int check(node *head, node *tail, int target){
  node *l = head;
  node *r = tail;
  while(l!=r){
    int cou = l->val+r->val;
    if(cou == target){
      return 1;
    }
    else if (cou < target){
      l = l->next;
    }
    else if (cou > target){
      r = r->prev;
    }
  }
  return 0;
}

int main(){
  int target;
  scanf("%d",&target);
  node *head = readList();
  node *tail = head;
  while(tail->next!=NULL){
    tail = tail->next;
  }
  printf("%d\n",check(head,tail,target));
  return 0;
}
