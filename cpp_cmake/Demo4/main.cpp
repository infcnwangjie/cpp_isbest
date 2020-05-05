#include<iostream>
#include <vector>
#include <string>
using namespace std;

//使用wxWidgets编写程序  方向就这么定了
class CException
{
public:
    string msg;
    CException(string s) : msg(s) {}
};
double Devide(double x, double y)
{
    if (y == 0)
        throw CException("devided by zero");
    cout << "in Devide" << endl;
    return x / y;
}
int CountTax(int salary)
{
    try {
        if (salary < 0)
            throw - 1;
        cout << "counting tax" << endl;
    }
    catch (int) {
        cout << "salary < 0" << endl;
    }
    cout << "tax counted" << endl;
    return salary * 0.15;
}

int main(int argc,char * argv[]){
	
	vector<int> a(10,1);
	
	a.push_back(10);
	
	vector<int> b(a.begin(),a.begin()+5);
	
	cout<<"总量为"<<a.size()<<endl;
	
	for(vector<int>::iterator it =a.begin();it<a.end();it++){
		
		cout<<*it<<endl;
	}
	
	for(vector<int>::iterator it1 =b.begin();it1<b.end();it1++){
		
		cout<<*it1<<endl;
	}
	
	
	double f = 1.2;
    try {
        CountTax(-1);
        f = Devide(3, 0);
        cout << "end of try block" << endl;
    }
    catch (CException e) {
        cout << e.msg << endl;
    }
    cout << "f = " << f << endl;
    cout << "finished" << endl;
	
	
	return 0;
	
}