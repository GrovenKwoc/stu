#include<memory>
#include<string>
#include<cstring>
#include<iostream>

using namespace std;
char oriLights[5];//原始灯的状态
char lights[5];//变化过程中的灯的状态
char result[5];//开关是否按下的最终结果

int GetBit(char c,int i)
{
    return (c>>i)&1;
}

void SetBit(char *c,int i,int v)
{
    if(v){
         (*c)|=1<<i
    }else{
         (*c)&=~(1<<i);
    }  
}

void FlipBit(char *c,int i)
{
    (*c)^=(1<<i);
}

void OutputResult(int i,char result[])
{
    cout<<"PUZZLE #"<< t<<endl;
    for(int i=0;i<5;i++)
    {
         for(int j=0;j<6;j++)
         {
             cout<<GetBit(result[i],j);
             if(j<5)
                cout<<" ";
         }
         cout <<endl;
    }

}

int main()
{
    int T;
    cin>>T;
    for(int t=1;t<=T;++t)
    {
        for(int i=0;i<5;++i){
            for(int j=0;j<6;++j){
               int s;
               cin>>s;
               SetBit(oriLights[i],j,s);
            }
        }

        for(int n=0;n<64;++n){
            int switchs=n;
            memcpy(lights,oriLights,sizeof(oriLights))
            for(int i=0;i<5;++i){
               result[i]=switchs;
               for(int j=0;j<6;j++){
                  if(GetBit(switchs,j)){
                       if(j>0)
                         FlipBit(lights[i],j-1);
                  }
               }
            }
        }

    }
}
