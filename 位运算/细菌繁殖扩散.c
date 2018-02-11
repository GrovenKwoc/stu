#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
	int m,n;
	cin>>m>>n;
	
	int bac[11][11];
	int share[11][11];
	for(int i=0;i<11;i++){
		for(int j=0;j<11;j++){
			bac[i][j]=0;
			share[i][j]=0;
		}
	}
	bac[5][5]=m;

	for(int d=1;d<=n;d++){
		for(int i=1;i<=9;i++){
			for(int j=1;j<=9;j++){
				share[i][j]=bac[i][j];
				bac[i][j]*=2;
				
			}
		}
	
		for(int i=1;i<=9;i++){
			for(int j=1;j<=9;j++){
				if(bac[i][j]!=0){
					bac[i-1][j-1]+=share[i][j];
					bac[i][j-1]+=share[i][j];
					bac[i+1][j-1]+=share[i][j];
					bac[i+1][j]+=share[i][j];
					bac[i+1][j+1]+=share[i][j];
					bac[i][j+1]+=share[i][j];
					bac[i-1][j+1]+=share[i][j];
					bac[i-1][j]+=share[i][j];
				}
			}
		}	
	}

	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			cout<<bac[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
