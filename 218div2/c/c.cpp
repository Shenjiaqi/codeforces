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
#define pb push_back
#define FIR first
#define SEC second
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
int p[3],q[3];
int price[3];
int main()
{
  string s;
  cin>>s;
  FR(i,s)
    if(*i=='B')
      ++p[0];
    else if(*i=='S')
      ++p[1];
    else ++p[2];
  FOR(i,0,3)
    scanf("%d",q+i);
  FOR(i,0,3)
    scanf("%d",price+i);
  ll money;
  cin>>money;
  ll ans=0;
  for(ll f=0,t=101+1e13;f<=t;)
    {
      ll m=(f+t)/2;
      ll need=0;
      FOR(i,0,3)
	{
	  ll tmp=m*(ll)p[i]-(ll)q[i];
	  if(tmp>0)
	    need+=tmp*(ll)price[i];
	}
      if(need<=money)
	ans=m,f=m+1;
      else t=m-1;
    }
  cout<<ans;
  return 0;
}
