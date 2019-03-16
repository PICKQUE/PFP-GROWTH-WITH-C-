#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <chrono>

#include "rules.h"
#include "FPTree.h"
using std::list;
using std::endl;
Pattern removest(Pattern set, string str);

string operator -(Pattern& lhs,string& rhs) {
	string temp;
	for (auto str : lhs) {
		if (str != rhs) {
			temp += str;
		}
	}
	return temp;
}
void getrules(Pattern& set, Pattern current_set, rule& rules, const list<Pattern>& my_frequent_item, float minconf) {
	bool flag;
	for (auto str : current_set) {
		Pattern subSet = removest(current_set, str);
		float confidence=0;
		auto it = std::find(my_frequent_item.begin(), my_frequent_item.end(), subSet);
		
		if (it!= my_frequent_item.end()) {
			 confidence = (float)std::find(my_frequent_item.begin(),
				my_frequent_item.end(), set)->get_count() / (float)it->get_count();
		}

		if (confidence >= minconf) {
			flag = false;
			for (auto rule : rules) {
				if (rule[0] == subSet && rule[1] == set - subSet) {
					flag = true;
				}
			}
			if (!flag) {
				rules.push_back(subSet, set - subSet, confidence);
			}
			if (Pattern(subSet).length() >= 2) {
				getrules(set, subSet, rules, my_frequent_item, minconf);
			}
		}
	}
}

void rulesgenterator(list<Pattern>& my_frequent_item,float minconf,rule& rules) {
	for (auto it = my_frequent_item.begin(); it != my_frequent_item.end();it++) {
		if (it->length() > 1) {
			getrules(*it, *it, rules, my_frequent_item, minconf);
		}
	}
}

int main(int argc, char* argv[]) {
	if (argc < 3) {
		std::cout << "uso: " << argv[0] << " arquivo_entrada suporte_minimo num_threads"
			<< std::endl;
		exit(0);
	}
	auto file_name = std::string(argv[1]);
	//std::string file_name = "D:/test_single.dat";
	int minimum_support = 3;	
	//sscanf_s(argv[2], "%d", &minimum_support);

	int num_threads = 4;

	if (argc >= 4) {
		if (argv[3] <= 0) {
			std::cerr << "minimum_support native" << std::endl;
		}
		std::cout << "num_threads "<<argv[3]<<std::endl;
		sscanf_s(argv[3], "%d", &num_threads);
		//纠正线程数目为负错误
		if (num_threads < 0) {
			std::cerr << "num_threads native error" << std::endl;
			exit(1);
		}
	}

	FPTree tree(minimum_support, num_threads);

	auto t1 = std::chrono::high_resolution_clock::now();
	tree.build_fp_tree(file_name);
	auto things = tree.fpgrowth(std::list<string>());
	
	auto t2 = std::chrono::high_resolution_clock::now();
	
	//耗费的时间
	std::cout
		<< std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()
		<< std::endl;

	
	for (auto it : things) {
		it.print();
		std::cout << endl;
	}
	rule rules;
	float minconf = 0.6;

	rulesgenterator(things, minconf, rules);
	rules.print();


	return 0;
}

Pattern removest(Pattern set, string str) {
	list<string> temp;
	for (auto i : set) {
		if (i != str) {
			temp.push_back(i);
		}
	}
	return { temp,0 };
}