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
vector<int> digitOfN;
bool vis[1<<18][101];
ll dp[1<<18][101];
int m;
ll que(int usd, ll val, ll mul)
{
  int left = ( ( 1 << digitOfN.size() ) - 1 ) ^ usd;
  ll need = ( m - val ) % m;
  if( left == 0 )
    return val == 0 ? 1 : 0;
  if( !vis[left][need] )
    {
      vis[left][need] = true;
      ll r(0);
      for( int i = 0, pre = -1 ; ( 1 << i ) <= left; ++i )
	if( ( ( 1 << i ) & left )  &&  digitOfN[i] != pre)
	  {
	    r += que( usd | ( 1 << i ), ( val + digitOfN[i] * mul ) % m,
		      mul / 10LL );
	    pre = digitOfN[i];
	  }
      dp[left][need] = r;
    }
  return dp[left][need];
}
int main()
{
  ll n;
  cin >> n >> m;
  ll mul = 1;
  for( ll i = n; i ; i /= 10 )
    {
      digitOfN.push_back(i % 10);
      mul *= 10LL;
    }
  sort(digitOfN.begin(), digitOfN.end());
  mul /= 10LL;
  ll ans = que(0, 0, mul);
  if( digitOfN[0] == 0 )
    {
      ans -= que(1, 0, mul);
    }
  cout << ans;
  return 0;
}
