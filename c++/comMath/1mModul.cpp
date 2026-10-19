#include <stdio.h>
#include <vector>
#include <cmath>
#include "1mModul.h"

using namespace std;


void fillMatrix(vector<vector<double>> & matrix){
    matrix = {
        {-7.45, 0.52, 4.61, 2.11, -9.67, 0.44},
        {3.8 , 0.67, -2.17, -4.31, -0.72, -9.54},
        {2.7, 8.82, 4.7, -9.1, -2.23, -8.89},
        {7.97, -7.44, 7.77, 9.12, -7.19, 5.69},
        {-1.08, 3.29, 4.08, -8.68, 9.43, -1.09}
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