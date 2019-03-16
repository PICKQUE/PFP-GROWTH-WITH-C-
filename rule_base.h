#pragma once
#include<list>
#include<string>
using std::list;
using std::string;
class rule_base {
private:
	list<string> a;
	list<string> b;

public:
	rule_base(list<string> lhs, list<string> rhs)
		:a(lhs), b(rhs)
	{}
	void print() {
		int i = 0;
		std::cout << "{"<<"[";
		for (auto it = a.begin(); it != a.end();it++,i++) {
			std::cout << *it;
			if (i != a.size() - 1) {
				std::cout << ",";
			}
		}std::cout <<"]"<<","<< "[";
		i = 0;
		for (auto it = b.begin(); it != b.end(); it++, i++) {
			std::cout << *it;
			if (i != b.size() - 1) {
				std::cout << ",";
			}
		}
		std::cout << "]" << "}";
	}

};