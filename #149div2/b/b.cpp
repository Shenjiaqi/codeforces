#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
  freopen("in","r",stdin);
  int n;
  scanf("%d",&n);
  int lm,rm,ans=1;
  scanf("%d%d",&lm,&rm);
  for(int i=2;i<=n;++i)
    {
      int l,r;
      scanf("%d%d",&l,&r);
      if(l>=lm && r<=rm && ans>0)
	;
      else if(l<=lm && r>=rm)
	lm=l,rm=r,ans=i;
      else
	{
	  ans=-1;
	  lm=min(l,lm);
	  rm=max(r,rm);
	}
    }
  printf("%d",ans);
  return 0;
}
