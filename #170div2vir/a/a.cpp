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
#include <stdlib.h>
#include <functional>
using namespace std;
typedef long long ll;
#define N 100
#define M 100
int p[N][M];
int q[N][N];
int vis[N];
int n,m;
void dfs(int v)
{
  vis[v]=1;
  for(int i=0;i<n;++i)
    if(!vis[i] && q[v][i])
      dfs(i);
}
int main()
{
  freopen("in","r",stdin);
  cin>>n>>m;
  int all=0;
  for(int i=0;i<n;++i)
    {
      int num;
      cin>>num;
      if(num)
	all=1;
      for(int j=0;j<num;++j)
	{
	  int l;
	  cin>>l;
	  --l;
	  p[i][l]=1;
	}
    }
  for(int i=0;i<n;++i)
    for(int j=i;j<n;++j)
      for(int k=0;k<m;++k)
	if(p[i][k] && p[j][k])
	  {
	    q[i][j]=q[j][i]=1;
	    break;
	  }
  int ans(0);
  for(int i=0;i<n;++i)
    if(!vis[i])
      {
	dfs(i);
	++ans;
      }
  cout<<(ans-all);
  return 0;
}
