///////////////////////////////////////////////////////////////////////////////
// You need to
//    1. Read Problem 3 in homework assignmnet #2.
//    2. Implement function GetStudentName.
//    3. Implement function MatchBracket.
//    4. Compile your code as explained in the PDF file.
//    5. Run the executable.
//    6. Test and debug your code.
//    7. Submit your code ("student_code_2.h") and results ("solution_2.dat")
//       via Canvas.
//
///////////////////////////////////////////////////////////////////////////////

//required libraries
#include <string>
#include <stack>
//you can include standard C++ libraries here


// This function should return your name.
// The name should match your name in Canvas

void GetStudentName(std::string& your_name)
{
    //replace the placeholders "Firstname" and "Lastname"
    //with you first name and last name
    your_name.assign("Timothy Mwiti");
}


int MatchBracketFromFront(std::string str, int position){
    std::stack<char> charsStack;
    charsStack.push(str.at(position));
    char cTemp;
    for(int i = position+1; i < str.length(); i++){
        if(str.at(i) == '(' || str.at(i) == '[' || str.at(i) == '{'){
            charsStack.push(str.at(i));
        }else{
            switch(str.at(i)){
                case ')':
                    cTemp = charsStack.top();
                    charsStack.pop();
                    if(cTemp != '(')
                        return -1;
                    break;
                case ']':
                    cTemp = charsStack.top();
                    charsStack.pop();
                    if(cTemp != '[')
                        return -1;
                    break;
                case '}':
                    cTemp = charsStack.top();
                    charsStack.pop();
                    if(cTemp != '{')
                        return -1;
                    break;
            }
            if(charsStack.empty())
                return i;
        }
    }
    return -1;
}

int MatchBracketFromBack(std::string str, int position){
    std::stack<char> charsStack;
    charsStack.push(str.at(position));
    char cTemp;
    for(int i = position-1; i >= 0; i--){
        if(str.at(i) == ')' || str.at(i) == ']' || str.at(i) == '}'){
            charsStack.push(str.at(i));
        }else{
            switch(str.at(i)){
                case '(':
                    cTemp = charsStack.top();
                    charsStack.pop();
                    if(cTemp != ')')
                        return -1;
                    break;
                case '[':
                    cTemp = charsStack.top();
                    charsStack.pop();
                    if(cTemp != ']')
                        return -1;
                    break;
                case '{':
                    cTemp = charsStack.top();
                    charsStack.pop();
                    if(cTemp != '}')
                        return -1;
                    break;
            }
            if(charsStack.empty())
                return i;
        }
    }
    return -1;
}

int MatchBracket (const std::string& str, int position)
{
    std::string strCopy = str;
    if(str.at(position) == '(' || str.at(position) == '[' || str.at(position) == '{'){
        return MatchBracketFromFront(strCopy, position);
    }else if(str.at(position) == ')' || str.at(position) == ']' || str.at(position) == '}'){
        return MatchBracketFromBack(strCopy, position);
    }
    return -1;
}




