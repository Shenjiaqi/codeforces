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
const int N = 307;
char s[N][N];
int main()
{
  int n;
  scanf("%d", &n);
  for( int i = 0; i < n; ++i )
    scanf("%s", s[i] );
  char d = s[0][0], o = s[0][1];
  if( d == o )
    {
      printf("NO");
      return 0;
    }
  for( int i = 0 ; i < n ; ++ i)
    for( int j = 0; j < n; ++ j)
      if( i == j || i + j == n - 1 )
	{
	  if( s[i][j] != d )
	    {
	      printf("NO");
	      return 0;
	    }
	}
      else if( s[i][j] != o )
	{
	  printf("NO");
	  return 0;
	}
  printf("YES");
  return 0;
}
