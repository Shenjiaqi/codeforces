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
const int N=1e4+7;
const int M=1e5+7;
int a[N],b[M];
int gcd(int a,int b)
{
  return b==0?a:gcd(b,a%b);
}
ll pom(ll a,int b,int m)
{
  ll r(1);
  for(int i=1;i<=b;i<<=1,a=(a*a)%m)
    if(i&b)
      r=(r*a)%m;
  return r;
}
int main()
{
  int n,m,p;
  scanf("%d%d%d",&n,&m,&p);
  FOR(i,0,n)
    scanf("%d",a+i);
  FOR(i,0,m)
    scanf("%d",b+i);
  int mb=p-1;
  FOR(i,0,m)
    mb=gcd(mb,b[i]);
  vector<int> c;
  FOR(i,1,sqrt(p-1)+1)
    if(((p-1)%i)==0)
      c.push_back(i),
	c.push_back((p-1)/i);
  sort(c.begin(),c.end());
  c.resize(unique(c.begin(),c.end())-c.begin());
  vector<bool> is;
  is.resize(c.size());
  FOR(i,0,n)
    {
      int tmp=pom(a[i],mb,p);
      FOR(j,0,c.size())
	if(pom(tmp,c[j],p)==1)
	  {
	    is[j]=true;
	    break;
	  }
    }
  vector<int> cc;
  FOR(i,0,c.size())
    if(is[i])
      cc.push_back(c[i]);
  vector<ll> cnt;
  FR(i,cc)
    cnt.push_back(1);
  reverse(cc.begin(),cc.end());
  ll ans(0);
  FOR(i,0,cc.size())
    if(cnt[i])
      {
	ans+=cnt[i]*(ll)cc[i];
	FOR(j,i+1,cc.size())
	  if((cc[i]%cc[j])==0)
	    cnt[j]-=cnt[i];
      }
  cout<<ans<<endl;
  return 0;
}
