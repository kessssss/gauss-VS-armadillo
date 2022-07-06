#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

#ifndef UNTITLED_GAUSS_FUNC_H
#define UNTITLED_GAUSS_FUNC_H

int find_max(vector<double> &M, size_t str, int clmn_now);                    //this function finds the maximum number in the column
vector<double> soedenit(vector<double> &M, vector<double> &N, size_t str);    //this function makes one matrix out of the given matrix and its right (const) part
void swap(vector<double> &M, int max, size_t clmn, int str_to);               //this function swaps the two given rows of the matrix
void devide(vector<double> &M, size_t clmn, int str_now);                     //this function devides the row by its maximum number
void get_zero(vector<double> &M, size_t clmn, int str_now);                   //this function makes all the numbers of column (besides the maximum number) == 0
vector<double> gauss(vector<double> &M, size_t str, size_t clm);              //this function finds the solution using Gauss method

#endif
