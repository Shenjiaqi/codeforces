#include <cstdio>
#include <iostream>
using namespace std;
#define N 4000
#define K 800
int p[N][N];
int dp[2][N+1];
int s[N][N];
int q[N][N];
int l[N];
int main()
{
  int n,k;
  scanf("%d%d",&n,&k);
  for(int i=0;i<n;++i)
    for(int j=0;j<n;++j)
      scanf("%d",&p[i][j]);
  for(int i=0;i<n;++i)
    for(int j=i+1;j<n;++j)
      s[i][j]+=s[i][j-1]+p[i][j];
  for(int i=0;i<n;++i)
    for(int j=i+1;j<n;++j)
      q[i][j]+=q[i][j-1]+s[i][j];
  for(int i=1;i<=n;++i)
    dp[0][i]=s[0][i-1];
  for(int i=1;i<k;++i)
    {
      int f=i&1;
      int t=i^1;
      for(int j=1;j<=n;++j)
	{
	  for(;l[j]<j-1 &&
		q[l[j]][j]-q[l[j]+1][j]>dp[f][l[j]+1]-dp[d][l[j]];
	      ++l[j])
	    ;
	  dp[t][j]=dp[f][l[j]]+q[l[j]][j];
	}
    }
  printf("%d",dp[k&1][n]);
  return 0;
}
