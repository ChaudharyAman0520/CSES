#include<bits/stdc++.h>
using namespace std;
void bipartite(unordered_map<int,vector<int>>v,int n)
{
	queue<int>q;
	vector<int>colour(n+1,-1);
	for(int i=1;i<=n;i++)
	{
		if(colour[i]==-1)
		{
			q.push(i);
			colour[i]=0;
			while(q.empty()==false)
			{
				int node=q.front();
				q.pop();
				for(auto u:v[node])
				{
					if(colour[u]==-1)
					{
						colour[u]=1-colour[node];
						q.push(u);
					}
					else if(colour[u]==colour[node])
					{
						cout<<"IMPOSSIBLE"<<endl;
						return;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<colour[i]+1<<" ";
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
	bipartite(v,n);
}
