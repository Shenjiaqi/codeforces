#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define N 100007
int p[N*2+1][3],poi;
int s[N+1];
int n;
bool out[N+1];
char ans[N+1];
void add(int f,int t)
{
  ++poi;
  p[poi][0]=t,p[poi][1]=s[f],s[f]=poi;
}
int dfs(int v,int f)
{
  int r(1);
  int j=0;
  for(int i=s[v];i;i=p[i][1])
    if(p[i][0]!=f)
      r+=(p[i][2]=dfs(p[i][0],v));
    else j=i;
  p[j][2]=n-r;
  return r;
}
void cut(int v,int f,int num,int e)
{
  p[e&1?e+1:e-1][2]-=num;
  for(int i=s[v];i;i=p[i][1])
    if(p[i][0]!=f && out[p[i][0]]==false)
      cut(p[i][0],v,num,i);
}
int search(int v,int f,int maxn)
{
  int i;
  for(i=s[v];i;i=p[i][1])
    if(p[i][2]>maxn)
      break;
  if(i==0)
    return v;
  else
    for(i=s[v];i;i=p[i][1])
      if(p[i][0]!=f && out[p[i][0]]==false)
	{
	  int j=search(p[i][0],v,maxn);
	  if(j)
	    return j;
	}
  return 0;
}
void cal(int num,int v,int l)
{
  if(num==1)
    {
      ans[v]=l;
      out[v]=true;
      return;
    }
  else if(num>0)
    {
      int k=search(v,v,(1+num-1)/2);
      ans[k]=l;
      out[k]=true;
      for(int i=s[k];i;i=p[i][1])
	if(out[p[i][0]]==false)
	  {
	    cut(p[i][0],k,num-p[i][2],i);
	    cal(p[i][2],p[i][0],l+1);
	  }
    }
}
int main()
{
  freopen("in.txt","r",stdin);
  scanf("%d",&n);
  for(int i=1;i<n;++i)
    {
      int f,t;
      scanf("%d%d",&f,&t);
      add(f,t);
      add(t,f);
    }
  dfs(1,0);
  cal(n,1,0);
  for(int i=1;i<=n;++i)
    printf("%c ",('A'+ans[i]));
  return 0;
}
