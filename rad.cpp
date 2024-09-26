#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

bool isValidIP(const string& ip) {
    vector<string> parts;
    stringstream ss(ip);
    string part;
    while (getline(ss, part, '.')) {
        parts.push_back(part);
    }
    if (parts.size() != 4) return false;
    for (const auto& segment : parts) {
        if (segment.empty() || (segment.size() > 1 && segment[0] == '0')) return false;
        for (char c : segment) {
            if (!isdigit(c)) return false;
        }
        int num = stoi(segment);
        if (num < 0 || num > 255) return false;
    }
    return true;
}

void sortSurnames(vector<string>& surnames) {
    sort(surnames.rbegin(), surnames.rend());
}

void replaceSpacesWithTabs(string& str) {
    for (char& c : str) {
        if (c == ' ') c = '\t';
    }
}

void countCharacters(const string& str, int& letters, int& digits, int& others) {
    letters = digits = others = 0;
    for (char c : str) {
        if (isalpha(c)) ++letters;
        else if (isdigit(c)) ++digits;
        else ++others;
    }
}

int countWords(const string& str) {
    stringstream ss(str);
    string word;
    int count = 0;
    while (ss >> word) ++count;
    return count;
}

bool isPalindrome(const string& str) {
    string cleanStr;
    for (char c : str) {
        if (isalnum(c)) cleanStr += tolower(c);
    }
    string revStr = cleanStr;
    reverse(revStr.begin(), revStr.end());
    return cleanStr == revStr;
}

string nextUkrainianLetter(char letter) {
    string alphabet = "АБВГҐДЕЄЖЗИІЇЙКЛМНОПРСТУФХЦЧШЩЬЮЯ";
    size_t pos = alphabet.find(letter);
    if (pos == string::npos || pos == alphabet.size() - 1)
        return "Далі букв немає";
    return string(1, alphabet[pos + 1]);
}

int main() {
    string ip;
    cout << "Enter IP address: ";
    cin >> ip;
    cout << (isValidIP(ip) ? "Valid IP address.\n" : "Invalid IP address.\n");

    vector<string> surnames(5);
    cout << "Enter 5 student surnames:\n";
    for (int i = 0; i < 5; ++i) {
        cout << "Surname " << i + 1 << ": ";
        cin >> surnames[i];
    }
    sortSurnames(surnames);
    cout << "Sorted surnames:\n";
    for (const auto& surname : surnames) {
        cout << surname << endl;
    }

    cin.ignore();
    string sentence;
    cout << "Enter a string with spaces: ";
    getline(cin, sentence);
    replaceSpacesWithTabs(sentence);
    cout << "String with tabs: " << sentence << endl;

    int letters, digits, others;
    cout << "Enter a string to count characters: ";
    getline(cin, sentence);
    countCharacters(sentence, letters, digits, others);
    cout << "Letters: " << letters << ", Digits: " << digits << ", Others: " << others << endl;

    cout << "Enter a sentence: ";
    getline(cin, sentence);
    cout << "Number of words: " << countWords(sentence) << endl;

    cout << "Enter a string to check for palindrome: ";
    getline(cin, sentence);
    cout << (isPalindrome(sentence) ? "Palindrome.\n" : "Not a palindrome.\n");

    char letter;
    cout << "Enter a Ukrainian letter (UPPER CASE): ";
    cin >> letter;
    cout << "Next letter: " << nextUkrainianLetter(letter) << endl;

    return 0;
}
