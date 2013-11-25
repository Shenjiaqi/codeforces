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
typedef long long ll;
typedef pair<int,int> ppi;
typedef pair<ll,ll> ppl;
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
#define N 10
vector<ppi> p[N];
int q[N][N];
void cal(vector<ppi> & pos1,vector<ppi> &pos2)
{
  vector<ppi> p1a,p1b;
  FR(i,pos1)
    if(
}
int main()
{
  int n,m,k,s;
  FOR(i,0,n)
    FOR(j,0,m)
    {
      int v;
      scanf("%d",&v);
      p[v].push_back(ppi(i,j));
    }
  FOR(i,1,N)
    FOR(j,1,N)
    if(i!=j)
      {
	cal(p[i],p[j]);
      }
}
