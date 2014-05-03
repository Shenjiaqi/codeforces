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
const int N=100007;
int n,k;
vector<int> p[N];
bool test(int w)
{
  stack<int> st;
  stack<int> q[N];
  int poi[N]={0};
  for(int i=n;i>0;--i)
    st.push(i);
  for(int i=1;i<=n-w+1;++i)
    {
      int t=i+w-1;
      for(;!st.empty() && st.top()<i;st.pop())
	;
      for(;!st.empty() && st.top()<=t;st.pop())
	{
	  int v=st.top();
	  for(;poi[v]<p[v].size();++poi[v])
	    if(p[v][poi[v]]>=i)
	      break;
	  if(poi[v]<p[v].size() && p[v][poi[v]]<=t)
	    {
	      int tt=p[v][poi[v]];
	      if(tt<v)
		q[tt].push(v);
	    }
	  else break;
	}
      if(st.empty() || st.top()>t)
	{
	  return true;
	}
      if(w==3 && i==3)
	{
	  cout<<st.top()<<' '<<poi[3]<<' '<<p[3].size()<<' '<<p[3][0]<<endl;
	}
      for(;!q[i].empty();q[i].pop())
	st.push(q[i].top());
    }
  return false;
}
int main()
{
  scanf("%d%d",&n,&k);
  FOR(i,1,n)
    {
      int f,t;
      scanf("%d%d",&f,&t);
      p[f].PB(t);
      p[t].PB(f);
    }
  FOR(i,1,n+1)
    sort(p[i].begin(),p[i].end());
  int ans=0;
  for(int f=0,t=k;f<=t;)
    {
      int m=(f+t)>>1;
      if(test(m))
	ans=m,f=m+1;
      else t=m-1;
    }
  printf("%d",ans);
  return 0;
}
