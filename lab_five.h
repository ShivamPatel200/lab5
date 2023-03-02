#include <vector>
using namespace std;

#ifndef LAB_FIVE
#define LAB_FIVE

struct double_vector {
    double id;
    double from;
    double to;
    double_vector(const double_vector & i_v) : id(i_v.id), from(i_v.from), to(i_v.to) {}; 
    double_vector() : id(-1), from(0), to(0) {};
};

struct pairs {
    double from;
    double to;
    double dist;
};

vector <double_vector> read_file(string file1);

double dot_prod(double_vector v1, double_vector v2);

double vector_len(double_vector v1);

double cosine_dist(double_vector v1, double_vector v2);

vector <pairs> calculate_cosine_pairs(vector <double_vector> my_vector);

bool compare(pairs p1, pairs p2);

#endif