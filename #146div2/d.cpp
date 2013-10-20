#include <cstdio>
#include <cmath>g
#define N (100000)
int main()
{
  freopen("in","r",stdin);
  int n;
  scanf("%d",&n);
  double X,B,Y1,Y2,Y,a,r1,r2;
  X=Y1=Y2=Y=a=r1=r2=0;
  B=1.0;
  for(int i=0;i<=n;++i)
    {
      r2=r1;
      if(i!=n)
	scanf("%lf",&r1);
      else r1=0;
      a=X+Y;
      //      printf("%lf %lf %lf %lf %lf %lf\n", X,B,Y1,Y2,Y,a);
      if(fabs(r2-1.0)<1e-13)
	{
	  X=a*(1.0-r1);
	  Y=B*(1.0-r1);
	  Y2=-2.0*B*(1.0-r1);
	  Y1=B*(1.0-r1);
	  B=(1.0-B)*(1.0-r1);
	}
      else
	{
	  X=(X*r2/(1.0-r2)+a)*(1.0-r1);
	  Y=(B+(Y-Y2-Y1)*r2/(1-r2))*(1.0-r1);
	  Y2=(-2.0*B+(Y2-2.0*Y1)*r2/(1.0-r2))*(1.0-r1);
	  Y1=(B+Y1*(r2/(1.0-r2)))*(1.0-r1);
	  B=(B*r2/(1.0-r2)+(1.0-B))*(1.0-r1);
	}
    }
  //  ans+=A;
  printf("%.16lf\n",X+Y);
  return 0;
}
