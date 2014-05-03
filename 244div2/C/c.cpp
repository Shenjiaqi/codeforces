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
const int M = 3e5 + 7;
int cost[N];
vector<int> p[N];
bool vis[N];
bool in[N];
int tag[N], ti;
int mi[N];
stack<int> stk;
int n, m, res;
ll costSum;
int ans[N][2];
const int inf = 1e9 + 7;
const int mod = 1e9 + 7;
void dfs( int v)
{
  tag[v] = mi[v] = ++ti;
  in[v] = vis[v] = true;
  stk.push(v);
  for( int i = 0; i < p[v].size(); ++i )
    {
      int t = p[v][i];
      if( !vis[t] )
	{
	  dfs(t);
	  mi[v] = min( mi[v], mi[t] );
	}
      else if( in[t] )
	mi[v] = min( mi[v], mi[t] );
	// mi[v] = min( mi[v], tag[t] );
    }
  if( tag[v] == mi[v] )
    {
      int minC = inf;
      int cnt = 0;
      for(;;)
	{
	  int t = stk.top();
	  stk.pop();
	  in[t] = false;
	  if( cost[t] < minC )
	    minC = cost[t], cnt = 1;
	  else if( cost[t] == minC )
	    ++cnt;
	  if( t == v )
	    break;
	}
      res = ( ( ll) res * (ll) cnt ) % mod;
      costSum += minC;
    }
}
int main()
{
  scanf("%d", &n);
  for( int i = 1 ; i <= n; ++i )
    scanf("%d", cost + i );
  scanf("%d", &m);
  for( int i = 0 ; i < m; ++i )
    {
      int f, t;
      scanf("%d%d", &f, &t);
      p[f].push_back(t);
    }
  res = 1;
  for( int i = 1; i <= n; ++i )
    if( !vis[i] )
      dfs(i);
  cout << costSum << ' ' << res << endl;
  return 0;
}
