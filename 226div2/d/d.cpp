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
#define N 20
const ld eps=1e-13;
bool vis[1<<N];
ld dp[1<<N];
int n,l,r;
int light[N][3];
ld dist(ld x1,ld y1,ld x2,ld y2)
{
  x1-=x2;
  y1-=y2;
  return sqrtl(x1*x1+y1*y1);
}
ld caldis(int num,ld from)
{
  ld x=light[num][0],y=light[num][1];
  ld ang=(ld)light[num][2]/(ld)180*acosl(-1.0);
  // ld bet=acosl(-1)-atan2l(y,x-from)-ang;
  ld bet=atan2l(y,x-from);
  if(bet<0)
    {
      bet+=acosl(-1);
    }
  bet=acosl(-1)-bet-ang;
  if(bet<=eps)
    return r;
  return sinl(ang)*dist(x,y,from,0)/sinl(bet);
}
ld cal(int msk)
{
  if(!vis[msk])
    {
      vis[msk]=true;
      dp[msk]=-1e100;
      for(int i=0;(1<<i)<=msk;++i)
	if((1<<i)&msk)
	  {
	    ld dis=cal(msk^(1<<i));
	    dis+=caldis(i,dis);
	    dp[msk]=max(dp[msk],dis);
	  }
    }
  return dp[msk];
}
int main()
{
  scanf("%d%d%d",&n,&l,&r);
  FOR(i,0,n)
    scanf("%d%d%d",&light[i][0],&light[i][1],&light[i][2]);
  vis[0]=true;
  dp[0]=l;
  double dis=cal((1<<n)-1)-l;
  if(dis>r-l)
    dis=r-l;
  printf("%.7lf",dis);
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
