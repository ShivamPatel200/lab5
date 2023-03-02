#include <iostream>
#include <vector>
#include <algorithm>
#include "lab_five.h"
using namespace std;


int main() {
    vector <double_vector> my_vector = read_file("double_vectors1.txt");
    vector <pairs> my_pairs = calculate_cosine_pairs(my_vector);
    sort(my_pairs.begin(), my_pairs.end(), compare);

    for (auto i : my_pairs) {
        cout << "(" << i.from << ", " << i.to << ")= " << i.dist <<endl;
    }

}