#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// TC O(k^N)
// SC O(N)

// int solve(int day, const vector<vector<int>> &schedule, int last)
// {
//     if (day == 0)
//     {
//         int maxK = 0;
//         for (int k = 0; k < 3; ++k)
//         {
//             if (k != last)
//                 maxK = max(maxK, schedule[day][k]);
//         }
//         return maxK;
//     }

//     int maxK = -1;
//     for (int k = 0; k < 3; ++k)
//     {
//         if (k != last)
//             maxK = max(maxK,
//                        schedule[day][k] + solve(day - 1, schedule, k));
//     }

//     return maxK;
// }

// TC O(N * 4 * 3)
// SC O(N *4)

int solve(int day, vector<vector<int>> &trainingPoints, const vector<vector<int>> &schedule, int last)
{
    if (day == 0)
    {
        int maxK = 0;
        for (int k = 0; k < 3; ++k)
        {
            if (k != last)
            {
                maxK = max(maxK,
                           schedule[day][k]);
            }
        }
        return maxK;
    }

    if (trainingPoints[day][last] != -1)
    {
        return trainingPoints[day][last];
    }

    int maxK = -1;
    for (int k = 0; k < 3; ++k)
    {
        if (k != last)
            maxK = max(maxK,
                       schedule[day][k] + solve(day - 1, trainingPoints, schedule, k));
    }

    return trainingPoints[day][last] = maxK;
}

// TC O(N*4*3)
// SC O(N*4)

// int solve(const vector<vector<int>>& schedule)
// {
//     vector<vector<int>> trainingPoints(schedule.size(), vector<int>(4, -1));

//     trainingPoints[0][0] = max(schedule[0][1], schedule[0][2]);
//     trainingPoints[0][1] = max(schedule[0][0], schedule[0][2]);
//     trainingPoints[0][2] = max(schedule[0][0], schedule[0][1]);
//     trainingPoints[0][3] = max(schedule[0][0], max(schedule[0][1], schedule[0][2]));

//     for (int day = 1; day < schedule.size(); ++day)
//     {
//         for (int last = 0; last <= 3; ++last)
//         {
//             trainingPoints[day][last] = 0;
//             for (int k = 0; k < 3; ++k)
//             {
//                 if (k != last)
//                 {
//                     trainingPoints[day][last] = max(trainingPoints[day][last],
//                                                     schedule[day][k] + trainingPoints[day - 1][k]);
//                 }
//             }
//         }
//     }
//     return trainingPoints[schedule.size() - 1][3];
// }

// TC O(N * 4 * 3)
// SC O(1)

int solve(const vector<vector<int>> &schedule)
{
    vector<int> trainingPoints(4, -1);

    trainingPoints[0] = max(schedule[0][1], schedule[0][2]);
    trainingPoints[1] = max(schedule[0][0], schedule[0][2]);
    trainingPoints[2] = max(schedule[0][0], schedule[0][1]);
    trainingPoints[3] = max(schedule[0][0], max(schedule[0][1], schedule[0][2]));

    vector<int> tmp(4, -1);
    for (int day = 1; day < schedule.size(); ++day)
    {
        for (int last = 0; last <= 3; ++last)
        {
            tmp[last] = 0;
            for (int k = 0; k < 3; ++k)
            {
                if (k != last)
                {
                    tmp[last] = max(tmp[last],
                                    schedule[day][k] + trainingPoints[k]);
                }
            }
        }
        trainingPoints = tmp;
    }
    return trainingPoints[3];
}

int main()
{   // keep Nx3 size schedule
    // Example 1:
    // Input: matrix = [[10, 40, 70], [20, 50, 80], [30, 60, 90]]
    // Output: 210
    // Explanation:
    // Day 1: fighting practice = 70
    // Day 2: stealth training = 50
    // Day 3: fighting practice = 90
    // Total = 70 + 50 + 90 = 210
    // This gives the optimal points.

    // Example 2:
    // Input: matrix = [[70, 40, 10], [180, 20, 5], [200, 60, 30]]
    // Output: 290
    // Explanation:
    // Day 1: running = 70
    // Day 2: stealth training = 20
    // Day 3: running = 200
    // Total = 70 + 20 + 200 = 290
    // This gives the optimal points.

    // vector<vector<int>> schedule = {{10, 40, 70},
    //                                 {20, 50, 80},
    //                                 {30, 60, 90}};

    vector<vector<int>> schedule = {{70, 40, 10},
                                    {180, 20, 5},
                                    {200, 60, 30}};

    // cout << solve(2, schedule, 404) << endl;

    // vector<vector<int>> trainingPoints(schedule.size(), vector<int>(4, -1));

    // cout << solve(2, trainingPoints, schedule, 3) << endl;

    // cout << solve(schedule) << endl;

    return 0;
}