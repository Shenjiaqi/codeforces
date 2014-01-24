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
int p[25*25*25+7];
bool vis[1<<24];
int q[1<<24];
int n;
char s[7];
int ans;
int mp(int a,int b,int c)
{
  int r=0;
  if(a)
    r=1+__builtin_ctz(a);
  if(b)
    r=r*25+__builtin_ctz(b)+1;
  if(c)
    r=r*25+__builtin_ctz(c)+1;
  return r;
}
int cal(int st)
{
  if(!vis[st])
    {
      vis[st]=true;
      int z1=st&(-st);
      if(z1==st)
	{
	  q[st]=p[mp(0,0,z1)];
	}
      else
	{
	  int t=st^z1;
	  int z2=t&(-t);
	  if(z2==t)
	    {
	      q[st]=cal(z1)+cal(z2)+p[mp(0,z1,z2)];
	    }
	  else
	    {
	      t^=z2;
	      int z3=t&(-t);
	      q[st]=cal(st^z1)+cal(st^z2)+cal(st^z3)-
		// cal((st^z1)&(st^z2))-cal((st^z1)&(st^z3))-cal((st^z2)&(st^z3))+
		// cal((st^z1)&(st^z2)&(st^z3));
		cal((st^z1)^z2)-cal((st^z1)^z3)-cal((st^z2)^z3)+
		cal(((st^z1)^z2)^z3);
	      q[st]+=p[mp(z1,z2,z3)];
	    }
	}
    }
  return q[st];
}
int main()
{
  scanf("%d",&n);
  FOR(i,0,n)
    {
      scanf("%s",s);
      vector<int> t;
      FOR(j,0,3)
	t.PB(s[j]-'a'+1);
      sort(t.begin(),t.end());
      t.resize(unique(t.begin(),t.end())-t.begin());
      int c=0;
      FR(j,t)
	c=c*25+*j;
      ++p[c];
    }
  vis[0]=true;
  for(int i=1;i<(1<<24);++i)
    {
      int tmp=cal(i);
      ans^=tmp*tmp;
    }
  cout<<ans;
  return 0;
}
