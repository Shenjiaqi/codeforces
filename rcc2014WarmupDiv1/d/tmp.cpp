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
vector<int> p[N];
void add( int f, int t )
{
  p[f].push_back(t);
}
void dfs( int v, int from )
{
  for( auto i : p[v] )
    if( i != from )
      {
	cout << v << " -> " << i << ";" << endl;
	dfs( i, v );
      }
}
int main()
{
  int n;
  cin >> n;
  cout << n << endl;
  for( int i = 1; i < n ;++i )
    {
      int a, b;
      cin >> a >> b;
      add( a, b );
      add( b, a );
    }
  dfs( 1, 1 );
  return 0;
}
