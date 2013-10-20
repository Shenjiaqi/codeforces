#include <cstdio>
#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<int,int> pos;
#define N (1000)
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
vector<string> base;
void bfs(int d,pos p,map<pos,int> &in)
{
  queue<pos> q;
  q.push(p);
  q.push(pos(-1,-1));
  map<pos,int> vis;
  vis[p]=1;
  for(int i=0;i<d+1;)
    {
      pos pp=q.front();
      q.pop();
      if(pp.first<0)
	{
	  ++i;
	  q.push(pp);
	}
      else
	{
	  in[pp]=1;
	  for(int j=0;j<4;++j)
	    {
	      int x=pp.first+dir[j][0];
	      int y=pp.second+dir[j][1];
	      if(base[x][y]!='X' && vis.find(pos(x,y))==vis.end())
		{
		  q.push(pos(x,y));
		  vis[pos(x,y)]=1;
		}
	    }
	}
    }
}
int bfs2(int d,int k,pos p,map<pos,int> & num)
{
  map<pos,int> vis;
  queue<pos> q;
  q.push(p);
  q.push(pos(-1,-1));
  vis[p]=1;
  int m=-1;
  for(int i=0;i<d+1;)
    {
      pos t=q.front();
      q.pop();
      if(t.first<0)
	{
	  ++i;
	  q.push(t);
	}
      else
	{
	  if(num[t]==k-1)
	    m=max(m,++num[t]);
	  else num.erase(t);
	  for(int j=0;j<4;++j)
	      {
		int x,y;
		x=dir[j][0]+t.first,y=dir[j][1]+t.second;
		if(base[x][y]!='X' && vis.find(pos(x,y))==vis.end())
		  {
		    q.push(pos(x,y));
		    vis[pos(x,y)]=1;
		  }
	      }
	}
    }
  return m;
}
int main()
{
  freopen("input.txt","r",stdin);
  int n,m,d;
  scanf("%d%d%d",&n,&m,&d);
  base.resize(n);
  for(int i=0;i<n;++i)
    cin>>base[i];
  vector<pos> rats;
  for(int i=0;i<n;++i)
    for(int j=0;j<m;++j)
      if(base[i][j]=='R')
	rats.push_back(pos(i,j));
  if(rats.size()<=((1+8)*8/2-8)*4*2)
    {
      map<pos,int> vis;
      bfs(d,rats[0],vis);
      //cout<<vis.size()<<endl;
      /*for(map<pos,int>::iterator ii=vis.begin();ii!=vis.end();++ii)
	cout<<(ii->first).first<<' '<<(ii->first).second<<endl;
	return 0;*/
      for(map<pos,int>::iterator ite=vis.begin();ite!=vis.end();++ite)
	{
	  map<pos,int> cov;
	  map<pos,int> cc;
	  bfs(d,ite->first,cov);
	  int k=1;
	  int z=0;
	  int num=0;
	  for(;k<rats.size();++k)
	    if(cov.find(rats[k])==cov.end())
	      {
		++num;
		z=bfs2(d,num,rats[k],cc);
		/*if((ite->first).first==1 && (ite->first).second==2)
		  {
		    for(map<pos,int>::iterator ii=cc.begin();ii!=cc.end();++ii)
		      if(ii->second==z)
			cout<<(1+(ii->first).first)<<' '<<(1+(ii->first).second)<<endl;
		    cout<<endl;
		    }*/
		if(z<num)
		  break;
	      }
	  if(z==num)
	    {
	      int x=(ite->first).first;
	      int y=(ite->first).second;
	      if(z==0)
		{
		  for(int i=1;i<n-1;++i)
		    for(int j=1;j<m-1;++j)
		      if(base[i][j]!='X' && i!=x && j!=y)
			{
			  cout<<(x+1)<<' '<<(y+1)<<' '<<(i+1)<<' '<<(j+1)<<endl;
			  return 0;
			}
		}
	      else
		for(map<pos,int>::iterator ii=cc.begin();ii!=cc.end();++ii)
		  if(ii->second==num)
		    {
		      cout<<(x+1)<<' '<<(y+1)<<' '<<((ii->first).first+1)<<' '<<((ii->first).second+1)<<endl;
		      return 0;
		    }
	    }
	}
    }
  printf("-1");
  return 0;
}
  
