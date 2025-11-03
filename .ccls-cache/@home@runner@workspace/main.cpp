//Toba Mohaqqeq
//COMSC-210
//lab-26

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <list>
#include <chrono>
#include <random>
#include <numeric>
using namespace std;
using chrono::duration_cast;
using chrono::microseconds;
using chrono::system_clock;

    const int NUM_RUNS = 15;
    const int NUM_OPS = 4;
    const int NUM_STRUCTS =3;
    enum Op {READ_OP,SORT_OP, INSERT_OP, DELEE_OP };
    enum DS {VEC, LIST_DS, SET_DS};
    const int K_INSERT = 2000;
    const int COLW_LABEL = 12;
    const int CLOW_NUM = 11;

//---------function prototypes---------
bool load_names_file(const string& filename, vector<string>& out);
void run_one_race(const vector<string>& baseData, long long runSlice[NUM_OPS][NUM_STRUCTS]);




