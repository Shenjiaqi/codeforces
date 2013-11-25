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
#define N 57
int p[N*N*2+7][3],poi;
int sp[N];
int d[N];
int s,t,ss,tt;
void ad(int f,int t,int v)
{
  ++poi,p[poi][0]=t,p[poi][1]=sp[f],p[poi][2]=v,sp[f]=poi;
}
void add(int f,int t,int v)
{
  ad(f,t,v);
  ad(t,f,0);
}
bool bfs()
{
  queue<int> que;
  memset(d,0,sizeof(d));
  que.push(s);
  d[s]=1;
  for(;!que.empty();)
    {
      int v=que.front();
      que.pop();
      for(int i=sp[v];i;i=p[i][1])
	{
	  int z=p[i][0];
	  if(p[i][2]>0 && 0==d[z])
	    d[z]=d[v]+1,
	      que.push(z);
	}
    }
  // cout<<d[t]<<endl;
  return d[t]>0;
}
int dfs(int v,int f)
{
  if(v==t)
    return f;
  int rf=f;
  for(int i=sp[v];f>0 && i;i=p[i][1])
    {
      int z=p[i][0];
      if(p[i][2]>0 && d[v]+1==d[z])
	{
	  int tmp=dfs(z,min(f,p[i][2]));
	  p[i][2]-=tmp;
	  p[i+((i&1)?1:-1)][2]+=tmp;
	  f-=tmp;
	}
    }
  return rf-f;
}
int mf()
{
  int r(0);
  for(;bfs();)
    for(int i;(i=dfs(s,1e9));)
      r+=i;
  return r;
}
int main()
{
  int n,k;
  scanf("%d%d",&n,&k);
  s=1,t=n;
  ss=n+1,tt=n+2;
  FOR(i,0,n)
    FOR(j,0,n)
    {
      int c;
      scanf("%d",&c);
      if(c>0)
	{
	  add(i+1,j+1,c);
	  add(i+1,ss,k);
	  add(tt,j+1,k);
	}
    }
  add(ss,tt,k);
  printf("%d",mf());
  return 0;
}
