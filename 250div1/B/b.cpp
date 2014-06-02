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
const int N = 1e5 + 7;
const int M = 1e5 + 7;
int a[N];
vector<int> p[N];
int fa[N];
int num[N];
bool in[N];
int gfa(int v )
{
  return fa[v] == v ? v : ( fa[v] = gfa( fa[v] ) );
}
void join( int a, int b )
{
  a = gfa(a);
  b = gfa(b);
  if( a != b )
    {
      fa[b] = a;
      num[a] += num[b];
    }
}
int main()
{
  int n, m;
  scanf("%d%d", &n, &m);
  set< pair<int,int>, greater<pair<int,int> > > sett;
  for( int i = 1; i <= n; ++ i)
    {
      scanf("%d", a + i);
      fa[i] = i;
      num[i] = 1;
      in[i] = true;
      sett.insert( make_pair( a[i], i) );
    }
  for( int i = 0; i < m; ++i )
    {
      int x, y;
      scanf("%d%d", &x, &y);
      p[x].push_back(y);
      p[y].push_back(x);
    }
  ll ans(0);
  for( ; !sett.empty(); )
    {
      int v = sett.begin()->second;
      int f = sett.begin()->first;
      in[v] = false;
      sett.erase( sett.begin() );
      for( int i = 0; i < p[v].size(); ++i )
	{
	  int t = p[v][i];
	  if( !in[t] )
	    {
	      int ft = gfa(t);
	      int fv = gfa(v);
	      if( ft != fv )
		{
		  ans += (ll)num[ft] * (ll)num[fv] * (ll)f;
		  join( ft, fv);
		}
	    }
	}
    }
  printf("%.6lf", (double)( (ld)ans * (ld)2.0/ (ld)( (ll)n * (ll)( n - 1 ) ) ) );
  return 0;
}
