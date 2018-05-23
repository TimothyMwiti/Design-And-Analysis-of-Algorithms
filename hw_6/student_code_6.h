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
#include <utility>

std::map<std::string, int> weightsmap;
// This function should return your name.
// The name should match your name in Canvas

void GetStudentName(std::string& your_name)
{
   //replace the placeholders "Firstname" and "Lastname"
   //with you first name and last name 
   your_name.assign("Timothy Mwiti");
}

std::pair<bool, int> FindMaxBalancedSequenceHelper(int start, int a_i_sum, const std::vector<int>& weights){
    std::string dictKey = std::to_string(start)+"_"+std::to_string(a_i_sum);
    if(start == weights.size()-1){
        if(a_i_sum == 1){
            return std::make_pair(true, -weights.at(start));
        }
        if(a_i_sum == -1){
            return std::make_pair(true, weights.at(start));
        }else if(a_i_sum == 0){
            return std::make_pair(true, 0);
        }
        return std::make_pair(false, -2147483647);
    }else if(weights.size()-start < abs(a_i_sum)){
        weightsmap.insert(std::make_pair(dictKey, -2147483647));
        return std::make_pair(false, -2147483647);
    }
    std::pair<bool,int> multiply_by_one;
    std::pair<bool,int> multiply_by_neg;
    std::pair<bool,int> multiply_by_zero;
    if(weightsmap.find(dictKey) == weightsmap.end()){
        multiply_by_one = FindMaxBalancedSequenceHelper(start+1, a_i_sum+1, weights);
        multiply_by_neg = FindMaxBalancedSequenceHelper(start+1, a_i_sum-1, weights);
        multiply_by_zero = FindMaxBalancedSequenceHelper(start+1, a_i_sum, weights);
    }else{
        int computedVal = weightsmap.find(std::to_string(start)+"_"+std::to_string(a_i_sum))->second;
        if(computedVal == -2147483647){
            return std::make_pair(false, -2147483647);
        }else{
            return std::make_pair(true, computedVal);
        }
    }

    if(!multiply_by_neg.first && !multiply_by_one.first && multiply_by_zero.first){ // 0 0 1
        weightsmap.insert(std::make_pair(dictKey, multiply_by_zero.second));
        return std::make_pair(true, multiply_by_zero.second);
    }else if(multiply_by_neg.first && !multiply_by_one.first && !multiply_by_zero.first){ // 1 0 0
        weightsmap.insert(std::make_pair(dictKey, multiply_by_neg.second- weights.at(start)));
        return std::make_pair(true, multiply_by_neg.second - weights.at(start));
    }else if(!multiply_by_neg.first && multiply_by_one.first && !multiply_by_zero.first){ // 0 1 0
        weightsmap.insert(std::make_pair(dictKey, multiply_by_one.second+ weights.at(start)));
        return std::make_pair(true, multiply_by_one.second + weights.at(start));
    }else if(!multiply_by_neg.first && multiply_by_one.first && multiply_by_zero.first){ // 0 1 1
        int max_sum = std::max(multiply_by_one.second + weights.at(start), multiply_by_zero.second);
        weightsmap.insert(std::make_pair(dictKey, max_sum));
        return std::make_pair(true, max_sum);
    }else if(multiply_by_neg.first && !multiply_by_one.first && multiply_by_zero.first){ // 1 0 1
        int max_sum = std::max(multiply_by_neg.second - weights.at(start), multiply_by_zero.second);
        weightsmap.insert(std::make_pair(dictKey, max_sum));
        return std::make_pair(true, max_sum);
    }else if(multiply_by_neg.first && multiply_by_one.first && !multiply_by_zero.first){ // 1 1 0
        int max_sum = std::max(multiply_by_neg.second - weights.at(start), multiply_by_one.second + weights.at(start));
        weightsmap.insert(std::make_pair(dictKey, max_sum));
        return std::make_pair(true, max_sum);
    }else if(multiply_by_neg.first && multiply_by_one.first && multiply_by_zero.first){ // 1 1 1
        int tempmax = std::max(multiply_by_neg.second - weights.at(start), multiply_by_one.second + weights.at(start));
        int max_sum = std::max(tempmax, multiply_by_zero.second);
        weightsmap.insert(std::make_pair(dictKey, max_sum));
        return std::make_pair(true, max_sum);
    }else{ // 0 0 0
        weightsmap.insert(std::make_pair(dictKey, -2147483647));
        return std::make_pair(false, -2147483647);
    }
}

int FindMaxBalancedSequence (const std::vector<int>& weights)
{
    int ret_val = FindMaxBalancedSequenceHelper(0, 0,weights).second;
    weightsmap.clear();
    return ret_val;
}
