#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
#include "lab_five.h"
using namespace std;

vector <double_vector> read_file(string file1) {
    vector <double_vector> vector_collection;
    ifstream input_file(file1);
    if (input_file.is_open()) {
        int id_temp = 0;
        double from_temp;
        double to_temp;
        while(input_file >> from_temp >> to_temp) {
            double_vector temp_vector;
            temp_vector.id = id_temp;
            temp_vector.from = from_temp;
            temp_vector.to = to_temp;
            vector_collection.push_back(temp_vector);
            id_temp++;
        }
    }
    return vector_collection;
}

double dot_prod(double_vector v1, double_vector v2) {
    return (v1.from * v2.from) + (v1.to * v2.to);
}

double vector_len(double_vector v1) {
    return sqrt(dot_prod(v1, v1));
}

double cosine_dist(double_vector v1, double_vector v2) {
    double dot = dot_prod(v1, v2);
    double chicago = vector_len(v1) * vector_len(v2);
    return dot / chicago;
}

vector <pairs> calculate_cosine_pairs(vector <double_vector> my_vector){
    vector <pairs> cosine_pairs;
    for (int i = 0; i < my_vector.size()-1; i++) {
        for (int j = i + 1; j < my_vector.size(); j++) {
            struct pairs temp_vector;
            temp_vector.from = my_vector[i].from;
            temp_vector.to = my_vector[i].to;
            temp_vector.dist = cosine_dist(my_vector[i], my_vector[j]);
            cosine_pairs.push_back(temp_vector);
        }
    }
    return cosine_pairs;
}



bool compare(pairs p1, pairs p2) {
    return p1.dist < p2.dist;
}

