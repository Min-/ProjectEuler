//
//  solutions.cpp
//  ProjectEuler
//
//  Created by Min Zhang on 2020/4/3.
//  Copyright © 2020 Min Zhang. All rights reserved.
//

#include <iostream>
#include <set>

#include "numbers.hpp"
#include "solutions.hpp"

std::vector<int> FindCircularPrimes(int n){
    /*
     project euler problem #35
     */

    std::vector<int> primes = PrimeUnderN(n);
    std::set<std::string> primes_set;
    std::vector<int> results;
    
    for (int p: primes){
        primes_set.emplace(std::to_string(p));
    }
    
    for (int p: primes){
        std::string p_str = std::to_string(p);
        std::vector<std::string> p_str_perm = CircularListPermutation(p_str);
        std::vector<bool> res;
        for (std::string p_perm: p_str_perm){
            auto search_res = primes_set.find(p_perm);
            if (search_res == primes_set.end()){
                res.emplace_back(false);
            } else {
                res.emplace_back(true);
            }
        }
        if (std::all_of(res.begin(), res.end(), [](bool x){return x;})){
            results.emplace_back(p);
        }
    }
    
    return results;
}

