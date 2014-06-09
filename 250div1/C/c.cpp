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
typedef pair<ld,ld> ppld;
#define PB push_back
#define FIR first
#define SEC second
#define MP make_pair
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
const int N = 207;
const ll mod = (int)1e9 + 7;
int p[N][2];
int dp[N][N][N][2];
bool vis[N][N][N][2];
bool cnt[N][N];
int n;
int addM( int a, int b )
{
  return ( (ll)a + b ) % mod;
}
int mulM( int a, int b )
{
  return ( (ll)a * b ) % mod;
}
ll sq( int a )
{
  return (ll)a * a;
}
ld dis( int a, int b )
{
  return sqrtl( sq( p[a][0] - p[b][0] ) + sq( p[a][1] - p[b][1] ) );
}
ld dis( int x0, int y0, int x1, int y1 )
{
  return sqrtl( sq( x0 - x1 ) + sq( y0 - y1 ) );
}
ll cross( int x0, int y0, int x1, int y1 )
{
  return (ll)x0 * y1 - (ll)y0 * x1;
}
bool oth( int a, int b, int c, int d )
{
  int x0 = p[b][0] - p[a][0];
  int y0 = p[b][1] - p[a][1];
  int x1 = p[c][0] - p[a][0];
  int y1 = p[c][1] - p[a][1];
  ll tmp1 = cross( x0, y0, x1, y1 );
  if( tmp1 == 0 )
    return true;
  x1 = p[d][0] - p[a][0];
  y1 = p[d][1] - p[a][1];
  ll tmp2 = cross( x0, y0, x1, y1);
  if( tmp2 == 0 )
    return true;
  return ( ( tmp2 > 0 && tmp1 < 0 ) || ( tmp1 > 0 && tmp2 < 0 ) );
}
bool touch( int a, int b, int c, int d )
{
  if( min( p[a][0], p[b][0] ) > max( p[c][0], p[d][0] ) ||
      max( p[a][0], p[b][0] ) < min( p[c][0], p[d][0] ) ||
      min( p[a][1], p[b][1] ) > max( p[c][1], p[d][1] ) ||
      max( p[a][1], p[b][1] ) < min( p[c][1], p[d][1] ) )
    return false;
  return oth( c, d, a, b ) && oth( a, b, c, d );
}
bool connect( int a, int b )
{
  int x = ( p[a][0] + p[b][0] ) / 2;
  int y = ( p[a][1] + p[b][1] ) / 2;
  ld sum(0);
  for( int i = 0; i < n; ++i )
    {
      int j = ( i + 1 ) % n;
      if( i != a && i != b && j != a && j != b )
	{
	  if( touch( a, b, i, j ) )
	    {
	      // cout << a << ' ' << b << ' ' << i << ' ' << j << endl;
	      return false;
	    }
	}
      else
	{
	  // if( i != a && i != b )
	  //   {
	  //     int x0 = p[i][0] - p[a][0], y0 = p[i][1] - p[a][1];
	  //     int x1 = p[i][0] - p[b][0], y1 = p[i][1] - p[b][1];
	  //     if( cross( x0, y0, x1, y1 ) == 0 &&
	  // 	  (ll)x0 * x1 + (ll)y0 * y1 < 0 )
	  // 	return false;
	  //   }
	  int x0 = p[b][0] - p[a][0];
	  int y0 = p[b][1] - p[a][1];
	  int x1 = p[j][0] - p[i][0];
	  int y1 = p[j][1] - p[i][1];
	  if( cross( x0, y0, x1, y1 ) == 0 )
	    {
	      if( b == i || a == j )
	  	x0 = -x0, y0 = -y0;
	      if( ( (ll)x0 * x1 > 0 || (ll)y0 * y1 > 0 ) )
	  	return false;
	    }
	}
      ld cr = cross( p[i][0] - x, p[i][1] - y,
		     p[i + 1][0] - x, p[i + 1][1] - y );
      ld tmp = asinl( min( (ld)1.0, fabsl(cr) /
			   ( dis( p[i][0], p[i][1], x, y ) * 
			     dis( p[i + 1][0], p[i + 1][1], x, y) ) ) );
      if( (ll)( p[i][0] - x ) * ( p[i + 1][0] - x ) + 
	  (ll)( p[i][1] - y ) * ( p[i + 1][1] - y ) < 0 )
	tmp = acosl( -1 ) - tmp;
      if( cr < 0 )
	sum -= tmp;
      else sum += tmp;
    }
  return fabsl(sum) > 3 * 2;
}
int cal( int v, int from, int to, int con )
{
  if( !vis[v][from][to][con] )
    {
      // assert( ( v + 1 == from || cnt[v][from] ) &&
      // 	      ( ( ( to + 1 ) % n == v ) || cnt[to][v] ) );
      vis[v][from][to][con] = true;
      int left = to - from + 2;
      // cout << v << ' ' << from << ' ' << to << ' ' << left << endl;
      if( left <= 3 )
	dp[v][from][to][con] = 1;
      else
	{
	  int t(0);
	  if( cnt[from][to] )
	    {
	      t = cal( from, from + 1, to, 1 );
	    }
	  if( con )
	    {
	      for( int i = from + 1; i != to; ++i)
		if( cnt[v][i] )
		  {
		    t = addM( t, mulM( cal( v, from, i, 0 ), 
				       cal( v, i, to, 1) ) );
		  }
	    }
	  dp[v][from][to][con] = t;
	}
    }
  // cout << from << ' ' << to << ' ' << con << ' ' << dp[from][to][con] << endl;
  return dp[v][from][to][con];
}
int cal2( int f, int t )
{
  if( !vis[0][f][t][0] )
    {
      vis[0][f][t][0] = true;
      int r(0);
      if( t - f + 1 <= 3 )
	r = 1;
      else
	for( int i = f + 1; i != t; ++i )
	  {
	    if( cnt[f][i] && cnt[i][t] )
	      r = addM( r, mulM( cal2( f, i ), cal2( i, t ) ) );
	  }
      // cout << f << ' ' << t << "!" << ' ' << r << endl;
      dp[0][f][t][0] = r;
    }
  return dp[0][f][t][0];
}
int main()
{
  scanf("%d", &n);
  for( int i = 0; i < n; ++i )
    {
      int x, y;
      scanf("%d%d", &x, &y);
      p[i][0] = x * 2, p[i][1] = y * 2;
    }
  p[n][0] = p[0][0], p[n][1] = p[0][1];
  for( int i = 0; i < n; ++i )
    for( int j = i + 1; j < n; ++j )
      if( abs( i - j ) == 1 || connect( i, j ) )
	{
	  cnt[i][j] = cnt[j][i] = true;
	  // cout << i << ' ' << j << endl;
	}
  // int ans = cal2( 0, n - 1 ); //cal( 0, 1, n - 1, 1);
  int ans = cal( 0, 1, n - 1, 1);
  printf("%d", ans);
  return 0;
}
