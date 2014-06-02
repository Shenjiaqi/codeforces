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
const int N = 207;
const ll mod = (int)1e9 + 7;
int pos[N][2];
int dp[N][N];
int main()
{
  int n;
  scanf("%d", &n);
  for( int i = 0; i < n; ++i )
    {
      int x, y;
      scanf("%d%d", &x, &y);
      pos[i][0] = x, pos[i][1] = y;
    }
  for( int i = 0; i < n; ++i )
    for( int j = i; j < n; ++j )
      {
	if( i == j || !ok( i, j ) )
	  cnt[i][j] = cnt[j][i] = false;
	else cnt[i][j] = cnt[j][i] = true;
      }
  for( int i = 0; i < n; ++i )
    dp[i][
}
