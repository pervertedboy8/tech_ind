#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> st;
    int removed = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (!st.empty() && st.back().first == x) {
            st.back().second++;
        } else {
            if (!st.empty() && st.back().second >= 2) {
                removed += st.back().second;
                st.pop_back();
            }
            if (!st.empty() && st.back().first == x) {
                st.back().second++;
            } else {
                st.push_back({x, 1});
            }
        }
    }
    if (!st.empty() && st.back().second >= 2) {
        removed += st.back().second;
    }
    cout << removed << endl;
    return 0;
}
