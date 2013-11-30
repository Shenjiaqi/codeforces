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
#define N 3007
#define K 3007
int n,k;
int v[N][K];
int p[N];
int q[N][2];
int ans;
void dfs(int a,int b,int left)
{
  assert(a<b);
  if(v[a][b])
    return;
  v[a][b]=1;
  ++ans;
  if(left<=0)
    return;
  if(b<n)
    {
      if(p[a]==0)
	{
	  if(q[b][0])
	    return;
	  else
	    dfs(b,b+1,left-1);
	}
      else if(p[a]!=100)
	{
	  if(q[b][0])
	    dfs(a,b+1,left-1);
	  else if(q[b][1])
	    dfs(b+1,b+2,left-1),dfs(b,b+1,left-1);
	  else dfs(b,b+1,left-1),dfs(b+1,b+2,left-1),dfs(a,b+1,left-1);
	}
      else
	{
	  if(q[b][0])
	    dfs(a,b+1,left-1);
	  else if(q[b][1])
	    dfs(b+1,b+2,left-1);
	  else dfs(a,b+1,left-1),dfs(b+1,b+2,left-1);
	}
    }
}
int main()
{
  scanf("%d%d",&n,&k);
  FOR(i,0,n)
    scanf("%d",p+i);
  if(p[n-1]==100)
    q[n-1][1]=1;
  if(p[n-1]==0)
    q[n-1][0]=1;
  for(int i=n-2;i>=0;--i)
    {
      q[i][0]=((p[i]==0) && q[i+1][0]);
      q[i][1]=((p[i]==100) || q[i+1][1]);
    }
  dfs(0,1,k);
  cout<<ans<<endl;
  return 0;
}
