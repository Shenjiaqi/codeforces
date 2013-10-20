#include <cstdio>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const ll C=1000000007;
ll powmc(ll a,ll b)
{
  ll r=1LL;
  for(ll i=1;i<=b;i<<=1)
    {
      if(i&b)
	r=(r*a)%C;
      a=(a*a)%C;
    }
  return r;
}
int main()
{
  freopen("in.txt","r",stdin);
  int n;
  scanf("%d",&n);
#define N (100000)
  int v[N];
  for(int i=0;i<n;++i)
    scanf("%d",v+i);
  sort(v,v+n);
  int ans(0);
  int p[N+1]={0,1};
  int num[N+1]={0};
  int nn[N+1]={0};
  for(int i=0,j=n,k=1;i<n;++i,--j)
    for(;k<=v[i];++k)
      {
	nn[k]=j;
	for(int l=k;l<=v[n-1];l+=k)
	  ++num[l];
      }
  for(int i=0,j=n,k=1;i<n;++i,--j)
    for(;i<n && k<=v[i];++k)
      {
	ans=((ll)ans+(ll)p[k]*(powmc(num[k],j)-powmc(num[k]-1,j)+C))%C;
	cout<<k<<' '<<ans<<endl;
	for(int l=k+k;l<=v[n-1];l+=k)
	  {
	    int tmp=j-nn[l];
	    if(tmp<=0)
	      {
		p[l]=(p[l]+(ll)p[k])%C;
	      }
	    else 
	      p[l]=((ll)p[l]+(ll)p[k]*(powmc(num[k],j-nn[l])-powmc(num[k]-1,j-nn[l])+C))%C;
	  }	cout<<p[6]<<' '<<p[k]<<'!'<<powmc(num[k],j-nn[6])<<' '<<powmc(num[k]-1,j-nn[6])<<endl;

      }
  printf("%d",ans);
  return 0;
}
