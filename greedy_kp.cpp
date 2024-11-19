#include <iostream>
#include <algorithm>
using namespace std;

double fractionalKnapsack(int W, int values[], int weights[], int n) {
    double ratio[n];
    int indices[n];

    
    for (int i = 0; i < n; ++i) {
        ratio[i] = (double)values[i] / weights[i];
        indices[i] = i;
    }

    
    for (int i = 0; i < n - 1; ++i) {
        int maxIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (ratio[indices[j]] > ratio[indices[maxIndex]]) {
                maxIndex = j;
            }
        }
        // Swap to sort by ratio
        swap(indices[i], indices[maxIndex]);
    }

    double totalValue = 0.0;
    int currentWeight = 0;

    // Iterate over the sorted items
    for (int i = 0; i < n; ++i) {
        int index = indices[i];
        if (currentWeight + weights[index] <= W) {
            // Take the full item
            currentWeight += weights[index];
            totalValue += values[index];
        } else {
            // Take the fractional part of the item
            int remainingWeight = W - currentWeight;
            totalValue += values[index] * ((double)remainingWeight / weights[index]);
            break;  // The knapsack is full
        }
    }

    return totalValue;
}

int main() {
    int W, n;

    // Get maximum weight capacity
    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> W;

    // Get number of items
    cout << "Enter the number of items: ";
    cin >> n;

    int values[n], weights[n];

    // Get the values and weights of each item
    cout << "Enter the values and weights of the items:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Item " << i + 1 << " - Value: ";
        cin >> values[i];
        cout << "Item " << i + 1 << " - Weight: ";
        cin >> weights[i];
    }

    // Call the knapsack function and display the result
    double maxValue = fractionalKnapsack(W, values, weights, n);
    cout << "Maximum value in knapsack = " << maxValue << endl;

    return 0;
}
