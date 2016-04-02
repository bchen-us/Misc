#include <iostream>
using std::cout;
using std::cin;
using std::endl;


int main(){

	int size = 5;
	int left = 0;
	int right = size;
	int bottom = size;
	int top = 0;
	int arr[5][5] = { {1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}, {16,17,18,19,20}, {21,22,23,24,25} };
		for (int i = left; i < right; i++){
			cout << arr[top][i]<< " ";
		}
		cout << endl;
		top += 1;
		for (int j = top; j < bottom; j++){
			cout << arr[j][right-1] << " ";
		}
		cout << endl;
		right -= 1;

		for (int i = right; right >= left; i--){
			cout << arr[bottom-1][i] << " ";
		}
		cout << endl;
		bottom -= 1;

		for (int j = bottom; j >= top; j--){
			cout << arr[j][left-1] << " ";
		}
		cout << endl;
		left += 1;
	


}