#include<iostream>
using namespace std;
int main(){
    int n;
    string word;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> word;
        if(word.size() <= 10){
            cout << word << endl;
            continue;
        }
        string newword;
        newword = word[0] + to_string(word.size() - 2) + word.back();
        cout << newword << endl;
    }
    return 0;
}