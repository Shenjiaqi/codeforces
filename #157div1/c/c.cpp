#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
  freopen("in.txt","r",stdin);
  int n;
  scanf("%d",&n);
#define N (100000)
  int p[N];
  for(int i=0;i<n;++i)
    scanf("%d",p+i);
  sort(p,p+n);
  ll v[2][N+1]={0LL};
  v[0][1]=1;
  const ll C=1000000007;
  for(int i=0;i<n;++i)
    {
      int f=1&i;
      int t=1-f;
      for(int j=1;j<=p[i];++j)
	{
	  v[t][j]=v[f][j];
	  for(int k=1;k<j;++k)
	    if((j%k)==0)
	      v[t][j]=(v[f][j]+v[t][j]+v[f][k])%C;
	}
      //printf("%d\n",(int)v[t][3]);
      memset(v[f],0,sizeof(v[f]));
    }
  int ans(0);
  for(int i=1;i<=p[n-1];++i)
    ans=(ans+v[1&n][i])%C;
  printf("%d",ans);
  return 0;
}
