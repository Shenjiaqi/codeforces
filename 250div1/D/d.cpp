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

const int N = 1e5 + 7;
const int M = 1e5 + 7;
ll p[ N * 4 ];
vector<int> md[ N * 4 ];
int a[N];
ll init( int i, int from, int to )
{
  if( from == to )
    p[i] = a[from];
  else
    {
      int mid = ( from + to ) / 2;
      p[i] = init( i * 2, from, mid ) +
	init( i * 2 + 1, mid + 1, to );
    }
}
ll que( int i, int from, int to, int x, int y )
{
  if( to < x || from > y )
    return 0;
  if( x <= from && to <= y )
    return p[i];
  int mid = ( from + to ) / 2;
  return que( i * 2, from, mid + 1, x, y) + 
    que( i * 2 + 1, mid, to, x, y);
}
void am( int i, int from, int to, int x, int y, int x )
{
  if( to < x || from > y )
    return ;
  if( from <= x && to <= y )
    {
      md.push_back(x);
      p[i] %= x;
    }
}
int main()
{
  int n, m;
  ios::sync_with_stdio( false );
  scanf("%d%d", &n, &m);
  for( int i = 1; i <= n; ++i )
    {
      scanf("%d", a + i);
    }
  init( 1, 1, n );
  for( int i = 0; i < m; ++i )
    {
      int type;
      scanf("%d", &type );
      if( type == 1 )
	{
	  int l, r;
	  scanf("%d%d", &l, &r);
	  cout << que( 1, 1, n, l, r ) << endl;;
	}
      else if( type == 2 )
	{
	  int l, r, x;
	  scanf("%d%d%d", &l, &r, &x);
	  am( 1, 1, n, l, r, x);
	}
      else
	{
	  int k, x;
	  mdf( 1, 1, n, k, k, x );
	}
    }
  return 0;
}
