#include <cstdio>
int main()
{
  freopen("in","r",stdin);
  int y,k,n;
  scanf("%d%d%d",&y,&k,&n);
  int t=k-(y%k);
  if(t==0)
    t=k;
  if(t+y<=n)
    for(int i=t;i<=n-y;i+=k)
      printf("%d ",i);
  else printf("-1");
  return 0;
}
