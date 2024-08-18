/*
 * HRMparser.h
 *
 *  Created on: Aug 16, 2024
 *      Author: engrm
 */

#ifndef HRMPARSER_H_
#define HRMPARSER_H_

#include <iostream>
#include <vector>
#include <map>

enum class status { END_DETECTED, INVALID_TAG, VALID_INDEX};

class HRM_parser {
private:
	std::multimap<std::string, std::multimap<std::string, std::string>> tagData;

public:
	void parseHRML(std::string tagStr);
	std::multimap<std::string,std::multimap<std::string, std::string>> getTagData() { return tagData; }
	bool isValidTag(std::string endTagStr);
	std::string getTag() { return this->tagData.begin()->first; }
	std::multimap<std::string, std::string> getNameValue() { return this->tagData.begin()->second; }

	//std::string get(const HRM_parser& currTag);
};

#endif /* HRMPARSER_H_ */
