/*Task: Given two assembly lines, each with n stations, along with the processing time at each
 * station, the entry time for each line, and the exit time for each line. You are also given the
 * transfer times between stations on opposite lines. Find the minimum time to manufacture a
 * chassis.*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// TC: O(n) where n is the number of stations
// SC: O(n) for the DP arrays
int assemblyLineScheduling(vector<int>& a1, vector<int>& a2, vector<int>& t1, vector<int>& t2,
                           int e1, int e2, int x1, int x2)
{
    int n = a1.size();

    // dp1[i] = minimum time to reach station i on line 1
    // dp2[i] = minimum time to reach station i on line 2
    vector<int> dp1(n), dp2(n);

    // Base case: first station
    dp1[0] = e1 + a1[0];
    dp2[0] = e2 + a2[0];

    // Fill the DP arrays
    for (int i = 1; i < n; i++)
    {
        // Minimum time to reach station i on line 1
        // Either from previous station on line 1 or transfer from line 2
        dp1[i] = min(dp1[i - 1] + a1[i], dp2[i - 1] + t2[i - 1] + a1[i]);

        // Minimum time to reach station i on line 2
        // Either from previous station on line 2 or transfer from line 1
        dp2[i] = min(dp2[i - 1] + a2[i], dp1[i - 1] + t1[i - 1] + a2[i]);
    }

    // Return minimum of exiting from either line
    return min(dp1[n - 1] + x1, dp2[n - 1] + x2);
}

// Space Optimized Version
// TC: O(n)
// SC: O(1) - constant space
int assemblyLineSchedulingOptimized(vector<int>& a1, vector<int>& a2, vector<int>& t1,
                                    vector<int>& t2, int e1, int e2, int x1, int x2)
{
    int n = a1.size();

    // Current minimum times for both lines
    int time1 = e1 + a1[0];
    int time2 = e2 + a2[0];

    for (int i = 1; i < n; i++)
    {
        int newTime1 = min(time1 + a1[i], time2 + t2[i - 1] + a1[i]);
        int newTime2 = min(time2 + a2[i], time1 + t1[i - 1] + a2[i]);

        time1 = newTime1;
        time2 = newTime2;
    }

    return min(time1 + x1, time2 + x2);
}

int main()
{
    int n;
    cout << "Enter number of stations: ";
    cin >> n;

    vector<int> a1(n), a2(n);
    vector<int> t1(n - 1), t2(n - 1);

    cout << "Enter processing times for line 1: ";
    for (int i = 0; i < n; i++) cin >> a1[i];

    cout << "Enter processing times for line 2: ";
    for (int i = 0; i < n; i++) cin >> a2[i];

    cout << "Enter transfer times from line 1 to line 2: ";
    for (int i = 0; i < n - 1; i++) cin >> t1[i];

    cout << "Enter transfer times from line 2 to line 1: ";
    for (int i = 0; i < n - 1; i++) cin >> t2[i];

    int e1, e2, x1, x2;
    cout << "Enter entry time for line 1: ";
    cin >> e1;
    cout << "Enter entry time for line 2: ";
    cin >> e2;
    cout << "Enter exit time for line 1: ";
    cin >> x1;
    cout << "Enter exit time for line 2: ";
    cin >> x2;

    int minTime = assemblyLineSchedulingOptimized(a1, a2, t1, t2, e1, e2, x1, x2);
    cout << "Minimum time to manufacture: " << minTime << endl;

    return 0;
}
