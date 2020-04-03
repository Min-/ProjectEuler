//
//  Prob49_prime_permutations.cpp
//  ProjectEuler
//
//  Created by Min Zhang on 2020/4/3.
//  Copyright © 2020 Min Zhang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <chrono>

#include "../numbers.hpp"
#include "../benchmark.hpp"
#include "../solutions.hpp"
#include "Prob49_prime_permutations.hpp"

std::vector<int> PrimePermutation(int p, std::set<int> prime_map);
std::vector<TupleDistance> FindAllDistancesBetweenTuples(const std::vector<int> values);

std::vector<int> FourDigitIncreaseSequence(){
    //FilterFourDigitPrimes
    // loop:
        //EachPermutation
        //FindTripleWithEqualDistance
            //SORT
            //FindAllDistancesBetweenTuples
            //GenerateCounterMap
            //GetTripleWithEqualDistance
    //ReturnTriple
    std::vector<int> output;
    
    std::set<int> prime_set;
    std::vector<int> primes = PrimeRange(1000, 10000);
    //std::vector<int> primes = {1487};
    for (int p: primes){
        prime_set.emplace(p);
    }
    
    for (int p: primes){
        std::map<int,int> dists_map;
        
        
        std::vector<int> p_perms = PrimePermutation(p, prime_set);
        std::sort(p_perms.begin(), p_perms.end(), std::greater<>());
        
        std::vector<TupleDistance> dists = FindAllDistancesBetweenTuples(p_perms);
        dists_map = GenerateCounterMap(dists);
            
        std::vector<TupleDistance> triples = GetTripleWithEqualDistance(3, dists_map, dists);
        if (triples.size() >= 3){
            output.emplace_back(p_perms[triples[0].indexA]);
            output.emplace_back(p_perms[triples[0].indexB]);
            output.emplace_back(p_perms[triples[1].indexA]);
            output.emplace_back(p_perms[triples[1].indexB]);
            output.emplace_back(p_perms[triples[2].indexA]);
            output.emplace_back(p_perms[triples[2].indexB]);
        }
       
    }
    
    return output;
    
}


//EachPermutation
std::vector<int> PrimePermutation(int p, std::set<int> prime_set){
    std::string p_str = std::to_string(p);
    std::vector<std::string> perm_strings;
    std::vector<int> output;
    perm_strings = AtomicListPermutation(p_str);
    for (std::string p: perm_strings){
        int n = std::stoi(p);
        if (prime_set.count(n) != 0)
            output.emplace_back(n);
    }
    return output;
}



//FindAllDistancesBetweenTuples Also keep the index
std::vector<TupleDistance> FindAllDistancesBetweenTuples(const std::vector<int> values){
    std::vector<TupleDistance> res;
    for (int indexa = 0; indexa < values.size(); indexa++){
        for (int indexb = 0; indexb < values.size(); indexb++){
            if (indexb > indexa)
                res.emplace_back(TupleDistance(values[indexb] - values[indexa], indexa, indexb));
        }
    }
    return res;
}

// generate the counter map
std::map<int,int> GenerateCounterMap(std::vector<TupleDistance> tuples){
    std::map<int,int> counter;
    for (TupleDistance v: tuples){
        if (counter.find(v.distance) == counter.end()){
            counter.insert({v.distance, 1});
        } else {
            counter[v.distance]++;
        }
    }
    return counter;
}

std::vector<TupleDistance> GetTripleWithEqualDistance(int n, std::map<int,int> counter_map, std::vector<TupleDistance> tuples){
    std::vector<TupleDistance> output;
    for (auto v: tuples){
        if (counter_map.find(v.distance)->second >= n)
            output.emplace_back(v);
    }
    return output;
 }

