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
#define FIR first
#define SEC second
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
#define N 200007
int n,m;
int a[N],v[N];;
int nxt[N];
vector<int> pre[N];
multimap<int,int> mapp;
void fill(int to,int num)
{
  if(to<0)
    return;
  v[to]+=num;
  if(v[to]>=a[to])
    {
      fill(nxt[to],v[to]-a[to]);
      v[to]=a[to];
      int nt=nxt[to];
      FR(i,pre[to])
	{
	  nxt[*i]=nt;
	  if(nt>=0)
	    pre[nt].PB(*i);
	}
      pre[to].resize(0);
    }
}
int main()
{
  scanf("%d",&n);
  FOR(i,1,n+1)
    scanf("%d",a+i);
  // FOR(i,1,n+1)
  //   {
  //     for(typeof(mapp.begin()) j=mapp.begin(),k;j!=mapp.end();)
  // 	if(j->FIR<a[i])
  // 	  {
  // 	    nxt[j->SEC]=i;
  // 	    pre[i].PB(j->SEC);
  // 	    k=j++;
  // 	    mapp.erase(k);
  // 	  }
  // 	else break;
  //     nxt[i]=-1;
  //     mapp.insert(ppi(a[i],i));
  //   }
  // FOR(i,1,n+1)
  //   cout<<nxt[i]<<endl;
  FOR(i,1,n)
    {
      nxt[i]=i+1;
      pre[i+1].PB(i);
    }
  nxt[n]=-1;
      // typeof(mapp.begin()) ite=mapp.upper_bound(a[i]);
      // if(ite==mapp.end())
      // 	  nxt[i]=-1;
      // else
      // 	{
      // 	  for(int k=ite->SEC;k<=n;++k)
      // 	    if(
      // 	  nxt[i]=ite->SEC;
      // 	  pre[ite->SEC].PB(i);
      // 	}
      // mapp[a[i]]=i;
  scanf("%d",&m);
  FOR(i,0,m)
    {
      int t;
      scanf("%d",&t);
      if(t==1)
	{
	  int c,d;
	  scanf("%d%d",&c,&d);
	  fill(c,d);
	}
      else if(t==2)
	{
	  int c;
	  scanf("%d",&c);
	  printf("%d\n",v[c]);
	}
    }
  return 0;
}
