//
//  Prob49_prime_permutations.hpp
//  ProjectEuler
//
//  Created by Min Zhang on 2020/4/3.
//  Copyright © 2020 Min Zhang. All rights reserved.
//

#ifndef Prob49_prime_permutations_hpp
#define Prob49_prime_permutations_hpp

#include <stdio.h>

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <chrono>
#include <map>

#include "../numbers.hpp"
#include "../benchmark.hpp"
#include "../solutions.hpp"
#include "Prob49_prime_permutations.hpp"

struct TupleDistance{
    int distance, indexA, indexB;
    TupleDistance(int dist, int a, int b)
    :distance(dist), indexA(a), indexB(b){};
    
    std::string to_str(){
        std::string output = " dist: " + std::to_string(distance) +\
        " a_index: " + std::to_string(indexA) +\
        " b_index: " + std::to_string(indexB);
        return output;
    }
};

std::vector<TupleDistance> FindAllDistancesBetweenTuples(const std::vector<int> values);

std::vector<int> FourDigitIncreaseSequence();

std::map<int,int> GenerateCounterMap(std::vector<TupleDistance> tuples);

std::vector<TupleDistance> GetTripleWithEqualDistance(int n, std::map<int,int> counter_map, std::vector<TupleDistance> tuples);

#endif /* Prob49_prime_permutations_hpp */
