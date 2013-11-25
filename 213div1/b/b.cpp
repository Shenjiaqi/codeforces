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
#define N 50
int c[N];
bool p[N*10001+1];
int main()
{
  int n,d;
  scanf("%d%d",&n,&d);
  FOR(i,0,n)
    scanf("%d",c+i);
  sort(c,c+n);
  int inf=p[0];
  int maxv(0);
  int idx=0;
  for(;idx<n && maxv+d>=c[idx];++idx)
    maxv+=c[idx];
  p[0]=true;
  for(int i=0;i<idx;++i)
    for(int j=maxv;j-c[i]>=0;--j)
      if(p[j-c[i]])
	p[j]=true;
  int z(0);
  for(int i=0;i<maxv;++z)
    {
      for(i=min(maxv,i+d);!p[i];--i)
	;
    }
  printf("%d %d",maxv,z);
  return 0;
}
