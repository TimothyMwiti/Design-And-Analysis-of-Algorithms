///////////////////////////////////////////////////////////////////////////////
// You need to 
//    1. Read Problem 3 in homework assignmnet #4. 
//    2. Implement function GetStudentName.
//    3. Implement function MinMatching.
//    4. Compile your code as explained in the PDF file.
//    5. Run the executable.
//    6. Test and debug your code.
//    7. Submit your code ("student_code_4.h") and results ("solution_4.dat") 
//       via Canvas.
//
///////////////////////////////////////////////////////////////////////////////

//required libraries
#include <string>
#include <vector>
#include <cstring>
#include <cmath>

//you can include standard C++ libraries here


// This function should return your name.
// The name should match your name in Canvas

void GetStudentName(std::string& your_name)
{
   //replace the placeholders "Firstname" and "Lastname"
   //with you first name and last name 
   your_name.assign("Timothy Mwiti");
}

int MinMatching (std::vector<int> x, std::vector<int> y)
{ 
  std::sort(x.begin(), x.end());
  std::sort(y.begin(), y.end()); 
  int cost = 0;
  for(int i = 0; i < x.size(); i++){
      cost += std::abs(x[i]-y[i]);
  }  
  return cost;
}
