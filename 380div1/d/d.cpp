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
#define N 100007
const ll mod=1000000007;
int n;
vector<ppi> seq;
ll rev(ll v)
{
  ll r=1;
  for(ll q=1;q<=(mod-2);q<<=1,v=(v*v)%mod)
    if(q&(mod-2))
      r=(r*v)%mod;
  return r;
}
int po(ll v,ll r)
{
  ll ans=1;
  for(int i=0;(1LL<<i)<=r;++i,v=(v*v)%mod)
    if((1LL<<i)&r)
      ans=(ans*v)%mod;
  return ans;
}
ll cc(int a,int b)
{
  if(a<b)
    return 0;
  ll c=1,d=1;
  for(int i=0;i<b;++i)
    {
      c=(c*(ll)(a-i))%mod;
      d=(d*(ll)(i+1))%mod;
    }
  return (c*rev(d))%mod;
}
int cal2(int left,int right,int lsti,int i)
{
  ll ans=1;
  for(;ans>0 && i<seq.size();++i)
    {
      int pos=seq[i].SEC;
      int t=seq[i].FIR;
      if(pos<left)
	{
	  int s=left-pos-1;
	  int si=t-lsti-1;
	  if(si<s || right+(si-s)>=n)
	    ans=0;
	  else
	    {
	      ans=(ans*cc(si,s))%mod;
	      right+=(si-s);
	      left=pos;
	      lsti=t;
	    }
	}
      else if(pos>right)
	{
	  int s=pos-right-1;
	  int si=t-lsti-1;
	  if(si<s || left-(si-s)<0)
	    ans=0;
	  else
	    {
	      ans=(ans*cc(si,s))%mod;
	      left-=(si-s);
	      right=pos;
	      lsti=t;
	    }
	}
      else ans=0;
    }
  if(ans>0 && left>0 && (n-right-1)>0)
    ans=(ans*cc(left+n-right-1,left))%mod;
  return ans;
}
int cal()
{
  int left,right;
  int lsti;
  left=right=seq[0].SEC;
  lsti=seq[0].FIR;
  if(lsti!=1)
    {
      ll ans=0;
      ll tmp=po(2,lsti-2);
      ll ti=0;
      if(left-(lsti-1)>=0)
	ans=(tmp*cal2(left-(lsti-1),right,lsti,1))%mod;
      if(right+lsti-1<n)
	ans=(ans+tmp*cal2(left,right+(lsti-1),lsti,1))%mod;
      return ans;
    }
  return cal2(left,right,lsti,1);
}
int main()
{
  scanf("%d",&n);
  FOR(i,0,n)
    {
      int v;
      scanf("%d",&v);
      if(v)
	seq.PB(MP(v,i));
    }
  if(seq.size()==0)
    {
      printf("%d",po(2,n-1));
    }
  else
    {
      sort(seq.begin(),seq.end());
      printf("%d",cal());
    }
  return 0;
}
