#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
#include <string.h>
using namespace std;
int p[205][205],q[205][205];
int main()
{
  freopen("in","r",stdin);
  int n,m;
  cin>>n>>m;
#define INF (100001*201)
  for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j)
      if(i==j)
	q[i][j]=p[i][j]=0;
      else
	q[i][j]=p[i][j]=INF;
  for(int i=0;i<m;++i)
    {
      int f,t,w;
      cin>>f>>t>>w;
      p[f][t]=q[f][t]=p[t][f]=q[f][t]=w;
    }
  for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j)
      if(p[j][i]<INF)
	for(int k=1;k<=n;++k)
	  if(p[i][k]<INF)
	    if(p[j][k]>p[j][i]+p[i][k])
	      p[j][k]=p[j][i]+p[i][k];
  double ans=INF;
  for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j)
      if(q[i][j]<INF)
      {
	int a=0,b=0;
	for(int k=1;k<=n;++k)
	  if(p[i][k]<p[j][k])
	    a=max(a,p[i][k]);
	  else b=max(b,p[j][k]);
	ans=min(ans,max((double)(b+a+q[i][j])/2.0,(double)max(a,b)));
      }
  printf("%.9lf",ans);
  return 0;
}
