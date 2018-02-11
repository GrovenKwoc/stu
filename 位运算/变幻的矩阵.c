#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
	int n;
	cin>>n;
	bool flag=true;
	char pic_ori[n][n],pic_ref[n][n],pic_change[n][n];
	//读入原矩阵	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>pic_ori[i][j];
		}
	}
	//读入参照矩阵
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>pic_ref[i][j];
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(pic_ori[i][j]!=pic_ref[i][j]){
				flag=false;				
				break;
			}
		}
		if(!flag)break;
	}

	if(flag){
		cout<<"4";
		return 0;
	}

	flag=true;
	//将原矩阵顺时针方向旋转90度
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			pic_change[i][j]=pic_ori[j][i];
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n/2;j++){
			int temp=pic_change[i][j];
			pic_change[i][j]=pic_change[i][n-j-1];
			pic_change[i][n-j-1]=temp;
		}
	}

	//判断是否为变幻1
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(pic_change[i][j]!=pic_ref[i][j]){
				flag=false;				
				break;
			}
		}
		if(!flag)break;
	}

	if(flag){
		cout<<"1";
		return 0;		
	}
	
	flag=true;

	//将原矩阵逆时针方向旋转90度
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			pic_change[i][j]=pic_ori[j][i];
		}
	}
	for(int j=0;j<n;j++){
		for(int i=0;i<n/2;i++){
			int temp=pic_change[i][j];
			pic_change[i][j]=pic_change[n-1-i][j];
			pic_change[n-1-i][j]=temp;
		}
	}
	
	//判断是否为变幻2
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(pic_change[i][j]!=pic_ref[i][j]){
				flag=false;				
				break;
			}
		}
		if(!flag)break;
	}

	if(flag){
		cout<<"2";
		return 0;		
	}
	
	flag=true;

	//将原矩阵以中央元素为对应元素互换
	//中央元素位于（n/2,n/2）,n是基数
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			pic_change[i][j]=pic_ori[n-1-i][n-1-j];
		}
	}
        
	//判断是否为变幻3
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(pic_change[i][j]!=pic_ref[i][j]){
				flag=false;				
				break;
			}
		}
		if(!flag)break;
	}

	if(flag){
		cout<<"3";
		return 0;		
	}

	
	cout<<"5";
	return 0;
}
