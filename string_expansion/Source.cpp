#include <iostream>
#include <string>
#include <stack>


//some credits to scott andrews for giving some hints about the op_stack and operand stack. 
//Didn't realize I was redicovering what other's already figured out.
int main() {
	std::string s;
	std::getline(std::cin, s);
	std::stack<int> number_stack;
	std::stack<std::string> string_stack;

	std::string character_string = "";
	std::string number_string = "";
	std::string output_string = "";

	for (int i = 0; i < s.size(); i++) {
		// [0-9]
		if (s[i] < 58 && s[i] >= 48 ) {
			//if we transitioned from a character, then push that character onto the stack
			if (character_string != "") {
				string_stack.push(character_string);
				character_string = "";
			}
			number_string += s[i];
			
		}

		// \w+
		else if (s[i] <= 122 && s[i] >= 97) {
			character_string += s[i];

		}
		// (
		else if (s[i] == 40) {
			// if we transitioned from a number, push that number onto the number stack
			if (number_string != "") {
				number_stack.push(atoi(number_string.c_str()));
				number_string = "";
			}
			// (abc) is equivvalent to 1(abc) . This else if implies there is a number one infront of all open parens
			else if (number_string == "") {
				number_stack.push(1);
			}
			
			// if we transitioned from a character, push that onto the string stack.
			if (character_string != "") {
				string_stack.push(character_string);
				character_string = "";
			}
		}
		// )
		else if (s[i] == 41) {
			// we if transitioned from a chracter, push that onto the string stack
			if (character_string != "") {
				string_stack.push(character_string);
				character_string = "";
			}

			// This is similiar to op_stack operand stack.
			int op = number_stack.top();
			number_stack.pop();
			std::string op_string = "";
			std::string temp_string = "";
			op_string = string_stack.top();
			string_stack.pop();
			// this is the operation
			for (int i = 0; i < op; i++) {
				temp_string += op_string;
			}
			// if stack isn't empty, we do not output it to the output_string.
			if (string_stack.empty()) {
				output_string += temp_string;
			}
			// if number_stack and string_stack is empty, we can then output the results.
			else {
				op_string = string_stack.top();
				string_stack.pop();
				temp_string = op_string + temp_string;
				string_stack.push(temp_string);
			}
		}
	}
	std::cout << output_string << std::endl;
}