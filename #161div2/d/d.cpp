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
using namespace std;
#define N 100000
#define M 100000
int s[N+1];
int edge[M*2+1][2];
int edgei;
using namespace std;
void add(int a,int b)
{
  ++edgei,edge[edgei][0]=b,edge[edgei][1]=s[a],s[a]=edgei;
}
int main()
{
  freopen("in","r",stdin);
  int n,m,k;
  cin>>n>>m>>k;
  for(int i=0;i<m;++i)
    {
      int a,b;
      cin>>a>>b;
      add(a,b);
      add(b,a);
    }
  int vis[N+1]={0};
  int ord[N+1];
  vis[1]=1;
  int last=1;
  int ans[N+1],nans=0;
  for(int i=0;;++i)
    {
      ans[nans++]=last;
      ord[last]=i;
      if(i>=k)
	break;
      for(int c=s[last];c;c=edge[c][1])
	if(vis[edge[c][0]]==0)
	  {
	    last=edge[c][0];
	    vis[last]=1;
	    break;
	  }
    }
  for(int i=k+1;;++i)
    {
      int tmp=0;
      for(int c=s[last];c;c=edge[c][1])
	if(vis[edge[c][0]]==1 && i-ord[edge[c][0]]>k)
	  {
	    cout<<(i-ord[edge[c][0]])<<endl;
	    for(int j=ord[edge[c][0]];j<i;++j)
	      {
		cout<<ans[j]<<' ';
	      }
	    return 0;
	  }
	else if(vis[edge[c][0]]==0)
	  {
	    tmp=edge[c][0];
	  }
      last=tmp;
      vis[last]=1;
      ans[nans++]=last;
      ord[last]=i;
    }
  return 0;
}
