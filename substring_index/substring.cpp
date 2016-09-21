#include <iostream>
#include <string>
#include <functional>
using namespace std;


//Comparison of two functions for finding substrings

int findIndexOfSubstring(string s,string sub_s) {
	int index = -1;
	if (s.empty()) {
		return -1;
	}
	else {
		//The for loop condition check to make sure not to check beyond the string length
		for (int i = 0; i < s.length() && ((i + sub_s.length()) <= s.length()); i++) {
			//match first character
			if (s[i] == sub_s[0]) {
				index = i;
				//match the rest of the characters
				for (int j = 0; j < sub_s.length(); j++) {
					if (s[i + j] != sub_s[j]) {
						index = -1;
						break;
					}
					if (j == sub_s.length() - 1) {
						goto RETURN_EXIT;
					}

				}
			}
		}
	}
	RETURN_EXIT:
	return index;
	//FNV1A
}

int findIndexOfSubstring_hash(string s, string sub_s) {
	std::hash<string> str_hash;
	//while we don't need str1, it improves readability of code.
	string str1 = "";
	for (int i = 0; i < s.length() && ((i + sub_s.length()) <= s.length()); i++) {
		str1 = s.substr(i, sub_s.length());
		if ( str_hash(str1) == str_hash(sub_s)  ) {
			return i;
		}
	}
	return -1;
}


int main() {

	//cout << findIndexOfSubstring("ABCABC", "BC") << endl;
	//string str = "DOOM";
	//cout << str.substr(0,str.length() + 0);
	cout << findIndexOfSubstring_hash("ABCABC", "BC") << endl;


}