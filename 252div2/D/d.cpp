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
const int N = 3007;
int p[N];
int q[N][2];
bool vis[N];
int fa[N];
int que( int a )
{
  return a == fa[a] ? a : que( fa[a] );
}
void join( int a, int b )
{
  a = que(a);
  b = que(b);
  if( a != b )
    fa[b] = a;
}
void dfs( int v )
{
  if( !vis[v] )
    {
      vis[v] = true;
      join( v, q[v][1] );
      dfs( q[v][1] );
    }
}
int main()
{
  int n, m;
  scanf("%d", &n);
  for( int i = 0 ; i < n ; ++i )
    scanf("%d", p + i + 1);
  scanf("%d", &m);
  for( int i = 1 ; i <= n ; ++i )
    {
      q[ p[i] ][1] = i;
      q[i][0] = p[i];
      fa[i] = i;
    }
  int cntCir(0);
  for( int i = 1; i <= n ; ++i )
    if( !vis[i] )
      {
	dfs(i);
	++cntCir;
      }
  int dis = n - cntCir;
  vector<ppi> ans;
  // if( n == 456 )
  //   for( int i = 9 ; ; )
  //     {
  // 	cout << i << ' ' ;
  // 	i = q[i][1];
  // 	if( i == 9 )
  // 	  {
  // 	    cout << endl;
  // 	    break;
  // 	  }
      // }
  // for( int i = 1, j = 2; dis > m; --dis )
  //   {
  //     for( ; que(i) != que(j); )
  // 	{
  // 	  ++j;
  // 	  if( j > n )
  // 	    ++i, j = i + 1;
  // 	}
  //     int tmp = que(i);
  //     ans.push_back( make_pair(i, j ) );
  //     swap( q[i][1], q[j][1]);
  //     q[ q[i][1] ][0] = i;
  //     q[ q[j][1] ][0] = j;
  //     vector<int> lst;
  //     for( int k = 1; k <= n; ++k )
  // 	if( que(k) == tmp )
  // 	  {
  // 	    lst.push_back(k);
  // 	  }
  //     for( auto k : lst )
  // 	{
  // 	  fa[k] = k;
  // 	}
  //     memset( vis, 0 ,sizeof(vis) );
  //     dfs(i);
  //     dfs(j);
  //     ++j;
  //     if( j > n )
  // 	++i, j = i + 1;
  //   }
  // cout << dis << ' ' << m << endl;
  // if( n == 1578 )
  //   for( int i = 1; ; )
  //     {
  // 	cout << i << ' ' << ' ' << q[i][0] << endl;;
  // 	i = q[i][0];
  // 	if( i == 1 )
  // 	  {
  // 	    cout << endl;
  // 	    return 0;
  // 	  }
  //     }
  
  for( ; dis > m; --dis )
    {
      int i = 1;
      for( ; q[i][0] == i; ++i )
	;
      vector<int> lst;
      for( int k = i + 1; k <= n; ++k )
	if( que( q[k][0] ) == que( q[i][0] ) )
	  {
	    lst.push_back( k );
	  }
      int j = lst[0];
      ans.push_back( make_pair( i, j) );
      int a = q[i][0];
      int b = q[j][0];
      // cout << a << ' ' << b << ' ' << i << ' ' << j << endl;
      swap( q[a][1], q[b][1] );
      swap( q[i][0], q[j][0] );
      // memset( vis, 0, sizeof( vis )) ;
      lst.push_back(i);
      for( auto k : lst )
	{
	  fa[ q[k][0] ] = q[k][0];
	  // cout << k << ' ' << q[k][0] << endl;
	  vis[ q[k][0] ] = false;
	}
      dfs(a);
      dfs(b);
      // for( int i = 1; i <= n; ++i )
      // 	cout << i << ' ' << q[i][0] << ' ' << que( q[i][0] ) << endl;
    }
  for( int i = 1, j = 2; dis < m; ++dis)
    {
      for( ; que(i) == que(j); )
	{
	  ++j;
	  if( j > n )
	    ++i, j = i + 1;
	}
      ans.push_back( make_pair( i, j) );
      join( i, j);
      ++j;
      if( j > n )
	++i, j = i + 1;
    }
  printf("%d\n", (int)ans.size() );
  for( auto i : ans )
    printf("%d %d ", i.first, i.second );
  return 0;
}
