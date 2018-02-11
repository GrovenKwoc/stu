#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct student{
	int num;
	float score;
};
int main()
{

	int n,k;
	cin>>n>>k;
	student students[n];
	
	for(int i=0;i<n;i++){
		cin>>students[i].num>>students[i].score;
	} 

	for(int i=0;i<n;i++){
		float max=students[i].score;
		int max_ind=i;
		for(int j=i+1;j<n;j++){
			if(students[j].score>max){
				max=students[j].score;
				max_ind=j;
			}
		}

		if(max_ind!=i){
			student temp=students[i];
			students[i]=students[max_ind];
			students[max_ind]=temp;
		}
	}

	printf("%d %g",students[k-1].num,students[k-1].score);
	return 0;

}
