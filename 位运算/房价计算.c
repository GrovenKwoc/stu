#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(int argc,char** argv){
   int N,K;
   double HP=200.0;
   
   cin>>N>>K;
   if(N<10||N>50||K<1||K>20)return 1;
   
   for(int i=1;i<=20;i++){
       if(N*i-HP>=0){
           printf("%d",i);
           return 0;
       }
       HP*=(K/100.0+1.0);
   }

   printf("Impossible");
   return 0;
}
