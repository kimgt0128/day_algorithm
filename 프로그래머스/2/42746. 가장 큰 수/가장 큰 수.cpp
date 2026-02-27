#include<bits/stdc++.h>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> nums;
    nums.resize(numbers.size());
    
    for(int i = 0; i < numbers.size(); i++) {
        nums[i] = to_string(numbers[i]);
    }
    
    sort(nums.begin(), nums.end(), [](string& a, string& b) {
        return a + b > b + a;
    });
    
    for(string n : nums) answer += n;
    
    if(nums[0] == "0") return "0";
    return answer;
}