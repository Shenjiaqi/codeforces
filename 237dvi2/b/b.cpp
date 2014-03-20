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
int main()
{
  ld a, d;
  cin >> a >> d;
  ll A = a * 1e4 + .5;
  ll D = d * 1e4 + .5;
  int n;
  scanf("%d", &n);
  ll posX, posY, len;
  len = posX = posY = 0;
  for( int i = 0; i < n; ++i )
    {
      len = ( len + D ) % ( 4LL * A );
      if( len <= A )
	{
	  posX = len;
	  posY = 0;
	}
      else if( len <= 2 * A )
	{
	  posX = A;
	  posY = len - A;
	}
      else if( len <= 3 * A )
	{
	  posX = 3LL * A - len;
	  posY = A;
	}
      else
	{
	  posX = 0;
	  posY = 4 * A - len;
	}
      printf("%.4f %.4f\n", (float)posX / 1.0e4, (float)posY / 1.0e4 );
    }
  return 0;
}
