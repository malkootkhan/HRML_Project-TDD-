/*
 * Queryparser.h
 *
 *  Created on: Aug 16, 2024
 *      Author: engrm
 */

#ifndef QUERYPARSER_H_
#define QUERYPARSER_H_
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>


class Query_parser {
private:
	std::multimap<std::string, std::vector<std::string>> queryTag;
public:
	void parseQuery(std::string queryStr);
	std::multimap<std::string, std::vector<std::string>> getQueryData(){ return queryTag; }
	std::vector<std::string> getTagVec() { return this->queryTag.begin()->second;}
	std::string getAttrName() { return this->queryTag.begin()->first; }
	//virtual ~Query_parser();
};

#endif /* QUERYPARSER_H_ */
