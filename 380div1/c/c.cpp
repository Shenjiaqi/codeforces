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
#define N 1000007
#define M 100007
char str[N];
int dp[N][21][3];
vector<ppi> ans[M];
int cal(int from,int len)
{
  int r=0;
  for(int i=0,left=0;(1<<i)<=len;++i)
    if((1<<i)&len)
      {
	r+=dp[from][i][0];
	int tmp=min(dp[from][i][2],left);
	r+=tmp;
	left=left-tmp+dp[from][i][1];
	from+=(1<<i);
      }
  return r;
}
int main()
{
  int m;
  scanf("%s%d",str,&m);
  int n=0;
  for(;str[n];++n)
    {
      dp[n][0][0]=0;
      if(str[n]==')')
	dp[n][0][2]=1;
      else dp[n][0][1]=1;
    }
  for(int i=1;(1<<i)<=n;++i)
    for(int j=0;j+(1<<i)-1<n;++j)
      {
	int t=j+(1<<(i-1));
	dp[j][i][0]=dp[j][i-1][0]+dp[t][i-1][0];
	if(dp[j][i-1][1]>=dp[t][i-1][2])
	  {
	    dp[j][i][1]=dp[j][i-1][1]-dp[t][i-1][2]+dp[t][i-1][1];
	    dp[j][i][0]+=dp[t][i-1][2];
	    dp[j][i][2]=dp[j][i-1][2];
	  }
	else
	  {
	    dp[j][i][2]=dp[t][i-1][2]-dp[j][i-1][1]+dp[j][i-1][2];
	    dp[j][i][0]+=dp[j][i-1][1];
	    dp[j][i][1]=dp[t][i-1][1];
	  }
      }
  FOR(i,0,m)
    {
      int l,r;
      scanf("%d%d",&l,&r);
      printf("%d\n",cal(l-1,r-l+1)*2);
    }
  return 0;
}
