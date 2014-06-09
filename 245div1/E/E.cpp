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
#include <unordered_set>
#include <unordered_map>
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
int p[N][2];
int tag[N];
int tagVal[N];
int tagP[N];
int q[N];
int ans[N];
bool cmp( int a, int b)
{
  if( p[a][0] == p[b][0] )
    return p[a][1] > p[b][1];
  return p[a][0] < p[b][0];
}
int main()
{
  int n;
  scanf("%d", &n);
  for( int i = 0; i < n; ++i )
    {
      scanf("%d%d", &p[i][0], &p[i][1]);
      q[i] = i;
    }
  sort( q, q + n, cmp);
  multimap<int,int> mapp;
  for( int i = 0, j = 0, last = -1; i < n || !mapp.empty();)
    {
      int pos = i < n ? p[ q[i] ][0] : 1e9;
      for( ; !mapp.empty(); )
	{
	  auto k = mapp.begin();
	  if( k->first > pos )
	    break;
	  queue<int> q;
	  for( int z = k->first ; !mapp.empty(); )
	    {
	      k = mapp.begin();
	      if( k->first != z ) 
		break;
	      int v = k->second;
	      int t = tag[v];
	      if( tagP[t] > 0 )
		ans[v] = tagVal[t] ? 1 : -1;
	      else
		ans[v] = tagVal[t] ? -1 : 1;
	      tagVal[t] -= ans[v];
	      j -= ans[v];
	      mapp.erase(k);
	    }
	  if( abs(j) > 2 )
	    {
	      printf("-1");
	      return 0;
	    }
	}
      if( i < n )
	{
	  int t = i;
	  int cnt(0);
	  for( ; i < n && p[ q[i] ][0] == pos; ++i )
	    {
	      tag[i] = t;
	      mapp.insert( make_pair( p[ q[i] ][1] + 1, i) );
	      ++cnt;
	    }
	  if( cnt & 1 )
	    {
	      if( j > 0 )
		tagP[t] = -1, tagVal[t] = -1;
	      else
		tagP[t] = 1, tagVal[t] = 1;
	      j += tagP[t];
	    }
	  else tagP[t] = 0;
	}
    }
  for( int i = 0; i < n; ++i )
    printf("%c ", ans[i] > 0 ? '1' : '0' );
  return 0;
}
