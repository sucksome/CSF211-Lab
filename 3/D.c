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
  int n;
  scanf("%d",&n);
  node *head = readList(n);
  node *tail = head;
  while(tail->next!=NULL){
    tail = tail->next;
  }
  node *l = head;
  node *r = tail;
  int lskill = l->val, rskill = r->val;
  int a = 0, b = 0;
  int ll = 1, rr = 1;
  while(ll+rr<=n){
    if(lskill == rskill){
      if(ll > a){
        a = ll;
      }
      if(rr > b){
        b = rr;
      }
      l = l->next;
      r = r->prev;
      ll++;
      rr++;
      lskill+=l->val;
      rskill+=r->val;
    }
    else if(lskill < rskill){
      l = l->next;
      ll++;
      lskill+=l->val;
    }
    else if (lskill > rskill){
      r = r->prev;
      rr++;
      rskill+=r->val;
    }
  }
  printf("%d %d\n",a,b);
  return 0;
}
