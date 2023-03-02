#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "lab_five.h"
#include "doctest.h"
using namespace std;

TEST_CASE("Testing my cosine vectors program") {
    SUBCASE("doubles_vectors.txt"){
        vector <double_vector> my_vector1 = read_file("double_vectors1.txt");
        CHECK(my_vector1.size() == 9);

        //testing the output function

        int test_id[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
        double test_from[] = {0.1, 0.3, 0.500, 0.7, 0.9, 9.9, 99.9, 8.9, 3.14};
        double test_to[] = {0.2, 0.4, 0.6, 0.8, 1.0, 2.3, 45, 22.1, 2.717};

        for(int i = 0; i < my_vector1.size(); i++) {
            CHECK(my_vector1[i].id == test_id[i]);
            CHECK(my_vector1[i].from == test_from[i]);
            CHECK(my_vector1[i].to == test_to[i]);
        }
        

        //testing dot prod

        double_vector v1;
        v1.from = 0.0;
        v1.to = 0.0;
        double_vector v2;
        v2.from = 1.0;
        v2.to = 1.0;
        CHECK(dot_prod(v1, v2) == 0.0);

        double_vector c1;
        c1.from = -1.0;
        c1.to = -2.0;
        double_vector c2;
        c2.from = 3.0;
        c2.to = 4.0;
        CHECK(dot_prod(c1, c2) == -11.0);

        // test vector len

        CHECK(vector_len(v1) == doctest::Approx(0));
        CHECK(vector_len(v2) == doctest::Approx(1.41421));

        // unit test vector len

        CHECK(vector_len(v1) == doctest::Approx(0.0));
        CHECK(vector_len(v2) == doctest::Approx(sqrt(2.0)));

        CHECK(cosine_dist(c1, c2) == doctest::Approx(-0.98387));

        vector <pairs> my_pairs = calculate_cosine_pairs(my_vector1);

        sort(my_pairs.begin(), my_pairs.end(), compare);

        for (int i = 0; i < my_pairs.size()-1; i++){
            CHECK(my_pairs[i].dist <= my_pairs[i+1].dist);
        }
}

}


