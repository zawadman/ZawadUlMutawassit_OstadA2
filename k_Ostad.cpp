#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool isKOstad(const string& st1, const string& st2, int k)
{
    vector<int> freq1(26, 0), freq2(26, 0);

    for (char c : st1)
    {
        freq1[c - 'a']++; //for indexing purposes subtracting character value of "a" gives the integer index
    }
    for (char c : st2)
    {
        freq2[c - 'a']++;
    }
    int sumPositive = 0;
    int sumNegative = 0;

    //LOOP to check the mismatches in the strings. ONLY insert delete and change
    for (int i = 0; i < 26; i++) {
        int diff = freq1[i] - freq2[i];
        if (diff > 0) {
            sumPositive += diff;
        } else {
            sumNegative += (-diff);
        }
    }

    int cost = max(sumPositive, sumNegative);
    return (cost <= k);
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