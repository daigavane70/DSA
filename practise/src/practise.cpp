#include<stdio.h>

char* binAddition(char* num1,char* num2){
	int carry=0;
	char result[8];

	for(int i=0;i<8;i++){
		if(num1[i]=='1' and num2[i]=='1'){
			if(carry==1){
				result[i]='1';
			}
			else{
				result[i]='0';
				carry=1;
			}
		}
		else{
			if(carry==1){
				result[i]='0';
			}
			else{
				result[i]='1';
				carry=0;
			}
		}
	}

	return result;
}

int main(){
	char num1[8],num2[8];

	char* result;

	printf("Enter Two 8 bit Binary Numbers -> \n");
	printf("Num 1: ");
	for(int i=0;i<8;i++)	scanf("%c",&num1[i]);
	printf("Num 2: ");
	for(int i=0;i<8;i++)	scanf("%c",&num2[i]);

	result=binAddition(num1,num2);

	printf("\n Result: ");
	for(int i=0;i<8;i++)	printf("%c",&result[i]);

}
