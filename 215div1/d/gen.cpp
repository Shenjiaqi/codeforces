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
#define N 100000
#define M 20
int n,m,d;

int main()
{
  n=50000,m=20,d=4;
  printf("%d %d %d\n",n,m,d);
  vector<ppi> p;
  srand(9);
  FOR(i,0,n)
    p.push_back(ppi(rand(),i+1));
  sort(p.begin(),p.end());
  int cnt=0;
  FOR(i,1,m)
    {
      int s=(rand()%(max(100,n/(m-i+1))));
      n-=s;
      printf("%d ",s);
      FOR(j,0,s)
	{
	  printf("%d ",p[cnt].second);
	  ++cnt;
	}
      printf("\n");
    }
  printf("%d ",n);
  FOR(i,0,n)
    {
      printf("%d ",p[cnt].second);
      ++cnt;
    }
  return 0;
}
