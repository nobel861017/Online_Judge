//Hamiltonian_Circuit2.cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <deque>
#include <string.h>
using namespace std;
vector< int > in_degree;
vector< int > out_degree;
vector< deque< int > > q[100001];
int n;
void print_graph(){
	for(int i = 1; i <= n; i++){
		cout << i; 
		for(int j = 0; j < q[i].size(); j++) cout << "->" << q[i][j][0];
		cout << '\n';
	}
}
void print_reduced_graph(){
	for(int i = 1; i <= n; i++){
		cout << i << ":\n"; 
		for(int j = 0; j < q[i].size(); j++){
			for(int k = 0; k < q[i][j].size(); k++)
				cout << q[i][j][k];
			cout << '\n';
		}
		cout << '\n';
	}
}
void print_degree(){
	for(int i = 1; i <= n; i++){
		cout << i << ": indeg = " << in_degree[i] << '\n';
		cout << i << ": outdeg = " << out_degree[i] << '\n';
	}
}
void print_path(int *path){
	for(int i = 0; i < n; i++){
		if(path[i] != 0) printf("%d ", path[i]);
	}
	puts("");
}
int Is_Adjacent(int u, int v){
	for(int i = 0; i < q[u].size(); i++) if(q[u][i][0] == v) return 1;
	return 0;
}
int get_adjacent_vertex(int v){
	return q[v][0][0];
}
void concatenate_path(int *path, int pre, int i, int idx){
	//puts("con");
	for(int j = idx, k = 0; k < q[pre][i].size(); j++, k++){
		path[j] = q[pre][i][k];
	}
}
void Reset_Is_Visit(int pre, int i, int *Is_Visit){
	for(int j = 0; j < q[pre][i].size(); j++){
		Is_Visit[q[pre][i][j]] = 0;
	}
}
int Traverse(int *path, int idx, int pre, int *Is_Visit){
	int tmp_pre = pre;
	if(idx == n){
		if(Is_Adjacent(pre, 1)) return 1;
		else return 0;
	}
	for(int i = 0; i < q[pre].size(); i++){
		if(out_degree[q[pre][i][0]] == 1 && Is_Visit[q[pre][i][0]] == 0){
			Is_Visit[q[pre][i][0]] = 1;
			int adjidx = get_adjacent_vertex(q[pre][i][0]);
			while(out_degree[adjidx] == 1 && Is_Visit[adjidx] == 0){
				Is_Visit[adjidx] = 1;
				q[pre][i].push_back(adjidx);
				adjidx = get_adjacent_vertex(adjidx);
			}
			Is_Visit[adjidx] = 1;
			q[pre][i].push_back(adjidx);
			pre = adjidx;
			if(Traverse(path, idx + q[tmp_pre][i].size(), pre, Is_Visit) == 1){
				concatenate_path(path, tmp_pre, i, idx);
				return 1;
			}
			Reset_Is_Visit(tmp_pre, i, Is_Visit);
		}
		else if(Is_Visit[q[pre][i][0]] == 0){
			pre = q[pre][i][0];
			Is_Visit[pre] = 1;
			if(Traverse(path, idx + 1, pre, Is_Visit) == 1){
				//concatenate_path(path, tmp_pre, i, idx);
				path[idx] = q[tmp_pre][i][0];
				return 1;
			}
			Is_Visit[pre] = 0;
		}
	}
	return 0;
}
void Find_Hamiltonian_Circuit(){
	int path[n + 1], Is_Visit[n + 1];
	memset(path, 0, sizeof(path));
	memset(Is_Visit, 0, sizeof(Is_Visit));
	path[0] = 1, Is_Visit[1] = 1;
	if(Traverse(path, 1, 1, Is_Visit) == 0){
		cout << "-1";
	}
	else{
		print_path(path);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int m, v1, v2;
	cin >> n >> m;
	for(int i = 0; i < n; i++) in_degree.push_back(0), out_degree.push_back(0);
	while(m--){
		cin >> v1 >> v2;
		if(Is_Adjacent(v1, v2)) continue;
		out_degree[v1]++, in_degree[v2]++;
		deque< int > tmp;
		tmp.push_back(v2);
		q[v1].push_back(tmp);
	}
	//print_graph();
	//print_degree();
	Find_Hamiltonian_Circuit();
	print_reduced_graph();
}