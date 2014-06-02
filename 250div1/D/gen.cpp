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

int main()
{
  int n, m;
  // n = 1e5, m = 1e5;
  n = 5, m = 5;
  cout << n << ' ' << m << endl;
  for( int i = 0 ; i < n; ++i )
    {
      cout << 1000000007 << ' ';
    }
  cout << endl;
  int cnt = 1e6;
  for( int i = 0 ; i < m / 2; ++i, --cnt )
    {
      cout << 2 << ' ' << 1 << ' ' << n << ' ' << cnt << endl;
      cout << 1 << ' ' << 1 << ' ' << n << endl;
    }
  return 0;
}
