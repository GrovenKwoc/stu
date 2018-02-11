#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<memory.h>
using namespace std;
int main()
{	
	double length=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		length+=log10(i);
	
	}
	printf("%d!需要%d个长度的数组来存储",n,(int)ceil(length));
        return 0;
}
