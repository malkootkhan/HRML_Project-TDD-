/*
 * Result.cpp
 *
 *  Created on: Aug 17, 2024
 *      Author: engrm
 */

#include "Result.h"

std::string matchAttr(std::string& aName, std::multimap<std::string, std::string> attr_name_val) {
	for(auto& item: attr_name_val) {
		if(item.first == aName) {
			return item.second;
		}
	}
	return "Not Found!";
}

void Result::compareHRMtags(std::vector<HRM_parser>& hrm, std::vector<Query_parser>& query) {

	std::string attribute_name;
	std::string attribute_value;
	for(auto& itemQ: query) {
		bool flag = true;
		HRM_parser fItem;
		std::vector<std::string> vec = itemQ.getTagVec();
		std::string aName = itemQ.getAttrName();
		for(auto& itemQVec:vec) {
		std::string t = itemQVec;
		for(auto itemH: hrm){
			 fItem = itemH;
			if (t == itemH.getTag())
				{
					flag = false;
					break;
				}
		}
		if(flag) {
				std::cout<< "Not Found!"<<std::endl;
				break;
			}
		else {
			attribute_value = matchAttr(aName, fItem.getNameValue());
		}
		}
		std::cout<<attribute_value<<std::endl;
	}
}



