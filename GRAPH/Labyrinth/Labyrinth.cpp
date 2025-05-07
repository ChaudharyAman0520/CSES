#include<bits/stdc++.h>
using namespace std;
bool isvalid(int i,int j,int n,int m)
{
	if(i<0||i>=n)
	{
		return false;
	}
	if(j<0||j>=m)
	{
		return false;
	}
	return true;
}
void bfs(vector<vector<char>>&v,pair<int,int>src,pair<int,int>dest,int n,int m)
{
	vector<vector<int>>visited(n,vector<int>(m,0));
	queue<pair<int,int>>q;
	q.push(src);
	vector<vector<pair<int,int>>> from(n,vector<pair<int,int>>(m,{-1,-1}));
	vector<vector<char>> direc(n,vector<char>(m,'X'));
	from[src.first][src.second]=src;
	direc[src.first][src.second]='H';
	visited[src.first][src.second]=1;
	while(q.empty()==false)
	{
		pair<int,int>p=q.front();
		q.pop();
		vector<int>dx={0,1,0,-1};
		vector<int>dy={1,0,-1,0};
		vector<char> move = {'R','D','L','U'};
		bool flag=false;
		for(int k=0;k<4;k++)
		{
			int nx=p.first+dx[k];
			int ny=p.second+dy[k];
			if(isvalid(nx,ny,n,m))
			{
				if(nx==dest.first&&ny==dest.second)
				{
					from[nx][ny]={p.first,p.second};
					direc[nx][ny]=move[k];
					visited[nx][ny]=1;
					flag=true;
				}
				else
				{
					if(v[nx][ny]=='.'&&visited[nx][ny]==0)
					{
						visited[nx][ny]=1;
						q.push({nx,ny});
						from[nx][ny]={p.first,p.second};
						direc[nx][ny]=move[k];
					}
				}
			}
		}
		if(flag==true)
		{
			break;
		}
	}
	for(auto i:visited)
	{
		for(auto j:i)
		{
			cout<<j<<" ";
		}
		cout<<endl;
	}
	for(auto i:from)
	{
		for(auto j:i)
		{
			cout<<"{"<<j.first<<","<<j.second<<"}"<<" ";	
		}
		cout<<endl;
	}
	for(auto i:direc)
	{
		for(auto j:i)
		{
			cout<<j<<" ";
		}
		cout<<endl;
	}
	if(visited[dest.first][dest.second]==0)
	{
		cout<<"NO"<<endl;
		return;
	}
	int length=0;
	vector<char>result;
	while(direc[dest.first][dest.second]!='H')
	{
		length++;
		result.push_back(direc[dest.first][dest.second]);
		dest=from[dest.first][dest.second];
	}
	reverse(result.begin(),result.end());
	cout<<"YES"<<endl<<length<<endl;
	for(auto i:result)
	{
		cout<<i;
	}
	cout<<endl;
}
main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<char>>v;
	for(int i=0;i<n;i++)
	{
		vector<char> supp;
		for(int j=0;j<m;j++)
		{
			char ch;
			cin>>ch;
			supp.push_back(ch);
		}
		v.push_back(supp);
	}
	//~ for(auto i:v)
	//~ {
		//~ for(auto j:i)
		//~ {
			//~ cout<<j;
		//~ }
		//~ cout<<endl;
	//~ }
	pair<int,int>src,dest;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(v[i][j]=='A')
			{
				src={i,j};
			}
			if(v[i][j]=='B')
			{
				dest={i,j};
			}
		}
	}
	bfs(v,src,dest,n,m);
}
