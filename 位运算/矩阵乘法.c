#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
	int n,m,k,temp;
	cin>>n>>m>>k;
	int mat1[n][m];
	int mat2[m][k];
	int mat3[n][k];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>mat1[i][j];
		}
	}

	for(int i=0;i<m;i++){
		for(int j=0;j<k;j++){
			cin>>mat2[i][j];
		}
	}
	temp=0;

	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			mat3[i][j]=0;
			while(temp<m){
				mat3[i][j]+=mat1[i][temp]*mat2[temp][j];
				temp++;
			}
			temp=0;
		}
		for(int j=0;j<k;j++){
			cout<<mat3[i][j]<<" ";
		}
		cout<<endl;
		
	}
	return 0;
}
