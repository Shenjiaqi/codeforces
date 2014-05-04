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
const int N = 5007;
struct e
{
  int gt[ 'z' - 'a' + 1 ];
  int pre;
  int cnt;
  int len;
};
e p[2][N * 2];
int lst[2], poi[2];
char s[2][N];
void add( int id, int v)
{
  int n = ++lst[id];
  memset( &p[id][n], 0, sizeof(p[id][n]) );
  p[id][n].cnt = 1;
  int i = poi[id];
  p[id][n].len = 1 + p[id][i].len;
  poi[id] = n;
  for( ; i >= 0 && p[id][i].gt[v] == 0; i = p[id][i].pre )
    {
      p[id][i].gt[v] = n;
    }
  if( i < 0 )
    {
      p[id][n].pre = 0;
    }
  else
    {
      int j = p[id][i].gt[v];
      if( 1 + p[id][i].len == p[id][j].len )
	{
	  ++p[id][j].cnt;
	  p[id][n].pre = j;
	}
      else
	{
	  int m = ++lst[id];
	  memcpy( &p[id][m], &p[id][j], sizeof( p[id][m] ) );
	  p[id][m].len = 1 + p[id][i].len;
	  ++p[id][m].cnt;
	  p[id][n].pre = p[id][j].pre = m;
	  for( ; i >= 0 && p[id][i].gt[v] == j; i = p[id][i].pre )
	    p[id][i].gt[v] = m;
	}
    }
}
int dfs( int v1, int v2, int lim, int len, int c1, int c2)
{
  if( lim > 0 && lim < len )
    return lim;
  c1 = min( c1, p[0][v1].cnt);
  c2 = min( c2, p[1][v2].cnt);
  if( c1 == 1 && c2 == 1 )
    return len;
  for( int i = 0; i <= 'z' - 'a'; ++i )
    if( p[0][v1].gt[i] && p[1][v2].gt[i] )
      lim = dfs( p[0][v1].gt[i], p[1][v2].gt[i], lim, len + 1,
		 c1, c2);
  return lim;
}
int main()
{
  scanf("%s%s", s[0], s[1]);
  p[1][0].pre = p[0][0].pre = -1;
  p[1][0].cnt = p[0][0].cnt = N;
  p[1][0].len = p[1][0].len = 0;
  for( int i = 0; i < 2; ++i )
    {
      for( int j = 0 ; s[i][j]; ++j )
	{
	  add( i, s[i][j] - 'a');
	}
    }
  int ans = dfs( 0, 0, -1, 0, 1e9, 1e9);
  printf("%d", ans);
//   cout << p[0][0].gt[ 'p' - 'a' ] << endl;
  return 0;
}
