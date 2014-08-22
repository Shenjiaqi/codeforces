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
const int N = 1e5 + 7;
struct ed
{
  int to, tag;
  ll len;
  ed( int t, int tg, int l){ to = t, tag = tg, len = l;};
};
vector<ed> p[N];
vector<int> q;
ll dis[N];
bool in[N];
const ll inf = (1e17);
bool cmp( const int &a, const int &b )
{
  return dis[a] < dis[b];
}
void add( int f, int t, int len, int tag)
{
  p[f].push_back( ed( t, tag, len) );
}
int main()
{
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for( int i = 0 ; i < m ; ++i )
    {
      int u, v, x;
      scanf("%d%d%d", &u, &v, &x);
      add( u, v, x, 0 );
      add( v, u, x, 0 );
    }
  for( int i = 0 ; i < k ; ++i )
    {
      int s, y;
      scanf("%d%d", &s, &y);
      add( 1, s, y, 1);
    }
  for( int i = 1 ; i <= n; ++i )
    dis[i] = inf;
  dis[1] = 0;
  queue<int> que;
  que.push(1);
  in[1] = true;
  for( ; !que.empty(); que.pop() )
    {
      int v = que.front();
      in[v] = false;
      for( auto i : p[v] )
	{
	  int to = i.to;
	  ll len = dis[v] + i.len;
	  if( len < dis[to] )
	    {
	      dis[to] = len;
	      if( !in[to] )
		{
		  in[to] = true;
		  que.push(to);
		}
	    }
	}
    }
  for( int i = 1 ; i <= n ; ++i )
    q.push_back(i);
  sort( q.begin(), q.end(), cmp );
  int ans(0);
  for( const auto &i : p[1] )
    if( dis[ i.to ] == i.len && i.tag == 0 )
      in[ i.to ] = true;
  for( int i = 1 ; i < n ; )
    {
      int j = i;
      for( ; j < n && dis[ q[i] ] == dis[ q[j] ] ; ++j )
	{
	  if( !in[ q[j] ] )
	    ++ans;
	}
      for( ; i < j ; ++i )
	{
	  for( const auto &k : p[ q[i] ] )
	    if( dis[ k.to ] == dis[ q[i] ] + k.len )
	      {
		in[ k.to ] = true;
	      }
	}
    }
  printf("%d", k - ans);
  return 0;
}

