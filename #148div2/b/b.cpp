#include <cstdio>
#include <cstring>
#define N (100)
char s[N+1];
char tmp[N+1];
bool valid[N+1];
int times[10];
void solv(char * s,int len)
{
  int cp=1,dp=1,lp;
  lp=0;
  for(;;)
    {
      if(cp<=0 || cp>len)
	break;
      if(valid[cp]==1)
	cp+=dp;
      else if(s[cp]>='0' && s[cp]<='9')
	{
	  //printf(" !%c %d! ",s[cp],cp);
	  ++times[s[cp]-'0'];
	  --s[cp];
	  if(s[cp]<'0')
	    valid[cp]=1;
	  lp=cp;
	  cp+=dp;
	}
      else
	{
	  if(s[cp]=='<')
	    dp=-1;
	  else dp=1;//s[cp]=='>'
	  int tmp=lp;
	  lp=cp;
	  cp+=dp;
	  if(cp>=1 && cp<=len)
	    if(s[tmp]=='<' || s[tmp]=='>')
	      valid[tmp]=1;
	}
    }
}
int main()
{
  freopen("in","r",stdin);
  int n,q;
  scanf("%d%d",&n,&q);
  scanf("%s",s+1);
  for(int j=0;j<q;++j)
    {
      int l,r;
      memcpy(tmp,s,sizeof(tmp));
      memset(valid,0,sizeof(valid));
      memset(times,0,sizeof(times));
      scanf("%d%d",&l,&r);
      solv(tmp+l-1,r-l+1);
      for(int i=0;i<10;++i)
	printf("%d ",times[i]);
      printf("\n");
    }
  return 0;
}
