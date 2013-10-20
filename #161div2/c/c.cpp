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
int main()
{
  freopen("in","r",stdin);
  int n;
  cin>>n;
  vector<int> mapp[2];
  mapp[0].resize(n+1);
  mapp[1].resize(n+1);
  fill(mapp[0].begin(),mapp[0].end(),0);
  fill(mapp[1].begin(),mapp[1].end(),0);
  for(int i=0;i<n*2;++i)
    {
      int j;
      cin>>j;
      if(mapp[0][j]==0)
	cin>>mapp[0][j];
      else cin>>mapp[1][j];
    }
  vector<int> order;
  order.resize(n);
  order[0]=1;
  vector<int> fil;
  fil.resize(n+1);
  fill(fil.begin(),fil.end(),0);
  fil[1]=1;
  for(int i=0;i<n-2;++i)
    {
      int a1=mapp[0][order[i]],a2=mapp[1][order[i]];
      if(a2==mapp[0][a1] || a2==mapp[1][a1])
	{
	  if(fil[a1])
	    {
	      cout<<-1;
	      return 0;
	    }
	  order[i+1]=a1;
	  fil[a1]=1;
	}
      else
	{
	  if(fil[a2])
	    {
	      cout<<-1;
	      return 0;
	    }
	  order[i+1]=a2;
	  fil[a2]=1;
	}
    }
  for(int i=1;i<=n;++i)
    if(fil[i]==0)
      order[n-1]=i;
  for(int i=0;i<n;++i)
    if((mapp[0][order[i]]!=order[(i+1)%n] && mapp[1][order[i]]!=order[(i+1)%n])||
       (mapp[0][order[i]]!=order[(i+2)%n] && mapp[1][order[i]]!=order[(i+2)%n]))
      {
	cout<<-1;
	return 0;
      }
  for(int i=0;i<n;++i)
    cout<<order[i]<<' ';
  return 0;
}
