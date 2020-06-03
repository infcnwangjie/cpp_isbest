
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
//g++ -o test learn_thread.cpp -std=c++11
volatile int val;
mutex mut;
 
void icrement (int a) {
	cout<<"传参"<<a<<endl;
	for (int i = 0; i < 100000000; i++) {
		mut.lock ();
		cout<<"num is "<<val++<<endl;
		
		mut.unlock ();
	}
}
 
int main (int argc, char* argv []) {
	//创建两个线程
	thread t1 (icrement,4);
	thread t2 (icrement,5);
	//等待两个线程执行完
	t1.join ();
	t2.join ();
	cout << val << endl;
	return 0;

}