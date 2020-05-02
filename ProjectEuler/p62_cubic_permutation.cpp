//
//  p62_cubic_permutation.cpp
//  ProjectEuler
//
//  Created by Min Zhang on 2020/5/2.
//  Copyright © 2020 Min Zhang. All rights reserved.
//

#include "p62_cubic_permutation.hpp"
#include "pch.h"
#include <cmath>
#include <vector>

//#define PRINT

//int -> array char -> sort -> unique id for all perumutations
std::string permutation_id (long a){
    std::string string = std::to_string(a);
    //sort
    std::sort(string.begin(), string.end());
#ifdef PRINT
    std::cout << string << std::endl;
#endif
    return string;
}

long cube(long a){
    return a*a*a;
}


int main_p62(){
    std::map<std::string, long> cubemap;
    std::map<std::string, std::vector<long>> cubelist;
    std::map<std::string, std::vector<long>> cubeorder;
    
    for (long i = 1; i < 15000; i++){
        long cube = i*i*i;
        std::string cube_perm = permutation_id(cube);
                
        cubemap[cube_perm]++;
        
        std::vector<long> vec;
        auto search = cubelist.find(cube_perm);
        if (search == cubelist.end()){
            cubelist[cube_perm] = vec;
            cubelist[cube_perm].emplace_back(cube);
            cubeorder[cube_perm].emplace_back(i);
        } else {
            cubelist[cube_perm].emplace_back(cube);
            cubeorder[cube_perm].emplace_back(i);
        }
        
    }
    
//
//    for (std::pair<int, int> p: cubemap){
//        std::cout << p.first << " " << p.second << std::endl;
//    }
    for (auto p: cubemap){
        if (p.second==5){
            std::cout << p.first << std::endl;
            std::cout << ":::" << std::endl;
            
            std::vector<long> cubes = cubelist[p.first];
            for (long v: cubes){
                std::cout << v << "\t";
            }
            std::cout << std::endl;
            std::cout << "xxxxx" << std::endl;
            
            std::vector<long> orders = cubeorder[p.first];
            for (long v: orders){
                std::cout << v << "\t";
            }
            std::cout << std::endl;
            std::cout << "----------------------------" << std::endl;
        }
    }
    
    // make sure the Intergers are not overflow
    std::cout << std::to_string(cube(2044)) << std::endl;
    std::cout << std::to_string((long)2044*2044*2044) << std::endl;
    std::cout << cube(2541) << std::endl;
    std::cout << std::to_string((long)2541*2541*2541) << std::endl;
    return 0;
}
