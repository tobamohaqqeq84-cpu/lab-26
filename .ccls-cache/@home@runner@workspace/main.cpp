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
void print_average(const long long accum[NUM_OPS][NUM_STRUCTS]);
long long time_read_vector(const vector<string>& base);
long long time_read_list(const vector<string>& base);
long long time_read_set(const vector<string>& base);
long long time_sort_vector(const vector<string>&base);
long long time_sort_list(const vector<string>& base);
long long time_insert_vector(vector<string>& v, int k);
long long time_insert_list (list<string>& lst, int k);
long long time_insert_set(set<string>& st, int k);
long long time_delete_list(list<string>& lst , int k);
long long time_delete_vector(vector<string>& v, int k);
long long time_delete_set(set<string>& st, int k);

//-------int mait  function---------

int main(){
    vector<string> baseData;
    if(!load_names_file("name.txt", baseData)){
        cout <<"Error loading file"<<endl;
        return 1;
    }
    long long times[2][NUM_OPS][NUM_STRUCTS] ={};
    for (int run = 1; run <= NUM_RUNS;++run){
        run_one_race(baseData, times[0]);
        for (int op = 0; op < NUM_OPS; ++op)
        for (int ds = 0; ds < NUM_STRUCTS; ++ds);
        times[1][op][ds] += times[0][op][ds];
    }

cout << "Number of simulations: "<< NUM_RUNS << endl;
    print_average(times[1]);
    return 0;
    
}

bool load_names_file(const string& filename, vector<string>& out){
    ifstream fin(filename);
    if(!fin) return false;
    string s; out.clear();
    while (fin >> s) out.push_back(s);
    return true;
}
void run_one_race(const vector<string>& baseData, long long runSlice[NUM_OPS][NUM_STRUCTS]){
    runSlice[READ_OP][VEC] = time_read_vector(baseData);
    runSlice[READ_OP][LIST_DS] = time_read_list(baseData);
    runSlice[READ_OP][SET_DS] = time_read_set(baseData);
    runSlice[SORT_OP][VEC] = time_sort_vector(baseData);
    runSlice[SORT_OP][LIST_DS] = time_sort_list(baseData);
    runSlice[SORT_OP][SET_DS] = 0;

vector<string> v(baseData);
    list<string> lst(baseData.begin(), baseData.end());
    set<string> st(baseData.begin(), baseData.end());

    runSlice[INSERT_OP][VEC] = time_insert_vector(v, K_INSERT);
    runSlice[INSERT_OP][LIST_DS] = time_insert_list(lst, K_INSERT);
    runSlice[INSERT_OP][SET_DS] = time_insert_set(st, K_INSERT);
    runSlice[DELEE_OP][VEC] = time_delete_vector(v, K_DELETE);
    runSlice[DELEE_OP][LIST_DS] = time_delete_list(lst, K_DELETE);
    runSlice[DELEE_OP][SET_DS] = time_delete_set(st, K_DELETE);
}




