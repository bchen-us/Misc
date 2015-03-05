#include <iostream>
#include <stack>
#include<queue>
using namespace std;

namespace local{
	//implementing a stack with two queues
	class stack{
	private:
		// first queue will ultimately contain all elements
		queue<int> first;
		//The second queue is used for push and pop operation.
		// It will used to order the elements in the first queue, to allow the first queue to emulate a stack.
		queue<int> second;

	public:
		stack();
		int empty();
		int size();
		int top();
		void pop();
		void push(int px);
	};
}

local::stack::stack(){

}

int local::stack::empty(){

	return first.empty();
}

int local::stack::size(){

	return first.size();
}

int local::stack::top(){

	return first.front();
}

void local::stack::pop(){

	first.pop();
}

void local::stack::push(int px){

	if (first.empty()){
		first.push(px);
	}
	else{
		while (!first.empty()){
			second.push(first.front());
			first.pop();
		}
		first.push(px);
		while (!second.empty()){
			first.push(second.front());
			second.pop();
		}
	}
}


int main(){

	local::stack test;

	queue<int> f;
	queue<int> s;

	for (int i = 0; i < 10; i++){
		f.push(i);
	}
	while (!f.empty()){
		cout << f.front() << endl;
		f.pop();
	}

	for (int i = 0; i < 10; i++){
		test.push(i);
	}


	cout << "\n\n------\n" << endl;
	while (!test.empty()){
		cout << test.top() << endl;
		test.pop();
	}
	cout << "\n\n++++\n" << endl;
	test.push(9999);
	test.push(60);
	test.push(-2000);
	cout << test.top() << endl; 
	test.pop();
	cout << test.top() << endl;
	test.pop();
	cout << test.top() << endl;
	test.pop();
	return 0;

}