#include <cstdio>
#include <vector>
using namespace std;
#define MAXV (5000)
#define N (3000000)
int s[MAXV+1];
int num[MAXV+1];
int p[N+1][2];
int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  int n;
  scanf("%d",&n);
  int poi=0;
  for(int i=0;i<2*n;++i)
    {
      int v;
      scanf("%d",&v);
      ++poi;
      p[poi][0]=i+1,p[poi][1]=s[v],s[v]=poi,++num[v];
    }
  for(int i=1;i<=MAXV;++i)
    if(num[i]&1)
      {
	printf("-1");
	return 0;
      }
  for(int i=1;i<=MAXV;++i)
    for(int v=i;s[v];)
      {
	printf("%d ",p[s[v]][0]);
	s[v]=p[s[v]][1];
	printf("%d\n",p[s[v]][0]);
	s[v]=p[s[v]][1];
      }
  return 0;
}
