#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
bool isValidBinaryString(const string &s) {
    for (char c : s) {
        if (c != '0' && c != '1') {
            return false;
        }
    }
    return true;
}
int calculateCost(const string &s, int A, int B) {
    int count_01 = 0, count_10 = 0;
    for (size_t i = 1; i < s.length(); ++i) {  
        if (s[i-1] == '0' && s[i] == '1') count_01++;
        if (s[i-1] == '1' && s[i] == '0') count_10++;
    }
    return count_01 * A + count_10 * B;
}
int calculateHammingDistance(const string &original, const string &rearranged) {
    int hamming_distance = 0;
    for (size_t i = 0; i < original.length(); ++i) {  
        if (original[i] != rearranged[i]) {
            hamming_distance++;
        }
    }
    return hamming_distance;
}
string rearrangeToMinimizeCost(const string &s, int A, int B) {
    int count_0 = count(s.begin(), s.end(), '0');
    int count_1 = s.length() - count_0;  
    
    string rearranged;
    if (A > B) {
        rearranged = string(count_1, '1') + string(count_0, '0');
    } else {
        rearranged = string(count_0, '0') + string(count_1, '1');
    }
       return rearranged;
}
int main() {
    int T;
    cin >> T;   
    while (T--) {
        string s;
        cin >> s;
        if (!isValidBinaryString(s)) {
            cout << "INVALID" << endl;
            continue;
        }
        int A, B;
        cin >> A >> B;  
        int original_cost = calculateCost(s, A, B);
        string rearranged = rearrangeToMinimizeCost(s, A, B);
        int hamming_distance = calculateHammingDistance(s, rearranged); 
        cout << hamming_distance << endl;
    }
   return 0;
}