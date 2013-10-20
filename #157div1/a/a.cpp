#include <cstdio>
int main()
{
  freopen("in.txt","r",stdin);
  bool del=false;
  char output[100001]={0};
  int n=0;
  for(char t;EOF!=scanf("%c",&t);)
    {
      if(t!='1' && t!='0')
	break;
      if(del==true || t!='0')
	output[n++]=t;
      else
	del=true;
    }
  if(del==false)
    output[n-1]='\0';
  printf("%s",output);
  return 0;
}
