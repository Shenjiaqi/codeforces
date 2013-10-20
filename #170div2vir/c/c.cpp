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
struct tp{
  int a,b,c;
};
bool cmp(const tp &t1,const tp &t2)
{
  if(t1.a!=t2.a)
    return t1.a<t2.a;
  if(t1.b!=t2.b)
    return t1.b<t2.b;
  return t1.c<t2.c;
}
int q[2][100005][2];
int main()
{
  freopen("in","r",stdin);
  int n,m,k;
  cin>>n>>m>>k;
  vector< tp > p[2]; 
  for(int i=0;i<n;++i)
    {
      int x1,y1,x2,y2;
      scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
      if(x1==x2)
	{
	  tp tt;
	  tt.a=x1,tt.b=min(y1,y2),tt.c=max(y1,y2);
	  p[0].push_back(tt);
	}
      else
	{
	  tp tt;
	  tt.a=y1,tt.b=min(x1,x2),tt.c=max(x1,x2);
	  p[1].push_back(tt);
	}
    }
  int ans(0);
  for(int i=0;i<2;++i)
    {
      sort(p[i].begin(),p[i].end(),cmp);
      for(int j=0;j<p[i].size();)
	{
	  int k=j;
	  int num=(i==0?m:n);
	  int s=-1,t=-1;
	  for(;k<p[i].size() && p[i][k].a==p[i][j].a;++k)
	    {
	      if(t<p[i][k].b)
		{
		  num-=(t-s);
		  s=p[i][k].b;
		}
	      t=max(t,p[i][k].c);
	    }
	  num-=(t-s);
	  q[i][++q[i][0][0]][0]=num;
	  q[i][q[i][0][0]][1]=j;
	  ans^=num;
	  j=k;
	}
    }
  if(ans)
    {
      cout<<"FIRST"<<endl;
      for(int i=0;i<2;++i)
	for(int j=1;j<=q[i][0][0];++j)
	  {
	    int cut=ans;
	    if((cut<= q[i][j][0]) && cut)
	      {
		int xy=q[i][j][1];
		int num=0;
		int s=0,t=0;
		for(int k=xy;k<p[i].size() && p[i][k].a==p[i][xy].a;++k)
		  {
		    if(t<p[i][k].b)
		      {
			num+=(p[i][k].b-t);
			if(num>=cut)
			  {
			    if(i==0)
			      cout<<p[i][k].a<<' '<<0<<' '<<p[i][k].a<<' '<<(p[i][k].b-(num-cut))<<endl;
			    else cout<<0<<' '<<p[i][k].a<<' '<<(p[i][k].b-(num-cut))<<' '<<p[i][k].a<<endl;
			    return 0;
			  }
		      }
		    t=max(t,p[i][k].c);
		  }
		if(i==0)
		  cout<<p[i][xy].a<<' '<<0<<' '<<p[i][xy].a<<' '<<(t+(cut-num))<<endl;
		else cout<<0<<' '<<p[i][xy].a<<' '<<(t+(cut-num))<<' '<<p[i][xy].a<<endl;
		break;
	      }
	  }
    }
  else cout<<"SECOND";
  return 0;
}
