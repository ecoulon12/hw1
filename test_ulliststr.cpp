#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
    ULListStr list;
	list.push_back("oldfront");
	list.push_back("oldback");


	// this should create an empty slot at the front of the list, and the new element can be put there
	list.pop_front();
	list.push_front("newfront");


	// now, a new element struct should get created at the front
	list.pop_back();
	list.push_front("cloudfront");


	// now, the original head should get deleted
	list.pop_back();

	list.pop_front();


	list.push_front("newback");

}
