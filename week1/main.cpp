/*
** October 2018
** week: 1
** file: main.cpp ( demonstrates features developed during the course )
** use with: main.h
**
** linux/cygwin compile with:
** g++ -Wnarrowing -std=c++11 main.cpp -o main
**
** win32/64 compile with: cl main.cpp
**
** Highlights
** ==========
** 1) forward namespace declaration
** 2) vector<Association<string, int>>  creation via using directive
** 3) structure definition for raw month data, using strings and const int size
** 4) vector push_back to insert data from structure,
** 5) using prefix ++ to index into raw data in structure array
** 6) auto reference with ranged-based for loop for access for vector
** 7) compile time constant expression for days in month (dom) search
** 8) call value() method to check for dom
** 9) try...catch expression, with exception error handling
**10) using vector<Association<string, int>>::const_iterator to iterate vector in search
**11) begin() / end() iterator
**12) key() / value() member method
**13) throw exception with search value
*/
#include "main.h"

int main(int argc, char* argv[])
{
	// forward namespace declarations
	using PJWAssociations::Association;
	using PJWAssociations::VecAsI;
	using PJWAssociations::NotFoundException;

	VecAsI daysInMonth;	// a vector of Association<> pointers 

	createMonths(daysInMonth); // populate months using normal function

	/* *******************************************
	** identify all element with VALUE of 30 days
	** ********************************************/
	std::cerr << "Using Days In Month dictionary, identify months with 30 days" << std::endl;

	for (const auto& assoc : daysInMonth) {
		constexpr int dom = 30; // number of days in month to search for
		// 
		if (assoc.value() == dom) {
			// can print off association using operator<<
			std::cerr << "\tMonths with " << dom << " days: " << assoc.key() << '\n';
		}
	}

	try { // use find_key function to search for a specific month

		std::string the_key = "Septembre"; // September (FR)
		int idx = findKey(daysInMonth, the_key);
		std::cerr << "FOUND KEY: " << the_key << " WITH VALUE: " << idx << std::endl;
	}
	catch (const NotFoundException& E) {
		std::cerr << "NOT FOUND EXCEPTION CAUGHT: ";
		std::cerr << "Data: " << E.data() << std::endl;
		// now do something sensible 
	}

	// use std::foreach (STL) algorithm with lambda expression to print all
	std::for_each(std::begin(daysInMonth), std::end(daysInMonth),
		[&](Association<std::string, int> avi) {
		std::cerr << "\tMonth: " << avi.key() << " has days: " << avi.value() << std::endl;
	});

	// if running within IDE
	char c = std::cin.get();
}

namespace PJWAssociations {
	const int daysInMonth = 12;

	struct monthData { // make a structure for our data
		int monthDays[daysInMonth];
		string monthNames[daysInMonth];
	};

	monthData theMonthData = {
	  { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, // array of days in month Jan-Dec inclusive
	  { "January", "February", // winter
		"March", "April", "May", // spring
		"June", "July", "August", // summer
		"September", "October", "November", // autumn
		"December" // winter
	  }
	};


	/*
	** fill vector passed in as a parameter using instances of assocation, reading off data from monthDataStructure
	*/
	void createMonths(VecAsI& months)
	{
		using PJWAssociations::theMonthData;

		int item{ 0 }; // initializer for index into struct
		months.push_back(Association <string, int>(theMonthData.monthNames[item], theMonthData.monthDays[item]));  // jan
		months.push_back(Association <string, int>(theMonthData.monthNames[++item], theMonthData.monthDays[item]));  // f
		months.push_back(Association <string, int>(theMonthData.monthNames[++item], theMonthData.monthDays[item]));  // m
		months.push_back(Association <string, int>(theMonthData.monthNames[++item], theMonthData.monthDays[item]));  // a
		months.push_back(Association <string, int>(theMonthData.monthNames[++item], theMonthData.monthDays[item]));  // m
		months.push_back(Association <string, int>(theMonthData.monthNames[++item], theMonthData.monthDays[item]));  // j
		months.push_back(Association <string, int>(theMonthData.monthNames[++item], theMonthData.monthDays[item])); // j
		months.push_back(Association <string, int>(theMonthData.monthNames[++item], theMonthData.monthDays[item])); // a
		months.push_back(Association <string, int>(theMonthData.monthNames[++item], theMonthData.monthDays[item]));  // s
		months.push_back(Association <string, int>(theMonthData.monthNames[++item], theMonthData.monthDays[item])); // o
		months.push_back(Association <string, int>(theMonthData.monthNames[++item], theMonthData.monthDays[item]));  // n
		months.push_back(Association <string, int>(theMonthData.monthNames[++item], theMonthData.monthDays[item])); // d
	}



	/*
	** using vector iterator search in dictionary for string key, return index for found value,
	** otherwise throw Exception
	*/
	int findKey(VecAsI& dict, const string& k)
	{
		using iter = vector<Association<string, int>>::const_iterator;
		iter i = dict.begin();
		do {
			if (i->key() == k) {
				return i->value();
			}
		} while (++i != dict.end());

		throw(NotFoundException(k));
	}

}// ns
