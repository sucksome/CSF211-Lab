#include <stdio.h>
#include <stdlib.h>

struct Student{
    char email[38];
    char branch[4];
    char id[14];
};

typedef struct Student Student;

char *genId(Student *stud){
    char *id = stud->id;
    char *email = stud->email;
    char *branch = stud->branch;
    id[0] = '2';
    id[1] = '0';
    id[2] = email[3];
    id[3] = email[4];
    id[4] = 'A';
    if(branch[0]=='C'){
        id[5] = '7';
    }
    else{
        if(branch[1] == 'C'){
            id[5] = 'A';
        }
        else
            id[5] = '3';
    }
    id[6] = 'P';
    id[7] = 'S';
    for(int i = 8; i < 12; i++){
        id[i] = email[i-3];
    }
    id[12] = 'H';
    id[13] = '\0';
    return id;
}

int main(){
    Student stud;
    scanf("%s",stud.email);
    scanf("%s",stud.branch);
    printf("%s\n",genId(&stud));
    return 0;
}
