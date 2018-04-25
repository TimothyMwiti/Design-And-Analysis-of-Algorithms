///////////////////////////////////////////////////////////////////////////////
// You need to 
//    1. Read Problem 2 in homework assignmnet #3. 
//    2. Implement function GetStudentName.
//    3. Implement function FindBestSchedule.
//    4. Compile your code as explained in the PDF file.
//    5. Run the executable.
//    6. Test and debug your code.
//    7. Submit your code ("student_code_3.h") and results ("solution_3.dat") 
//       via Canvas.
//
///////////////////////////////////////////////////////////////////////////////
//required libraries
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

struct IntervalNode {
	int startTime;
	int endTime;
	int intervalNodeIndex;
	IntervalNode(int startTime, int endTime, int intervalNodeIndex) : startTime(startTime), endTime(endTime), intervalNodeIndex(intervalNodeIndex) {}
};

struct end_time_key {
	inline bool operator()(const IntervalNode &node1, const IntervalNode &node2) const {
		return node1.endTime < node2.endTime;
	}
};

struct start_time_key {
	inline bool operator()(const IntervalNode &node1, const IntervalNode &node2) const {
		return node1.startTime < node2.startTime;
	}
};

std::vector<IntervalNode> initializeIntervalNodes(std::vector <std::pair<int, int>> availabilities) {
	std::vector<IntervalNode> intervalNodes;
	for (int i = 0; i < availabilities.size(); i++) {
		IntervalNode nodeTemp = IntervalNode(availabilities.at(i).first, availabilities.at(i).second, i);
		intervalNodes.push_back(nodeTemp);
	}
	return intervalNodes;
}
//you can include standard C++ libraries here

// This function should return your name.
// The name should match your name in Canvas

void GetStudentName(std::string& your_name)
{
   //replace the placeholders "Firstname" and "Lastname"
   //with you first name and last name 
   your_name.assign("Timothy Mwiti");
}

//you can implement this function (recommended) or the the next one
int FindBestSchedule (std::vector<std::pair<int,int>> availabilities, int T)
{   
   //Vectors of IntervalNodes. First is sorted by start time, Second is sorted by end time
	std::vector<IntervalNode> intervalsByStartTime = initializeIntervalNodes(availabilities);
	std::vector<IntervalNode> intervalsByEndTime = initializeIntervalNodes(availabilities);
	std::sort(intervalsByStartTime.begin(), intervalsByStartTime.end(), start_time_key());
	std::sort(intervalsByEndTime.begin(), intervalsByEndTime.end(), end_time_key());
    
    //Indicate processed intervals (0 if not processed, 1 if processed)
    int processedIntervals[availabilities.size()] = {0};
    int intervalsCounter = 0;
    while(intervalsByEndTime.size() > 0){
        if(processedIntervals[intervalsByEndTime.front().intervalNodeIndex] == 1){
            intervalsByEndTime.erase(intervalsByEndTime.begin() + 0);
            continue;
        }
        intervalsCounter++;
        int curEndTime = intervalsByEndTime.front().endTime;
        int timeToCheckFor = curEndTime - T;
        processedIntervals[intervalsByEndTime.front().intervalNodeIndex] = 1;
        intervalsByEndTime.erase(intervalsByEndTime.begin() + 0);
        while(intervalsByStartTime.size() > 0 && timeToCheckFor >= intervalsByStartTime[0].startTime){
            processedIntervals[intervalsByStartTime[0].intervalNodeIndex] = 1;
            intervalsByStartTime.erase(intervalsByStartTime.begin() + 0);
        }
    }
   return intervalsCounter; /* replace -1 with the correct value */
}

//if you choose to implement this function, you can replace the code with 
//your own code

int FindBestSchedule (const std::vector<int>& left, const std::vector<int>& right, int T)
{
   assert(left.size() == right.size());
   size_t size = left.size();

   std::vector<std::pair<int, int>> availabilities;
   availabilities.reserve (size);

   for (size_t i = 0; i < size; i++)
   {
      availabilities.push_back (std::make_pair(left[i], right[i]));
   }
   
   return FindBestSchedule (availabilities, T);
}
