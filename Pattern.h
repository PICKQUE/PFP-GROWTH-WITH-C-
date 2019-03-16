/*
 * Pattern.h
 *
 *  Created on: 18/11/2014
 *      Author: vitor
 */

#ifndef PATTERN_H_
#define PATTERN_H_

#include <list>
#include <iostream>
#include <string>
#include <iterator>
#include "Item.h"
using std::list;
class Pattern {
private:
	std::list<string> pattern_set;
	int count;
	friend bool operator==(const Pattern&, const Pattern&);
	friend Pattern operator-(const Pattern&, const Pattern&);
public:
	Pattern(std::list<string> pattern_set, int count) :
		pattern_set(pattern_set) ,count(count){
	}
	Pattern(std::string a)
		:count(0)  {
		pattern_set.push_back(a);
		
	}
	std::list<string>::iterator begin() {
		return pattern_set.begin();
	}
	list<string>::iterator end() {
		return pattern_set.end();
	}
	const list<string>::iterator begin() const{
		return const_cast<Pattern*>(this)->pattern_set.begin();
	}
	const list<string>::iterator end() const{
		return const_cast<Pattern*>(this)->pattern_set.end();
	}
	auto erase(list<string>::iterator& it) {
		return pattern_set.erase(it);
	}
	list<string> get_patternset() {
		return pattern_set;
	}
	string operator [](int size) {
		int i = 0;
		for (auto it = pattern_set.begin(); it != pattern_set.end()&&i<=size; ++it,++i) {
			return *it;
		}
	}
	int get_count()const {
		return count;
	}
	int length() const{
		return pattern_set.size();
	}
	void print() {
		std::cout << '[';
		int i = 0;
		for (auto it = pattern_set.begin(); it != pattern_set.end() && i < pattern_set.size(); it++, i++) {
			std::cout << *it;
			if (i != pattern_set.size() - 1)
				std::cout << ",";
		}
		std::cout << ']';
		std::cout << count;
	}
	void print_confidence() {
		int i = 0;
		for (auto it = pattern_set.begin(); it != pattern_set.end()&&i<pattern_set.size(); it++,i++) {
			std::cout <<"["<< *it<<"]";
			if (i != pattern_set.size() - 1) {
				std::cout << ",";
			}
		}

	}
};

#endif /* PATTERN_H_ */
