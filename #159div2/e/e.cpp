#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
using namespace std;
int waitt[100001],want[100001];
void add(int l,int k,int num)
{
  if(l<=0)
    return ;
  if(num==0)
    return;
  int * arr=(k?waitt:want);
  for(;l<=100000;l+=(l&(-l)))
    arr[l]+=num;
}
int que(int l)
{
  int r(0);
  for(;l>0;l-=(l&(-l)))
    r+=(waitt[l]+want[l]);
  return r;
}
int main()
{
  freopen("in","r",stdin);
  int n,m;
  cin>>n>>m;
  vector< vector<int> > info;
  info.resize(n);
  for(int i=0;i<n;++i)
    info[i].resize(4);
  for(int i=0;i<n;++i)
    {
      cin>>info[i][0]>>info[i][1]>>info[i][2];
      info[i][3]=i;
    }
  typedef long long ll;
  sort(info.begin(),info.end());
  ll time=info[0][0];
  int lev=1;
  int await=0,awant=0;
  multimap<int,int> inele;
  multimap<int,int> waiting;
  vector<ll>ans;
  ans.resize(n);
  typedef multimap<int,int>::iterator mite;
  typedef pair<int,int> ppi;
  for(int i=0,c=0;i<n || waiting.size()>0 || inele.size()>0;)
    {
      pair<mite,mite>pp=inele.equal_range(lev);
      int num=0;
      //cout<<i<<' '<<"time "<<time<<" lev "<<lev<<endl;
      for(;pp.first!=pp.second;++pp.first,++num)
	ans[info[(pp.first)->second][3]]=time;
      inele.erase(lev);
      add(lev,0,-num);
      
      num=0;
      for(;i<n && info[i][0]==time;++i,++num)
	{
	  waiting.insert(ppi(info[i][1],i));
	  add(info[i][1],1,1);
	}
      
      num=0;
      pp=waiting.equal_range(lev);
      for(;pp.first!=pp.second;++pp.first,++num)
	{
	  inele.insert(ppi(info[(pp.first)->second][2],(pp.first)->second));
	  //cout<<'!'<<pp.first->second<<' '<<info[pp.first->second][2]<<endl;
	  add(info[pp.first->second][2],0,1);
	}
      waiting.erase(lev);
      add(lev,1,-num);
      int down=que(lev-1);
      int up=(int)(waiting.size()+inele.size())-down;
      //cout<<"up"<<up<<" down "<<down<<endl;
      if(up==0 && down==0)
	{
	  if(i<n)
	    time=info[i][0];
	}
      else if(up>=down)
	{
	  ll mtime=100001;
	  if(i<n)
	    mtime=min(mtime,(ll)info[i][0]-time);
	  mite ii=waiting.upper_bound(lev);
	  if(ii!=waiting.end())
	    mtime=min(mtime,(ll)ii->first-lev);
	  ii=inele.upper_bound(lev);
	  if(ii!=inele.end())
	    mtime=min(mtime,(ll)ii->first-lev);
	  time+=mtime,lev+=mtime;
	}
      else
	{
	  ll mtime=100001;
	  if(i<n)
	    mtime=min(mtime,(ll)info[i][0]-time);
	  mite ii=waiting.upper_bound(lev);
	  if(ii!=waiting.begin())
	    {
	      --ii;
	      mtime=min(mtime,lev-(ll)ii->first);
	    }
	  ii=inele.upper_bound(lev);
	  if(ii!=inele.begin())
	    {
	      --ii;
	      mtime=min(mtime,lev-(ll)ii->first);
	    }
	  time+=mtime,lev-=mtime;
	}
    }
  for(int i=0;i<n;++i)
    cout<<ans[i]<<endl;
  return 0;
}
