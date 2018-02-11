#include<iostream>
#include<ctime>
using namespace std;
main(){
	int n,k;
	clock_t start,finish;
	cin>>n>>k;
	float a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	start=clock();
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j]<a[j+1]){
				float temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	finish=clock();
	cout<<a[k-1]<<" "<<finish-start;
}
