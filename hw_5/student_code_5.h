///////////////////////////////////////////////////////////////////////////////
// You need to 
//    1. Read Problem 2 in homework assignmnet #5. 
//    2. Implement function GetStudentName.
//    3. Implement function FindBestSchedule.
//    4. Compile your code as explained in the PDF file.
//    5. Run the executable.
//    6. Test and debug your code.
//    7. Submit your code ("student_code_5.h") and results ("solution_5.dat") 
//       via Canvas.
//
///////////////////////////////////////////////////////////////////////////////

//required libraries
#include <string>
#include <vector> 
#include <queue>
#include <iostream>
#include <algorithm>
#include <functional>
//you can include standard C++ libraries here

// This function should return your name.
// The name should match your name in Canvas

void GetStudentName(std::string& your_name)
{
   //replace the placeholders "Firstname" and "Lastname"
   //with you first name and last name 
   your_name.assign("Timothy Mwiti");
}

template<typename T> void print_queue(T& q){
    while( ! q.empty()){
        std::cout << q.top().second << " ";
        q.pop();
    }
}
class CompareIntervals
{
public:
    bool operator()(std::pair<int,int> firstInterval,std::pair<int,int> secondInterval) {
        return firstInterval.second>secondInterval.second;
    }
};
//you can use one of the following signatures

//int FindMeasure (const std::vector<std::pair<int,int>>& intervals, int coverage)
//or 
//int FindMeasure(std::vector<std::pair<int, int>> intervals, int coverage)

int FindMeasure (std::vector<std::pair<int,int>> intervals, int coverage)
{  
   int measure = 0;
   int startIntervalMark = 0;
   std::sort(std::begin(intervals), std::end(intervals));
   std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>, CompareIntervals> intervalsOrderedByFinishTime;
   // std::cout << "Yes" << std::endl;
   /*
   for(int i = 0; i < intervals.size(); i++){
       std::cout<< intervals.at(i).first <<std::endl;
       std::cout << intervals.at(i).second << std::endl;
       std::cout<< "ENd of  one" << std::endl;
   }
   */
   for(int i = 0; i < intervals.size(); i++){
       while(! intervalsOrderedByFinishTime.empty() && intervalsOrderedByFinishTime.top().second <= intervals.at(i).first){
           std::pair<int, int> tempInterval = intervalsOrderedByFinishTime.top();
           intervalsOrderedByFinishTime.pop();
           if(intervalsOrderedByFinishTime.size() == coverage){
               std::pair<int,int> firstToFinish = intervalsOrderedByFinishTime.top();
               std::pair<int, int> nextToPush = intervals.at(i);
               int endCoverage = std::min(firstToFinish.second, nextToPush.first);
               measure += endCoverage - tempInterval.second;
           }
       }
       intervalsOrderedByFinishTime.push(intervals.at(i));
       if(intervalsOrderedByFinishTime.size() == coverage){
           std::pair<int,int> firstToFinish = intervalsOrderedByFinishTime.top();
           std::pair<int,int> nextToPush = intervals.at(i+1);
           int endCoverage = std::min(firstToFinish.second, nextToPush.first);
           measure += endCoverage - intervals.at(i).first;
       }
   }

   while(! intervalsOrderedByFinishTime.empty()){
       std::pair<int, int> tempInterval = intervalsOrderedByFinishTime.top();
       intervalsOrderedByFinishTime.pop();
       if(intervalsOrderedByFinishTime.size() == coverage){
           std::pair<int,int> firstToFinish = intervalsOrderedByFinishTime.top();
           measure += firstToFinish.second - tempInterval.second;
           break;
       }
   }

   return measure;
}


