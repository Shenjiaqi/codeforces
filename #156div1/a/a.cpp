#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

#define N (4000)
int m[N][N]={0};
int can[N][N]={0};
int main()
{
  freopen("in","r",stdin);
  int n;
  vector<int> num;
  cin>>n;
  num.resize(n);
  for(int i=0;i<n;++i)
    cin>>num[i];
  vector<int> nn(num.begin(),num.end());
  sort(num.begin(),num.end());
  map<int,int> mapp;
  for(int i=0,j=0;i<n;++i)
    if(i==0 || num[i]!=num[i-1])\
      mapp[num[i]]=j++;
  int z=0;
  for(int i=0;i<n;++i)
    {
      nn[i]=mapp[nn[i]];
      z=max(z,nn[i]);
    }
  /*for(int i=0;i<n;++i)
    cout<<nn[i]<<endl;*/
  int ans=0;
  for(int i=0;i<n;++i)
    {
      int v=nn[i];
      for(int j=0;j<=z;++j)
	if(j!=v && can[j][v])
	  {
	    can[j][v]=0;
	    ans=max(ans,++m[v][j]);
	  }
      for(int j=0;j<=z;++j)
	if(j!=v && can[v][j]==0)
	  {
	    can[v][j]=1;
	    ans=max(ans,++m[v][j]);
	  }
      ans=max(ans,++m[v][v]);
    }
  cout<<ans;
  return 0;
}
