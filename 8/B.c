#include <stdio.h>
#include <string.h>

void createPal(char *inp, char *ret, int size){
	strncpy(ret,inp,size/2 );

	int mid =  size/2 -1, ii = mid+1;
	if (size % 2){
		ii = size/2 +1;
		ret[size/2] = inp[size/2];
	}
	for (int i = mid; i >= 0; i--){
		ret[ii] = inp[i];
		ii++;
	}
}

int allN(int size, char *input){
	for (int i = 0; i < size; i++){
		if (input[i] != '9')
			return 0;
	}
	return 1;
}

void nextPal(int size, char *input){
	if (allN(size,input)){
		printf("%d",1);
		for (int i = 0; i < size-1; i++)
			printf("%d",0);
		printf("%d\n",1);
		return;
	}

	char ret[size+1];
	ret[size] = '\0';

	createPal(input,ret,size);
	int mid = (size % 2)? size/2: size/2 -1;
	
	if (strcmp(ret,input) <= 0){
		if (input[mid] == '9'){
			int i = mid;
			while (input[i] == '9'){
				input[i] = '0';
				i--;
			}
			input[i]++;
			createPal(input,ret,size);
		}
		else{
			ret[mid]++;
			if (size % 2 == 0)
				ret[mid+1] = ret[mid];
		}
	}
	
	printf("%s\n",ret);
}

int main(){
	int size;
	scanf("%d",&size);
	getchar();

	char input[size+1];
	for (int i = 0; i < size; i++)
		scanf("%c",input+i);
	input[size] = '\0';

	if (size)
		nextPal(size,input);
	return 0;
}
