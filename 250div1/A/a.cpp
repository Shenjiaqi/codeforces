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
typedef pair<ld,ld> ppld;
#define PB push_back
#define FIR first
#define SEC second
#define MP make_pair
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
const int N = 1007;
const int M = 2007;
int val[N];
vector<int> p[N];
bool in[N];
int main()
{
  int n, m;
  scanf("%d%d", &n, &m);
  set< pair<int,int>, greater< pair<int,int> > > sett;
  for( int i = 1; i <= n; ++i )
    {
      scanf("%d", val + i );
      in[i] = true;
      sett.insert( make_pair( val[i], i ) );
    }
  for( int i = 0; i < m; ++i )
    {
      int a, b;
      scanf("%d%d", &a, &b);
      p[b].push_back(a);
      p[a].push_back(b);
    }
  int ans(0);
  for( ; !sett.empty(); )
    {
      int v = sett.begin()->second;
      sett.erase( sett.begin() );
      in[v] = false;
      for( int i = 0; i < p[v].size(); ++i )
	{
	  int t = p[v][i];
	  if( in[t] )
	    {
	      ans += val[t];
	    }
	}
    }
  printf("%d", ans);
  return 0;
}
