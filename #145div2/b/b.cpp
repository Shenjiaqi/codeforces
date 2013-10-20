#include <cstdio>
#include <cstdlib>
#define N (100)
int p[N][2];
int n,k;
int cmp(const void * a,const void *b)
{
  int *c=(int*)a,*d=(int*)b;
  if(*c==*d)
    return *(c+1)-*(d+1);
  return ((*d)-(*c));
}
int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  scanf("%d%d",&n,&k);
  for(int i=0;i<n;++i)
    {
      scanf("%d",*(p+i));
      p[i][1]=i+1;
    }
  qsort(p,n,sizeof(p[0]),cmp);
  printf("%d\n",p[k-1][0]);
  for(int i=0;i<k;++i)
    printf("%d ",p[i][1]);
  return 0;
}
