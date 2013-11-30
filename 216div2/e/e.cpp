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
#define N 300007
#define M 300007
#define R 1000007
vector<ppi> p;
vector<ppi> pos[R];
vector<int> q[M];
vector<int> ans;
int n,m;
int cnt[R];
void add(int k,int v)
{
  for(;k<=R-1;k+=(k&(-k)))
    cnt[k]+=v;
}
int que(int k)
{
  int r(0);
  for(;k;k^=(k&(-k)))
    r+=cnt[k];
  return r;
}
int main()
{
  // freopen("in","r",stdin);
  scanf("%d%d",&n,&m);
  FOR(i,0,n)
    {
      int l,r;
      scanf("%d%d",&l,&r);
      p.push_back(ppi(l,r));
    }
  sort(p.begin(),p.end());
  FOR(i,0,m)
    {
      int c;
      scanf("%d",&c);
      FOR(j,0,c)
	{
	  int v;
	  scanf("%d",&v);
	  q[i].push_back(v);
	}
    }
  FOR(i,0,m)
    FOR(j,0,q[i].size()-1)
    pos[q[i][j]].push_back(ppi(q[i][j+1],i));
  ans.resize(m);
  int cc=1;
  FOR(i,0,n)
    {
      int l=p[i].first,r=p[i].second;
      for(;cc<l;++cc)
	FR(j,pos[cc])
	  {
	    int tmp=que(j->first);
	    ans[j->second]-=tmp;
	  }
      add(l,1);
      add(r+1,-1);
    }
  for(;cc<1e6+1;++cc)
    FR(j,pos[cc])
      ans[j->second]-=que(j->first);
  FOR(i,0,m)
    FR(j,q[i])
    ans[i]+=que(*j);
  FR(i,ans)
    printf("%d\n",*i);
  return 0;
}
