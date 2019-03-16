/*
 * Item.h
 *
 *  Created on: 14/10/2014
 *      Author: vitor
 */

#ifndef ITEM_H_
#define ITEM_H_

#include <iostream>
using std::string;
class Item {
public:
	int count = 1;
	string value;

	Item() :
		count(0), value(" ") {
	}

	Item(string value) :
		value(value) {
	}

	string get_value() const {
		return value;
	}

	void set_value(string value) {
		this->value = value;
	}

	int get_count() const {
		return count;
	}

	void increment() {
		count++;
	}

	bool operator<(const Item& outro) const {
		return count < outro.count;
	}

	bool operator>(const Item& outro) const {
		return count > outro.count;
	}

	void print() {
		std::cout << '(';
		for (auto it : value) {
			std::cout << it<< ", " ;
		}
		std::cout<< count << ')';
	}
};

#endif /* ITEM_H_ */
