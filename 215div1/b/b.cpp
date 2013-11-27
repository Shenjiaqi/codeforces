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
#define N 200007
#define M 200007
int a[N],b[M];
int n,m,p;
int dif[N+M][3];
map<int,int> mapp;
void ud(int c,int t,int num,bool sub)
{
  int r=0;
  if(dif[c][2]!=t)
    dif[c][2]=t,dif[c][1]=0;
  else r=dif[c][1];
  dif[c][1]+=num;
  int rdet=abs(r-dif[c][0]);
  int ndet=abs(dif[c][0]-dif[c][1]);
  if(sub)
    --mapp[rdet];
  ++mapp[ndet];
  if(mapp.find(rdet)!=mapp.end() && mapp[rdet]==0)
    mapp.erase(rdet);
}
int main()
{
  scanf("%d%d%d",&n,&m,&p);
  FOR(i,0,n)
    {
      scanf("%d",a+i);
      mapp[a[i]]=0;
    }
  FOR(i,0,m)
    {
      scanf("%d",b+i);
      mapp[b[i]]=0;
    }
  int cnt=0;
  FR(i,mapp)
    i->second=cnt++;
  FOR(i,0,n)
    a[i]=mapp[a[i]];
  vector<int> c;
  FOR(i,0,m)
    {
      ++dif[b[i]=mapp[b[i]]][0];
      c.push_back(b[i]);
    }
  sort(c.begin(),c.end());
  c.resize(unique(c.begin(),c.end())-c.begin());
  // FOR(i,0,3)
  //   cout<<dif[i][0]<<' ';cout<<endl;
  vector<int> ans;
  for(int i=0;i<p && (ll)i+(ll)(m-1)*(ll)p<(ll)n;++i)
    {
      mapp.clear();
      FR(k,c)
	++mapp[dif[*k][0]];
      // FR(k,mapp)
      // 	cout<<k->first<<' '<<k->second<<endl;
      int j=i;
      for(int c=0;c<m;++c,j+=p)
	ud(a[j],i,1,true);
      if(mapp.size()==1 && mapp.begin()->first==0)
	ans.push_back(i);
      for(int ii=i;j<n;j+=p,ii+=p)
	{
	  ud(a[ii],i,-1,true);
	  ud(a[j],i,1,true);
	  if(mapp.size()==1 && mapp.begin()->first==0)
	    ans.push_back(ii+p);
	}
    }
  sort(ans.begin(),ans.end());
  printf("%d\n",(int)ans.size());
  for(int i=0;i<ans.size();++i)
    printf("%d ",ans[i]+1);
  return 0;
}
