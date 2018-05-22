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
// This function should return your name.
// The name should match your name in Canvas

void GetStudentName(std::string& your_name)
{
   //replace the placeholders "Firstname" and "Lastname"
   //with you first name and last name 
   your_name.assign("Timothy Mwiti");
}


/*
1. Helper function (i, j, a_i_sum, weight_a_sum){
    if i == j{
        if a_sum == 0: return weight_a_sum;
        if a_sum == -1: return weight_a_sum + weight(i);
        if a_sum == 1: return weight_a_sum - weight(i);
    }else{
        //multiply by ome:
        by_one = helper_function(i + 1, j, a_i_sum-1, weight_a_sum + weight(i));
        by_neg = helper_function(i + 1, j, a_i_sum+1, weight_a_sum - weight(i));
        by_zero = helper_function(i + 1, j, a_i_sum-1, weight_a_sum);
        return max(by_one, by_neg, by_zero);
    }
}


std::pair<int, int> FindMaxBalancedSequenceHelper(int start, int a_i_sum, const std::vector<int>& weights){
    if(start == weights.size()-1){
        if(std::max(weights.at(start), std::max(0, -weights.at(start))) == 0){
            return std::make_pair(a_i_sum, 0);
        }else if(std::max(weights.at(start), std::max(0, -weights.at(start))) == weights.at(start)){
            return std::make_pair(a_i_sum+1, weights.at(start));
        }else if (std::max(weights.at(start), std::max(0, -weights.at(start))) == -weights.at(start)){
            return std::make_pair(a_i_sum-1, -weights.at(start));
        }
    }else{
        int temp = weights.at(start);
        std::pair<int,int> multiply_by_one = std::make_pair(a_i_sum+1, (FindMaxBalancedSequenceHelper(start+1, a_i_sum+1, weights)).second + temp);
        std::pair<int,int> multiply_by_neg = std::make_pair(a_i_sum-1, (FindMaxBalancedSequenceHelper(start+1, a_i_sum-1, weights)).second - temp);
        std::pair<int,int> multiply_by_zero = std::make_pair(a_i_sum, (FindMaxBalancedSequenceHelper(start+1, a_i_sum, weights)).second);
        return std::make_pair(a_i_sum, std::max(std::max(multiply_by_neg.second, multiply_by_one.second), multiply_by_zero.second));
    }
}
*/
std::pair<bool, int> FindMaxBalancedSequenceHelper(int start, int a_i_sum, const std::vector<int>& weights, bool is_valid){
    if(start == weights.size()-1){
        if(abs(a_i_sum) > 1){
            return std::make_pair(false, 0);
        }
        if(a_i_sum == 1){
            return std::make_pair(true, -weights.at(start));
        }
        if(a_i_sum == -1){
            return std::make_pair(true, weights.at(start));
        }
        return std::make_pair(true, 0);
    }else{        
        std::pair<bool,int> multiply_by_one;
        std::pair<bool,int> multiply_by_neg;
        std::pair<bool,int> multiply_by_zero;
        multiply_by_one = FindMaxBalancedSequenceHelper(start+1, a_i_sum+1, weights, true);
        multiply_by_neg = FindMaxBalancedSequenceHelper(start+1, a_i_sum-1, weights, true);
        multiply_by_zero = FindMaxBalancedSequenceHelper(start+1, a_i_sum, weights, true);

        //std::cout<< multiply_by_neg.second << std::endl;
        //std::cout<< multiply_by_zero.second << std::endl;
        //std::cout<< multiply_by_one.second << std::endl;
        if(!multiply_by_neg.first && !multiply_by_one.first && multiply_by_zero.first){
            return std::make_pair(true, multiply_by_zero.second);
        }else if(multiply_by_neg.first && !multiply_by_one.first && !multiply_by_zero.first){
            return std::make_pair(true, multiply_by_neg.second - weights.at(start));
        }else if(!multiply_by_neg.first && multiply_by_one.first && !multiply_by_zero.first){
            return std::make_pair(true, multiply_by_one.second + weights.at(start));
        }else if(!multiply_by_neg.first && multiply_by_one.first && multiply_by_zero.first){
            return std::make_pair(true, std::max(multiply_by_one.second + weights.at(start), multiply_by_zero.second));
        }else if(multiply_by_neg.first && !multiply_by_one.first && multiply_by_zero.first){
            return std::make_pair(true, std::max(multiply_by_neg.second - weights.at(start), multiply_by_zero.second));
        }else if(multiply_by_neg.first && multiply_by_one.first && !multiply_by_zero.first){
            return std::make_pair(true, std::max(multiply_by_neg.second - weights.at(start), multiply_by_one.second + weights.at(start)));
        }else if(multiply_by_neg.first && multiply_by_one.first && multiply_by_zero.first){
            int tempmax = std::max(multiply_by_neg.second - weights.at(start), multiply_by_one.second + weights.at(start));
            return std::make_pair(true, std::max(tempmax, multiply_by_zero.second));
        }else{
            return std::make_pair(false, -299999999);
        }
    }
}
//implement the following function
int FindMaxBalancedSequence (const std::vector<int>& weights)
{
    return FindMaxBalancedSequenceHelper(0, 0,weights, true).second;
}