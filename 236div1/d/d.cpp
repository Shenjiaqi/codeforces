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
const int N = 1007;
const int KK = 47;
const int mod = 1e9 + 7;
int dp[N][KK];
int ans[N][KK];
int c[N][KK];
int st[KK];
inline int add( ll a, ll b)
{
  return ( a + b ) % mod;
}
inline int mul( ll a, ll b)
{
  return ( a * b ) % mod;
}
int pow( int a, int b)
{
  int r(1);
  for( ; b; b >>= 1, a = mul( a, a) )
    if( b & 1 )
      r = mul( r, a );
  return r;
}
int rev( int a )
{
  return pow( a, mod - 2 );
}
int main()
{
  dp[0][0] = 1;
  for( int i = 0 ; i < N; ++i )
    for( int j = N - 1; j >= i; --j )
      for( int k = KK - 1; k > 0; --k )
	dp[j][k] = add( dp[j][k], dp[ j - i ][ k - 1] );
  c[0][0] = 1;
  for( int i = 1; i < N; ++i )
    {
      c[i][0] = 1;
      for( int j = 1; j < min( KK, i + 1 ); ++j )
	{
	  c[i][j] = mul( c[i][j - 1], i - j + 1 ) ;
	  c[i][j] = mul( c[i][j], rev( j ) );
	}
    }
  st[1] = 1;
  for( int i = 2; i < KK; ++i )
    st[i] = mul( st[ i - 1], i );
  // sum(i) dp[i][k] * C ( n - i - k + 1+ k , k ) * k!
  // = sum(i) dp[i][k] * C ( n - i + 1, k ) * k!
  // i < n - k
  for( int n = 1; n < N; ++n )
    for( int k = 1; k <= min( KK - 1, n ); ++k )
      {
  	for( int i = ( k - 1 ) * k / 2; i <= n - k ; ++i )
  	  {
  	    int tmp = mul( dp[i][k], c[ n - i - ( k ) + k ][ k ] );
  	    ans[n][k] = add( ans[n][k], tmp );
  	  }
  	ans[n][k] = mul( ans[n][k], st[k] );
      }
  // for( int i = 1; i < N; ++i )
  //   for( int j = 1; j <= min(KK - 1, i); ++j )
  //     for( int s = ( j - 1 ) * j / 2; s <= i - j + 1; ++s)
  // 	ans[i][j] = add( ans[i][j], mul( st[k],
  // 					 mul( dp[s][k], C[ i - s + 1 ][j] ) ) );
  int t;
  scanf("%d", &t);
  for( int i = 0 ; i < t ; ++i )
    {
      int n, k;
      scanf("%d%d", &n, &k );
      if( ( k - 1 ) * k / 2 <= n - ( k - 1 ) )
	printf("%d\n", ans[n][k]);
      else printf("0\n");
    }
  return 0;
}
