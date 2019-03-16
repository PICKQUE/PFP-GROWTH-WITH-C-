#pragma once
#include<list>
#include<string>
#include<vector>
#include"rule_base.h"
#include "Pattern.h"
using std::list;
using std::string;
using std::vector;

class rule {
private:
	list<Pattern> frequent_set;
	vector<float> confidence;
	vector<rule_base> myrule;
public:
	rule(list<Pattern> rules, float confidence) 
	:frequent_set(rules),confidence(confidence)
	{}
	rule() {
	}
	list<Pattern>::iterator begin() {
		return frequent_set.begin();
	}
	list<Pattern>::iterator end() {
		return frequent_set.end();
	}
	//float get_confidence()const {
	//	return confidence;
	//}
	void push_back(const Pattern& lhs, const Pattern& rhs, float confi) {
		confidence.push_back(confi);
		list<string> temp1;
		list<string> temp;
		for (auto str : lhs) {
			temp.push_back(str);
		}
		for (auto str : rhs) {
			temp1.push_back(str);
		}
		myrule.push_back({ temp,temp1 });
	}
	void print() {
		std::cout << "Association rules : " << std::endl;
		int i=0;
		/*for (auto it = frequent_set.begin(); it != frequent_set.end(),i<frequent_set.size();it++,i++) {
			std::cout << "{ ";
			it->print_confidence();
			std::cout << " " << confidence[i];	
			std::cout << " }"<<std::endl;
		}*/
		for (auto it = confidence.begin(); it != confidence.end(); it++,i++) {
			myrule[i].print();
			std::cout <<" "<< *it<<std::endl;
		}

	}
};