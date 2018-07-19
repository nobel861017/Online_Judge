//Metropolitan.cpp
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, M, u, v;
	cin >> N >> M;
	vector< unordered_map <int,int> > adjLists(N+1);
	vector<int> degree;
	for(int i = 0; i < N; i++) degree.push_back(0);
	while(M--){
		cin >> u >> v;
		degree[u]++;
		degree[v]++;
		if(degree[u] >= 50000 || degree[v] >= 50000){
			cout << 3;
			return 0;
		}
		adjLists[u].insert(make_pair(v,1));
		adjLists[v].insert(make_pair(u,1));
	}
	int ans = 1;
	for(int i = 0; i < N; i++){
		if(degree[i] == 1){
			if(ans < 2) ans = 2;
			degree[i]--;
			degree[adjLists[i].begin()->first]--;
			adjLists[adjLists[i].begin()->first].erase(adjLists[adjLists[i].begin()->first].find(i));
		}
		else if(degree[i] == 2){
			unordered_map<int,int>::iterator it;
			it = adjLists[i].begin();
			int x = it->first;
			++it;
			int y = it->first;
			if(adjLists[x].find(y) != adjLists[x].end())
				if(ans < 3) ans = 3;
			degree[i]--;
			degree[x]--;
			degree[y]--;
			adjLists[x].erase(adjLists[x].find(i));
			adjLists[y].erase(adjLists[y].find(i));
		}
		else if(degree[i] == 3){
			unordered_map<int,int>::iterator it;
			it = adjLists[i].begin();
			int x = it->first;
			++it;
			int y = it->first;
			++it;
			int z = it->first;
			if( adjLists[x].find(y) != adjLists[x].end() && adjLists[y].find(z) != adjLists[y].end()
			  && adjLists[z].find(x) != adjLists[z].end() ){
				if(ans < 4) ans = 4;
				break;
			}
			degree[i]--;
			degree[x]--;
			degree[y]--;
			degree[z]--;
			adjLists[x].erase(adjLists[x].find(i));
			adjLists[y].erase(adjLists[y].find(i));
			adjLists[z].erase(adjLists[z].find(i));
		}
	}
	cout << ans;
	return 0;
}