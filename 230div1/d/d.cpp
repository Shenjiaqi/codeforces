#include <cstdio>
#include <queue>
#include <list>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <utility>
using namespace std;
const int N = 1e5 + 7;
const int inf = 1e7;
struct ss
{
  int l0,l1,l2;
  ss(int a, int b ,int c){ l0 = a, l1 = b, l2 = c;};
};
int main()
{
  int n;
  scanf("%d", &n);
  vector<int> array[3];
  map<int,int> hash;
  for( int i = 0 ; i < 3 ; ++i )
    {
      for( int j = 0 ; j < n ; ++j )
	{
	  int v;
	  scanf("%d", &v);
	  array[i].push_back(v);
	  hash[v] = 0;
	}
    }
  int cnt = 0;
  for( typeof( hash.begin() ) i = hash.begin(); i != hash.end() ; ++i )
    i->second = ++cnt;
  vector<int> vis[3];
  vector<pair<int,int> > appSeq[3];
  for( int i = 0 ; i < 3; ++i )
    {
      vis[i].resize( cnt + 1 );
      appSeq[i].push_back( make_pair(0,0) );
      for( int j = 0 ; j < n ; ++j )
	{
	  int val = hash[ array[i][j] ] ;
	  if( vis[i][val] == 0 )
	  {
	    vis[i][val] = appSeq[i].size();
	    appSeq[i].push_back( make_pair( val, j + 1) );
	  }
	}
    }
  int s[3] = {0};
  for( int i = 1 ; i <= cnt; ++i )
    {
      int count = 0, ci = 0;
      for( int j = 0 ; j < 3; ++j )
	if( vis[j][i] != 0 )
	  ++count, ci = j;
      if( count == 1 )
	s[ci] = max( s[ci], vis[ci][i] );
    }
//   queue<int> jmpList;
//   for( int i = appSeq[0].size() - 1, j = s[1]; ; --i )
//     {
//       jmpList.push(j);
//       if( i < s[0] )
// 	break;
//       int val = appSeq[0][i].first;
//       int posIn1 = vis[1][val];
//       if( posIn1 != 0 )
// 	j = max(j, posIn1);
//       else break;
//     }
//   queue<ss> candList;
  vector<queue<int> > insertList;
  vector<queue<int> > removeList;
  vector<int> canInsert;
  insertList.resize( cnt + 1 );
  removeList.resize( cnt + 1 );
  canInsert.resize( appSeq[2].size() );
  for( int i = appSeq[2].size() - 1, j = s[0], k = s[1]; i >= s[2] ; --i )
    {
      if( j < inf )
	{
	  removeList[0][j-1].push(i);
	  insertList[ appSeq[0].size() - 1 ].push(i);
	}
      if( k < inf )
	insertList[k].push(i);
      canInsert[i] = k;
//       candList.push( ss(j, k, i ) );
      int passVal = appSeq[2][i].first;
      int posIn0 = vis[0][passVal];
      int posIn1 = vis[1][passVal];
//       int rj = j;
//       if( posIn1 > k )
// 	j = max( j, posIn1 );
//       if( posIn0 > rj )
// 	k = max( k, posIn0 );
	  j = max( j, posIn0 == 0 ? inf : posIn0 );
	  k = max( k, posIn1 == 0 ? inf : posIn0);
    }

  //------------------------
//   for( int i = 0 ; i < 3 ; ++i )
//     {
//       for( int j = 0 ; j < appSeq[i].size(); ++j )
// 	cout << appSeq[i][j].first << ' ';
//       cout << endl;
//     }
//   for( ; !jmpList.empty() ; jmpList.pop() )
//     cout << jmpList.front() << ' '; cout << endl; 
//   for( ; !candList.empty(); candList.pop() )
//     {
//       ss tmpSs =candList.front();
//       cout << tmpSs.l0 << ' ' << tmpSs.l1 << ' ' << tmpSs.l2 << endl;
//     }
//   return 0;
  //------------------------

  int ans = 3 * n + 1;
  stack<ss> rCandList;
  set<int> minArray;
  vector<bool> inMinArray;
  inMinArray.resize( appSeq[2].size() );
  int t[3];
  t[0] = appSeq[0].size() - 1;
  t[1] = s[1];
  t[2] = appSeq[2].size() - 1;
  for( ; t[0] >= s[0] ; --t[0] )
    {
      for( ; !insertList[ t[1] ].empty() ; insertList[ t[1] ].pop() )
	  {
	    int posIn2 = insertList[ t[1] ].front();
	    if( !inMinArray[posIn2] )
	      {
		inMinArray[posIn2] = true;
		minArray.insert(posIn2);
	      }
	  }
      ans = min( ans, appSeq[0][ t[0] ].second + appSeq[1][ t[1] ].second +
		 appSeq[2][ *minArray.begin() ].second );
      for( ; !removeList[ t[0] ].empty() ; removeList[ t[0] ].pop() )
	{
	  int posIn2 = removeList[ t[0] ].empty();
	  if( canInsert[ posIn2 ] < t[1] )
	    {
	      insertList[ canInsert[ posIn2 ] ].push( posIn2 );
	      set.erase(posIn2);
	      inMinArray[posIn2] =false;
	    }
	}
    }
  printf("%d", ans);
  return 0;
}
