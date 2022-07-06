#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void print_matr(const vector<double> &M, size_t column)
{
    cout << "\nmatrix\n";
    for(size_t i = 0; i < M.size(); ){
        cout << "| ";
        for(size_t j = 0; j < column; j++) {
            printf("%5.2f", M[i]);
            i++;
        }
        cout << " |\n";
    }
}


void print_prosto(const vector<double> &M1){
    int s = M1.size();
    printf("\nan additional matrix\n");
    for(int i = 0; i < s; i++){
        printf("| %.3f |\n", M1[i]);
    }
}
