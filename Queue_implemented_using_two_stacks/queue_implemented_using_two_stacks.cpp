#include <stack>
#include <iostream>
using namespace std;

class queues_with_stacks{
	private:
		stack<int> first;
		stack<int> second;
		int back_element;
public:
	queues_with_stacks();
	int empty();
	int size();
	int front();
	int back();
	void pop();
	void push_back(int arg1);


};

queues_with_stacks::queues_with_stacks(){
	int back_element = 0;
}

int queues_with_stacks::empty(){
	return first.empty();
}
int queues_with_stacks::size(){
	return first.size();
}
int queues_with_stacks::front(){
	return first.top();
}
int queues_with_stacks::back(){
	if (first.size() == 0){
		return first.top();
	}
	else{
		return this->back_element;
	}
}
void queues_with_stacks::pop(){
	first.pop();
}
void queues_with_stacks::push_back(int arg1){
	if (0 == first.size()){
		first.push(arg1);
	}
	else{
		while (first.size() != 0){
			second.push(first.top());
			first.pop();
		}
		this->back_element = second.top();
		first.push(arg1);
		while (second.size() != 0){
			first.push(second.top());
			second.pop();
		}
	}
}


int main(){
	queues_with_stacks test;
	for (int i = 0; i < 10; i++){
		test.push_back(i);
	}
	for (int i = 0; i < 10; i++){
		cout << test.front() << endl;
		test.pop();
	}

}