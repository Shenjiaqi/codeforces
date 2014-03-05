#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
using namespace std;
const int N = 50007;
const int M = 150007;
const int Q = 250007;
bool onLine[N];
bool bigSet[N];
list<int> friends[N];
int initF[M][2];
int query[Q][3];
int friendCnt[N];
int onLineFriends[N];
const int lim = 200;
void setFriend( int a, int b)
{
  if( !bigSet[a] || bigSet[b] )
    friends[a].push_back(b);
}
void addFriend( int a, int b)
{
  setFriend( a, b);
  setFriend( b, a);
  if( onLine[a] && !bigSet[a] )
    ++onLineFriends[b];
  if( onLine[b] && !bigSet[b] )
    ++onLineFriends[a];
}
void unSetFriend( int a, int b)
{
  if( !bigSet[a] || bigSet[b] )
    for( typeof( friends[a].begin() ) i = friends[a].begin();
	 i != friends[a].end(); ++i )
      if( *i == b )
	{
	  friends[a].erase(i);
	  break;
	}
}
void delFriend( int a, int b)
{
  unSetFriend( a, b);
  unSetFriend( b, a);
  if( onLine[a] && !bigSet[a] )
    --onLineFriends[b];
  if( onLine[b] && !bigSet[b] )
    --onLineFriends[a];
}
int main()
{
  int n, m, q, o;
  scanf("%d%d%d%d", &n, &m, &q, &o);
  for( int i = 0 ; i < o ; ++i )
    {
      int id;
      scanf("%d", &id);
      onLine[id] = true;
    }
  for( int i = 0 ; i < m ; ++i )
    {
      scanf("%d%d", &initF[i][0], &initF[i][1] );
      ++friendCnt[ initF[i][0] ];
      ++friendCnt[ initF[i][1] ];
    }
  for( int i = 0 ; i < q ; ++i )
    {
      char type;
      scanf("\n%c %d", &type, &query[i][1]);
      query[i][0] = type;
      if( type == 'A' || type == 'D' )
	{
	  scanf("%d", &query[i][2]);
	  if( type == 'A' )
	    {
	      ++friendCnt[ query[i][1] ];
	      ++friendCnt[ query[i][2] ];
	    }
	}
    }
  for( int i = 1; i <= n ; ++i )
    if( friendCnt[i] > lim )
      bigSet[i] = true;
  for( int i = 0 ; i < m ; ++i )
    addFriend( initF[i][0], initF[i][1] );
  for( int i = 0 ; i < q ; ++i )
    {
      if( query[i][0] == 'O' )
	{
	  int v = query[i][1];
	  onLine[v] = true;
	  if( !bigSet[v] )
	    for( typeof(friends[v].begin()) j = friends[v].begin();
		 j != friends[v].end(); ++j )
	      ++onLineFriends[*j];
	
	}
      else if( query[i][0] == 'F' )
	{
	  int v = query[i][1];
	  onLine[v] = false;
	  if( !bigSet[v] )
	    for( typeof( friends[v].begin() ) j = friends[v].begin();
		 j != friends[v].end(); ++j )
	      --onLineFriends[*j];
	}
      else if( query[i][0] == 'A' )
	{
	  addFriend( query[i][1], query[i][2] );
	}
      else if( query[i][0] == 'D' )
	{
	  delFriend( query[i][1], query[i][2] );
	}
      else
	{
	  // query[i][0] == 'C'
	  int v = query[i][1];
	  int ans = onLineFriends[v];
	  for( typeof( friends[v].begin() ) j = friends[v].begin(); 
	       j != friends[v].end(); ++j )
	    if( bigSet[*j] && onLine[*j] )
	      ++ans;
	  printf("%d\n", ans);
	}
    }
  return 0;
}
