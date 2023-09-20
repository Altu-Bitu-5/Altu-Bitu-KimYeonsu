//05_우선순위큐_필수문제2_2607:비슷한 단어
#include <iostream>
#include <string>

using namespace std;

bool isSimilar(int* a, int* b)
{
    int k = 0, first = -1;
    for (int i = 0; i < 26; ++i) 
    {
        if (a[i] != b[i]) 
        {
            if (first == -1){
                first = i;
            }    
            if (a[i] - b[i] > 1 || a[i] - b[i] < -1){
                return false;
            }    
            else 
            {
                ++k;
                if (k == 2){
                    if ((a[first] + a[i]) != (b[first] + b[i])){
                        return false;
                    } 
                } 
                    
                if (k >= 3){
                    return false;
                } 
                
            }
        }
    }
    return true;
}

int main() 
{
    int n;
    cin >> n;

    string firstWord;
    cin >> firstWord;

    int count1[26] = {0}; // 첫 번째 단어의 알파벳 개수 배열
    for (char ch : firstWord) {
        count1[ch - 'A']++;
    }

    int similarCount = 0;

    for (int i = 1; i < n; i++) 
    {
        string word;
        cin >> word;

        int count2[26] = {0}; // 현재 단어의 알파벳 개수 배열
        for (char ch : word) {
            count2[ch - 'A']++;
        }

        if (isSimilar(count1, count2)) {
            similarCount++;
        }
    }

    cout << similarCount << endl;

    return 0;
}
