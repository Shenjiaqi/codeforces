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
char s[N];
bool test( int obs )
{
  int pos = 0;
  int rMax = -N, lMax = N;
  for( int i = 0 ; s[i] != '\0' ; ++i )
    {
      rMax = max( rMax, pos);
      lMax = min( lMax, pos);
      int add = s[i] == 'L' ? -1 : 1;
      if( pos + add != obs )
	pos += add;
    }
  return pos < lMax || pos > rMax;
}
int main()
{
  scanf("%s", s);
  if( test( N + 1 ) )
    printf("1");
  else
    {
      int ans(0);
      int rObs = 0;
      for( int f = 1, t = N ; f <= t; )
	{
	  int mid = ( f + t ) >> 1;
	  if( test( mid ) )
	    rObs = mid, f = mid + 1;
	  else t = mid - 1;
	}
      ans += rObs;
      int lObs = 0;
      for( int f = -1, t = -N; f >= t; )
	{
	  int mid = ( f + t ) / 2;
	  if( test( mid ) )
	    lObs = mid, f = mid - 1;
	  else t = mid + 1;
	}
      ans += abs(lObs);
      printf("%d", ans);
    }
  return 0;
}
