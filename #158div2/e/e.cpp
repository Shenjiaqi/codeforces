#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
using namespace std;
typedef pair<int,int> pp;
vector<pp> pos;
struct node{
  vector<int> y;
  int left;
  int right;
};
vector< node > tree;
void init(int f,int t,int k)
{
  if(f>t)
    return;
  if(k>=tree.size())
    tree.resize(k+1);
  tree[k].left=pos[f].first,tree[k].right=pos[t].first;
  for(int i=f;i<=t;++i)
    tree[k].y.push_back(pos[i].second);
  sort(tree[k].y.begin(),tree[k].y.end());
  int m=(f+t)>>1;
  if(f<t)
    {
      init(f,m,k<<1);
      init(m+1,t,(k<<1)|1);
    }
}
int que(int lev,int x,int yy)
{
  if(lev>=tree.size())
    return 0;
  if(x<tree[lev].left)
    return 0;
  if(tree[lev].y.size()==0 ||yy<tree[lev].y[0])
    return 0;
  int r(0);
  if(x>=tree[lev].right)
    return (upper_bound((tree[lev].y).begin(),(tree[lev].y).end(),yy)-tree[lev].y.begin());
  else
    {
      r=que(lev<<1,x,yy);
      r+=que((lev<<1)|1,x,yy);
    }
  //cout<<'r'<<' '<<r<<' '<<lev<<' '<<tree[lev].left<<' '<<tree[lev].right<<' '<<x<<' '<<yy<<endl;
  return r;
}
int main()
{
  freopen("in","r",stdin);
  int n;
  cin>>n;
  pos.resize(n);
  vector<int> x,y;
  x.resize(n),y.resize(n);
  for(int i=0;i<n;++i)
    {
      cin>>pos[i].first>>pos[i].second;
      x[i]=pos[i].first;
      y[i]=pos[i].second;
    }
  vector<int> num(9);
  for(int i=0;i<9;++i)
    cin>>num[i];
  sort(pos.begin(),pos.end());
  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  tree.resize(3*n+1);
  init(0,n-1,1);
  sort(num.begin(),num.end());
  for(;;)
    {
      int a=num[0]+num[3]+num[6]-1;
      int b=a+num[1]+num[4]+num[7];
      int c=num[6]+num[7]+num[8]-1;
      int d=c+num[3]+num[4]+num[5];
      if((x[a]!=x[a+1]) && ( x[b]!=x[b+1]) && 
	 (y[c]!=y[c+1]) && (y[d]!=y[d+1]))
	{
	  if(que(1,x[a],y[c])==num[6] &&
	     que(1,x[a],y[d])==num[6]+num[3] &&
	     que(1,x[b],y[c])==num[6]+num[7] &&
	     que(1,x[b],y[d])==num[6]+num[7]+num[3]+num[4])
	    {
	      //for(int i=0;i<9;++i)
	      //cout<<num[i]<<' ';
	      //cout<<endl;
	      printf("%f ",((float)x[a]+x[a+1])/2.0);
	      printf("%f\n",((float)x[b]+x[b+1])/2.0);
	      printf("%f ",((float)y[c]+y[c+1])/2.0);
	      printf("%f",((float)y[d]+y[d+1])/2.0);
	      return 0;
	    }
	}
      if(!next_permutation(num.begin(),num.end()))
	break;
    }
  printf("-1");
  return 0;
}
