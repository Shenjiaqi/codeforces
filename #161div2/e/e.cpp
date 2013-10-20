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
using namespace std;
typedef long long ll;
#define N 1005
#define M 1005
int p[N][M];
ll hor[N][M];
ll vol[N][M];
ll dr[N][M];
ll dl[N][M];
ll v[N][M][5];
int main()
{
  freopen("in","r",stdin);
  int n,m,k;
  cin>>n>>m>>k;
  for(int i=0;i<n;++i)
    for(int j=0;j<m;++j)
      cin>>p[i][j];
  for(int i=0;i<n;++i)
    {
      ll s=0;
      for(int j=0;j<m;++j)
	{
	  hor[i][j]=s+(ll)p[i][j];
	  s=hor[i][j];
	}
    }
  for(int i=0;i<m;++i)
    {
      ll s=0;
      for(int j=0;j<n;++j)
	{
	  vol[j][i]=s+(ll)p[j][i];
	  s=vol[j][i];
	}
    }
  for(int i=1-m;i<n;++i)
    {
      ll s=0;
      for(int x=(i<0?0:i),y=(i<0?-i:0);x<n && y<m;++x,++y)
	{
	  dr[x][y]=s+(ll)p[x][y];
	  s=dr[x][y];
	}
    }
  for(int i=1-m;i<n;++i)
    {
      ll s=0;
      for(int x=(i>0?i:0),y=(i<0?m+i-1:m-1); (n > x) && (y >= 0);++x,--y )
	{
	  dl[x][y]=s+(ll)p[x][y];
	  s=dl[x][y];
	}
    }
  for(int i=0;i<=k-1;++i)
    for(int j=k-1-(k-1-(k-1-i));j<=k-1+(k-1-(k-1-i));++j)
      v[k-1][k-1][0]+=(ll)p[i][j];
  for(int i=k-1;i<=k-1+k-1;++i)
    for(int j=k-1-(k-1-(i-(k-1)));j<=k-1+(k-1-(i-(k-1)));++j)
      v[k-1][k-1][1]+=(ll)p[i][j];
  for(int i=0;i<=2*(k-1);++i)
    for(int j=k-1;j<=k-1+(k-1-abs(i-(k-1)));++j)
      v[k-1][k-1][2]+=(ll)p[i][j];
  for(int i=0;i<=2*(k-1);++i)
    for(int j=k-1-(k-1-abs((k-1)-i));j<=k-1;++j)
      v[k-1][k-1][3]+=(ll)p[i][j];
  /*for(int i=0;i<=2*(k-1);++i)
    for(int j=k-1-(k-1-abs(k-1-i));j<=k-1+(k-1-abs(k-1-i));++j)
    v[k-1][k-1][4]+=(ll)p[i][j]*(ll)(k-abs(k-1-i)-abs(k-1-j));*/
  ll mv=v[k-1][k-1][4],mx=k-1,my=k-1;
  for(int i=k;i<=n-k;++i)
    {
      v[i][k-1][0]=v[i-1][k-1][0]+hor[i][(k-1)*2]-(dl[i-1][0]-dl[i-1-(k-1)][k-1])-
	(dr[i-1][k-1+k-1]-((i>k&&k>1)?dr[i-1-(k-1)-1][k-1-1]:0));
      v[i][k-1][1]=v[i-1][k-1][1]-hor[i-1][(k-1)*2]+dr[i+k-1][k-1]+(dl[i+k-1-1][k]-dl[i-1][2*(k-1)+1]);
      v[i][k-1][2]=v[i-1][k-1][2]-dr[i-1][(k-1)*2]+((i>k&&k>1)?dr[i-1-k][k-2]:0)+dl[i+k-1][k-1]-((2*(k-1)+1<m)?dl[i-1][2*(k-1)+1]:0);
      v[i][k-1][3]=v[i-1][k-1][3]-(dl[i-1][0]-(i>k?dl[i-1-k][k]:0))+dr[i+k-1][k-1];
      v[i][k-1][4]=v[i-1][k-1][4]+v[i][k-1][1]-v[i-1][k-1][0];
      if(mv<v[i][k-1][4])
	mv=v[i][k-1][4],mx=i;
      //cout<<i<<' '<<v[i][k-1][4]<<' '<<v[i][k-1][0]<<' '<<v[i][k-1][1]<<' '<<v[i][k-1][2]<<' '<<v[i][k-1][3]<<endl;
    }
  for(int i=k-1;i<=n-k;++i)
    for(int j=k;j<=m-k;++j)
      {
	v[i][j][2]=v[i][j-1][2]-(vol[i+k-1][j-1]-(i>=k?vol[i-k][j-1]:0))+dr[i][j+k-1]-(i>=k?dr[i-k][j-1]:0)+
	  dl[i+k-1][j]-dl[i][j+k-1];
	v[i][j][3]=v[i][j-1][3]+vol[i+k-1][j]-(i>=k?vol[i-k][j]:0)-(dl[i][j-1-(k-1)]-(i>=k?dl[i-k][j]:0))-
	  (dr[i+k-1][j-1]-dr[i][j-1-(k-1)]);
	v[i][j][4]=v[i][j-1][4]+v[i][j][2]-v[i][j-1][3];
	if(v[i][j][4]>mv)
	  mv=v[i][j][4],mx=i,my=j;
	//cout<<mv<<' '<<i<<' '<<j<<' '<<v[i][j][4]<<' '<<v[i][j][2]<<' '<<v[i][j][3]<<' '<<endl;
      }
  cout<<(mx+1)<<' '<<(my+1);
  /*freopen("aout","w",stdout);
  for(int i=k-1;i<=n-k;++i)
    {
      for(int j=k-1;j<=m-k;++j)
	cout<<i<<' '<<j<<' '<<v[i][j][4]<<endl;
      cout<<endl;
      }*/
  return 0;
}
