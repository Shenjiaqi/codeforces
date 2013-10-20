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
  typedef pair<int,int> pos;
  vector< pos > p;
  p.resize(n-1);
  for(int i=0;i<n-1;++i)
    {
      cin>>p[i].first>>p[i].second;
      --p[i].first,--p[i].second;
    }
  vector < pos > ans;
  vector < int > anst;
  for(int i=1;i<n && !p.empty();++i)
    {
      int q=0;
      vector< int > emp(n);
      for(int j=0;j<p.size();++j)
	{
	  if(p[j].second>=n-i)
	    ++q;
	  emp[p[j].second]=1;
	}
      if(q)
	{
	  for(int j=0;j<n-i;++j)
	    if(emp[j]==0)
	      {
		ans.push_back(pos(j,n-i));
		anst.push_back(2);
		for(int k=0;k<p.size();++k)
		  if(p[k].second==j)
		    p[k].second=n-i;
		  else if(p[k].second==n-i)
		    p[k].second=j;
		break;
	      }
	}
      q=0;
      int qq=0;
      for(int j=0;q==0 && j<p.size();++j)
	if(p[j].first==n-i)
	  q=1;
	else qq=p[j].first;
      if(q==0)
	{
	  ans.push_back(pos(n-i,qq));
	  anst.push_back(1);
	  for(int j=0;j<p.size();++j)
	    if(p[j].first==qq)
	      p[j].first=n-i;
	    else if(p[j].first==n-i)
	      p[j].first=qq;
	}
      vector< pos > tmp;
      for(int j=0;j<p.size();++j)
	if(p[j].first<n-i && p[j].second<n-i)
	  tmp.push_back(p[j]);
      p=tmp;
    }
  cout<<ans.size()<<endl;
  for(int i=0;i<ans.size();++i)
    cout<<anst[i]<<' '<<(1+ans[i].first)<<' '<<(1+ans[i].second)<<endl;
  return 0;
}
