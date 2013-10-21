#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
#define N 300007
#define A 1000007
int p[N];
int q[A+1];
void add(int v,int num)
{
  if(v>0)
    for(;v<=A;v+=(v&(-v)))
      q[v]+=num;
}
int que(int v)
{
  int r(0);
  if(v>0)
    for(;v;v^=(v&(-v)))
      r+=q[v];
  return r;
}
int main()
{
  int n,k;
  scanf("%d%d",&n,&k);
  int minv=1e9;
  for(int i=0;i<n;++i)
    {
      scanf("%d",p+i);
      minv=min(minv,p[i]);
      add(max(p[i]-k,1),1);
      add(p[i]+1,-1);
    }
  for(int i=minv;i>k;--i)
    {
      int s(0);
      for(int j=i;j<=A && s<n;j+=i)
	s+=que(j);
      if(s==n)
	{
	  printf("%d",i);
	  return 0;
	}
    }
  printf("%d",min(k,minv));
  return 0;
}
