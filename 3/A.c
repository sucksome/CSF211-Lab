#include <stdio.h>
#include <stdlib.h>

struct song{
  struct song *prev;
  int id;
  struct song *next;
};

typedef struct song song;

song *addSong(song *head, int s){
  if(head == NULL){
    head = malloc(sizeof(song));
    head->prev = NULL;
    head->next = NULL;
    head->id = s;
    return head;
  }
  song *temp = head;
  while(temp->next!=NULL){
    temp = temp->next;
  }
  temp->next = malloc(sizeof(song));
  temp->next->prev = temp;
  temp->next->next = NULL;
  temp->next->id = s;
  return head;
}

song *curr(song *head, int *i){
  song *temp = head;
  for(int j = 0; j <(*i)-1 ; j++){
    temp = temp->next;
  }
  return temp;
}

void playNext(song *head,int *i){
  song *cur = curr(head,i);
  if(cur->next != NULL){
    (*i)++;
  }
}

void playPrev(song *head, int *i){
  song *cur = curr(head,i);
  if(cur != head){
    (*i)--;
  }
}

int main(){
  int n;
  scanf("%d",&n);
  song *head = NULL;
  for(int k = 0; k < n; k++){
    int x;
    scanf("%d",&x);
    if (head == NULL){
      head = addSong(head,x);
    }
    else
      addSong(head,x);
  }
  int i = 1;
  while(1){
    int choice;
    scanf("%d",&choice);
    if(choice == 1){
      int new;
      scanf("%d",&new);
      addSong(head,new);
    }
    else if (choice == 2){
      printf("%d\n",curr(head,&i)->id);
    }
    else if (choice == 3){
      playNext(head,&i);
    }
    else if (choice == 4){
      playPrev(head,&i);
    }
    else if (choice == 5){
      return 0;
    }
  }
}
