#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

const int N=3000+10;
bool uechveli[N],ushanso[N],f[N][N];
int k,n,p[N],answer,i;

void rec(int i,int l,int round)
{

 if ( f[i+3][l+3] ) return;

 //cout<<i<<" "<<l<<endl;

 f[i+3][l+3]=true;

 answer++;

 if ( round==k || l<=0 ) return;

 if ( !ushanso[l] && p[i]>0 ) rec(n+1-l+1,l-2,round+1);
 if ( !ushanso[l] && p[i]<100 ) rec(n+1-l,l-1,round+1);
 if ( !uechveli[l] && p[i]>0 ) rec(i,l-1,round+1);
 if ( !uechveli[l] && p[i]<100 ) rec(i,l,round+1);
}

main()
{
 cin>>n>>k;
 for ( i=1;i<=n;i++ )
  cin>>p[i];

 if ( p[n]==100 ) uechveli[1]=true;
 if ( p[n]==0 ) ushanso[1]=true;

 for ( i=2;i<=n;i++ )
  if ( uechveli[i-1] || p[n-i+1]==100 ) uechveli[i]=true;
  else if ( ushanso[i-1] && p[n-i+1]==0 ) ushanso[i]=true;

 rec(1,n-1,0);

 cout<<answer<<endl;
}
