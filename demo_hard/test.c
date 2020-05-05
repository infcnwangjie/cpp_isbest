
#include<stdio.h>
#include "add.h"

int main(int argc,char * argv[]){
	
	for (int i=0;i<4;i++){
	printf("%s",argv[i]);
	}
	printf("%d",add(5,78));
	printf("%s","hello world");
	
	return 0;
	
}