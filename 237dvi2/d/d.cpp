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
const int N = 1e6 + 7;
const int mod = 1e9 + 7;
char s[N];
int dp[2][5];
int addMod( int a, int b)
{
  return ( a + b ) % mod;
}
int main()
{
  scanf("%s", s);
  int f = 0, t = 1;
  if( s[0] == '*' )
    dp[f][0] = 1;
  else if( s[0] == '0' )
    dp[f][1] = 1;
  else if( s[0] == '1' )
    dp[f][2] = 1;
  else if( s[0] == '2' )
    {
      printf("0");
      return 0;
    }
  else // ?
    {
      dp[f][0] = dp[f][1] = dp[f][2] = 1;
    }
  for( int i = 1 ; s[i] != '\0'; ++i )
    {
      memset(dp[t], 0, sizeof(dp[t]) );
      if( s[i] == '*' )
	{
	  // dp[t][0] = dp[t][2] = dp[t][4] = dp[f][0];
	  dp[t][0] = addMod( dp[f][0], addMod( dp[f][2], dp[f][4] ) );
	}
      else if( s[i] == '0' )
	{
	  // dp[t][1] = dp[t][3] = dp[f][1];
	  dp[t][1] = addMod( dp[f][1], dp[f][3] );
	}
      else if( s[i] == '1' )
	{
	  // dp[t][0] = dp[f][3];
	  // dp[t][1] = dp[t][3] = dp[f][2];
	  dp[t][2] = addMod( dp[f][1], dp[f][3] );
	  dp[t][3] = dp[f][0];
	}
      else if( s[i] == '2' )
	{
	  // dp[t][0] = dp[f][4];
	  dp[t][4] = dp[f][0];
	}
      else // ?
	{
	  // dp[t][0] = dp[t][2] = dp[t][4] = dp[f][0];
	  // dp[t][1] = dp[t][3] = dp[f][1];
	  // dp[t][0] = addMod( dp[t][0], dp[f][3]);
	  // dp[t][1] = addMod( dp[t][1], dp[f][2]);
	  // dp[t][3] = addMod( dp[t][3], dp[f][2]);
	  // dp[t][0] = addMod( dp[t][0], dp[f][4]);
	  dp[t][0] = addMod( dp[f][0], addMod( dp[f][2], dp[f][4] ) );
	  dp[t][1] = addMod( dp[f][1], dp[f][3] );
	  dp[t][2] = addMod( dp[f][1], dp[f][3] );
	  dp[t][3] = dp[f][0];
	  dp[t][4] = dp[f][0];
	}
      swap(f, t);
    }

  // for( int j = 0; j < 4; ++j )
  //   cout << dp[f][j] <<' ' ;//cout << "!" << i <<endl;

  int ans = addMod(dp[f][0], dp[f][1]);
  ans = addMod( ans, dp[f][3] );
  printf("%d", ans);
  return 0;
}
