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
const int N = 5007;
struct e
{
  int gt[ 'z' - 'a' + 1 ];
  int pre;
};
e p[2][N * 2];
int poi[2], pre[2];
char s[2][N];
void add( int idx, int v)
{
  int n = ++poi[idx];
  memset( p[idx][n].gt, 0 , sizeof(p[idx][n].gt) );
  p[idx][n].pre = 0;
  int i = pre[idx];
  pre[idx] = n;
  for( ; i && p[idx][i].gt[v] == 0; i = p[idx][i].pre)
    p[idx][i].gt[v] = n;
  if( i == 0 )
    {
      p[idx][n].pre = i;
    }
  else
    {
      
    }
}
int main()
{
  scanf("%s%s", s[0], s[1]);
  for( int i = 0; i < 2; ++i )
    for( int j = 0; s[i][j]; ++j )
      add( i, s[i][j] - 'a');
  return 0;
}
