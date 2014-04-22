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
int n;
vector<int> p[N];
int s[N];
int dep[N];
int fa[N][20];
ppi mv3[N][3];
struct z
{
  ppi head[2], tail[2];
  int mv;
};
q[N];
void add( int f, int t )
{
  p[f].push_back(t);
}
void cal( int v, int parent )
{
  dep[v] = 1 + dep[parent];
  for( int i = 0, j = parent; i < 20; ++i )
    {
      fa[v][i] = j;
      j = fa[j][i];
    }
  for( auto i : p[v] )
    if( i != parent )
      cal( i, v );
}
void upd( int v, int val, int idx )
{
  if( mv3[v][0].first <= val )
    mv3[v][2] = mv3[v][1], mv3[v][1] = mv3[v][0], mv2[v][0] = ppi(val, idx);
  else if( mv3[v][1].first <= val )
    mv3[v][2] = mv3[v][1], mv3[v][1] = ppi(val, idx);
  else if( mv3[v][2] < val )
    mv3[v][2] = ppi( val, idx);
}
int dfs( int v, int from )
{
  int r = 0;
  for( auto i : p[v] )
    if( i != from )
      {
	int tmp = dfs( i, v );
	r = max( r, tmp);
	upd( v, tmp, i );
      }
  return r + 1;
}
ppi exc( int v, int from1, int from2 )
{
  if( mv3[v][0].second != from1 && mv3[v][0].second != from2 )
    return mv3[v][0];
  else if( mv3[v][1].second != from1 && mv3[v][1].second != from2 )
    return mv3[v][1];
  return mv3[v][2];
}
void dfs2( int v, int from, int val )
{
  upd( v, val, from);
  for( auto i : p[v] )
    if( i != from )
      dfs2( i, v, exc( v, i, 0).first + 1);
}
void merge( z & to, const z & from, int pt, int pf )
{
  to.val = max( to.val, max(
			    to.head[0].second == pf ?
			    to.head[1].first : to.head[0].first,
			    from.tail[0].second == pt ?
			    from.tail[1].first : from.tail[0].first)
		);
  for( int i = 0; i < 2; ++i )
    to.head[i] = from.head[i];
}
void cal( z & to, int v, int len)
{
  for( ; len; )
    {
      int i = __builtin_ctz(len);
      len ^= 1 << i;
      int pr = fa[v][0];
      merge( to, q[pr][i], v, pr );
      v = fa[v][i];
    }
}

void dfs3( int v)
{
  int pr = fa[v][0];
  q[v][1].head[0] = exc( pr, v, 0 );
  q[v][1].head[1] = exc( pr, v, q[v][1].head[0].second);
  q[v][1].tail[0] = exc( v, pr, 0);
  q[v][1].tail[1] = exc( v, pr, q[v][1].tail[0].second);
  q[v][1].val = 0;
  for( int j = 2, k = fa[v][0]; j < 20; ++j )
    {
      int pr = fa[k][0];
      for( int l = 0; l < 2; ++l )
	q[v][j].head[l] = q[pr][j - 1].head[l],
	  q[v][j].tail[l] = q[v][j - 1].tail[l];
      q[v][j].val = max( q[v][ j - 1 ].val,
			 max( pr == q[v][j - 1].head[0].second ?
			      q[v][j - 1].head[1].first :
			      q[v][j - 1].head[0].first, 
			      k == q[pr].tail[0].second ?
			      q[pr].tail[1].first :
			      q[pr].tail[0].first) );
      k = fa[k][j];
    }
  for( auto i : p[v] )
    if( i != fa[v][0] )
      dfs3( i );
}
int main()
{
  scanf("%d", &n);
  for( int i = 1; i < n; ++i )
    {
      int a, b;
      scanf("%d%d", &a, &b);
      add( a, b );
      add( b, a );
    }
  for( int i = 1; i <= n; ++i )
    mv3[i][0] = mv3[i][1] = mv3[i][2] = ppi( 0, -1 );
  cal(1, 1);
  dfs(1, 1);
  dfs2( 1, 1, -1);
  dfs3(1);
  int m;
  scanf("%d", &m);
  for( int i = 0; i < m; ++i )
    {
      int a, b;
      scanf("%d%d", &a, &b);
      if( dep[a] < dep[b] )
	swap( a, b);
      int c = a, d = b;
      for( int j = 20, det = dep[c] - dep[d]; j >= 0; --j)
	if( det & ( 1 << j ) )
	  c = fa[c][j];
      if( c != d )
	{
	  for( int j = 19; j >= 0; --j )
	    if( fa[c][j] != fa[d][j] )
	      c = fa[c][j], d = fa[d][j];
	  c = fa[c][0], d = fa[d][0];
	}
      int ans = 0;
      if( b == c )
	{
	  int len = dep[a] - dep[b];

	}
      printf("%d\n", ans);
    }
  return 0;
}
