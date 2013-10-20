#include <cstdio>
#define N (100005)
double a[N],x[N],y[N],y1[N],y2[N],b[N],c[N],p[N];
int main()
{
  freopen("in","r",stdin);
  int n;
  scanf("%d",&n);
  b[0]=c[0]=1.0;
  for(int i=1;i<=n+1;++i)
    {
      if(i<=n)
	scanf("%lf",p+i);
      else p[i]=0;
      x[i]=p[i-1]*x[i-1]+a[i-1];
      y[i]=(2.0*(double)i-3.0)*y1[i-1]-2.0*y2[i-1]+y[i-1]*p[i-1];
      y1[i]=y1[i-1]*p[i]+b[i-1]*p[i];
      y2[i]=y2[i-1]*p[i]+(i-1)*b[i-1]*p[i];
      c[i]=c[i-1]*p[i-1]+b[i-1];
      a[i]=(1.0-p[i])*(x[i]+y[i]);
      b[i]=(1.0-p[i])*c[i];
      // printf("%lf %lf %lf %lf\n",p[i],a[i],x[i],y[i]);
    }
  printf("%.6lf",a[n+1]);
  return 0;
}
