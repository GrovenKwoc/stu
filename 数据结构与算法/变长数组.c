#include<cstdio>
#include<iostream>
#include<ctime>
using namespace std;
main(){
	int n,k;
	cin>>n>>k;
	float a[k];
	float comp;
	clock_t start,finish;
	
	for(int i=0;i<k;i++){
		cin>>a[i];
	}

	start=clock();
	for(int i=0;i<k-1;i++){
		for(int j=0;j<k-i-1;j++){
			if(a[j]<a[j+1]){
				float temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}

	for(int i=k;i<n;i++){
		cin>>comp;
		if(comp>a[k-1]){
			for(int j=0;j<k;j++){
				if(a[j]<comp){
					for(int d=k-1;d>j;d--){
						a[d]=a[d-1];					
					}
				a[j]=comp;
				break;
				}
			}
		}
	}
	finish=clock();
	cout<<a[k-1]<<" "<<finish-start;
	

	
}
