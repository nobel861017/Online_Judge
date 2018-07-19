#include <vector>
#include <deque>
#include <iostream>

using namespace std;

int main(){
    int N = 10;
    vector< deque< int > > myVector[N+1];
    deque< int > temp;
    temp.push_back(3);
    myVector[1].push_back(temp);
    return 0;
}
