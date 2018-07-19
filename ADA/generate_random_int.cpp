//generate_random_int.cpp
#include <iostream>
#include <random>
using namespace std;
void print_2(int x){
	for(int i = 0; i < 26; i++){
		printf("%d",(x & (1 << (25 - i))) != 0);
	}
	puts("");
}
int main(){
	random_device rd;  //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> dis(1, (1 << 26) - 1);
    print_2(dis(gen));
	
}