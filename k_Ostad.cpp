#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool isKOstad(const string& st1, const string& st2, int k)
{
    
}


int main()
{
    string str1 = "anagram";
    string str2 = "grammar";
    int k = 3;

    if (isKOstad(str1, str2, k)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}