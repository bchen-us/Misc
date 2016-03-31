#include <iostream>
using namespace std;

int xor_full_adder(int x, int y){

	/*
	int xor_result = x ^ y;
	int and_result = x & y;
	int carry_in = 0
	carry_in = and_result << 1;
	carry_in = carry_in | ((xor_result & carry_in) << 1);
	return xor_result ^ carry_in;
	
	*/

	/*
	int carry_in = (x & y) << 1;
	carry_in = carry_in | (((x ^ y) & carry_in) << 1);
	return (x ^ y) ^ carry_in;
	*/

	return (x ^ y) ^ (((x & y) << 1) | (((x ^ y) & ((x & y) << 1)) << 1));
}


int main(){

	cout << xor_full_adder(20, 37) << endl;

}