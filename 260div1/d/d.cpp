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
#include <unordered_map>
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
const int SN = 333;
int p[N];
int st[SN][N];
int idx[SN];
int n;
inline int bg( int s )
{
  return s * SN;
}
inline int ed( int s )
{
  s = ( s + 1 ) * SN;
  --s;
  return min( s, n - 1);
}
inline int getNum( int s, int pos )
{
  int bs = bg(s), es = ed(s);
  pos -= bs;
  pos += idx[s];
  if( pos > es )
      pos = pos - es - 1 + bs;
  return p[pos];
}
inline int que(int s, int f, int t, int k)
{
  // int st = bg(s), et = ed(s);
  int r(0);
  if( st[s][k] > 0 )
    {
      if( t - f + 1 < SN / 2 )
	{
	  for( int i = f ; i <= t ; ++i )
	    if( getNum(s, i) == k )
	      ++r;
	}
      else
	{
	  r = st[s][k];
	  for( int i = bg(s) ; i < f ; ++i )
	    if( getNum(s, i) == k )
	      --r;
	  for( int i = ed(s) ; i > t ; --i )
	    if( getNum(s, i) == k )
	      --r;
	}
    }
  return r;
}
inline int del( int s, int pos )
{
  int v = getNum(s, pos);
  --st[s][v];
  return v;
}
inline void setNum(int s, int pos, int v)
{
  int bs = bg(s), es = ed(s);
  pos = pos - bs + idx[s];
  if( pos > es )
    pos = pos - es - 1 + bs;
  p[pos] = v;
}
inline void add( int s, int pos, int v)
{
  ++st[s][v];
  setNum(s, pos, v);
}
inline void rotate(int s, int l, int r )
{
  int bs = bg(s), es = ed(s);
  if( l == bs && r == es )
    {
      --idx[s];
      if( idx[s] < bs)
	idx[s] = es;
    }
  else
    {
      int i = r - bs + idx[s];
      if( i > es )
	i = i - es - 1 + bs;
      for( int j = 0 ; j < r - l ; ++j )
	{
	  int ii = i - 1;
	  if( ii < bs )
	    ii = es;
	  swap( p[i], p[ii] );
	  i = ii;
	}
    }
}
inline void decode( int &l, int &r, int &k, int lastAns)
{
  l = ( ( l + lastAns - 1 ) % n ) + 1;
  r = ( ( r + lastAns - 1 ) % n ) + 1;
  k = ( ( k + lastAns - 1 ) % n ) + 1;
  if( l > r )
    swap( l, r);
}
int main()
{
  scanf("%d", &n);
  int m = ( n + SN - 1 ) / SN;
  for( int i = 0 ; i < m ; ++i )
    {
      idx[i] = bg(i);
      for( int j = 0 ; j < SN && idx[i] + j < n ; ++j )
	{
	  scanf("%d", p + idx[i] + j );
	  ++st[i][ p[ idx[i] + j ] ];
	}
    }
  int q;
  scanf("%d", &q);
  for( int i = 0, lastAns = 0 ; i < q ; ++i )
    {
      int t, l, r, k = 0;
      scanf("%d%d%d", &t, &l, &r);
      if( t == 2 )
	scanf("%d", &k);
      decode( l, r, k, lastAns );
      --l, --r;
      int iL = l / SN, iR = r / SN;
      if( t == 1 )
	{
	  if( iL == iR )
	    {
	      rotate(iL, l, r);
	    }
	  else
	    {
	      int v = del( iR, r );
	      int ad = del( iL, ed(iL) );
	      add( iL, ed(iL), v);
	      rotate( iL, l, ed(iL) );
	      for( int i = iL + 1; i < iR ; ++i )
		{
		  v = del(i, ed(i) );
		  add(i, ed(i), ad);
		  rotate(i, bg(i), ed(i) );
		  ad = v;
		}
	      add( iR, r, ad);
	      rotate( iR, bg(iR), r);
	    }
	}
      else
	{
	  int ans(0);
	  if( iL == iR )
	    {
	      ans = que(iL, l, r, k);
	    }
	  else
	    {
	      ans = que(iL, l, ed(iL), k ) + que(iR, bg(iR), r, k);
	      for( int i = iL + 1 ; i < iR ; ++i )
		ans += que( i, bg(i), ed(i), k );
	    }
	  printf("%d\n", ans);
	  lastAns = ans;
	}
    }
  return 0;
}
