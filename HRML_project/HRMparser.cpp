/*
 * HRMparser.cpp
 *
 *  Created on: Aug 16, 2024
 *      Author: engrm
 */

#include "HRMparser.h"

bool HRM_parser::isValidTag(std::string endTagStr) {

	if( endTagStr[0] != '<' || endTagStr[1] != '/' || endTagStr[endTagStr.length() - 1] != '>') {
		std::cerr<<"Invalid tag input"<<std::endl;
		return false;
	}
	std::string tmp = endTagStr.substr(2, endTagStr.find('>') - 2 );
	if(tmp != this->getTag()){
		std::cerr<<"Invalid tag input"<<std::endl;
		return false;
	}
	return true;
}

void HRM_parser::parseHRML(std::string tagStr) {
	/*<tag-name attribute1-name = "value1" attribute2-name = "value2" ...>*/
	int max_len = tagStr.length();
	if(max_len <= 0){
		std::cerr<<"there is no input tag string"<<std::endl;
		return;
	}
	std::string::size_type startIndex = tagStr.find('<');
	std::string::size_type endIndex = tagStr.find(' ');
	if(startIndex == std::string::npos || endIndex == std::string::npos){
		std::cerr<<"tagStr.find() function failed to find the parameter in string: invalid tag string"<<std::endl;
		return;
	}
	std::string tagname = tagStr.substr( (startIndex + 1), (endIndex - (startIndex+1)));

	std::multimap<std::string,std::string> tmpMap;
	while(true)
		{
			std::string attrName;
			std::string attrValue;

			if(tagStr[endIndex] == '>' || tagStr[startIndex] == '>')
					break;

			startIndex = endIndex;
			while(tagStr[startIndex] == ' '||tagStr[startIndex] == '"')
				startIndex++;
			if(tagStr[startIndex] == '>')
				break;

			tagStr = tagStr.substr(startIndex, max_len - startIndex);
			startIndex = 0;
			endIndex = tagStr.find('=');
			if(tagStr[endIndex - 1] == ' ')
				endIndex--;

			attrName = tagStr.substr(startIndex, endIndex - startIndex);


			startIndex = endIndex;
			while(tagStr[startIndex] == ' ' || tagStr[startIndex] == '='|| tagStr[startIndex] == '"')
				startIndex++;

			if(tagStr[endIndex] == '>')
				break;

			tagStr = tagStr.substr(startIndex, max_len - startIndex);
			startIndex = 0;
			endIndex = tagStr.find('"');
			attrValue = tagStr.substr(startIndex, endIndex - startIndex);

			//stage the attribute name and value
			tmpMap.insert({attrName , attrValue});

		}
	tagData.insert({tagname, tmpMap});

}

