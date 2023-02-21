#include <stdio.h>

int isValid(int n, int k, int A[n]){
    int r, eq = 0, greater = 0, less = 0;
    for (int i = 0; i < n; i++){
        if(A[i]==k)
            eq++;
        else if (A[i]>k)
            greater++;
        else
            less++;
    }
    int withdrawn;
    int atmost = eq + less;
    if (greater == k && atmost == n-k)
        return 1;
    else if (greater > k)
        return 2;
    else if (eq + greater < k)
        return -1;
    else{
        for (withdrawn = 0; withdrawn <= eq; withdrawn++){
            if(greater + withdrawn == k && atmost - withdrawn == n-k)
                return 1;
        }
        if ( eq + greater > k)
            return 2;
    }
}

int binS(int n, int A[n]){
    int l = 0, r = n, mid, score = -1;
    while(l < r){
        if(r - l == 1){
            if(isValid(n,r,A)==1)
                score = r;
            else if (isValid(n,l,A)==1)
                score = l;
            break;
        }
        mid = (l+r)/2;
        int check = isValid(n,mid,A);
        if(check == 2){
            l = mid;
        }
        else if (check == -1){
            r = mid;
        }
        else if (check == 1){
            score = mid;
            break;
        }
    }
    return score;
}

int main(){
    int n;
    scanf("%d",&n);
    int A[n];
    for (int i = 0; i < n; i++){
        scanf("%d",&A[i]);
    }
    int score = binS(n,A);
    if (score == -1){
        printf("No Score possible\n");
        return 0;
    }
    printf("%d\n",score);
    return 0;
}
