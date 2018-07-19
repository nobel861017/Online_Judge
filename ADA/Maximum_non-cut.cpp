//Maximum_non-cut.cpp
#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>
#include <utility>
#include <list>
using namespace std;
typedef unsigned long long ull;
ull total_weight = 0;
ull n, m, s, t, u, v, w;
vector< list< pair < ull, ull > > > adj(300001);

void make_edge(ull u, ull v, ull w){
	adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

ull Dijkstra(ull s, ull t){
	vector< ull > dis(n + 1, ULLONG_MAX);
	priority_queue< pair < ull, ull >, vector< pair< ull, ull> >, greater<pair < ull, ull > > > min_priority_queue;
	min_priority_queue.push(make_pair(0, s));
    dis[s] = 0;
    while (!min_priority_queue.empty()){
    	ull u = min_priority_queue.top().second;
    	min_priority_queue.pop();
    	list< pair< ull, ull> >::iterator i;
    	for (i = adj[u].begin(); i != adj[u].end(); ++i){
    		ull v = (*i).first;
            ull w = (*i).second;
            if (dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                min_priority_queue.push(make_pair(dis[v], v));
            }
            if(u == t) break;
    	}
    }
    return dis[t];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> s >> t;
	while(m--){
		cin >> u >> v >> w;
		total_weight += w;
		make_edge(u, v, w);
	}
    ull ans = Dijkstra(s, t);
    if(ans == ULLONG_MAX) cout << "-1";
    else cout << total_weight - ans;
	return 0;
}