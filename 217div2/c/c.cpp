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
#define N 5007
#define M 107
int n,m;
typedef map<ppi,int,greater<ppi> > mi;
mi mapl,mapr;
int pl[M],pr[M];
void add(int v,int num,mi &mapp,int p[])
{
  if(mapp.find(ppi(p[v],v))!=mapp.end())
    mapp.erase(ppi(p[v],v));
  p[v]+=num;
  if(p[v]>0)
    mapp[ppi(p[v],v)]=1;
}
int main()
{
  scanf("%d%d",&n,&m);
  FOR(i,0,n)
    {
      int v;
      scanf("%d",&v);
      add(v,1,mapl,pl);
      add(v,1,mapr,pr);
    }
  queue<ppi> q;
  int ans(0);
  for(;!mapr.empty();)
    {
      typeof(mapl.begin()) a=mapl.begin();
      typeof(mapr.begin()) b=mapr.begin();
      int c=a->first.second;
      int d=b->first.second;
      if(mapr.size()>1)
	{
	  ++b;
	  d=b->first.second;
	}
      else if(mapl.size()>1)
	{
	  ++a;
	  c=a->first.second;
	}
      add(c,-1,mapl,pl);
      add(d,-1,mapr,pr);
      if(c!=d)
	++ans;
      q.push(ppi(c,d));
    }
  printf("%d",ans);
  for(;!q.empty();q.pop())
    printf("\n%d %d",q.front().first,q.front().second);
  return 0;
}
