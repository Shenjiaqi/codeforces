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
#define N 1000
#define M 1000
int p[N][M];
ll hor[N][M];
ll vol[N][M];
ll dr[N][M];
ll dl[N][M];
ll v[N][M][5];
int main()
{
  freopen("in","w",stdout);
  int n,m,k;
  n=1000,m=1000,k=100;
  cout<<n<<' '<<m<<' '<<k<<endl;
  srand(18);
  for(int i=0;i<n;++i)
    {
      for(int j=0;j<m;++j)
	cout<<(rand()%1000001)<<' ';
      cout<<endl;
    }
  return 0;
}
