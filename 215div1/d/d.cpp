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
typedef long long ll;
typedef pair<int,int> ppi;
typedef pair<ll,ll> ppl;
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
#define N 100007
#define M 27
int p[N];
int n,m,d;
int pos[M];
vector<ppi> q[N];
bool msk[1<<21];
int ans;
void setmsk(int u)
{
  if(msk[u])
    return;
  msk[u]=true;
  for(int i=u;i;i^=(i&(-i)))
    setmsk(u^(i&(-i)));
}
void dfs(int v,int usd,int num)
{
  //cout<<v<<' '<<usd<<' '<<num<<' '<<ans<<endl;
  if(v>=n-d+1)
    ans=num;
  if(ans<=num || msk[usd])
    {
      setmsk(usd);
      return ;
    }
  FR(i,q[v])
    {
      int u=i->second;
      if(u&usd)
	{
	  dfs(i->first,usd,num);
	  return ;
	}
    }
  setmsk(usd);
  // cout<<v<<' '<<usd<<' '<<num<<' '<<ans<<endl;
  // cout<<"!!"<<usd<<' '<<v<<endl;
  FR(i,q[v])
    {
      // if(ans<=num+1)
      // 	return ;
      int uusd=(i->second)|usd;
      dfs(i->first,uusd,num+1);
    }
}
int main()
{
  scanf("%d%d%d",&n,&m,&d);
  FOR(i,0,m)
    {
      int s;
      scanf("%d",&s);
      FOR(j,0,s)
	{
	  int v;
	  scanf("%d",&v);
	  p[v]=i;
	}
    }
  FOR(i,1,d+1)
    pos[p[i]]=i;
  for(int i=0,j=d;j<=n;++i,++j)
    {
      for(int k=0;k<m;++k)
	if(pos[k]>i)
	  q[i].push_back(ppi(pos[k],(1<<k)));
      sort(q[i].begin(),q[i].end(),greater<ppi>());
      if(j+1>n)
	break;
      pos[p[j+1]]=j+1;
    }
  ans=m;
  dfs(0,0,0);
  printf("%d",ans);
  return 0;
}
