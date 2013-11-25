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
#define N 1007
struct edge
{
  int t,l,r;
};
vector<edge> p[N];
int hi[N];
int n,m;
bool in[N];
struct cmp
{
  bool operator()(const edge &a,const edge &b) const
  {
    if(a.t!=b.t)
      return a.t<b.t;
    if(a.l!=b.l)
      return a.l<b.l;
    return a.r<b.r;
  }
};
struct cmp2
{
  bool operator()(const edge &a,const edge &b) const
  {
    if(hi[a.t]!=hi[b.t])
      return hi[a.t]<hi[b.t];
    if(a.r-a.l!=b.r-b.l)
      return a.r-a.l>b.r-b.l;
    if(a.t!=b.t)
      return a.t>b.t;
    if(a.l!=b.l)
      return a.l<b.l;
    return a.r>b.r;
  }
};
bool test(int val)
{
  map<edge,int,cmp2> que;
  edge e;
  e.t=1,e.l=1,e.r=1e6+1;
  que[e]=1;
  map<edge,int,cmp> vis;
  vis[e]=1;
  for(;!que.empty();)
    {
      edge v=que.begin()->first;
      que.erase(que.begin());
      FR(i,p[v.t])
	//if(v.f!=i->t)
	  {
	    //e.f=v.t;
	    e=*i;
	    e.l=max(e.l,v.l);
	    e.r=min(e.r,v.r);
	    if(e.r-e.l+1>=val && vis.find(e)==vis.end())
	      {
		if(e.t==n)
		  return true;
		vis[e]=1,que[e]=1;
	      }
	  }
    }
  return false;
}
int main()
{
  scanf("%d%d",&n,&m);
  FOR(i,0,m)
    {
      int a,b,l,r;
      scanf("%d%d%d%d",&a,&b,&l,&r);
      if(a!=b)
	{
	  edge e;
	  e.t=b,e.l=l,e.r=r;
	  p[a].push_back(e);
	  e.t=a;
	  p[b].push_back(e);
	}
    }
  memset(hi,1<<6,sizeof(hi));
  hi[n]=0;
  in[n]=true;
  queue<int> que;
  que.push(n);
  for(;!que.empty();)
    {
      int v=que.front();
      que.pop();
      in[v]=false;
      FR(i,p[v])
	if(hi[i->t]>hi[v]+1)
	  {
	    hi[i->t]=hi[v]+1;
	    if(!in[i->t])
	      que.push(i->t),in[i->t]=true;
	  }
    }
  int ans=0;
  for(int f=1,l=1e6;f<=l;)
    {
      int m=(f+l)>>1;
      if(test(m))
	ans=m,f=m+1;
      else l=m-1;
    }
  if(ans>0)
    printf("%d",ans);
  else printf("Nice work, Dima!");
  return 0;
}
