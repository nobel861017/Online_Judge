//deque_test.cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <deque>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector< deque< int > > q[1000];
	deque< int > tmp;
	int v;
	cin >> v;
	tmp.push_back(v);
	q[0].push_back(tmp);
	vector< deque< int > >::iterator it;
	it = q[0].begin();
	cout << q[0][0].front();
	cout << q[0][0][0];
}