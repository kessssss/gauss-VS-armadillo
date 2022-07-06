#include <vector>
#include <cstdlib>
using namespace std;


vector<double> soedenit(vector<double> &M, vector<double> &N, size_t str)
{
    size_t clmn = M.size() / str;

    vector<double> NEW(str * (clmn + 1), 0);
    for(int i1 = 0; i1 < str; i1++){
        for(int j1 = 0; j1 <= clmn; j1++){
            if(j1 == clmn){
                NEW[i1 * (clmn+1) + j1] = N[i1];
            }
            else{
                NEW[i1 * (clmn+1) + j1] = M[clmn * i1 + j1];
            }
        }
    }
    return NEW;
}


void swap(vector<double> &M, int maxstr, size_t clmn, int str_to)
{
    for(int j = 0; j < clmn; j++){
        swap(M[str_to * clmn + j], M[maxstr * clmn + j]);
    }
}


int find_max(vector<double> &M, size_t str, int clmn_now)
{
    size_t clm = M.size() / str;
    int num_max = clmn_now;
    double maxi = M[clmn_now * clm + clmn_now];
    for(int i = clmn_now; i < str; i++){
        if(fabs(M[i * clm + clmn_now]) > fabs(maxi)){
            maxi = M[i * clm + clmn_now];
            num_max = i;
        }
    }
    return num_max;
}


void devide(vector<double> &M, size_t clmn, int str_now)
{
    double del = M[str_now * clmn + str_now];
    if(del != 0){
        for(int f = 0; f < clmn; f++){
            M[str_now * clmn + f] = M[str_now * clmn + f] / del;
        }
    }
}


void get_zero(vector<double> &M, size_t clmn, int str_now)
{
    size_t str = M.size() / clmn;
    double dev = M[str_now * clmn + str_now];
    for(int t = 0; t < str; t++){
        if((t != str_now) and (M[t * clmn + str_now] != 0)){
            double mnozh = M[t * clmn + str_now] / dev;
            for (int i = 0; i < clmn; i++){
                M[t * clmn + i] = M[t * clmn + i] - mnozh * M[str_now * clmn + i];
            }
        }
    }

}


vector<double> gauss(vector<double> &M, size_t str, size_t clm)
{
    int max_str = 0;
    vector<double> M1( str * 1, 0);
    for(int j = 0; j < (clm-1); j++){
        max_str = find_max(M, str, j);
        swap(M, max_str, clm, j);
        devide(M, clm, j);
        get_zero(M, clm, j);
    }
    for(int i = 0; i < str; i++){
        M1[i] = M[clm * i + (clm-1)];
    }
    return M1;
}
