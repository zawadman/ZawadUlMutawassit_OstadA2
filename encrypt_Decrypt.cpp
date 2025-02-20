#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void encrypt(const string& str1, string& str2)
{
    //the input is empty, the encrypted result is empty
    if (str1.empty()) {
        str2.clear();
        return;
    }

    //encode consecutive characters
    string encoded;
    char currentChar = str1[0];
    int count = 1;

    for (size_t i = 1; i < str1.size(); i++) {
        if (str1[i] == currentChar) {
            count++;
        } else {
            //the end of a run of 'currentChar'
            encoded += currentChar + to_string(count);
            currentChar = str1[i];
            count = 1;
        }
    }
    //append last run
    encoded += currentChar + to_string(count);

    reverse(encoded.begin(), encoded.end());

    str2 = encoded;
}

void decrypt(const string& str2)
{
    //reverse the encrypted string
    string reversed = str2;
    reverse(reversed.begin(), reversed.end());

    //parse the reversed string as (character + count)
    string decoded;
    size_t i = 0;
    while (i < reversed.size()) {
        //the next character should be a letter
        char c = reversed[i];
        i++;

        //next part is a number (count). We might have multiple digits.
        string countStr;
        while (i < reversed.size() && isdigit(reversed[i])) {
            countStr.push_back(reversed[i]);
            i++;
        }
        //convert the digit string to an integer
        int count = stoi(countStr);

        //append 'c' repeated 'count' times
        decoded.append(count, c);
    }

    cout << "Decrypted: " << decoded << endl;
}

int main()
{
    string s1 = "ostad";
    string s2; //will hold the encrypted form

    //encrypt s1 into s2
    encrypt(s1, s2);

    cout << "Original:  " << s1 << endl;
    cout << "Encrypted: " << s2 << endl;

    //decrypt s2 and print the result
    decrypt(s2);

    return 0;
}