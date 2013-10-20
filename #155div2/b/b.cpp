#include <cstdio>
using namespace std;
int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  int days[]={200,31,28,31,30,31,30,31,31,30,31,30,31};
  for(int i=1;i<=12;++i)
    days[i]+=days[i-1];
  int num[366*2+200]={0};
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;++i)
    {
      int m,d,p,t;
      scanf("%d%d%d%d",&m,&d,&p,&t);
      for(int j=days[m-1]+d-t-1;j<days[m-1]+d-1;++j)
	num[j]+=p;
    }
  int m(0);
  for(int i=0;i<366+200;++i)
    if(m<num[i])
      m=num[i];
  printf("%d",m);
  return 0;
}
