#include <vector>
#include<iostream>
#include<iomanip>
#include <chrono>
#include"fill.h"
#include"print.h"
#include"gauss_func.h"

// I have spent quite a while figuring out the compilation, so here it is:
// g++ main.cpp print.cpp gauss_func.cpp fill.cpp  -o a.new -O2  -I ~/CLionProjects/gauss/include
// /usr/local/Cellar/openblas/0.3.18/lib/libopenblas.a
// /usr/local/Cellar/gcc/11.2.0_3/lib/gcc/11/libgfortran.a
// -lblas -llapack -larmadillo

#include <armadillo>

using namespace std;
using namespace arma;

int main()
{
    int m = 10000, n = 10000;
    vector<double> A(n * m, 0.0);   //this is our matrix
    vector<double> CONST(n , 0.0);     //this is the right (const) part

    fill_prosto(CONST);
    fill_triangle(A, n);     //you can check available functions for filling in the header "fill.h"
    //print_matr(A, m);         //you might want to check
    //rint_prosto(CONST);

    vector<double> NEW(n * (m+1), 0);
    NEW = soedenit(A, CONST, n);

    //print_matr(NEW, m+1);     //you might want to check

    std::chrono::time_point<std::chrono::system_clock> tic, tac, tim, tok;
    tic = std :: chrono :: system_clock :: now();   //this function will help us calculate the time
    NEW = gauss(NEW, n, (m+1));
    tac = std :: chrono :: system_clock :: now();

    mat A1(A.data(), n, m);
    mat A2 = A1.t();
    vec CONST2(CONST.data(), n);
    tim = std :: chrono :: system_clock :: now();
    vec NEW2 = solve(A2, CONST2);
    tok = std :: chrono :: system_clock :: now();


    std:: chrono :: duration<double> calculation_G = tac - tic;
    std:: chrono :: duration<double> calculation_A = tok - tim;
    cout << "\nTHIS PROGRAM WAS DONE IN\n " << calculation_G.count() << " sec using Gaussian method\n";
    cout << calculation_A.count() << "sec using Armadillo lib\n";

    //NEW2.print();
    //print_matr(NEW, 1);    //you might want to check
    
    vec newvec(NEW.data(), n);
    vec endmatr = newvec - NEW2;
    double max_val = endmatr.max();
    double min_val = endmatr.min();
    std :: cout << "the maximum value between two matrixes: " << setprecision(16) << scientific << max(fabs(max_val), fabs(min_val)) << endl;
}
