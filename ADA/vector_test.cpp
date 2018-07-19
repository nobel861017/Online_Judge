//vector_test.cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <deque>
#include <string.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector< deque< int > >q[n + 1];
	deque< int > tmp;
	tmp.push_back(3);
	q[1].push_back(tmp);
	cout << q[1].empty();
}