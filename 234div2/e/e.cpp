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
ll sum;
int a[N];
set<int> info[17];
int n, m;
int que(int idx, int pos, int dir)
{
  typeof( info[idx].begin() ) ite;
  if( dir == 0 )
    {
      //left
      ite = info[idx].upper_bound(pos);
      --ite;
      return pos - *ite ;
    }
  ite = info[idx].lower_bound(pos);
  return *ite - pos;
}
void setV(int idx, int pos, int val)
{
  if( val ==  0 )
    // 1 -> 0; assert( info[idx].find(pos) == info[idx].end() );
    info[idx].insert(pos);
  else info[idx].erase(pos); 
  // assert( info[idx].find(pos) != info[idx].end() );
}
ll cal(ll v)
{
  return ( v + 1LL ) * v / 2LL;
}
void change(int pos, int val)
{
  int oldVal = a[pos];
  a[pos] = val;
  int chg = oldVal ^ val;
  for( int i = 0 ; ( 1 << i ) <= chg; ++i )
    if( chg & ( 1 << i ) )
    {
      int oldSumLeft = que(i, pos - 1, 0);
      int oldSumRight = que(i, pos + 1, 1);
      ll det = cal( oldSumLeft + oldSumRight + 1 ) << i;
      det -= ( cal( oldSumLeft ) + cal( oldSumRight ) ) << i;
      if( val & ( 1 << i ) )
	{// 0 -> 1
	  setV(i, pos, 1);
	  sum += det;
	}
      else
	{// 1 - > 0
	  setV(i, pos, 0);
	  sum -= det;
	}
    }
}
int main()
{
  scanf("%d%d", &n, &m);
  for( int i = 0 ; i < 17 ; ++i )
    for( int j = -1; j <= n ; ++j )
      info[i].insert(j);
  for( int i = 0 ; i < n ; ++i )
    {
      int ai;
      scanf("%d", &ai);
      change(i, ai);
    }
  for( int i = 0 ; i < m ; ++i )
    {
      int pi, vi;
      scanf("%d%d", &pi, &vi);
      change(pi - 1, vi);
      printf("%I64d\n", sum);
    }
  return 0;
}
