/*
 * test_case.cpp
 *
 *  Created on: Aug 17, 2024
 *      Author: engrm
 */

#include "Queryparser.h"
#include "HRMparser.h"
#include "Result.h"
#include <gtest/gtest.h>
#include <sstream>

/*HRM_parser class testing started*/
class myHRMparserTest:public::testing::Test {
public:
	HRM_parser HRM_test_obj;
	std::multimap<std::string, std::multimap<std::string, std::string>> temp;
	std::multimap<std::string, std::string>::iterator it;
	void SetUp() override {
		std::string HRM_str = "<tag3 another1=\"another\" final1=\"final\">";
		HRM_test_obj.parseHRML(HRM_str);
		temp = HRM_test_obj.getTagData();
		it = temp.begin()->second.begin();
	}
};



TEST_F(myHRMparserTest, HRMtagName1){
	ASSERT_EQ("tag3", temp.begin()->first);
}

TEST_F(myHRMparserTest, HRMattrName1){
	ASSERT_EQ("another1", it->first);
}

TEST_F(myHRMparserTest, HRMattrValue1){
	ASSERT_EQ("another", it->second);
}

TEST_F(myHRMparserTest, HRMattrName2){
	it++;
	ASSERT_EQ("final1", it->first);
}

TEST_F(myHRMparserTest, HRMattrValue2){
	it++;
	ASSERT_EQ("final", it->second);
}

/*Query_parser class testing started*/
class myQueryParserTest: public::testing::Test {
public:
	Query_parser query_test_obj;
	std::multimap<std::string, std::vector<std::string>> tmp;
	void SetUp() override {
		std::string testStr = "tag1.tag2.tag3~name";
		query_test_obj.parseQuery(testStr);
		tmp = query_test_obj.getQueryData();
	}
/*
	void tearDown() override {

	}
	*/
};

TEST_F(myQueryParserTest, tagTwo){

		ASSERT_EQ("tag2", tmp.begin()->second[1]);
}

TEST_F(myQueryParserTest, tagThree){

	ASSERT_EQ("tag3", tmp.begin()->second[2]);
}


/*Result test cases started here*/
class myResultTest: public ::testing::Test {
protected:
	Result result;
    Query_parser query_test_obj;
    HRM_parser HRM_test_obj;

    void SetUp() override {
        // Manually set up both objects
        std::string HRM_str = "<tag3 another1=\"another\" final1=\"final\">";
        HRM_test_obj.parseHRML(HRM_str);

        std::string testStr = "tag1.tag2.tag3~name";
        query_test_obj.parseQuery(testStr);
    }

};

TEST_F(myResultTest, compareHRMtagsTest){

	std::vector<HRM_parser> hrm_test_object;
	std::vector<Query_parser> query_test_object;
	hrm_test_object[0] = HRM_test_obj;
	query_test_object[0] = query_test_obj;
    // Redirect std::cout to a string stream
    std::ostringstream output;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf());

    // Call the function
    result.compareHRMtags(hrm_test_object, query_test_object );

    // Restore the original buffer
    std::cout.rdbuf(oldCoutBuffer);

    // Check the entire output
    std::string expectedOutput ="Name1\nNot Found!\nHelloWorld\n";

	ASSERT_EQ(output.str(), expectedOutput);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

