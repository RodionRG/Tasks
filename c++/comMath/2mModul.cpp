#include <stdio.h>
#include <vector>
#include <cmath>
#include "1mModul.h"

using namespace std;


void fillMatrix(vector<vector<double>> & matrix){
    matrix = {
        {2, 2, 5, 1, 8, 18},
        {1, 1, 9, 5, 4, 20},
        {7, 3, 8, 7, 8, 33},
        {3, 4, 8, 6, 7, 28},
        {5, 8, 1, 5, 8, 27}
    };
}

void printm(vector<vector<double>> matrix){
    for (unsigned int i = 0; i < matrix.size(); i++) {
        printf("|");
        for (unsigned int j = 0; j <= matrix.size(); j++) {
            printf("%.3f ", matrix[i][j]);
        }
        printf("|");
        puts("");
    }
}