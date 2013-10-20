#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
#define PAK(a,b) ((a<<20)|(b))
#define N (200)
#define INF (200*200*200+1)
typedef long long ll;
map<ll,int> mapp[2][2];
void add(int a,int b,ll la,ll lb,int v)
{
  //printf("%d %lld %lld\n",v,la,lb);
  if(mapp[a][b].find(PAK(la,lb))==mapp[a][b].end())
    mapp[a][b][PAK(la,lb)]=v;
  else if(mapp[a][b][PAK(la,lb)]>v)
    mapp[a][b][PAK(la,lb)]=v;
}
int p[N+1];
int q[N+1];
int main()
{
  freopen("input.txt","r",stdin);
  //  freopen("output.txt","w",stdout);
  int n;
  ll a,b;
  //  scanf("%d%I64d%I64d",&n,&a,&b);
  scanf("%d%lld%lld",&n,&a,&b);
  for(int i=0;i<n;++i)
    scanf("%d",p+i);
  for(int i=n-1;i>=0;--i)
    q[i]=q[i+1]+p[i];
  if(a>=p[0])
    {
      a-=p[0];
      mapp[0][0][PAK(a,b)]=0;
    }
  if(b>=p[0])
    {
      b-=p[0];
      mapp[0][1][PAK(a,b)]=0;
    }
  int ans=INF;
  for(int i=1,ra=p[0];i<n;++i)
    {
      //printf("!!%d\n",i);
      int t=p[i];
      int c=i&1;
      int d=1-c;
      //printf("!%d %d\n",mapp[d][0].size(),mapp[d][1].size());
      mapp[c][0].clear();
      mapp[c][1].clear();
      for(int j=0;j<2;++j)
	{
	  for(map<ll,int>::iterator ite=mapp[d][j].begin();ite!=mapp[d][j].end();++ite)
	    {
	      //	      printf("!%d\n",ite->second);
	      ll y=ite->first;
	      ll e=y>>20;
	      ll f=y&((1<<20)-1);
	      if(e>=q[i])
		ans=min(ans,ite->second+((j==0)?0:min(ra,t)));
	      if(f>=q[i])
		ans=min(ans,ite->second+((j==1)?0:min(ra,t)));
	      if(e>=t)
		{
		  int tmp=ite->second+j*min(ra,t);
		  if(tmp<ans)
		    add(c,0,e-t,f,tmp);
		}
	      if(f>=t)
		{
		  int tmp=ite->second+(1-j)*min(ra,t);
		  if(tmp<ans)
		    add(c,1,e,f-t,tmp);
		}
	    }
	}
      ra=t;
    }
  int u=(n-1)&1;
  if(ans<INF)
    printf("%d",ans);
  else printf("-1");
  return 0;
}
