#include <cstdio>
#define N (100000)
int seg[N][6];
int cmp(const void *a,const void *b)
{
  int *c=(int*)a,*d=(int*)b;
  if(*c!=*d)
    return *c-*d;
  ++c,++d;
  if(*c!=*d)
    return *c-*d;
  ++c,++d;
  return *c-*d;
}
int main()
{
  int x0,y0,x1,y1;
  scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;++i)
    scanf("%d%d",*(seg+i),*(seg)+1,*(seg+2));
  qsort(seg,n,sizeof(seg[0]),cmp);
  for(
}
