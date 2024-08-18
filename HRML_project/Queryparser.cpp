/*
 * Queryparser.cpp
 *
 *  Created on: Aug 16, 2024
 *      Author: engrm
 */

#include "Queryparser.h"

	void Query_parser::parseQuery(std::string queryStr){
		if(queryStr.find('~') == std::string::npos){
			std::cerr<<"The query is invalid"<<std::endl;
			return;
		}
		std::vector<std::string> tag;
		std::string attr_name;
		std::string::size_type startIndex = 0;
		std::string::size_type endIndex = queryStr.find('.');
		if(endIndex == std::string::npos) {
			endIndex = queryStr.find('~');
			if(endIndex == std::string::npos){
				std::cerr<<"Invalid query, having no attribute"<<std::endl;
				return;
			}
			tag.push_back(queryStr.substr(startIndex, endIndex - startIndex));
			attr_name = queryStr.substr(endIndex + 1, (queryStr.length() - (endIndex+1)) );
			queryTag.emplace(attr_name, tag);
			return;
		}
		while(true){
			tag.push_back(queryStr.substr(startIndex, endIndex - startIndex));
			queryStr = queryStr.substr(endIndex + 1, (queryStr.length() - (endIndex + 1)) );

			startIndex = 0;
			endIndex = queryStr.find('.');
			if(endIndex == std::string::npos) {
				endIndex = queryStr.find('~');
				if(endIndex == std::string::npos){
					std::cerr<<"Invalid query, having no attribute"<<std::endl;
					return;
				}
			tag.push_back(queryStr.substr(startIndex, endIndex - startIndex));
			attr_name = queryStr.substr(endIndex + 1, (queryStr.length() - (endIndex+1)) );
			queryTag.emplace(attr_name, tag);
			return;
		}

		}


	}
