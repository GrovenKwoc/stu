#include<iostream>
#include<cstdio>
#include<cstring>
#include<memory.h>
using namespace std;

int main()
{
	char s[101];
	char a[101];
	char b[101];
	
	gets(s);
	gets(a);
	gets(b);

	int s_len=strlen(s);
	int a_len=strlen(a);
	int b_len=strlen(b);
	bool match_mode=false;

	for(int i=0;i<s_len;i++){

		if((a[0]==s[i])&&((i==0)||(s[i-1]==32))){

			match_mode=true;
			int k=i;
			for(int j=1;j<a_len;j++){
				k++;
				if(a[j]!=s[k]){
					match_mode=false;

					break;
				}
			
			}
			if(match_mode&&(s[k+1]!=32)&&(s[k+1]!='\0')){
				match_mode=false;

			}

			if(match_mode){

				if(b_len==a_len){
					for(int l=k-b_len+1,c=0;l<=k;l++){
						s[l]=b[c];
						c++;
					}
			
				}if(b_len<a_len){
					for(int l=0;l<b_len;l++){
						s[k-l]=b[b_len-l-1];
						l++;
					}
					
					for(int l=k;l<s_len;l++){
						s[l-a_len+b_len]=s[l];
					}
					s[s_len-a_len+b_len]='\0';
					s_len=strlen(s);
				}
			
			}
		}
		
	}
	cout<<s;
	return 0;
}
