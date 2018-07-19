#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
vector< int > degree, degree_order;
bool degreecmp(int i, int j)
{
	return degree[i] < degree[j];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, M, ans = 1, v1, v2;
	cin >> N >> M;
	vector< unordered_map < int, int > > AdjacencyList(N + 1);
	for(int i = 0; i < N; i++)
		degree.push_back(0), degree_order.push_back(i);
	while(M--)
	{
		cin >> v1 >> v2;
		degree[v1]++, degree[v2]++;
		if(degree[v1] >= 50000 || degree[v2] >= 50000)
		{
			cout << 3;
			return 0;
		}
		AdjacencyList[v1].insert(make_pair(v2, 1));
		AdjacencyList[v2].insert(make_pair(v1, 1));
	}
	sort(degree_order.begin(), degree_order.end(), degreecmp);
	//for(int i = 0; i < N; i++)
		//cout << degree_order[i] << ' ' << degree[degree_order[i]] << '\n';
	//cout << "-----\n";
	for(int i = 0; i < N; i++)
	{
		int deg = degree[degree_order[i]], idx = degree_order[i];
		//cout << idx << ' ' << deg << '\n';
		if((deg > 3) || (deg + 1 <= ans)) continue;
		else
		{
			if(deg == 1)
			{
				ans = 2;
				//some debug-friendly preparation
				int neighbor_index = AdjacencyList[idx].begin()->first;
				//remove idx from the graph
				degree[idx]--, degree[neighbor_index]--;
				AdjacencyList[neighbor_index].erase(AdjacencyList[neighbor_index].find(idx));
			}
			else if(deg == 2)
			{
				//some debug-friendly preparation
				int j = 0, neighbor_index[2];
				for(unordered_map< int, int >::iterator it = AdjacencyList[degree_order[i]].begin(); j < 2; ++it, j++)
					neighbor_index[j] = it->first;
				//determine whether the neighbors are connected
				if(AdjacencyList[neighbor_index[0]].find(neighbor_index[1]) != AdjacencyList[neighbor_index[0]].end())
					ans = 3;
				//remove idx from the graph
				degree[idx]--, degree[neighbor_index[0]]--, degree[neighbor_index[1]]--;
				for(j = 0; j < 2; j++)
					AdjacencyList[neighbor_index[j]].erase(AdjacencyList[neighbor_index[j]].find(idx));
			}
			else if(deg == 3)
			{
				//some debug-friendly preparation
				int j = 0, neighbor_index[3];
				for(unordered_map< int, int >::iterator it = AdjacencyList[degree_order[i]].begin(); j < 3; ++it, j++)
					neighbor_index[j] = it->first;
				//determine whether the neighbors are connected
				if(AdjacencyList[neighbor_index[0]].find(neighbor_index[1]) != AdjacencyList[neighbor_index[0]].end()
				  && AdjacencyList[neighbor_index[1]].find(neighbor_index[2]) != AdjacencyList[neighbor_index[1]].end()
				  && AdjacencyList[neighbor_index[2]].find(neighbor_index[0]) != AdjacencyList[neighbor_index[2]].end())
				{
					ans = 4;
					break;
				}
				//remove idx from the graph
				degree[idx]--, degree[neighbor_index[0]]--, degree[neighbor_index[1]]--, degree[neighbor_index[2]]--;
				for(j = 0; j < 3; j++)
					AdjacencyList[neighbor_index[j]].erase(AdjacencyList[neighbor_index[j]].find(idx));
			}
			//sort(degree_order.begin(), degree_order.end(), degreecmp);
		}
	}
	cout << ans;
	return 0;
}