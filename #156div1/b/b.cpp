#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
ll num(ll c)
{
  return c*c;
}
ll num2(ll c)
{
  return (c+1)*c/(ll)2;
}
ll cal(int n,int x,int y,ll t)
{
  ll blocks=2*t*t+2*t+1;
  //printf("\n\n%lld\n%lld\n",t,blocks);
  if(y<=t)
    blocks-=num(t-(ll)y+1);
  // printf("%lld\n",blocks);
  if(x<=t)
    blocks-=num(t-(ll)x+1);
  // printf("%lld\n",blocks);
  if(n-y<t)
    blocks-=num(t-n+(ll)y);
  // printf("%lld\n",blocks);
  if(n-x<t)
    blocks-=num(t-n+(ll)x);
  // printf("%lld\n",blocks);;
  int tmp;
  tmp=x+y-2+1;
  if(tmp<t)
    blocks+=num2(t-tmp);
  //printf("%lld\n",blocks);
  tmp=n-1-(y-x)+1;
  if(tmp<t)
    blocks+=num2(t-tmp);
  //printf("%lld\n",blocks);
  tmp=2*n-x-y+1;
  if(t>tmp)
    blocks+=num2(t-tmp);
  //printf("%lld\n",blocks);
  tmp=(y-x)-(1-n)+1;
  if(tmp<t)
    blocks+=num2(t-tmp);
  // printf("%lld\n",blocks);
  return blocks;
}
int main()
{
  //freopen("in","r",stdin);
  int n,x,y;
  ll c;
  cin>>n>>x>>y>>c;
  //scanf("%d %d %d %lld",&n,&x,&y,&c);
  int ans=0;
  int f,l;
  for(f=0,l=2*n;f<=l;)
    {
      int m=(f+l)/2;
      ll blocks=cal(n,x,y,m);
      //printf("%lld %lld %d %d %d\n",blocks,c,f,m,l);
      if(blocks>=c)
	{
	  ans=m;
	  l=m-1;
	  //printf("!%d\n",l);
	}
      else f=m+1;
    }
  printf("%d",ans);
  return 0;
}
