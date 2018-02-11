#include<iostream>
#include<cstring>
#include<cmath>
#include<memory.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	if(n<0||n>10000)return 1;

	int ans[36000]={0};
	int residual=0;
	bool show=false;
	ans[35999]=1;
	if(n==0){
		cout<<ans[35999];
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=35999;j>=0;j--){
			if(residual==0&&ans[j]==0)continue;	
			if(ans[j]==0){
				ans[j]=residual%10;
				residual/=10;
				continue;
			}
			if(ans[j]!=0){
				residual+=ans[j]*i;
				ans[j]=residual%10;
				residual/=10;
			}
					
		}
	}

	for(int i=0;i<36000;i++){
		if(ans[i]!=0)show=true;
		if(show)cout<<ans[i];
	}
        return 0;
}
