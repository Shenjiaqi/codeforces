#include <cstdio>
using namespace std;
int main()
{
  int days[]={200,31,28,31,30,31,30,31,31,30,31,30,31};
  for(int i=1;i<=12;++i)
    days[i]+=days[i-1];
  int num[366*2+200]={0};
  int n;
  scanf("%d",&n);
  int m(0);
  for(int i=0;i<366+200;++i)
    if(m<num[i])
      m=num[i];
  printf("%d",m);
  return 0;
}
