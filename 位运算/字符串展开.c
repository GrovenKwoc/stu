#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
	int p1,p2,p3;
	char str[10000];
	char left,right;
	cin>>p1>>p2>>p3>>str;
	int len=strlen(str);
	int insert_len=0;
	bool ins=false;
	//读取‘-’号并判断是否填充	
	for(int i=0;str[i]!=0;i++){
		if(str[i]=='-'){
			left=str[i-1];//记录减号左边字符
			right=str[i+1];//记录减号右边字符
			if((left>='a'&&left<='z'&&right>='a'&&right<='z'&&(left<right))||(left>='0'&&left<='9'&&right>='0'&&right<='9'&&(left<right))){
				ins=true;
			}else continue;
		}

		if(ins){
			insert_len=(right-left-1)*p2;//需要插入的字符个数
			//对原串进行移位
			if(insert_len!=0){
				for(int k=len;k>i;k--){
					str[k+insert_len-1]=str[k];
				}
			}
			else{
				for(int k=i;k<len;k++){
					str[k]=str[k+1];
				}
			}
			//将字符插入原串
			if(p3==1){
				for(int j=0;j<insert_len;j++){
					str[i+j]=left+1+j/p2;
					if(p1==1)continue;
					if(p1==2&&str[i+j]>='a'&&str[i+j]<='z')str[i+j]-=32;
					if(p1==3)str[i+j]='*';
				}
			}
			if(p3==2){
				for(int j=0;j<insert_len;j++){
					str[j+i]=right-1-j/p2;
					if(p1==1)continue;
					if((p1==2)&&str[i+j]>='a'&&str[i+j]<='z')str[i+j]-=32;
					if(p1==3)str[i+j]='*';
				}
			}
		}
		ins=false;
		len=strlen(str);
		insert_len=0;
		
	}
	cout<<str;
	return 0;
}
