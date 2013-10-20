#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
using namespace std;
vector<vector<int> > rate;
vector<vector<pair<int,int> > > choice;
vector<vector<pair<int,int> > > ff;
#define M (400)
void pt(int l,int r,const int v)
{
  if(l)
    {
      pt(l-1,choice[l][r].second,v);
      cout<<(choice[l][r].first+1);
      for(int i=0;i<=choice[l][r].first;++i)
	cout<<' '<<(1+ff[l][i].second);
      cout<<endl;
    }
}
int main()
{
  freopen("input.txt","r",stdin);
  int n,v;
  cin>>n>>v;
  vector<int> food;
  food.resize(n);
  for(int i=0;i<n;++i)
    cin>>food[i];
  int m;
  cin>>m;
  vector<vector<int> > friends;
  friends.resize(m);
  for(int i=0;i<m;++i)
    {
      friends[i].resize(3);
      cin>>friends[i][0]>>friends[i][1]>>friends[i][2];
    }
  rate.resize(n+1);
  choice.resize(n+1);
  ff.resize(n+1);
  for(int i=0;i<=n;++i)
    rate[i].resize(M+1),choice[i].resize(M+1);
  rate[0][0]=1;
  for(int i=1;i<=n;++i)
    {
      for(int j=0;j<m;++j)
	if(friends[j][0]<=i && friends[j][1]>=i)
	  ff[i].push_back(make_pair(friends[j][2],j));
      sort(ff[i].begin(),ff[i].end());
      for(int j=0;j<=M;++j)
	if(rate[i-1][j])
	  {
	    int tmp=min(food[i-1],food[i-1]+j-v);
	    if(rate[i][tmp]<rate[i-1][j])
	      {
		rate[i][tmp]=rate[i-1][j];
		choice[i][tmp]=make_pair(-1,j);
	      }
	    for(int k=0,sum=v;k<ff[i].size();++k)
	      if(food[i-1]+j>=sum+ff[i][k].first)
		{
		  tmp=min(food[i-1],food[i-1]+j-sum-ff[i][k].first);
		  if(rate[i][tmp]<rate[i-1][j]+k+1)
		    {
		      rate[i][tmp]=rate[i-1][j]+k+1;
		      choice[i][tmp]=make_pair(k,j);
		    }
		  sum+=ff[i][k].first;
		}
	      else break;
	  }
    }
  int z=0;
  for(int i=0;i<=M;++i)
    if(rate[n][z]<rate[n][i])
      z=i;
  cout<<(rate[n][z]-1)<<endl;
  pt(n,z,v);
  return 0;
}
