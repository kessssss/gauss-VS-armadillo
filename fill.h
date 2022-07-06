#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

#ifndef UNTITLED_FILL_H
#define UNTITLED_FILL_H

void fill_gilbert(vector<double> &M, size_t str);       //this function makes Gilbert's matrix
void fill_prosto(vector<double> &M1);                   //this function fills the right part of matrix with numbers i = [1;n]
void fill_one(vector<double> &M, size_t str);           //this function fills matrix's diagonal with '1'
void fill_triangle(vector<double> &M, size_t str);      //this function fills the upper right part of the matrix with '1'

#endif
