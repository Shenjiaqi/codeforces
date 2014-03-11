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
int n, m;
int l, r, p;
ll disSqu( ll a, ll b)
{
  return a * a + b * b;
}
int sub( int a, int b)
{
  return ( ( (a - b ) % p ) + p ) % p;
}
int add( int a, int b)
{
  return ( a + b ) % p;
}
int mul( ll a, ll b)
{
  return ( a * b ) % p;
}
int que( int lim )
{
  int ans = 0;
  if( lim > 0 )
    {
      int r = 0;
      for( int i = 1, lI = m; i <= n && lI >= 0; ++i )
	{
	  for( ; lI >=0 && disSqu( lI, i ) > (ll) lim * lim; --lI)
	    ;
	  if( lI < 0 )
	    break;
	  int all = (ll)( lI + 1 ) * (ll)lI / 2LL ;
	  int cnt = lI;
	  int disCnt = 0;
	  for( int j = i; j <= lI; j += i )
	    {
	      cnt = sub( cnt, 1 );
	      disCnt = add( disCnt, m + 1 - j );
	      // disCnt = add( disCnt, j );
	    }
	  if( i == 1 )
	    r = add( r, mul( all, n + 1 - i )  );
	  else
	    r = add( r, mul( sub( mul( cnt, m + 1 ), disCnt ), n + 1 - i ) );
	    // r = add( r, mul( mul( cnt, m + 1 ), n + 1 - i ) );
	  // cout << i << ' ' << lI << ' ' << disCnt << ' ' << r << ' ' << 
	  //   cnt <<endl;	
	  // cout << r << endl;
	}
      r = mul( r, 2 );
      r = add( r, add( mul( n + 1, m ), mul( m + 1, n ) ) );
      ans = r;
    }
  return ans;
}
int main()
{
  scanf("%d%d%d%d%d", &n, &m, &l, &r, &p);
  int ans = que(r);
  if( l > 1 )
    {
      sub( ans, que( l - 1 ) );
    }
  cout << ans;
  return 0;
}
