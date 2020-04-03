//
//  benchmark.hpp
//  ProjectEuler
//
//  Created by Min Zhang on 2020/4/3.
//  Copyright © 2020 Min Zhang. All rights reserved.
//

#ifndef benchmark_hpp
#define benchmark_hpp

#include "benchmark.hpp"
#include <chrono>
#include <iostream>

struct Timer{
    typedef std::chrono::time_point<std::chrono::steady_clock> time;
    time start, end;
    std::chrono::duration<float> duration;
    
    Timer(){
        start = std::chrono::high_resolution_clock::now();
    };
    
    ~Timer(){
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "Total time: " << duration.count() << " s" << std::endl;
    }
};

#endif /* benchmark_hpp */
