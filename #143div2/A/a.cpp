#include <cstdio>
int main()
{
  freopen("in.txt","r",stdin);
  int n;
  scanf("%d",&n);
  int ans(0);
  for(int i=0;i<n;++i)
    {
      int r(0);
      int a;
      scanf("%d",&a);
      r+=a;
      scanf("%d",&a);
      r+=a;
      scanf("%d",&a);
      r+=a;
      if(r>=2)
	++ans;
    }
  printf("%d",ans);
  return 0;
}
