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
#define N 100000
int p[N];
int main()
{
  //freopen("in","r",stdin);
  int n,l,r,ql,qr;
  scanf("%d%d%d%d%d",&n,&l,&r,&ql,&qr);
  int sum(0);
  FOR(i,0,n)
    {
      scanf("%d",p+i);
      sum+=p[i];
    }
  int cnt(0);
  int ans=2e9+1;
  for(int i=0;;++i)
    {
      int s=min(i,n-i);
      int tmp=cnt*l+(sum-cnt)*r;
      if(i>s+1)
	tmp+=ql*(i-s-1);
      if(n-i>s+1)
	tmp+=qr*(n-i-s-1);
      ans=min(tmp,ans);
      if(i>=n)
	break;
      cnt+=p[i];
    }
  printf("%d",ans);
  return 0;
}
