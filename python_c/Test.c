#include<stdio.h>

int basicTest(int a, float b, char * pChar)
{
    printf("a=%d\n", a);
    printf("b=%f\n", b);
    printf("%s\n", pChar);
    return 100;
}

 char* strTest(char* pVal){
	return pVal;
}

float floatTest(float * a){
return *a;
}

int szTest(int a[], int nLen){	
	return a[nLen-1]+5;
}


typedef struct Student{
	int id;
	char * name;
	int age;
	float weight;
}Student;

Student * whoheavy(Student *a,Student *b){
	
	if(a->weight>b->weight)
		return a;
	else{
		return b;
	}
}


int test_numpy(float * a){
	int datatotal=0;
	while(*(a++)!=0){
		datatotal+=1;
	}
	return datatotal;
}