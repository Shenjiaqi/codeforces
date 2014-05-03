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
const int N = 1e6 + 7;
int p[N];
int main()
{
  int n, m;
  scanf("%d%d", &n, &m);
  for( int i = 0; i < n; ++i )
    scanf("%d", p + i);
  sort( p, p + n );
  ll ans(0);
  for( int i = n - 1; i > 0; i -= m)
    ans += (p[i] - p[0]);
  ll minV = ans;
  for( int i = 1, l = 0, r = n - 1; i < n; ++i )
    {
      int det = p[i] - p[i - 1];
      ++l;
      ans += (ll)( ( l + m - 1 ) / m ) * (ll)det;
      ans -= (ll)( ( r + m - 1 ) / m ) * (ll)det;
      --r;
      minV = min( minV, ans);
    }
  cout << minV * 2;
  return 0;
}
