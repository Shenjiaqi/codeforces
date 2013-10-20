#include <cstdio>
#define N (100)
int n;
char p[N+1];
void pt(int a,int b)
{
  if(p[a]=='R' && p[b]=='L')
    a^=b,b^=a,a^=b;
  printf("%d %d\n",a,b);
}
int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  scanf("%d\n",&n);
  printf("%d\n",n);
  for(int i=1;i<=n;++i)
    scanf("%c",p+i);
  pt(1,n/2+1);
  pt(n,n/2);//n>=4
  for(int i=2;i<n/2;++i)
    pt(i,n-i+1);
  return 0;
}
