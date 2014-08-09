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
char s[N], si;
int p[N]['z' - 'a' + 1], pi;
void add()
{
  for( int i = 0, j = 1 ; s[i]; ++i )
    {
      int v = s[i] - 'a';
      if( p[j][v] == 0 )
	p[j][v] = ++pi;
      j = p[j][v];
    }
}
int dfs(int v)
{
  bool a = true, b = true;
  int cnt(0);
  for( int i = 0 ; i < 'z' - 'a' + 1 ; ++i )
    if( p[v][i] )
      {
	++cnt;
	int val = dfs(p[v][i]);
	if( ( val & 2 ) )
	  a = false;
	if( ( val & 1 ) )
	  b = false;
      }
  if( cnt == 0 )
    {
      a = true;
      b = false;
    }
  return ( a ? 2 : 0 ) | ( b ? 1 : 0 );
}
int main()
{
  int n, k;
  scanf("%d%d", &n, &k);
  pi = 1;
  for( int i = 0 ; i < n ; ++i )
    {
      scanf("%s", s);
      add();
    }
  int num = 0;
  for( int i = 0 ; i < 'z' - 'a' + 1 ; ++i )
    if( p[1][i] )
      {
	int tmp = dfs(p[1][i] );
	if( tmp & 1 )
	  num |= 1;
	if( tmp & 2 )
	  num |= 2;
      }
  bool fir;
  if( num == 0 )
    fir = false;
  else if( num == 2 )
    {
      if( k & 1 )
	fir = true;
      else fir = false;
    }
  else if( num == 1 )
    {
      fir = false;
    }
  else
    fir = true;
  if( fir )
    printf("First");
  else printf("Second");
  return 0;
}
