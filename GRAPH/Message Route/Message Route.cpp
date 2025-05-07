#include<bits/stdc++.h>
using namespace std;
void bfs(unordered_map<int,vector<int>>&v,int src,int dest)
{
	queue<int>q;
	int visited[dest+1]={0};
	unordered_map<int,int> parent;
	q.push(src);
	visited[src]=1;
	parent[src]=-1;
	while(q.empty()==false)
	{
		int curr=q.front();
		q.pop();
		if(curr==dest)
		{
			break;
		}
		for(auto i:v[curr])
		{
			if(visited[i]==0)
			{
				visited[i]=1;
				q.push(i);
				parent[i]=curr;
			}
		}
	}
	if(visited[dest]==0)
	{
		cout<<"IMPOSSIBLE"<<endl;
		return;
	}
	int current=dest;
	vector<int>result;
	while(current!=-1)
	{
		result.push_back(current);
		current=parent[current];
	}
	reverse(result.begin(),result.end());
	cout<<result.size()<<endl;
	for(auto i:result)
	{
		cout<<i<<" ";
	}
	cout<<endl;
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
	bfs(v,1,n);
}
