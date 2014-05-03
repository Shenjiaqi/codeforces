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
const int N = 2e5 + 7;
int p[N];
int main()
{
  int n, t, c;
  scanf("%d%d%d", &n, &t, &c);
  int cnt(0);
  int ans = n - c + 1;
  for( int i = 0; i < c; ++i )
    {
      scanf("%d", p + i);
      if( p[i] > t )
	++cnt;
    }
  if( cnt > 0 )
    --ans;
  for( int i = c; i < n; ++i )
    {
      scanf("%d", p + i );
      if( p[i] > t )
	++cnt;
      if( p[ i - c ] > t )
	--cnt;
      if( cnt > 0 )
	--ans;
    }
  printf("%d", ans);
  return 0;
}
