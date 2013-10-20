#pragma comment(linker, "/STACK:16777216")	
#include <iostream>
#include <set>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>
#include <stdlib.h>
#include <sstream>
#include <memory.h>
#include <ctime>
//#include <fstream>
using namespace std;
 
using namespace std;

double const PI = acos(-1.0);
double const EPS=1e-7;

#define INF 1000000000
#define MP make_pair
#define FILL(A,value) memset(A,value,sizeof(A))
#define MOD 1000000009

int a[1100][1100];
int s1[1100][1100];
int s2[1100][1100];

int n,m;

int get1(int x1,int y1,int x2,int y2){
	
  int res=s1[x2][y2];
  if (x1!=0 && y1!=0) res-=s1[x1-1][y1-1];
  return res;
}

int get2(int x1,int y1,int x2,int y2){
	
  int res=s2[x2][y2];
  if (x1!=0 && y1!=m-1) res-=s2[x1-1][y1+1];
  return res;
}

long long f(int x,int y,int k){
  long long res=a[x][y]*(long long)k;
  for (int i=1; i<k; i++){
    int p[4][2]={{x-i,y},{x,y-i},{x+i,y},{x,y+i}};

    /*cout<<get1(p[0][0],p[0][1],p[3][0],p[3][1])<<endl;
      cout<<get1(p[1][0],p[1][1],p[2][0],p[2][1])<<endl;
      cout<<get2(p[0][0],p[0][1],p[1][0],p[1][1])<<endl;
      cout<<get2(p[3][0],p[3][1],p[2][0],p[2][1])<<endl;*/

    res+=  (get1(p[0][0]+1,p[0][1]+1,p[3][0],p[3][1]) + get1(p[1][0],p[1][1],p[2][0]-1,p[2][1]-1) +
	    get2(p[0][0],p[0][1],p[1][0]-1,p[1][1]+1) + get2(p[3][0]+1,p[3][1]-1,p[2][0],p[2][1]) /*- 
												    a[p[0][0]][p[0][1]] - a[p[1][0]][p[1][1]] - a[p[2][0]][p[2][1]] - a[p[3][0]][p[3][1]]*/) * (long long) (k-i);


  }


  return res;
}

int main(){

  freopen("in","r",stdin);
  int k;
  cin>>n>>m>>k;
  //n=m=1000;
  //k=200;
  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
      scanf("%d",&a[i][j]);
      //a[i][j]=rand();
    }
  }

  for (int i=0; i<n; i++){
    s1[i][0]=a[i][0];
    s2[i][m-1]=a[i][m-1];
  }

  for (int j=0; j<m; j++){
    s1[0][j]=s2[0][j]=a[0][j];
  }


	
  for (int i=1; i<n; i++){
    for (int j=0; j<m; j++){
      if (j!=0){
	s1[i][j]=a[i][j]+s1[i-1][j-1];
      }
      if (j!=m-1){
	s2[i][j]=a[i][j]+s2[i-1][j+1];
      }
    }
  }
  /*cout<<endl;
    for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
    cout<<s2[i][j]<<' ';
    }
    cout<<endl;
    }
    cout<<endl;*/

  int p=-1,q=-1;
  long long mm=-INF;
  freopen("bout","w",stdout);
  for (int i=k-1; i<=n-k; i++){
    for (int j=k-1; j<=m-k; j++){
      long long c=f(i,j,k);
      //	cout<<c<<' ';
      cout<<i<<' '<<j<<' '<<c<<endl;
      if (c>mm){
	mm=c;
	p=i;
	q=j;
      }
    }
    //cout<<endl;
  }
  cout<<p+1<<' '<<q+1<<endl;




}
