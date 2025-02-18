#include <iostream>
#include <vector>

using namespace std;

vector<int> beautifulArray(int n) {
    vector<int> result = {1};  // Base case
    while (result.size() < n) {
        vector<int> temp;
        for (int num : result) {
            if (num * 2 - 1 <= n) 
                temp.push_back(num * 2 - 1); // Odd numbers
        }
        for (int num : result) {
            if (num * 2 <= n) 
                temp.push_back(num * 2); // Even numbers
        }
        result = temp;
    }
    return result;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> ans = beautifulArray(n);
    cout << "Beautiful Array: ";
    for (int num : ans) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
