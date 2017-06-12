// heap_priority.cpp : Defines the entry point for the console application.
//

#include <algorithm>
#include <iostream>
#include <stdexcept>
class binary_heap {
private:
	int * hp;
	// For the end of array index
	int capacity;
	// this variable is to prevent naming conflict with size()
	int amount;
	// necessary for push_back and pop operations.
	int last_index;
public:
	binary_heap();
	~binary_heap();
	void push_back(int item);
	int pop();
	// mode 0 , root to leaf
	// mode 1, leaf to root
	void enforce_property(int mode);
	bool empty();
	int size();
	friend std::ostream& operator<<(std::ostream& out, const binary_heap& rhs);

};

binary_heap::binary_heap() {
	this->hp = NULL;
	this->capacity = 0;
	this->amount = 0;
	this->last_index = 0;
}

binary_heap::~binary_heap() {
	delete[] this->hp;
	this->capacity = 0;
	this->amount = 0;
	this->last_index = 0;
}
bool binary_heap::empty() {
	return 0 == this->amount;
}

int binary_heap::size() {
	return this->amount;
}


// This only appends to the end, heap property isn't maintained. Must enforce.
void binary_heap::push_back(int item) {
	// empty and no memory allocated
	if (this->empty() && this->capacity == 0) {
		this->amount = 1;
		this->capacity = 10;
		this->hp = new int[this->capacity];
		this->hp[this->last_index] = item;
		this->last_index++;
	}
	//empty with memory allocated
	else if (this->empty() && this->capacity != 0) {
		this->amount = 1;
		this->hp[this->last_index] = item;
		this->last_index++;

	}
	// not empty but don't have capacity????
	else if (this->capacity == 0 && this->empty() == false) {

	}

	else if (this->capacity != 0 && this->empty() == false) {
		// check to make sure amount doesn't exceed capacity

		if (this->size() == this->capacity) {
			this->capacity = this->capacity * 2;
			int * temp = new int[this->capacity];
			memset(temp, 0, sizeof(int) * this->capacity);
			std::copy(this->hp, this->hp + this->amount, temp);
			delete[] this->hp;
			this->hp = temp;
		}
		this->hp[this->last_index] = item;
		this->last_index++;
		this->amount++;
	}
	// enforcing from last leaf to root
	this->enforce_property(0);

}

// pop from root, not from last_index
int binary_heap::pop() {
	if (last_index == 0) {
		throw std::runtime_error("Pop from empty heap");
	}
	this->amount--;
	this->last_index--;
	int ret_val = this->hp[0];
	this->hp[0] = this->hp[this->last_index];

#ifdef DEBUG
	std::cout << "before enforce_property(1):  ";
	for (int i = 0; i < this->amount; i++) {
		std::cout << this->hp[i] << " ";
	}
	std::cout << std::endl;
#endif
	enforce_property(1);
	return ret_val;
}

// when to enforce heap property?
// push_back , leaf node
// pop, root node
// push_back, leaf to root
// pop, root to leaf

//max heap
void binary_heap::enforce_property(int mode)
{
	// 4 / 2 = 2, 2 / 2 = 1 , 1 / 2 = 0
	//0 1 1 2 2 2 2 3 3 3 3 3 3 3 3 3 3
	//0 1 2 3 4 5 6 7 8 9 
	// obtaining parent , (index - 1) / 2 
	// parent = (index - 1) / 2
	// index = leaf
	// parent = (leaf - 1) / 2
	// 2 * parent = (leaf - 1)
	// 2 * parent + 1 = leaf


	// obtaining both children
	// leaf_left = 2 * parent + 1
	// leaf_right = 2 * parent + 2

	// insertion already happened
	if (0 == mode) {
		//enforce last index to root
		for (int i = this->last_index - 1; i > 0 ;  i = (i - 1) / 2) {
			//compare child with parent, swap if necessary
			if (hp[i] > hp[(i - 1) / 2]) {
				int temp = hp[i];
				hp[i] = hp[(i - 1) / 2];
				hp[(i - 1) / 2] = temp;
			}
			else {
				break;
			}
		}
	} // pop already happened
	// assume that pop will put the last leaf into the root
	// if both are equal, left first, then right
	else if (1 == mode) {
		int left;
		int right;
		int temp;
		for (int i = 0; i < this->last_index;) {
			left = 2 * i + 1;
			right = 2 * i + 2;
			// four possibilities
			if (left < this->last_index && right < this->last_index) {
				if (hp[left] >= hp[right]) {
					if (hp[i] < hp[left]) {
						temp = hp[i];
						hp[i] = hp[left];
						hp[left] = temp;
						i = left;
					}
					else {
						break;
					}
				}
				else {
					if (hp[i] < hp[right]) {
						temp = hp[i];
						hp[i] = hp[right];
						hp[right] = temp;
						i = right;
					}
					else {
						break;
					}
					
				}
			}
			else if ( (left < this->last_index) && !(right < this->last_index)) {
				if (hp[i] < hp[left]) {
					temp = hp[i];
					hp[i] = hp[left];
					hp[left] = temp;
					i = left;
				}
				else {
					break;
				}
			}
			// time to stop
			// else accounts for two possibilities, one of which is impossible
			else{
				break;
			}
		
		}
	
	}
	


}
std::ostream& operator<<(std::ostream& out, const binary_heap& rhs) {
	for (int i = 0; i < rhs.amount; i++) {
		out << rhs.hp[i] << " ";
	}
	return out;
}

#define CUSTOM2
int main()
{
	binary_heap b1;
#ifdef LOOP
	for (int i = 0; i < 10; i++) {
		b1.push_back(i);
	}
#endif

#ifdef CUSTOM
	b1.push_back(88);
	b1.push_back(72);
	b1.push_back(97);
	b1.push_back(47);
	b1.push_back(40);
	b1.push_back(72);
	b1.push_back(27);
#endif
	//78	69	52	5	27	80	45	84	69	44	68	13	53	91	26	43	54	90	51	84
#ifdef CUSTOM2
	b1.push_back(78);
	b1.push_back(69);
	b1.push_back(52);
	b1.push_back(5);
	b1.push_back(27);
	b1.push_back(80);
	b1.push_back(45);
	b1.push_back(84);
	b1.push_back(69);
	b1.push_back(44);
	b1.push_back(68);
	b1.push_back(13);
	b1.push_back(53);
	b1.push_back(91);
	b1.push_back(26);
	b1.push_back(43);
	b1.push_back(54);
	b1.push_back(90);
	b1.push_back(51);
	b1.push_back(84);
#endif
	std::cout << "Array after all insertion (unordered): "<< b1 << std::endl;
#ifdef DEBUG
	for (int i = 0; i < 20; i++) {
		std::cout << "pop(): " << b1.pop() << " , :  ";
		std::cout << b1 << std::endl;
	}
#endif
	std::cout << "All the sequential pop() operation: ";
	for (int i = 0; i < 20; i++) {
		std::cout << b1.pop() << " ";
	}
	std::cout << std::endl;
}

