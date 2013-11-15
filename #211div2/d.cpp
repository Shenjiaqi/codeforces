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
int main()
{
  int n,m,a;
  scanf("%d%d%d",&n,&m,&a);
  vector<int> b,p;
  b.resize(n);
  FOR(i,0,n)
    scanf("%d",&b[i]);
  sort(b.begin(),b.end());
  p.resize(m);
  FOR(i,0,m)
    scanf("%d",&p[i]);
  sort(p.begin(),p.end());
  int ans(0),ansm(0);
  for(int f=0,t=min(n,m);f<=t;)
    {
      int mid=(f+t)>>1;
      ll lft=a;
      ll sum(0);
      for(int i=0;lft>=0 && i<mid;++i)
	lft-=max(p[i]-b[n-mid+i],0),sum+=p[i];
      if(lft>=0)
	f=mid+1,ans=mid,ansm=sum-a;
      else t=mid-1;
    }
  printf("%d %d",ans,max(0,ansm));
  return 0;
}
