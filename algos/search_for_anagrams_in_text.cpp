#include <string.h>
#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

const int MAX_UNIQUE_CHARS = 256;

bool compare(const int arr1[], const int arr2[])
{
    for (int i = 0; i < MAX_UNIQUE_CHARS; i++)
        if (arr1[i] != arr2[i])
            return false;
    return true;
}

vector<string> getAnagramMatches(const string pattern, const string text) {
    vector<string> matches = {};
    int charsCount[MAX_UNIQUE_CHARS] = {}, windowCount[MAX_UNIQUE_CHARS] = {};
    int S = pattern.size(), L = text.size();

    for (int i = 0; i < S; i++) {
        charsCount[int(pattern[i])]++;
        windowCount[int(text[i])]++;
    }
    
    for (int i = S; i < L; i++) {
        if (compare(charsCount, windowCount)) {
            matches.push_back(text.substr(i-S, S));
        }
        
        windowCount[int(text[i])]++;
        windowCount[int(text[i-S])]--;
    }
       
    if (compare(charsCount, windowCount)) {
        matches.push_back(text.substr(L-S));
    }
    return matches;
} 

int main() {
    string pattern, text;
    cout << "Enter a pattern to search for: ";
    getline(cin, pattern);
    cout << "Enter a string to search: ";
    getline(cin, text);

    vector<string> matches = getAnagramMatches(pattern.c_str(), text.c_str());
    
    printf("Found %lu matches.\n\n", matches.size());
    
    for (auto it = matches.cbegin(); it != matches.cend(); ++it) {
        cout << *it << endl;
    }
    
    return 0;
}
