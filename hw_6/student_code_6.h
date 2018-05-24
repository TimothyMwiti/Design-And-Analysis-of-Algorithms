///////////////////////////////////////////////////////////////////////////////
// You need to 
//    1. Read Problem 2 in homework assignmnet #6.
//    2. Implement function GetStudentName.
//    3. Implement function FindBestSchedule.
//    4. Compile your code as explained in the PDF file.
//    5. Run the executable.
//    6. Test and debug your code.
//    7. Submit your code ("student_code_6.h") and results ("solution_6.dat") 
//       via Canvas.
//
///////////////////////////////////////////////////////////////////////////////

//required libraries
#include <string>
#include <vector> 

//you can include standard C++ libraries here
#include <algorithm>

//std::map<std::string, int> weightsmap;
// This function should return your name.
// The name should match your name in Canvas

void GetStudentName(std::string& your_name)
{
   //replace the placeholders "Firstname" and "Lastname"
   //with you first name and last name 
   your_name.assign("Timothy Mwiti");
}

int FindMaxBalancedSequence (const std::vector<int>& weights)
{
    std::vector<int> weightscopy = weights;
    std::sort(std::begin(weightscopy), std::end(weightscopy), std::greater<int>());
    int sum = 0;
    int weights_size = weights.size();
    for(int i = 0; i < weights_size/2; i++){
        sum += std::max((weightscopy.at(i) - weightscopy.at(weights_size-(i+1))), 0);
    }
    return sum;
}
