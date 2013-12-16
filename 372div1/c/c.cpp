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
const int M=307;
int n,m,d;
int p[M][3];
int main()
{
  scanf("%d%d%d",&n,&m,&d);
  FOR(i,0,m)
    FOR(j,0,3)
    scanf("%d",&p[i][j]);
  list<ppl> lst;
  lst.PB(MP(1,0)),lst.PB(MP(n,0));
  FOR(i,0,m)
    {
      ll a=p[i][0];
      // if(a==1)
      // 	lst.insert(lst.begin(),*lst.begin());
      // else if(a==n)
      // 	{
      // 	  typeof(lst.end()) i=lst.end();
      // 	  --i;
      // 	  lst.insert(lst.end(),*i);
      // 	}
      // else
      if(a!=1 && a!=n)
	FR(k,lst)
	  {
	    if(k->FIR==a)
	      break;
	    if(k->FIR>a)
	      {
		typeof(k) j=k;
		--j;
		ll v=k->SEC;
		if(k->SEC!=j->SEC)
		  v+=(a-k->FIR)*(j->SEC-k->SEC)/(j->FIR-k->FIR);
		// for(int k=0;k<2;++k)
		lst.insert(k,MP(a,v));
		break;
	      }
	  }
      FR(i,lst)
	i->SEC+=abs(i->FIR-a);
      if(i!=m-1)
	{
	  ll mi=1LL<<62;
	  FR(i,lst)
	    mi=min(mi,i->SEC);
	  ll len=(ll)d*(ll)(p[i+1][2]-p[i][2]);
	  for(typeof(lst.end()) i=lst.begin();;++i)
	    if(i->SEC==mi)
	      {
		lst.insert(i,*i);
		--i;
		for(;;--i)
		  {
		    i->FIR-=len;
		    if(i->FIR<=1)
		      {
			typeof(i) j=i;
			++j;
			if(i->SEC!=j->SEC)
			  i->SEC+=(1LL-i->FIR)*(j->SEC-i->SEC)/(j->FIR-i->FIR);
			i->FIR=1;
			lst.erase(lst.begin(),i);
			break;
		      }
		    if(i==lst.begin())
		      break;
		  }
		break;
	      }
	  for(typeof(lst.end()) i=lst.end();;--i)
	    {
	      if(i!=lst.end() && i->SEC==mi)
		{
		  lst.insert(i,*i);
		  for(;i!=lst.end();++i)
		  {
		    i->FIR+=len;
		    if(i->FIR>=n)
		      {
			typeof(i) j=i;
			--j;
			if(i->SEC!=j->SEC)
			  i->SEC+=((ll)n-i->FIR)*(j->SEC-i->SEC)/(j->FIR-i->FIR);
			i->FIR=n;
			++i;
			lst.erase(i,lst.end());
			break;
		      }
		  }
		  break;
		}
	    }
	}
    }
  ll ans=1LL<<62;
  FR(i,lst)
    ans=min(ans,i->SEC);
  ans=-ans;
  FOR(i,0,m)
    ans+=p[i][1];
  cout<<ans;
  return 0;
}
