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
#define N 300000
int p[N];
int n,k;
bool test(int mo)
{
  FOR(i,0,n)
    {
      int sub=p[i]%mo;
      if(mo==6)
	cout<<sub<<endl;
      if(sub>k)
	return false;
    }
  return true;
}
int main()
{
  scanf("%d%d",&n,&k);
  int minv=1e9,maxv=0;
  FOR(i,0,n)
    {
      scanf("%d",p+i);
      minv=min(minv,p[i]);
      maxv=max(maxv,p[i]);
    }
  int ans=0;
  for(int f=1,t=minv;f<=t;)
    {
      int m=(f+t)>>1;
      if(test(m))
	f=m+1,ans=m;
      else t=m-1;
    }
  printf("%d",ans);
}

