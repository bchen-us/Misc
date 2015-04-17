#include <iostream>
using namespace std;

int loop_condition_operand(int loop_condition,int& x){
	x++;
	return loop_condition;
}

int f_inner_inner_loop(int loop_condition,int& x){
	x++;
	return loop_condition;
}



int main(){

	int for_statement = 0;
	int inner_for_statement = 0;
	int inner_loop = 0;
	int inner_inner_loop = 0;

	// change n to any number you want
	int n = 11;

	for(int i = 0; i < loop_condition_operand(n , for_statement); i++){
			inner_loop++;
		for(int j = i; j < f_inner_inner_loop(n,inner_for_statement); j++){
			inner_inner_loop++;
		} 	
	}

	//counted
	cout << "\n\nWhen it's counted\n ------" << endl;
	cout << "Inner loop is " << inner_loop << endl;
	cout << "for statement is " << for_statement << endl;
	cout << "Inner for statement is " << inner_for_statement << endl;
	cout << "Inner - inner - loop is " << inner_inner_loop << endl;

	// calculated
	// arithmetic series
	cout << "\n\n ------ \n\n" << endl;
	cout << "n is " << n << endl;
	cout << "Inner loop (n/2 * 2) : " << n << endl;
	cout << "for statement ( ( ( (n + 1) / 2)) * 2) : " << n+1 << endl;
	cout << "Inner for statement is (0.5) * (n^2 + n) + n : " << (0.5) * (float)(n*n + n) + n << endl;
	cout << "Inner - inner - loop is (0.5) * (x^2 + x) : " << (0.5) * (float)(n * n + n) << endl;
}
