//Hamiltonian_Circuit.cpp
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include <string.h>
using namespace std;
vector< int > degree;
void print_graph(vector< unordered_map < int, int > > Adj_List, int n){
	unordered_map< int, int >::iterator it;
	for(int i = 1; i <= n; i++){
		cout << i; 
		for(it  = Adj_List[i].begin(); it != Adj_List[i].end(); ++it){
			cout << "->" << it->first;
		}
		cout << '\n';
	}
}

void print_path(int *path, int n){
	for(int i = 0; i < n; i++){
		if(path[i] != 0) printf("%d ", path[i]);
	}
	puts("");
}

int Is_Adjacent(vector< unordered_map < int, int > > Adj_List, int v1, int v2){
	unordered_map< int, int >::iterator it;
	for(it  = Adj_List[v1].begin(); it != Adj_List[v1].end(); ++it){
		if(it->first == v2) return 1;
	}
	return 0;
}

int Traverse(vector< unordered_map < int, int > > Adj_List, int n, int *path, int idx, int *Is_Visited){
	if(idx == n){
		//fprintf(stderr, "base case: path[0]: %d, path[idx - 1]: %d\n", path[0],path[idx - 1]);
		if(Is_Adjacent(Adj_List, path[idx - 1], path[0]) == 1){
			return 1;
		}
		else return 0;
	}

	for(int i = 2; i <= n; i++){
		if(Is_Adjacent(Adj_List, path[idx - 1], i) == 1 && Is_Visited[i] == 0){
			path[idx] = i;
			Is_Visited[i] = 1;
			if(Traverse(Adj_List, n, path, idx + 1, Is_Visited)) return 1;
			//path[idx] = -1;
			Is_Visited[i] = 0;
		}
		print_path(path, n);
	}
	return 0;
}

void Find_Hamiltonian_Circuit(vector< unordered_map < int, int > > Adj_List, int n){
	int path[n + 1], Is_Visited[n + 1];
	memset(path, 0, sizeof(path));
	memset(Is_Visited, 0, sizeof(Is_Visited));
	path[0] = 1;
	Is_Visited[1] = 1;
	if(Traverse(Adj_List, n, path, 1, Is_Visited) == 0){
		cout << "-1";
	}
	else{
		for(int i = 0; i < n; i++)
			cout << path[i] << ' ';
		cout << path[0];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m, v1, v2;
	cin >> n >> m;
	vector< unordered_map < int, int > > Adj_List(n + 1);
	for(int i = 0; i < n; i++) degree.push_back(0);
	while(m--){
		cin >> v1 >> v2;
		degree[v1]++, degree[v2]++;
		Adj_List[v1].insert(make_pair(v2, 1));

	}
	//print_graph(Adj_List, n);
	Find_Hamiltonian_Circuit(Adj_List, n);
	
}