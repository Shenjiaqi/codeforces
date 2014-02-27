#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1e6 + 7;
const ll mod = 1e9 + 7;
int p[N];
int count[N];
int rCount[N];
int perCnt[N];
int invCnt[N];
void add(int v, int val,int array[])
{
  for( ; v < N ; v += (v & ( -v ) ) )
    array[v] += val;
}
int que(int v, int array[])
{
  int r = 0 ;
  for( ; v > 0 ; v ^= ( v & (-v) ) )
    r += array[v];
  return r;
}
inline int mulMod(ll a, ll b)
{
  return ( a * b ) % mod;
}
inline int addMod( ll a, ll b)
{
  return ( a + b ) % mod;
}
int main()
{
  int n;
  scanf("%d", &n);
  perCnt[0] = 1;
  invCnt[0] = 0;
  for( int i = 0 ; i < n ; ++i )
    {
      scanf("%d", p + i );
      add( p[i], 1, count);
      perCnt[ i + 1 ] = mulMod( perCnt[i], i + 1 );
      int tmp1 = i + 1;
      int tmp2 = i;
      if( i & 1 )
	tmp1 >>= 1;
      else tmp2 >>= 1;
      invCnt[ i + 1 ] = addMod( mulMod( invCnt[i], i + 1 ), 
				mulMod( mulMod( tmp1, 
						tmp2 ), 
					perCnt[i] ) );

    }
  int ans = 0;
  int sumPer = 0;
  for( int i = 0 ; i < n ; ++i )
    {
      add( p[i], -1, count);
      int numOfLess = que( p[i], count );
      if( numOfLess > 0 )
	{
	  int numOfGrt = n - i - 1 - numOfLess;
	  ans = addMod( ans, mulMod( sumPer, 
				     mulMod( numOfLess, 
					     perCnt[ n - i - 1 ] ) ) );
	  int tmp1 = numOfLess;
	  int tmp2 = numOfLess - 1;
	  if( tmp2 & 1 )
	    tmp1 >>= 1;
	  else tmp2 >>= 1;
	  ans = addMod( ans, mulMod( perCnt[ n - i - 1], 
				     mulMod( tmp1, tmp2 ) ) );
// 	  cout << i << ' ' << ans << ' ' << tmp1 << ' ' << numOfLess << endl;
	  ans = addMod( ans, mulMod( numOfLess, invCnt[ n - i - 1 ] ) );
	  sumPer = addMod( sumPer, numOfLess );
	}
      add( p[i], 1, rCount);
    }
  ans = addMod( ans, sumPer );
  printf("%d", ans);
  return 0;
}
