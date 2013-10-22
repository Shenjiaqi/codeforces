#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>
using namespace std;
int main()
{
  //freopen("in.txt","r",stdin);
  int n,m;
  cin>>n>>m;
  vector<int> p[2];
  for(int i=0;i<n;++i)
    {
      string pos;
      int strength;
      cin>>pos>>strength;
      if(pos[0]=='A')
	p[0].push_back(strength);
      else p[1].push_back(strength);
    }
  sort(p[0].begin(),p[0].end());
  sort(p[1].begin(),p[1].end());
  vector<int> q;
  for(int i=0;i<m;++i)
    {
      int strength;
      cin>>strength;
      q.push_back(strength);
    }
  sort(q.begin(),q.end());
  int ans(0);
  for(int i=0;i<=p[0].size();++i)
    for(int j=0;j<=p[1].size();++j)
      {
	vector<int> left;
	left.resize(q.size());
	fill(left.begin(),left.end(),0);
	int ii=0;
	int v=0;
	int jj=0;
	for(int k=0;jj<j && k<q.size();++k)
	  if(q[k]>p[1][jj])
	    ++jj,left[k]=1;
	if(jj<j)
	  continue;
	ii=i-1;
	for(int k=q.size()-1;ii>=0 && k>=0;--k)
	  if(q[k]>=p[0][ii] && left[k]==0)
	    {
	      left[k]=1,v+=q[k]-p[0][ii];
	      --ii;
	    }
	if(ii>=0)
	  continue;
	if(i==p[0].size() && j==p[1].size())
	  for(int k=0;k<q.size();++k)
	    if(left[k]==0)
	      v+=q[k];
	ans=max(ans,v);
      }
  cout<<ans;
  return 0;
}
