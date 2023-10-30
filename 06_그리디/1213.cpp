//그리디알고리즘 필수1: 1213 팰린드롬 만들기
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  
    string name;
    cin >> name;
    
    vector<int> alphabet_count(26, 0);
    
    for (char c : name) {
        alphabet_count[c - 'A']++;
    }
    
    int odd_count = 0;
    char odd_char = '\0';
    string first_half = "";
  
    for (int i = 0; i < 26; i++) 
    {
        if (alphabet_count[i] % 2 == 1) 
        {
            odd_count++;
            odd_char = 'A' + i;
        }
        for (int j = 0; j < alphabet_count[i] / 2; j++){
            first_half += ('A' + i);
        }
    }
    
    if (odd_count > 1) 
    {
        cout << "I'm Sorry Hansoo" << "\n";
    }
    else 
    {
        string second_half = first_half;
        reverse(second_half.begin(), second_half.end());
        
      if (odd_count == 1) {
            cout << first_half + odd_char + second_half << "\n";
        } 
      else {
            cout << first_half + second_half << "\n";
        }
    }
    
    return 0;
}
