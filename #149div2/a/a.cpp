#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
  freopen("in","r",stdin);
  int x,y,a,b;
  scanf("%d%d%d%d",&x,&y,&a,&b);
  int n(0);
  for(int c=max(a,b+1);c<=x;++c)
    for(int d=b;d<min(y+1,c);++d)
	++n;
  printf("%d",n);
  for(int c=max(a,b+1);c<=x;++c)
    for(int d=b;d<min(y+1,c);++d)
	printf("\n%d %d",c,d);
  return 0;
}
