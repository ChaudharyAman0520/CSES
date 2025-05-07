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
void bfs(vector<vector<char>>&v,vector<vector<int>>&visited,int i,int j,int n,int m)
{
	queue<pair<int,int>>q;
	q.push({i,j});
	while(q.empty()==false)
	{
		pair<int,int>p=q.front();
		q.pop();
		vector<int>dx={0,1,0,-1};
		vector<int>dy={1,0,-1,0};
		for(int k=0;k<4;k++)
		{
			int nx=p.first+dx[k];
			int ny=p.second+dy[k];
			if(isvalid(nx,ny,n,m))
			{
				if(v[nx][ny]=='.'&&visited[nx][ny]==0)
				{
					visited[nx][ny]=1;
					q.push({nx,ny});
				}
			}
		}
	}
}
main()
{
	int n,m,ans=0;
	cin>>n>>m;
	vector<vector<char>>v;
	for(int i=0;i<n;i++)
	{
		vector<char> supp;
		for(int j=0;j<m;j++)
		{
			char x;
			cin>>x;
			supp.push_back(x);
		}
		v.push_back(supp);
	}
	//~ for(auto i:v)
	//~ {
		//~ for(auto j:i)
		//~ {
			//~ cout<<j<<;
		//~ }
		//~ cout<<endl;
	//~ }	
	vector<vector<int>> visited(n, vector<int>(m, 0));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(visited[i][j]==0&&v[i][j]=='.')
			{
				bfs(v,visited,i,j,n,m);
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}
