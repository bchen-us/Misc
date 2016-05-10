#include <iostream>
using std::cout;
using std::cin;
using std::endl;


int main(){
	//
	int size = 7;
	int left = 0;
	int right = size;
	int bottom = 6;
	int top = 0;
	int conti = 0;
	int arr[6][7] = { { 0, 1, 2, 3, 4, 5, 6 }, { 7, 8, 9, 10, 11, 12, 13 }, { 14, 15, 16, 17, 18, 19, 20 }, { 21, 22, 23, 24, 25, 26, 27 }, { 28, 29, 30, 31, 32, 33, 34 }, { 35, 36, 37, 38, 39, 40, 41 }};
	do{
		for (int i = left; i < right; i++){
			cout << arr[top][i] << " ";
			conti = 1;
		}
		if (conti == 0){
			break;
		}
		cout << endl;
		top += 1;
		conti = 0;
		for (int j = top; j < bottom; j++){
			cout << arr[j][right - 1] << " ";
			conti = 1;
		}
		if (conti == 0){
			break;
		}
		cout << endl;
		right -= 1;
		conti = 0;
		for (int i = right - 1; i >= left; i--){
			cout << arr[bottom - 1][i] << " ";
			conti = 1;
		}
		if (conti == 0){
			break;
		}
		cout << endl;
		bottom -= 1;
		conti = 0;
		for (int j = bottom - 1; j >= top; j--){
			cout << arr[j][left] << " ";
			conti = 1;
		}
		if (conti == 0){
			break;
		}
		cout << endl;
		left += 1;

	} while(conti);

}