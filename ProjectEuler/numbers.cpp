//
//  numbers.cpp
//  ProjectEuler
//
//  Created by Min Zhang on 2020/4/3.
//  Copyright © 2020 Min Zhang. All rights reserved.
//

#include "numbers.hpp"
#include "benchmark.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <chrono>


std::vector<int> PrimeUnderN(int n){
    std::cout << "find all primer under n" << std::endl;
    Timer timer;
    
    std::vector<int> primes = {2};
    int i = 3;
    while (i < n){
        for (int j = 0; j < primes.size(); j++){
            //std::cout << i%p << std::endl;
            if (i % primes[j] == 0){
                //std::cout << "i % p == 0" << std::endl;
                //std::cout << i << std::endl;
                i = i+1;
                break;
            } else {
                if (j != primes.size() - 1) {
                continue;
                } else {
                    //std::cout << "emplace_back " << i << std::endl;
                    primes.emplace_back(i);
                }
            }
        }
        i++;
    }
    return primes;
}

template<typename T>
std::vector<T> AtomicListPermutation(T a){
    /*
     auto Perm = AtomicListPermutation((std::string)"viola");
     for (auto s: Perm)
         std::cout << s << std::endl;
     */
    std::vector<T> res;
    std::sort(a.begin(), a.end());
    res.emplace_back(a);
    while (std::next_permutation(a.begin(), a.end())){
        res.emplace_back(a);
    };
    return res;
}

std::vector<std::string> CircularListPermutation(std::string a){
    //std::cout << "circular permutation" << std::endl;
    //Timer timer;
    
    std::vector<std::string> res={a};
    for (int i = 1; i < a.size(); i++){
        res.emplace_back(a.substr(i,a.size()-1) + a.substr(0,i));
    }
    
    return res;
}

