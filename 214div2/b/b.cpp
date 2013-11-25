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
#define N 100007
int p[N];
bool vis[N];
int main()
{
  int n,k;
  scanf("%d%d",&n,&k);
  FOR(i,0,n)
    scanf("%d",p+i);
  int mint=1e9,s=-1;
  FOR(i,0,n)
    if(vis[i]==false)
      {
	int sum(0);
	for(int j=i;vis[j]==false;j=(j+k)%n)
	  vis[j]=true,sum+=p[j];
	if(sum<mint)
	  s=i,mint=sum;
      }
  printf("%d",s+1);
  return 0;
}
