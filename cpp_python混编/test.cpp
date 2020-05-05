#include<iostream>
using namespace std;  // 命名空间

           // 比如在C＋＋中调用C库函数，就需要在C＋＋程序中用extern “C”声明要引用的函数。
           // 这是给链接器用的，告诉链接器在链接的时候用C函数规范来链接。
extern "C" // extern修饰符可用于指示C或者C＋＋函数的调用规范。
{
   

//addOne.c
//这个程序将输入数组的每个元素值+1
//输入参数：数组a，及a的元素个数n
 unsigned char * addOne(unsigned char *a,int n)
{
    for(int i=0;i<n;i++)
    {
        a[i]++;
    }
return a;
}

long  hello()                       // 定义一个 hello的方法
{
    long sum=0;
    int i=0;
    string name="wj";
    cout<<name<<endl;
    for(;i<100000;i++){sum+=i;}
    return sum;
}

}
