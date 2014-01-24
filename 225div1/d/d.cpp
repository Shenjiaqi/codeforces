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
#define M 10007
int n;
int dp[2][M*2];
const int zero=M;
const ll mod=1000000007;
int main()
{
  scanf("%d",&n);
  ll ans=0;
  FOR(i,0,n)
    {
      int v;
      scanf("%d",&v);
      int from=i&1;
      int to=1-from;
      memset(dp[to],0,sizeof(dp[to]));
      ++dp[from][zero];
      for(int j=zero-10000;j<=zero+10000;++j)
	if(dp[from][j])
	  {
	    if(j+v<=zero+10000)
	      dp[to][j+v]=(dp[to][j+v]+dp[from][j])%mod;
	    if(j-v>=zero-10000)
	      dp[to][j-v]=(dp[to][j-v]+dp[from][j])%mod;
	  }
      ans=(ans+(ll)dp[to][zero])%mod;
    }
  cout<<ans;
  return 0;
}
