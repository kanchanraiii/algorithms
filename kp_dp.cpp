#include <iostream>
#include <algorithm>
using namespace std;

int knapsack(int W, int weights[], int values[], int n, int selectedItems[]) {
    int dp[W + 1] = {0};  // Array to store the maximum value for each weight capacity (0 to W)

    // Fill the dp array using the bottom-up approach
    for (int i = 0; i < n; i++) {
        for (int w = W; w >= weights[i]; w--) {
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }

    // Backtrack to find the selected items
    int w = W;
    int idx = 0;

    // Initialize selectedItems with -1 to indicate unselected items
    fill(selectedItems, selectedItems + n, -1);

    for (int i = n - 1; i >= 0; i--) {
        // If the item was included in the optimal solution
        if (dp[w] != dp[w - weights[i]] + values[i]) {
            continue;
        } else {
            selectedItems[idx++] = i;  // Store the index of the item
            w -= weights[i];  // Reduce the weight
        }
    }

    return dp[W];  // Return the maximum value
}

int main() {
    int n, W;

    // Take number of items and knapsack capacity as input
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter knapsack capacity: ";
    cin >> W;

    int weights[n], values[n];

    // Input the weights and values of the items
    cout << "Enter weights of the items:\n";
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    cout << "Enter values of the items:\n";
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    int selectedItems[n];  // Array to store the indices of the selected items
    int maxValue = knapsack(W, weights, values, n, selectedItems);

    cout << "Maximum value that can be obtained: " << maxValue << endl;
    cout << "Items selected (0-based index): ";
    
    // Display the selected items
    for (int i = 0; i < n; i++) {
        if (selectedItems[i] != -1) {  // Only print valid indices
            cout << selectedItems[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
