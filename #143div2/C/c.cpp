#include <cstdio>
#include <algorithm>
using namespace std;
#define N (100000)
typedef long long ll;
int p[N];
ll q[N+1][2];
ll que[N+1][2];
int main()
{
  freopen("in.txt","r",stdin);
  int n,k;
  scanf("%d%d",&n,&k);
  for(int i=0;i<n;++i)
    scanf("%d",p+i);
  sort(p,p+n);
  int l(1);
  for(int i=0;i<n;)
    {
      int r=p[i],j=i;
      for(++i;i<n && p[i]==r;++i)
	;
      q[l][0]=r;
      q[l][1]=i-j;
      ++l;
    }
  int a,b;
  a=0,b=1;
  ll r(0),rr(0);
  int ans(0),anv(0);
  /*  for(int i=0;i<=l;++i)
      printf("%d %d\n",q[i][0],q[i][1]);*/
  for(int i=1;i<l;++i)
    {
      int u=q[i][1];
      r+=(q[i][0]-q[i-1][0])*rr;
      for(;k<r-que[a][1]*(q[i][0]-que[a][0]);++a)
	rr-=que[a][1],r-=que[a][1]*(q[i][0]-que[a][0]);
      if(k<r)
	{
	  ll tmp=(r-k+q[i][0]-que[a][0]-1)/(q[i][0]-que[a][0]);
	  que[a][1]-=tmp,rr-=tmp,r-=tmp*(q[i][0]-que[a][0]);
	}
      u+=rr;
      if(u>ans)
	ans=u,anv=q[i][0];
      que[b][0]=q[i][0],que[b][1]=q[i][1];
      ++b;
      rr+=q[i][1];
    }
  printf("%d %d",ans,anv);
  return 0;
}
