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
  int n;
  scanf("%d",&n);
  int p[4][4];
  FOR(i,0,4)
    FOR(j,0,4)
    scanf("%d",&p[i][j]);
  FOR(i,0,4)
    {
      int a=min(p[i][0],p[i][1]);
      int b=min(p[i][2],p[i][3]);
      int mi=a+b;
      if(mi<=n)
	{
	  printf("%d %d %d",i+1,a,n-a);
	  return 0;
	}
    }
  printf("-1");
  return 0;
}
