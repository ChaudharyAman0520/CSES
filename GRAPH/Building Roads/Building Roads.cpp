#include<bits/stdc++.h>
using namespace std;
void bfs(unordered_map<int, vector<int>>&v,vector<int>&visited,int nodes,int src)
{
	queue<int>q;
	q.push(src);
	while(q.empty()==false)
	{
		int curr=q.front();
		q.pop();
		for(auto i:v[curr])
		{
			if(visited[i]==0)
			{
				visited[i]=1;
				q.push(i);
			}
		}
	}
}
main()
{
	int n,m;
	cin>>n>>m;
	unordered_map<int, vector<int>>v;
	for(int i=1;i<=m;i++)
	{
		int s,e;
		cin>>s>>e;
		v[s].push_back(e);
		v[e].push_back(s);
	}
	
	//~ for(auto i:v)
	//~ {
		//~ cout<<i.first<<"->";
		//~ for(auto j:i.second)
		//~ {
			//~ cout<<j<<"->";
		//~ }
		//~ cout<<endl;
	//~ }
	
	vector<int> visited(n+1,0);
	for(auto i:v)
	{
		for(auto j:i.second)
		{
			if(visited[j]==0)
			{
				bfs(v,visited,n,j);
				visited[j]=2;
			}
		}
	}
	int start=-1,k=0;
	//~ for(int i=1;i<=n;i++)
	//~ {
		//~ cout<<i<<" "<<visited[i]<<endl;
	//~ }
	for(int i=1;i<=n;i++)
	{
		if(visited[i]==2||visited[i]==0)
		{
			if(start==-1)
			{
				start=i;
			}
			k++;
		}
	}
	cout<<k-1<<endl;
	for(int i=1;i<=n;i++)
	{
		if((visited[i]==2||visited[i]==0)&&(i!=start))
		{
			cout<<start<<" "<<i<<endl;
		}
	}
}
