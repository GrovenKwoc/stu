#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	char bombs[n][m],count[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>bombs[i][j];
			count[i][j]='0';
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(bombs[i][j]=='*'){
				count[i][j]='*';
				//三个格子被影响				
				if(i==0&&j==0){//左上角
					if(bombs[i+1][j]=='?')count[i+1][j]++;
					if(bombs[i][j+1]=='?')count[i][j+1]++;
					if(bombs[i+1][j+1]=='?')count[i+1][j+1]++;
					continue;
				}

				if(i==0&&j==m-1){//右上角
					if(bombs[i+1][j]=='?')count[i+1][j]++;
					if(bombs[i][j-1]=='?')count[i][j-1]++;
					if(bombs[i+1][j-1]=='?')count[i+1][j-1]++;
					continue;
				}

				if(i==n-1&&j==0){//左下角
					if(bombs[i-1][j]=='?')count[i-1][j]++;
					if(bombs[i][j+1]=='?')count[i][j+1]++;
					if(bombs[i-1][j+1]=='?')count[i-1][j+1]++;
					continue;
				}

				if(i==n-1&&j==m-1){//右下角
					if(bombs[i-1][j]=='?')count[i-1][j]++;
					if(bombs[i][j-1]=='?')count[i][j-1]++;
					if(bombs[i-1][j-1]=='?')count[i-1][j-1]++;
					continue;
				}
				//五个格子被影响
				if(i==0){
					if(bombs[i][j-1]=='?')count[i][j-1]++;
					if(bombs[i+1][j-1]=='?')count[i+1][j-1]++;
					if(bombs[i+1][j]=='?')count[i+1][j]++;
					if(bombs[i+1][j+1]=='?')count[i+1][j+1]++;
					if(bombs[i][j+1]=='?')count[i][j+1]++;
					continue;
				}
				
				if(j==0){
					if(bombs[i-1][j]=='?')count[i-1][j]++;
					if(bombs[i-1][j+1]=='?')count[i-1][j+1]++;
					if(bombs[i][j+1]=='?')count[i][j+1]++;
					if(bombs[i+1][j+1]=='?')count[i+1][j+1]++;
					if(bombs[i+1][j]=='?')count[i+1][j]++;
					continue;
				}

				if(i==n-1){
					if(bombs[i][j-1]=='?')count[i][j-1]++;
					if(bombs[i-1][j-1]=='?')count[i-1][j-1]++;
					if(bombs[i-1][j]=='?')count[i-1][j]++;
					if(bombs[i-1][j+1]=='?')count[i-1][j+1]++;
					if(bombs[i][j+1]=='?')count[i][j+1]++;
					continue;
				}
				if(j==m-1){
					if(bombs[i-1][j]=='?')count[i-1][j]++;
					if(bombs[i-1][j-1]=='?')count[i-1][j-1]++;
					if(bombs[i][j-1]=='?')count[i][j-1]++;
					if(bombs[i+1][j-1]=='?')count[i+1][j-1]++;
					if(bombs[i+1][j]=='?')count[i+1][j]++;
					continue;
				}
				//八个格子被影响
				if(bombs[i][j-1]=='?')count[i][j-1]++;
				if(bombs[i+1][j-1]=='?')count[i+1][j-1]++;
				if(bombs[i+1][j]=='?')count[i+1][j]++;	
				if(bombs[i+1][j+1]=='?')count[i+1][j+1]++;
				if(bombs[i][j+1]=='?')count[i][j+1]++;
				if(bombs[i-1][j+1]=='?')count[i-1][j+1]++;
				if(bombs[i-1][j]=='?')count[i-1][j]++;
				if(bombs[i-1][j-1]=='?')count[i-1][j-1]++;
			}
		}
		
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<count[i][j];
		}
		cout<<endl;
	}
	return 0;
}
