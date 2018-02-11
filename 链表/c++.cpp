#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
  int c,d;
  while (cin>>c>>d)
  {
    printf("成功读取数据，相加结果为%d\n",c+d); 
  }

  printf("读取数据失败");
  return 0;
}
