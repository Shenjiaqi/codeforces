#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
  freopen("in.txt","r",stdin);
  int n,d,l;
  scanf("%d%d%d",&n,&d,&l);
  if(n&1)
    {
      if(d>0)
	{
	  if(d> l*((n/2)+1)-(n/2))
	    printf("-1");
	  else
	    {
	      d-=1;
	      for(int i=1;i<=n;++i)
		if(i&1)
		  {
		    printf("%d ",min(l-1,d)+1);
		    d-=min(l-1,d);
		  }
		else
		    printf("1 ");
	    }
	}
      else
	{
	  if(d< n/2+1-(n/2)*l)
	    printf("-1");
	  else
	    {
	      d=-d;
	      d+=1;
	      for(int i=1;i<=n;++i)
		if(i&1)
		  printf("1 ");
		else
		  {
		    printf("%d ",min(l-1,d)+1);
		    d-=min(l-1,d);
		  }
	    }
	}
    }
  else
    {
      if(abs(d)>n/2*(l-1))
	printf("-1");
      else
	{
	  bool neg=(d<0);
	  if(d<0)
	    d=-d;
	  for(int i=1;i<=n;++i)
	    if(i&1)
	      {
		if(neg)
		  printf("1 ");
		else
		  {
		    printf("%d ",min(l-1,d)+1);
		    d-=min(l-1,d);
		  }
	      }
	    else
	      {
		if(neg)
		  {
		    printf("%d ",min(l-1,d)+1);
		    d-=min(l-1,d);
		  }
		else printf("1 ");
	      }
	}
    }
  return 0;
}
