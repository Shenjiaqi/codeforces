#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <fstream>
#include <cassert>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
#include <stack>
#include <complex>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <functional>
#include <cctype>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<int,int> ppi;
typedef pair<ll,ll> ppl;
typedef pair<double,double> ppd;
#define PB push_back
#define MP make_pair
#define FIR first
#define SEC second
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
#define N 1000007
#define K 1000007
int n,k;
int p[N],b[K],q[N];
void add(int id,int val)
{
  for(;id<N;id+=(id&(-id)))
    q[id]+=val;
}
int que(int id)
{
  int r=0;
  for(;id;id^=(id&(-id)))
    r+=q[id];
  return r;
}
ll cal()
{
  memset(q,0,sizeof(q));
  ll ans=0;
  map<int,int> mapp;
  for(int i=0,j=0;i<n;++i)
    {
      if(j<k && p[i]==b[j])
	{
	  for(typeof(mapp.begin()) ite=mapp.upper_bound(p[i]);
	      ite!=mapp.end();)
	    {
	      // cout<<ite->FIR<<' '<<que(ite->FIR)<<endl;
	      ans+=que(ite->FIR);
	      typeof(ite) ii=ite++;
	      mapp.erase(ii);
	    }
	  ++j;
	}
      else
	{
	  mapp[p[i]]=i;
	  ans-=que(p[i]);
	  // cout<<p[i]<<' '<<que(p[i])<<"!"<<endl;
	}
      add(1,1);
      add(p[i],-1);
    }
  FR(i,mapp)
    {
      ans+=que(i->FIR);
    }
  return ans;
}
int main()
{
  scanf("%d%d",&n,&k);
  FOR(i,0,n)
    scanf("%d",p+i);
  FOR(i,0,k)
    scanf("%d",b+i);
  ll ans;
  ans=cal();
  for(int i=0,j=n-1;i<j;++i,--j)
    swap(p[i],p[j]);
  for(int i=0,j=k-1;i<j;++i,--j)
    swap(b[i],b[j]);
  ans+=cal();
  ans+=n-k;
  cout<<ans<<endl;
#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}
