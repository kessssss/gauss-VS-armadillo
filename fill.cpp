#include <vector>
#include <cstdlib>
using namespace std;

void fill_one(vector<double> &M, size_t str)
{
    size_t clm = M.size() / str;
    for(size_t i = 0; i < str; i++) {
        for (size_t j = 0; j < clm; j++) {
            M[str * i + i] = 1;
        }
    }
}


void fill_triangle(vector<double> &M, size_t str)
{
    size_t clmn = M.size() / str;
    for(int i = 0; i < str; i++){
        for(int j = i; j < clmn; j++){
            M[i * clmn + j] = 1.0;
        }
    }
}


void fill_gilbert(vector<double> &M, size_t str)
{
    size_t clmn = M.size() / str;
    for(int i = 0; i < str; i++){
        for(int j = 0; j < clmn; j++){
            M[i * clmn + j] = 1.0 / (i + j + 1);
        }
    }
}


void fill_prosto(vector<double> &M1)
{
    int s = M1.size();
    for(int i = 1; i <= s; i++){
        M1[i-1] = i + i/10.0;
    }
}

