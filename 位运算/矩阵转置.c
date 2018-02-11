#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	int mat[n][m],mat1[m][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>mat[i][j];
		}
	}

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			mat1[i][j]=mat[j][i];
			cout<<mat1[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
