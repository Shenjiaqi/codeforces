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
  ios::sync_with_stdio(false);
  int n;
  scanf("%d", &n);
  map<int,int> mapp;
  for( int i = 0 ; i < n ; ++i )
    {
      int v;
      scanf("%d", &v);
      ++mapp[v];
    }
  int lastV = -1;
  ll lastG = 0;
  ll nLastG = 0;
  for( auto i : mapp )
    {
      ll g = (ll)i.second * (ll)i.first;
      ll tmpG;
      if( i.first == lastV + 1 )
	tmpG = nLastG + g;
      else
	 tmpG = max( nLastG, lastG ) + g;
      nLastG = max( nLastG, lastG);
      lastG = tmpG;
      lastV = i.first;
    }
  cout << max( lastG, nLastG);
  return 0;
}
