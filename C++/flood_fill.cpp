#include <iostream>
#include <vector>
using namespace std;

void floodFillHelper(vector<vector<int>>& image, int r, int c, int originalColor, int newColor) {
    int rows = image.size();
    int cols = image[0].size();

    // Base cases: out of bounds or pixel does not match the original color
    if (r < 0 || r >= rows || c < 0 || c >= cols || image[r][c] != originalColor) {
        return;
    }

    // Update the current pixel's color
    image[r][c] = newColor;

    // Recursively fill in all 4 adjacent directions (Down, Up, Right, Left)
    floodFillHelper(image, r + 1, c, originalColor, newColor);
    floodFillHelper(image, r - 1, c, originalColor, newColor);
    floodFillHelper(image, r, c + 1, originalColor, newColor);
    floodFillHelper(image, r, c - 1, originalColor, newColor);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int originalColor = image[sr][sc];

    // Only run recursion if the new color is different to avoid infinite loops
    if (originalColor != newColor) {
        floodFillHelper(image, sr, sc, originalColor, newColor);
    }

    return image;
}

int main() {
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    int startRow = 1, startCol = 1, newColor = 2;

    vector<vector<int>> result = floodFill(image, startRow, startCol, newColor);

    cout << "Updated Grid after Flood Fill:\n";
    for (const auto& row : result) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << "\n";
    }

    return 0;
}
