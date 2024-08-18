










//class QueryTag{
//
//};
//
//class Result {
//private:
//	resultingData;
//public:
//	compareQueryToInput();
//	displayResult();
//
//};

#include "HRMparser.h"
#include "Queryparser.h"
#include "Result.h"
#include <gtest/gtest.h>


#ifndef UNIT_TEST

int main()
{
	std::vector <HRM_parser> input_tag;
	std::vector<Query_parser> query_tag;
	//QueryTag query_tag;
	Result result;

	int N,Q;
	std::cin>>N;
	std::cin>>Q;
	std::cin.ignore();
	int i = N/2 - 1;
	/*Check boundry conditions and ensure the security later*/
	for(int input = 0; input < N; input++){
		std::string tagString;
		HRM_parser currTag;
		std::getline(std::cin,tagString);
		if(input < N/2) {
			currTag.parseHRML(tagString);
			input_tag.push_back(currTag);
		}
		else {
				if(!input_tag[i].isValidTag(tagString))
					return 0;
				i--;
			}
		}



	for (int query = 0; query < Q; query++){
		std::string str;
		Query_parser curr_query;
		std::getline(std::cin, str);
		curr_query.parseQuery(str);
		query_tag.push_back(curr_query);
		}

	result.compareHRMtags(input_tag, query_tag);
	//result.displayResult();

	return 0;
}
#endif

