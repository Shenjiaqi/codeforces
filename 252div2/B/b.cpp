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
const int N = 3007;
int p[N];
int main()
{
  int n, v;
  scanf("%d%d", &n, &v);
  map<int,int> mapp;
  for( int i = 0 ; i < n; ++i )
    {
      int a, b;
      scanf("%d%d", &a, &b);
      p[a] += b;
    }
  int ans(0); 
  int left(0);
  for( int i = 1; i < N; ++i )
    {
      ans += min( v, left + p[i] );
      left = max( 0, p[i] - max( 0,  v - left ) );
    }
  printf("%d", ans);
  return 0;
}
