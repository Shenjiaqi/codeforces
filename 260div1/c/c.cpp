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
//#include <unordered_set>
//#include <unordered_map>
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
const int N = 300007;
vector<int> p[N];
int fa[N];
int minOutLen[N];
int dia[N];
int out[N][2][2];
void add( int a, int b)
{
  p[a].push_back(b);
  p[b].push_back(a);
}
int qFa(int a)
{
  return a == fa[a] ? a : fa[a] = qFa( fa[a] );
}
void join(int a, int b)
{
  a = qFa(a), b = qFa(b);
  if( a != b )
    fa[b] = a;
}
void merge(int a, int b)
{
  a = qFa(a), b = qFa(b);
  if( a != b )
    {
      fa[b] = a;
      int oA = minOutLen[a], oB = minOutLen[b];
      dia[a] = max( max( dia[a], dia[b] ), oA + oB + 1 );
      minOutLen[a] = min( max( oA, oB + 1 ), max( oB, oA + 1 ) );
    }
}
int que(int a)
{
  a = qFa(a);
  return dia[a];
}
void upd( int v, int l, int f )
{
  if( l >= out[v][0][0] )
    {
      out[v][1][0] = out[v][0][0];
      out[v][1][1] = out[v][0][1];
      out[v][0][0] = l;
      out[v][0][1] = f;
    }
  else if( l > out[v][1][0] )
    {
      out[v][1][0] = l;
      out[v][1][1] = f;
    }
}
int dfs( int v, int f )
{
  for( auto i : p[v] )
    {
      if( i != f )
	{
	  int l = dfs( i, v);
	  upd( v, l, i);
	}
    }
  return out[v][0][0] + 1;
}
int dfs2( int v, int f, int val)
{
  upd( v, val, f);
  for( auto i : p[v] )
    if( f != i )
      {
	dfs2( i, v, 1 + ( out[v][0][1] == i ? out[v][1][0] : out[v][0][0] ) );
      }
}
int main()
{
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  for( int i = 1 ; i <= n ; ++i )
    {
      fa[i] = i;
      dia[i] = 0;
      minOutLen[i] = N;
    }
  for( int i = 0 ; i < m ; ++i )
    {
      int a, b;
      scanf("%d%d", &a, &b);
      add( a, b);
      join( a, b);
    }
  for( int i = 1 ; i <= n ; ++i )
    if( qFa(i) == i )
      {
	dfs(i, 0);
	dfs2(i, 0, 0);
      }
  for( int i = 1 ; i <= n ; ++i )
    {
      int tFa = qFa(i);
      dia[tFa] = max( dia[tFa], out[i][0][0] + out[i][1][0] );
      minOutLen[tFa] = min( minOutLen[tFa], out[i][0][0] );
    }
  for( int i = 0 ; i < q ; ++i )
    {
      int t;
      scanf("%d", &t);
      if( t == 2 )
	{
	  int a, b;
	  scanf("%d%d", &a, &b);
	  // add(a, b);
	  merge( a, b);
	}
      else
	{
	  int a;
	  scanf("%d", &a);
	  printf("%d\n", que(a) );
	}
    }
  return 0;
}
