#include<bits/stdc++.h>
using namespace std;
bool isValid(int i,int j,int n,int m)
{
	if(i<0||i>n-1)
	{
		return false;
	}
	if(j<0||j>m-1)
	{
		return false;
	}
	return true;
}
void bfs(vector<vector<char>>adj,vector<vector<bool>>&visited,vector<vector<int>>&dist)
{
	queue<pair<pair<int,int>,int>>q;
	int n=adj.size();
	int m=adj[0].size();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(adj[i][j]=='M')
			{
				visited[i][j]=true;
				//~ cout<<"i = "<<i<<" "<<"j = "<<j<<endl;
				q.push({{i,j},0});
				dist[i][j]=0;
			}
		}
	}
	
	while(q.empty()==false)
	{
		auto it=q.front();
		q.pop();
		vector<int> dx={0,1,0,-1};
		vector<int> dy={1,0,-1,0};
		for(int k=0;k<4;k++)
		{
			int nx=it.first.first+dx[k];
			int ny=it.first.second+dy[k];
			if(isValid(nx,ny,n,m))
			{
				if(visited[nx][ny]==false&&(adj[nx][ny]=='.'||adj[nx][ny]=='A'))
				{
					//~ cout<<"i = "<<nx<<" "<<"j = "<<ny<<endl;
					q.push({{nx,ny},it.second+1});
					visited[nx][ny]=true;
					dist[nx][ny]=min(dist[nx][ny],it.second+1);
				}
			}
		}
	}
}

void srcbfs(vector<vector<char>>&adj,vector<vector<int>>&dist)
{
	int n=adj.size();
	int m=adj[0].size();
	vector<vector<char>> from(n,vector<char>(m,'X'));
	vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>>(m,{-1,-1}));
	vector<vector<int>>visited(n,vector<int>(m,0));
	vector<vector<int>> distance(n,vector<int>(m,INT_MAX));
	int srcx=-1,srcy=-1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(adj[i][j]=='A')
			{
				srcx=i;
				srcy=j;
				break;
			}
		}
	}
	queue<pair<pair<int,int>,int>>q;
	q.push({{srcx,srcy},0});
	visited[srcx][srcy]=1;
	distance[srcx][srcy]=0;
	while(q.empty()==false)
	{
		auto it=q.front();
		q.pop();
		int i=it.first.first;
		int j=it.first.second;
		int d=it.second;
		vector<int> dx={-1,0,1,0};
		vector<int> dy={0,1,0,-1};
		vector<char> dir={'U','R','D','L'};
		for(int k=0;k<4;k++)
		{
			int nx=i+dx[k];
			int ny=j+dy[k];
			if(isValid(nx,ny,n,m))
			{
				if(visited[nx][ny]==0&&adj[nx][ny]=='.')
				{
					visited[nx][ny]=1;
					distance[nx][ny]=d+1;
					q.push({{nx,ny},d+1});
					from[nx][ny]=dir[k];
					parent[nx][ny]={i,j};
				}
			}
		}
	}
	//~ cout<<endl<<endl;
	//~ for(auto i:distance)
	//~ {
		//~ for(auto j:i)
		//~ {
			//~ cout<<j<<" ";
		//~ }
		//~ cout<<endl;
	//~ }
	//~ cout<<endl<<endl;
	//~ for(auto i:from)
	//~ {
		//~ for(auto j:i)
		//~ {
			//~ cout<<j<<" ";
		//~ }
		//~ cout<<endl;
	//~ }
	//~ cout<<endl<<endl;
	//~ for(auto i:parent)
	//~ {
		//~ for(auto j:i)
		//~ {
			//~ cout<<"{"<<j.first<<","<<j.second<<"}"<<" ";
		//~ }
		//~ cout<<endl;
	//~ }
	int desx=-1,desy=-1;
	bool flag=false;
	for(int i=0;i<n;i++)
	{
		if(distance[i][0]<dist[i][0])
		{
			desx=i;
			desy=0;
			flag=true;
			break;
		}
		if(distance[i][m-1]<dist[i][m-1])
		{
			desx=i;
			desy=m-1;
			flag=true;
			break;
		}
	}
	for(int i=0;i<m;i++)
	{
		if(distance[0][i]<dist[0][i])
		{
			desx=0;
			desy=i;
			flag=true;
			break;
		}
		if(distance[n-1][i]<dist[n-1][i])
		{
			desx=n-1;
			desy=i;
			flag=true;
			break;
		}
	}
	if(flag==false)
	{
		cout<<"NO"<<endl;
		return;
	}
	//~ else
	//~ {
		//~ cout<<"YES"<<endl;
		//~ cout<<desx<<" "<<desy<<endl;
	//~ }
	vector<char> ans;
	while(parent[desx][desy].first!=-1&&parent[desx][desy].second!=-1)
	{
		ans.push_back(from[desx][desy]);
		int px=parent[desx][desy].first;
		int py=parent[desx][desy].second;
		desx=px;
		desy=py;
	}
	reverse(ans.begin(),ans.end());
	cout<<"YES"<<endl;
	cout<<ans.size()<<endl;
	for(auto i:ans)
	{
		cout<<i;
	}
}
main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<char>> adj;
	for(int i=0;i<n;i++)
	{
		vector<char> supp;
		for(int j=0;j<m;j++)
		{
			char ch;
			cin>>ch;
			supp.push_back(ch);
		}
		adj.push_back(supp);
	}
	vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
	vector<vector<bool>> visited(n,vector<bool>(m,false));
	bfs(adj,visited,dist);
	//~ for(auto i:dist)
	//~ {
		//~ for(auto j:i)
		//~ {
			//~ cout<<j<<" ";
		//~ }
		//~ cout<<endl;
	//~ }
	srcbfs(adj,dist);
}
