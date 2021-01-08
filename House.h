#ifndef _HOUSE_
#define _HOUSE_

/* add the necessary includes */
#include <iostream>
#include <mutex>
#include <chrono>
#include <thread>
#include <vector>
#include <string>
#include <map>
#include <sstream>

/* add an include guard named _HOUSE_  */

class House
{
	public :
		/* create the prototype for the constructor based on House.cpp */
		/* create the prototype for ringDoorbell() based on House.cpp */
		House(std::string Name, std::map<int,std::string>CandyRanking);
		std::string ringDoorbell(std::ostringstream &path);
		
	private :
		std::string houseName;
		/* declare a mutex named door */
		/* declare a map named CandyRankingMap of type int,string */
		std::mutex door;
		std::map<int, std::string> CandyRankingMap;
};

#endif
