#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

vector<vector<pi> > graph;


void addedge(int x, int y, int cost)
{
	graph[x].push_back(make_pair(cost, y));
	graph[y].push_back(make_pair(cost, x));
}

void best_first_search(int actual_Src, int target, int n)
{
	vector<bool> visited(n, false);

	priority_queue<pi, vector<pi>, greater<pi> > pq;

	pq.push(make_pair(0, actual_Src));
	int s = actual_Src;
	visited[s] = true;
	while (!pq.empty()) {
		int x = pq.top().second;
		// Displaying the path having lowest cost
		cout << x << " ";
		pq.pop();
		if (x == target)
			break;

		for (int i = 0; i < graph[x].size(); i++) {
			if (!visited[graph[x][i].second]) {
				visited[graph[x][i].second] = true;
				pq.push(make_pair(graph[x][i].first,graph[x][i].second));
			}
		}
	}
}


int main()
{
	int v;

	cout<<"Enter the number of nodes : "<<endl;
	cin>>v;

	graph.resize(v+1);

	cout<<"enter the number of edge : "<<endl;
	int e;
	cin>>e;
	for(int i=0;i<e;i++)
    {
        cout<<"enter the source , destination, and cost of node "<<i+1<<" : "<<endl;
        int a,b,c;
        cin>>a>>b>>c;
        addedge(a,b,c);
    }
	cout<<"enter the source and Destination : "<<endl;


	int source ,target;
    cin>>source>>target;

	best_first_search(source, target, v);

	return 0;
}

/*
input  :
14

13
0 1 3
0 2 6
0 3 5
1 4 9
1 5 8
2 6 12
2 7 14
3 8 7
8 9 5
8 10 6
9 11 1
9 12 10
9 13 2

0
9


*/
