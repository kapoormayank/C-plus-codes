// LeetCode Problem 2037: Minimum Number of Moves to Seat Everyone
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Function to calculate the minimum number of moves to seat everyone
int minMovesToSeat(vector<int>& seats, vector<int>& students) {
    // Sort both the seats and students arrays
    sort(seats.begin(), seats.end());
    sort(students.begin(), students.end());

    int moves = 0;
    // Calculate the total moves required
    for (size_t i = 0; i < seats.size(); ++i) {
        moves += abs(seats[i] - students[i]);
    }
    return moves;
}

// Main function
int main() {
    int n;
    cout << "Enter the number of seats and students: ";
    cin >> n;
    vector<int> seats(n), students(n);
    cout << "Enter the positions of the seats: ";
    for (int i = 0; i < n; ++i) {
        cin >> seats[i];
    }
    cout << "Enter the positions of the students: ";
    for (int i = 0; i < n; ++i) {
        cin >> students[i];
    }
    int result = minMovesToSeat(seats, students);
    cout << "Minimum number of moves to seat everyone: " << result << endl;
    return 0;
}


