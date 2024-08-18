/*
 * Result.h
 *
 *  Created on: Aug 17, 2024
 *      Author: engrm
 */

#ifndef RESULT_H_
#define RESULT_H_

#include <iostream>
#include <vector>
#include "HRMparser.h"
#include "Queryparser.h"

class Result {
public:

	void compareHRMtags(std::vector<HRM_parser>& hrm, std::vector<Query_parser>& Query);
	//void display();
	//virtual ~Result();
};

#endif /* RESULT_H_ */
