#include <cstdio>
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
  freopen("in","r",stdin);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  string s,t;
  cin>>s>>t;
  int nums['Z'+1]={0},numt['Z'+1]={0},chg['Z'+1]={0},cg['Z'+1]={0};
  for(int i=0;i<s.length();++i)
    ++nums[s[i]],++numt[t[i]],++cg[s[i]];
  int ans(0);
  for(int i='A';i<='Z';++i)
    if(nums[i]>numt[i])
      ans+=nums[i]-numt[i],chg[i]=nums[i]-numt[i];
  cout<<ans<<endl;
  for(int i=0,j='A';i<s.length() && ans>0;++i)
    if(nums[s[i]]>numt[s[i]])
      {
	for(;nums[j]>=numt[j];++j)
	  ;
	--cg[s[i]];
	if(s[i]>j || cg[s[i]]<chg[s[i]])
	  {
	    --chg[s[i]];
	    --nums[s[i]],++nums[j];
	    --ans;
	    s[i]=j;
	  }
      }
  cout<<s;
  return 0;
}
