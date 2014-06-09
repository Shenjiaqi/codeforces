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
  int n, v;
  scanf("%d%d", &n, &v);
  vector<int> ans;
  for( int i = 0; i < n ; ++i )
    {
      int m;
      scanf("%d", &m);
      bool ok = false;
      for( int j = 0 ; j < m; ++j )
	{
	  int s;
	  scanf("%d", &s);
	  if( s < v )
	    ok = true;
	}
      if( ok )
	ans.push_back( i + 1 );
    }
  printf("%d\n", (int)ans.size() );
  for( auto i : ans )
    printf("%d ", i );
  return 0;
}
