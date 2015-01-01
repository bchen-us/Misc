#include <iostream>
#include <string>
using namespace std;



int main(){
	int number = 0;
	cout << "The number of iterations: ";
	cin >> number;
	string str = "1";
	string str2 = "";
	char current = 0;
	int amount = 0;

	for (int i = 0; i < number; i++){
		for (int j = 0; j < str.size(); j++){
			if (current != str[j]){
				current = str[j];
				amount = 0;
				for (int k = j; current == str[k]; k++){
					amount++;
				}
				str2 += to_string(amount);
				str2 += current;
			}

		}
		cout << str2 << endl;
		str = str2;
		str2 = "";
		current = 0;
		amount = 0;
	}

}