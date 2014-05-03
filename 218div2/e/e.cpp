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
#define N 300007
int n,k;
int p[N];
int main()
{
  scanf("%d",&n);
  FOR(i,0,n)
    scanf("%d",p+i);
  scanf("%d",&k);
  ll t=k-1,add=0;
  ll now=0;
  FOR(i,0,k)
    now+=(ll)(-t)*p[i],t-=2,add+=p[i]*2;
  ll ans=now,ansi=0;
  cout<<ans<<endl;
  for(int i=k;i<n;++i)
    {
      now-=(4LL*(ll)(p[i]-p[i-k]));
      add-=2LL*p[i-k];
      now-=add;
      cout<<now<<endl;
      if(now<ans)
	ansi=i;
      add+=2LL*p[i];
    }
  FOR(i,0,k)
    printf("%d ",((int)ansi+1+i));
  return 0;
}
