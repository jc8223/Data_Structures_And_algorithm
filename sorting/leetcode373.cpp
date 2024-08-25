#include <iostream>
#include <vector>
#include <algorithm>

// Custom comparator function
bool rowSumComparator(const std::vector<int>& row1, const std::vector<int>& row2) {
    int sum1 = 0;
    int sum2 = 0;

    // Calculate the sum of elements in each row
    for (int num : row1) {
        sum1 += num;
    }
    for (int num : row2) {
        sum2 += num;
    }

    // Compare the sums
    return sum1 < sum2;
}

int main() {
    // Create a 2D vector
    std::vector<std::vector<int>> matrix = {{4, 2, 6},
                                            {1, 5, 3},
                                            {9, 7, 8}};

    // Sort the 2D vector based on the sum of elements in each row
    std::sort(matrix.begin(), matrix.end(), rowSumComparator);

    // Print the sorted matrix
    for (const auto& row : matrix) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
