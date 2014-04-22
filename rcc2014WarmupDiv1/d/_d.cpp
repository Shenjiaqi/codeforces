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
const int N = 1e5 + 7;
const int M = 1e5 + 7;
const int inf = 1e9;
int n, m;
vector<int> p[N];
ppi mx[N][3];
int query[M][3];
int depth[N];
stack<ppi> q[N][4];
int seg[N * 4][2];
int fa[N][17];
void add( int a, int b)
{
  p[a].push_back(b);
  p[b].push_back(a);
}
int exc( int v, int from )
{
  return mx[v][0].second == from ? mx[v][1].first :
    mx[v][0].first;
}
int exc( int v, int from1, int from2 )
{
  if( mx[v][0].second != from1 && mx[v][0].second != from2 )
    return mx[v][0].first;
  return ( mx[v][1].second != from1 && mx[v][1].second != from2 ) ?
    mx[v][1].first : mx[v][2].first;
}
void upd( int v, int val, int idx)
{
  if( val >= mx[v][0].first )
    mx[v][2] = mx[v][1], mx[v][1] = mx[v][0], mx[v][0] = ppi( val, idx);
  else if( val >= mx[v][1].first )
    mx[v][2] = mx[v][1], mx[v][1] = ppi( val, idx);
  else if( val > mx[v][2].first )
    mx[v][2] = ppi( val, idx );
}
int cal(int v, int pre)
{
  depth[v] = 1 + depth[pre];
  for( int i = 0, j = pre; i < 17; ++i )
    {
      fa[v][i] = j;
      j = fa[j][i];
    }
  int r = 0;
  FR( i, p[v] )
    if( *i != pre )
      {
	int tmp = cal( *i, v);
	upd( v, tmp, *i);
	r = max( r, tmp);
      }
  return r + 1;
}
int up( int v, int len )
{
  for( int i = 0 ; len; len >>= 1, ++i )
    if( len & 1 )
      v = fa[v][i];
  return v;
}
int st( int val, int pos, int type, int idx, int a, int b)
{
  if( pos < a || pos > b )
    ;
  else if( a < b )
    {
      int mid = ( a + b ) / 2;
      seg[idx][type] = max( st( val, pos, type, idx * 2, a, mid), 
			    st( val, pos, type, idx * 2 + 1, mid + 1, b ) );
    }
  else
    seg[idx][type] = val;
  return seg[idx][type];
}
int qu( int from, int to, int idx, int type, int a, int b)
{
  if( from > to )
    return -inf;
  if( from > b || to < a )
    return -inf;
  if( from <= a && to >= b )
    return seg[idx][type];
  int mid = ( a + b ) / 2;
  return max( qu( from, to, idx * 2, type, a, mid ),
	      qu( from, to, idx * 2 + 1, type, mid + 1, b ) );
}
void dfs( int v, int val, int from )
{
  ++val;
  for( ; !q[v][0].empty(); )
    {
      int t = q[v][0].top().second;
      int i = q[v][0].top().first;
      q[v][0].pop();
      if( i < depth[v] )
	{
	  //int qu( int from, int to, int idx, int type, int a, int b)
	  int r = qu( i, depth[v] - 1, 1, 0, 1, n);
	  // cout << t << ' ' << query[t][2] << ' ' << depth[v] << ' ' 
	  //      << i.first << ' ' << r << endl;
	  // cout << query[t][2] << ' ' << v << ' ' << from << ' ' << i->first << ' '  << r << endl;
	  query[t][2] = max( query[t][2], r + depth[v] );
	}
    }
  for( ; !q[v][1].empty(); )
    {
      int t = q[v][1].top().second;
      int i = q[v][1].top().first;
      q[v][1].pop();
      int d = depth[i] + 1;
      if( d < depth[v] )
	{
	  //int r = que( d, 1 ) - d + 1;
	  int r = qu( d, depth[v] - 1, 1, 1, 1, n) - d + 1;
	  query[t][2] = max( query[t][2], r);
	}
    }
  for( ; !q[v][2].empty(); )
    {
      int t = q[v][2].top().second;
      int i = q[v][2].top().first;
      q[v][2].pop();
      query[t][2] = max( query[t][2], val + i);
    }
  for( ; !q[v][3].empty(); )
    {
      int t = q[v][3].top().second;
      int i = q[v][3].top().first;
      q[v][3].pop();
      int d = depth[i];
      if( d < depth[v] )
	{
	  //int r = que( d, 1) - d + 1 + depth[ query[t][1] ] - d + 1;
	  //int qu( int from, int to, int idx, int type, int a, int b)
	  int r = qu( d, depth[v] - 1, 1, 1, 1, n) - d + 
	    1 + depth[ query[t][1] ] - d + 1;
	  query[t][2] = max( query[t][2], r);
	}
    }
  // int tmp = qu( int from, int to, int idx, int type, int a, int b)
  FR( i, p[v] )
    if( *i != from )
      {
	int tmp = exc( v, *i );
	// if( v == 11 ) 
	//   cout << tmp << endl;
	//int st( int val, int pos, int type, int idx, int a, int b)
	st( tmp + depth[v], depth[v], 1, 1, 1, n);
	st( tmp - depth[v], depth[v], 0, 1, 1, n );
	dfs( *i, max( tmp, val) , v );
      }
}
int main()
{
  scanf("%d", &n);
  for( int i = 1; i < n; ++i )
    {
      int a, b;
      scanf("%d%d", &a, &b);
      add( a, b);
    }
  cal(1, 1);
  for( int i = 1; i < N; ++i )
    seg[i][0] = seg[i][1] = -inf;
  scanf("%d", &m);
  for( int i = 0; i < m; ++i )
    {
      int a, b;
      scanf("%d%d", &a, &b);
      if( depth[a] < depth[b] )
	swap( a, b);
      query[i][0] = a, query[i][1] = b;
      int c = a, d = b, len = depth[c] - depth[d];
      c = up( a, len );
      if( c == d )
	{
	  query[i][2] = max( exc( b, up( a, len - 1 ) ),
			     exc( a, fa[a][0] ) );
	  q[b][2].push( ppi( 0, i ) );
	  if( len > 1 )
	    {
	      int e = up( a, len / 2 );
	      q[a][0].push( ppi( depth[e], i ) );
	      q[e][1].push( ppi( b, i ) );
	    }
	}
      else
	{
	  for( int j = 16; j >= 0; --j )
	    if( fa[c][j] != fa[d][j] )
	      c = fa[c][j], d = fa[d][j];
	  c = fa[c][0], d = fa[d][0];
	  query[i][2] = max( exc( a, fa[a][0] ),
			     exc( b, fa[b][0] ) );
	  query[i][2] = max( query[i][2], 
			     exc(c, up( a, depth[a] - depth[c] - 1 ),
				 up( b, depth[b] - depth[c] - 1 ) ) + 
			     depth[b] - depth[c] );
	  q[c][2].push( ppi( depth[b] - depth[c], i ) );
	  int len = depth[a] + depth[b] - 2 * depth[c] ;
	  int e = up( a, len / 2 );
	  if( e != c )
	    {
	      q[a][0].push( ppi( depth[e], i ) );
	      q[b][0].push( ppi( depth[c] + 1, i ) );
	      q[e][3].push( ppi( up( a, depth[a] - depth[c] - 1 ), i ) );
	    }
	  else
	    {
	      q[a][0].push( ppi( depth[c] + 1, i ) );
	      q[b][0].push( ppi( depth[c] + 1, i ) );
	    }
	}
    }
  dfs( 1, -1, 1);
  for( int i = 0; i < m; ++i )
    printf("%d\n", query[i][2] );
  return 0;
}
