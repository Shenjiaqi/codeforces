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
const int K = N;
vector<int> d[N];
vector<pair<int,int> > edge;
int main()
{
  int n, kk;
  scanf("%d%d", &n, &kk);
  for( int i = 0 ; i < n; ++i )
    {
      int distance;
      scanf("%d", &distance);
      d[distance].push_back(i);
    }
  bool ok = true;
  if( d[0].size() != 1)
    ok = false;

  for( int i = 1, j = 0; ok && i < n; ++i )
    {
      if( ( i == 1 && kk < d[i].size() ) ||
	  ( i > 1 && (ll)( kk - 1 ) * d[ i - 1 ].size() < d[i].size() ) )
	{
	  ok = false;
	}
      else
	{
	  int l = 0;
	  for(int j = 0; l < d[i].size() &&
		j < d[ i - 1 ].size(); ++j )
	    {
	      for( int cnt = i == 1 ? -1 : 0; cnt < kk - 1 &&
		     l < d[i].size(); ++l, ++cnt )
		edge.push_back( make_pair( d[i - 1][j] + 1, d[i][l] + 1 ) );
	    }
	}
    }
  if( ok )
    {
      printf("%d\n", (int)edge.size() );
      for( int i = 0 ; i < edge.size(); ++i )
	printf("%d %d\n", edge[i].first, edge[i].second );
    }
  else printf("-1");
  return 0;
}
