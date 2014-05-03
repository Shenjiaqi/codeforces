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
const int N = 5007;
char s[2][N];
int len[2];
int h[2][N];
int cnt[N];
const int mod = 1e9 + 7;
int addM( int a, int b)
{
  return ( (ll)a + (ll)b ) % mod;
}
int subM( int a, int b)
{
  return addM( ( (ll)a - (ll)b ) % mod, mod );
}
int mulM( int a, int b)
{
  return ( (ll)a * (ll)b ) % mod;
}
int hasH( int a, int b)
{
  return addM( mulM( a, 37), b);
}
ll pk( int a, int b )
{
  return (((ll)a) << 20 ) | b;
}
int main()
{
  scanf("%s%s", s[0], s[1]);
  unordered_map<ll,int> mapp;
  for( int i = 0; s[0][i] ; ++i )
    {
      for( int j = 1, k = 0; s[0][j + i - 1]; ++j )
	{
	  k = hasH( k, s[0][ j + i - 1] );
	  ++mapp[ pk( k, j) ];
	}
    }
  for( int i = 0; s[1][i]; ++i )
    {
      for( int j = 1, k = 0; s[1][ j + i - 1]; ++j )
	{
	  k = hasH( k, s[1][ j + i - 1 ] );
	  auto ite = mapp.find( pk( k, j) );
	  if( ite != mapp.end() && ite->second == 1 )
	    {
	      ite->second = -1;
	      ++cnt[ite->first & ( ( 1 << 20 ) - 1 )];
	    }
	  else if( ite != mapp.end() && ite->second == -1 )
	    {
	      ite->second = -2;
	      --cnt[ite->first & ( ( 1 << 20 ) - 1 ) ];
	    }
	}
    }
  for( int i = 0; i < N; ++i )
    if( cnt[i] )
      {
	printf("%d", i);
	return 0;
      }
  printf("-1");
  return 0;
}
