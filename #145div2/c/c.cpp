#include <cstdio>
#define N (100000)
int p[N+1];
int q1[N+1];
int n;
int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  scanf("%d",&n);
  for(int i=1;i<=n;++i)
    {
      scanf("%d",p+i);
      q1[i]=q1[i-1];
      if(p[i]>=0)
	++q1[i];
    }
  int ans=n+1,q2(0);
  for(int i=n-1;i>0;--i)
    {
      if(p[i+1]<=0)
	++q2;
      if(q2+q1[i]<ans)
	ans=q2+q1[i];
    }
  printf("%d",ans);
  return 0;
}
