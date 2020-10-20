
/** 因为动态链接库使用c语言构建的，因此引入libs/add.h的时候需要extern c**/
#ifdef __cplusplus
extern "C"
{
#endif
#include "libs/add.h"
#ifdef __cplusplus
}
#endif

#include<stdio.h>

int main(int argc,char * argv[]){
	
	for (int i=0;i<4;i++){
	printf("%s",argv[i]);
	}
	printf("%d",add(5,78));
	printf("%s","hello world");
	
	return 0;
	
}