//
//  numbers.hpp
//  ProjectEuler
//
//  Created by Min Zhang on 2020/4/3.
//  Copyright © 2020 Min Zhang. All rights reserved.
//

#ifndef numbers_hpp
#define numbers_hpp

#include <stdio.h>

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <chrono>

#include "benchmark.hpp"
#include "numbers.hpp"

std::vector<int> PrimeUnderN(int);

std::vector<int> PrimeRange(int begin, int end);

std::vector<std::string> AtomicListPermutation(std::string);

std::vector<std::string> CircularListPermutation(std::string);

#endif /* numbers_hpp */
