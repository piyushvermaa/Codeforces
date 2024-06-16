#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> programmers, testers, skills;
        for (int i = 0; i < n + m + 1; ++i) {
            int a, b;
            cin >> a >> b;
            skills.push_back(a);
            if (a > b) {
                programmers.push_back(i);
            } else {
                testers.push_back(i);
            }
        }

        // Sort programmers in descending order (highest skill first)
        sort(programmers.begin(), programmers.end(), greater<int>());

        // Sort testers in ascending order (lowest skill first)
        sort(testers.begin(), testers.end());

        int programmerCount = 0, testerCount = 0;
        int totalSkill = 0;

        // Calculate team skill without each candidate
        for (int i = 0; i < n + m + 1; ++i) {
            // Skip the current candidate
            if (i == programmers[programmerCount] && programmerCount < n) {
                programmerCount++;
            } else if (i == testers[testerCount] && testerCount < m) {
                testerCount++;
            } else {
                totalSkill += skills[i];
            }
            cout << totalSkill << " ";
        }
        cout << endl;
    }

    return 0;
}
