
#include <iostream>
#include <exception>

using namespace std;
//g++ -o test learn_thread.cpp -std=c++11
class MyException:public
exception
{
 public:
 //noexcept表明不会再抛出异常
 const char* what()const noexcept
 {
 return "MyException";
 }
};

float fun(int a,int b) {
	
	if(b==0)
	throw MyException();
	return a/b;
}
 
int main (int argc, char* argv []) {
	try{
	float a=fun(5,0);
	cout<<a<<endl;
	}
	
	catch(MyException e){
		cout<<e.what()<<endl;
	}
	return 0;

}