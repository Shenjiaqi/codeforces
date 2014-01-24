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
#define N 200007
int val[N];
int range[N][2],idx;
int depth[N];
int p[N*4+7][3];
int n,m;
vector<int> edge[N];
void addedge(int f,int t)
{
  edge[f].PB(t);
}
void dfs(int v,int from,int len)
{
  range[v][0]=++idx;
  depth[v]=len;
  FR(i,edge[v])
    if(*i!=from)
      dfs(*i,v,len+1);
  range[v][1]=idx;
}
void init(int v,int f,int t)
{
  p[v][0]=f,p[v][1]=t;
  if(f<t)
    {
      v<<=1;
      init(v,f,(f+t)>>1);
      init(v|1,((f+t)>>1)+1,t);
    }
}
void add(int v,int f,int t,int num)
{
  if(p[v][1]<f || p[v][0]>t)
    return ;
  if(p[v][0]>=f && p[v][1]<=t)
    p[v][2]+=num;
  else
    {
      v<<=1;
      add(v,f,t,num);
      add(v|1,f,t,num);
    }
}
int que(int v,int pos)
{
  int r=0;
  if(p[v][0]<p[v][1])
    {
      if(((p[v][0]+p[v][1])>>1)>=pos)
	r=que(v<<1,pos);
      else
	r=que((v<<1)|1,pos);
    }
  return p[v][2]+r;
}
int main()
{
  scanf("%d%d",&n,&m);
  FOR(i,0,n)
    scanf("%d",val+i);
  FOR(i,0,n-1)
    {
      int a,b;
      scanf("%d%d",&a,&b);
      addedge(a,b);
      addedge(b,a);
    }
  dfs(1,0,1);
  init(1,1,n);
  FOR(i,0,m)
    {
      int type;
      scanf("%d",&type);
      if(type==1)
	{
	  int x,v;
	  scanf("%d%d",&x,&v);
	  if((depth[x]&1)==0)
	    v=-v;
	  add(1,range[x][0],range[x][1],v);
	}
      else
	{
	  assert(type==2);
	  int x;
	  scanf("%d",&x);
	  int ans=que(1,range[x][0]);
	  if(depth[x]&1)
	    ans+=val[x-1];
	  else ans=val[x-1]-ans;
	  printf("%d\n",ans);
	}
    }
  return 0;
}
