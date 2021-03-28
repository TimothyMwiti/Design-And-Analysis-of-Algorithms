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
#include <algorithm>
#include <utility>
#include<map>

// This function should return your name.
// The name should match your name in Canvas

void GetStudentName(std::string& your_name)
{
   //replace the placeholders "Firstname" and "Lastname"
   //with you first name and last name 
   your_name.assign("Timothy Mwiti");
}


std::vector<std::vector<int>> computedValues;
void initializeVectors(int size){
    std::vector<int> tempVect(size*2 - 1, -2147483647);
    for(int i = 0; i < size; i++){
        computedValues.push_back(tempVect);
    }
}

void FindMaxBalancedSequenceHelperDynamic(const std::vector<int>& weights){
    int weightsSize = weights.size();
    for(int i = weightsSize-1; i >= 0; i--){
        for(int j = (weightsSize-1)-i; j <= (weightsSize-1)+i; j++){
            if(i == weightsSize-1){
                computedValues[i][weightsSize-1] = 0;
                computedValues[i][weightsSize-2] = weights[i];
                computedValues[i][weightsSize] = -weights[i];
                break;
            }else{
                bool by_neg = computedValues[i+1][j-1] == -2147483647;
                bool by_zero = computedValues[i+1][j] == -2147483647;
                bool by_one = computedValues[i+1][j+1] == -2147483647;
                if(!by_neg && by_zero && by_one){
                    computedValues[i][j] = computedValues[i+1][j-1]-weights[i];
                }else if(by_neg && !by_zero && by_one){
                    computedValues[i][j] = computedValues[i+1][j];
                }else if(by_neg && by_zero && !by_one){
                    computedValues[i][j] = computedValues[i+1][j+1] + weights[i];
                }else if(!by_neg && !by_zero && by_one){
                    computedValues[i][j] = std::max(computedValues[i+1][j-1]-weights[i], computedValues[i+1][j]);
                }else if(!by_neg && by_zero && !by_one){
                    computedValues[i][j] = std::max(computedValues[i+1][j-1]-weights[i], computedValues[i+1][j+1] + weights[i]);
                }else if(by_neg && !by_zero && !by_one){
                    computedValues[i][j] = std::max(computedValues[i+1][j], computedValues[i+1][j+1] + weights[i]);
                }else if(!by_neg && !by_zero && !by_one){
                    int tempMax = std::max(computedValues[i+1][j], computedValues[i+1][j+1] + weights[i]);
                    computedValues[i][j] = std::max(tempMax, computedValues[i+1][j-1]-weights[i]);
                }else{
                    computedValues[i][j] = -2147483647;
                }                
            }
        }
    }

}

/*
    THIS IS AN IMPLEMENTATION OF A GREEDY APPROACH. ASSIGNMENT RUNS USING DYNAMIC BUT A USER
    CAN RUN USING THIS APPROACH IF THEY PREFER TO.
*/
int FindMaxBalancedSequenceGreedy (const std::vector<int>& weights)
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


int FindMaxBalancedSequence (const std::vector<int>& weights)
{
    computedValues.clear();
    initializeVectors(weights.size());
    FindMaxBalancedSequenceHelperDynamic(weights);   
    return computedValues[0][computedValues[0].size()/2];
}