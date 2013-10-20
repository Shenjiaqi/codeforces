#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define N (100)
#define M (100)
bool p[N+1];
int q[M*2+1][2];
int v[2*M+1];
int n,k,m;
int cmp(const void *a,const void *b)
{
  int *c=(int*)a,*d=(int*)b;
  if(*c==*d)
    return ((*(c+1)&1)-(*(d+1)&1));
  return (*d-*c);
}
int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  scanf("%d%d",&n,&k);
  for(int i=0;i<k;++i)
    {
      int t;
      scanf("%d",&t);
      p[t]=1;
    }
  scanf("%d\n",&m);
  char buf[11];
  for(int i=0;i<m;++i)
    {
      scanf("%s",buf);
      int d;
      scanf("%d",&d);
      int t;
      for(int j=0;j<d;++j)
	{
	  scanf("%d",&t);
	  if(t)
	    {
	      if(p[t])
		++q[2*i][0];
	    }
	  else ++q[2*i+1][0];
	}
      int r=n-k-(d-q[i*2][0]-q[i*2+1][0]);
      if(q[i*2+1][0]>r)
	{
	  r=q[i*2+1][0]-r;
	  q[2*i][0]+=r,q[2*i+1][0]-=r;
	}
      q[2*i+1][0]=min(k,q[2*i+1][0]+q[2*i][0]);
      q[2*i][1]=2*i,q[2*i+1][1]=2*i+1;
    }
  qsort(q,m*2,sizeof(q[0]),cmp);
  int i(0);
  for(;i<2*m && (q[i][1]&1);++i)
      v[q[i][1]/2]=3;
  if(i==0)
    {
      int t=q[0][0];
      for(;i<2*m && q[i][0]==t;++i)
	if(q[i][1]&1)
	  {
	    if(!v[q[i][1]/2])
	      v[q[i][1]/2]=3;
	  }
	else v[q[i][1]/2]=1;
      for(;i<2*m;++i)
	if(!v[q[i][1]/2])
	  v[q[i][1]/2]=2;
    }
  else
    {
      int t=q[i][0];
      for(;i<2*m && t==q[i][0];++i)
	v[q[i][1]/2]=3;
      for(;i<2*m;++i)
	if(!v[q[i][1]/2])
	  v[q[i][1]/2]=2;
    }
  for(int i=0;i<m;++i)
    printf("%d\n",(v[i]-1));
  return 0;
}
