#include<iostream>
#include<cstring>
using namespace std;

void Func(){
	static int n;
	cout<<n<<endl;
	n++;
}
int main(){
	Func();
	Func();
	Func();
	return 0;
}
