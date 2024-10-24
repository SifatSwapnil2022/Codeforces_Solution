#include<bits/stdc++.h>
using namespace std;

int main() {
    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        int target_number;
        cin >> target_number;

        int currentPosition = 0;
        int movingNumber = 1;
        bool winnerFound = false;

        while (!winnerFound) {
            int moveCount = 2 * movingNumber - 1;

            if (movingNumber % 2 == 1) { // Odd
                currentPosition -= moveCount;
            } else { // Even
                currentPosition += moveCount;
            }

            if (abs(currentPosition) > target_number) {
                if (movingNumber % 2 == 1) { // Odd, Sakurako's turn
                    cout << "Sakurako" << endl;
                } else { // Even, Kosuke's turn
                    cout << "Kosuke" << endl;
                }
                winnerFound = true; // Stop searching for a winner
            }
            movingNumber++;
        }
    }

    return 0;
}
