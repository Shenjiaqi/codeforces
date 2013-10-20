#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <string.h>
using namespace std;
typedef long long ll;
const ll C=1000000007LL;
ll pp(ll a)
{
  if(a<6)
    return 0LL;
  ll r=1LL;
  for(int i=0;i<6;++i,--a)
    r=(r*a)%C;
  return r;
}
void cal(int m,int *p)
{
  ll dp[2][2][11]={0LL};
  int l=0;
  int v[10]={0};
  for(int c=m;c;c/=10,++l)
    v[l]=c%10;
  dp[1&(l-1)][1][0]=1LL;
  //printf("%d\n",l);
  for(int i=l-1;i>=0;--i)
    {
      int f=i&1;
      int t=1-f;
      for(int j=0;j<=l;++j)
	{
	  if(j)
	    dp[t][0][j]=(dp[f][0][j-1]*2LL);
	  dp[t][0][j]=(dp[t][0][j]+dp[f][0][j]*8LL)%C;
	  ll tt;
	  if(v[i]>0)
	    {
	      tt=v[i];
	      if(v[i]-1>=7)
		--tt;
	      if(v[i]-1>=4)
		--tt;
	      dp[t][0][j]+=dp[f][1][j]*tt;
	      dp[t][0][j]%=C;
	      tt=0;
	      if(v[i]-1>=4)
		++tt;
	      if(v[i]-1>=7)
		++tt;
	      if(j)
		dp[t][0][j]+=dp[f][1][j-1]*tt;
	    }

	  dp[t][0][j]%=C;
	  
	  if(j && (v[i]==7 || v[i]==4) )
	    dp[t][1][j]=dp[f][1][j-1];
	  if(v[i]!=7 && v[i]!=4)
	    dp[t][1][j]+=dp[f][1][j];
	  dp[t][1][j]%=C;
	}
      memset(dp[f],0,sizeof(dp[f]));
    }
  for(int t=1,i=0;i<=l;++i)
    p[i]=(dp[t][0][i]+dp[t][1][i])%C;
  //printf("%d~\n",(int)dp[1][0][1]);
  --p[0];
}
int p[11]={0};
ll rev(ll val)
{
  ll kk=C-2;
  ll r=1;
  for(ll i=1;i<=kk;i<<=1)
    {
      if(i&kk)
	r=(r*val)%C;
      val=(val*val)%C;
    }
  return r;
}
ll cc(ll a,ll b)
{
  if(b>a || b<0)
    return 0;
  ll r=1,rr=1;
  for(ll i=a;i>a-b;--i)
    r=(r*i)%C;
  for(ll i=b;i>1;--i)
    rr=(rr*i)%C;
  return (r*rev(rr))%C;
}
int main()
{
  freopen("in.txt","r",stdin);
  int m;
  scanf("%d",&m);
  cal(m,p);
  //for(int i=0;i<10;++i)    printf("%d\n",p[i]);
  int ans=0;
  ll tt[2][11][7]={0};
  tt[0][0][0]=1LL;
  int z=0;
  for(int i=0;i<10 && p[i]>0;++i)
    {
      ll tmp=0;
      for(int j=0;j<i;++j)
	tmp=(tmp+tt[z][j][6])%C;
      tmp=(tmp*p[i])%C;
      ans=((ll)ans+tmp)%C;
      //printf("%d %lld!\n",i,tmp);
      int f=z,t=1-z;
      for(int j=0;j<=6;++j)
	for(int k=0;k+j<=6;++k)
	  for(int l=0;l+k*i<10;++l)
	    {
	      tt[t][l+k*i][j+k]+=tt[f][l][j]*cc(p[i],k);
	      tt[t][l+k*i][j+k]%=C;
	    }
      memset(tt[z],0,sizeof(tt[z]));
      z=1-z;
    }
  //printf("%d\n",ans);
  ll r=1;
  for(int i=2;i<=6;++i)
    r*=i;
  ans=((ll)ans*(r))%C;
  printf("%d",ans);
  return 0;
}
