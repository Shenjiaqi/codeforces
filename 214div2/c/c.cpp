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
#define N 107
int p[N],a[N],b[N];
bool ddp[N*101*2+7];
bool *dp;
int vval[N*101*2+7];
int *val;
int main()
{
  int n,k;
  scanf("%d%d",&n,&k);
  FOR(i,0,n)
    scanf("%d",a+i);
  FOR(i,0,n)
    {
      scanf("%d",b+i);
      b[i]*=k;
    }
  dp=ddp+N*101+1;
  val=vval+N*101+1;
  dp[0]=true;
  int mv=100*n;
  FOR(i,0,n)
    {
      int det=a[i]-b[i];
      int sv=(det>=0?mv:-mv)-det;
      int tv=(det>=0?-mv:mv);
      int pa=(det>=0?-1:1);
      for(int j=sv;;j+=pa)
	{
	  if((det>=0 && j<tv) || (det<0 && j>tv))
	    break;
	  if(dp[j])
	    {
	      int t=j+det;
	      dp[t]=true,val[t]=max(val[t],val[j]+a[i]);
	    }
	}
    }
  if(val[0]>0)
    printf("%d",val[0]);
  else printf("-1");
  return 0;
}
