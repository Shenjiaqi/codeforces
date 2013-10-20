#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
#include <cmath>
using namespace std;
int main()
{
  freopen("in","r",stdin);
  int n;
  cin>>n;
  typedef pair<int,int> pp;
  vector<pp> pos;
  pos.resize(n);
  for(int i=0;i<n;++i)
    cin>>pos[i].first>>pos[i].second;
  vector<double> ang;
  ang.resize(n);
  for(int i=0;i<n;++i)
    {
      ang[i]=(double)180.0*acos((double)pos[i].first/(sqrt((double)pos[i].first*pos[i].first+(double)pos[i].second*pos[i].second)))/(double)3.14159265359;
      if(pos[i].second<0)
	ang[i]=360.0-ang[i];
    }
  sort(ang.begin(),ang.end());
  double ans=0.0;
  for(int i=0;i<n-1;++i)
    ans=max(ans,fabs(ang[i+1]-ang[i]));
  ans=max(ans,360-ang[n-1]+ang[0]);
  printf("%.7lf",(360.0-ans));
  return 0;
}
