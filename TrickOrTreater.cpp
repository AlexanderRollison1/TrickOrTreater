#include <iostream>
#include <mutex>
#include <chrono>
#include <thread>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <sstream>

#include "House.h"
#include "TrickOrTreater.h"


int TrickOrTreater::ImDone = 0;

TrickOrTreater::TrickOrTreater(std::string Name, std::vector<House*>List)
	: name{Name}, ListOfHouses{List}
{
}

void TrickOrTreater::Walk(int speed) 
{
    for (int i = 0; i < 10; ++i) 
	{	
		path << '.';
		/* put this_thread to sleep for speed milliseconds */
		std::this_thread::sleep_for(std::chrono::milliseconds(speed));
    }
}


void TrickOrTreater::GoTrickOrTreating()
{
	int speed = 0;

	/* range based for loop over ListOfHouses */
	for(auto it: ListOfHouses)
	{	
		speed = rand()%500 + 1;   // speed is between 1 and 500
		/* call function Walk and pass it speed */
		Walk(speed);
		Bucket[it->ringDoorbell(path)]++;
	}
	
	// Increment ImDone because this thread is done trick or treating
	ImDone++;
}

std::string TrickOrTreater::getName()
{
	return name;
}

void TrickOrTreater::startThread()
{
	TOTThreadPtr = new std::thread(&TrickOrTreater::GoTrickOrTreating, this);
}

void TrickOrTreater::joinThread()
{
	this->TOTThreadPtr->join();
	delete this->TOTThreadPtr;
}

std::string TrickOrTreater::getPath()
{
	/* return the string version of ostringstream path */
	return path.str();
}

std::ostream& operator<<(std::ostream& output, const TrickOrTreater& TOT/* add both parameters */)
{
	output << TOT.name << "'s - ";

	/* create a range based for loop using TOT.Bucket    */
	/* use the insertion operator to write the map element to output */
	for(auto it: TOT.Bucket)
	{
		output<<it.second<< " " <<it.first<<", ";
	}
	output<<std::endl;
	return output;
}
