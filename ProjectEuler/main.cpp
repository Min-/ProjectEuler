//
//  main.cpp
//  ProjectEuler
//
//  Created by Min Zhang on 2020/4/2.
//  Copyright © 2020 Min Zhang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <chrono>

#include "numbers.hpp"
#include "benchmark.hpp"
#include "solutions.hpp"

//FindAllDistancesBetweenTuples Also keep the index
struct TupleDistance{
    int distance, indexA, indexB;
    TupleDistance(int dist, int a, int b)
    :distance(dist), indexA(a), indexB(b){};
};

std::vector<TupleDistance> FindAllDistancesBetweenTuples(const std::vector<int> values){
    std::vector<TupleDistance> res;
    for (int indexa = 0; indexa < values.size(); indexa++){
        for (int indexb = 0; indexb > indexa && indexb < values.size(); indexb++){
            res.emplace_back(TupleDistance(values[indexb] - values[indexb], indexa, indexb));
        }
    }
    return res;
}



int main() {
    Timer timer;
    //std::vector<std::string> res = CircularListPermutation("viola");
    //for (std::string v: res){
    //    std::cout << v << std::endl;
    //}
    std::vector<int> res;
    res = FindCircularPrimes(1000);
    //for (int n: res){
    //    std::cout << n << std::endl;
    //}
    std::cout << res.size() << std::endl;
    return 0;
}
