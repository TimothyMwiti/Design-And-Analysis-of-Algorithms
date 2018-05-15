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

//you can include standard C++ libraries here

// This function should return your name.
// The name should match your name in Canvas

void GetStudentName(std::string& your_name)
{
   //replace the placeholders "Firstname" and "Lastname"
   //with you first name and last name 
   your_name.assign("Firstname Lastname");
}


//you can use one of the following signatures

//int FindMeasure (const std::vector<std::pair<int,int>>& intervals, int coverage)
//or 
//int FindMeasure(std::vector<std::pair<int, int>> intervals, int coverage)

int FindMeasure (std::vector<std::pair<int,int>> intervals, int coverage)
{  
   int measure = 0;

   //your code goes here

   return measure;
}

