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
int main()
{
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for( int i = 0, x = 1, y = 1, left = n * m; i < k; ++i )
    {
      int num = n * m / k;
      left -= num;
      if( i == k - 1 )
	num += left;
      printf("%d", num);
      for( int j = 0; j < num ; ++j )
	{
	  printf(" %d %d", x, y );
	  if( x & 1 )
	    ++y;
	  else
	    --y;
	  if( y < 1 )
	    y = 1, ++x;
	  else if( y > m )
	    y = m, ++x;
	}
      printf("\n");
    }
  return 0;
}
