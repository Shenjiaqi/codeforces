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
ll cal( ll col, ll row, ll colD, ll rowD )
{
  if( colD < 0 || rowD < 0 || colD >= col || rowD >= row )
    return -1;
  return ( col / ( 1 + colD ) ) * ( row / ( 1 + rowD ) );
}
int main()
{
  ios::sync_with_stdio( false);
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  ll ans = -1;
  for( int t = 0 ; t < 2 ; ++t )
    {
      for( int i = 1 ; i * i <= n ; ++i )
	if( 0 == ( n % i ) )
	  {
	    ans = max( ans, cal( n, m, i - 1, k - i + 1 ) );
	    ans = max( ans, cal( n, m, n / i - 1, k - n / i + 1 ) );
	  }
      ans = max( ans, cal( n, m, n - 1, k - ( n - 1 ) + 1 ) );
      swap( n, m);
    }
  cout << ans << endl;
  return 0;
}
