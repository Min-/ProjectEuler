//
//  Euler79_passcode.cpp
//  ProjectEuler
//
//  Created by Min Zhang on 2020/4/11.
//  Copyright © 2020 Min Zhang. All rights reserved.
//

#include "Euler79_passcode.hpp"

std::vector<std::string> ReadInput(){
    std::vector<std::string> out;
    std::ifstream file("/Users/min/dev/ProjectEuler/ProjectEuler/data/p079_keylog.txt");
     std::string str;
    while (std::getline(file, str))
    {
        out.emplace_back(str);
    }
    return out;
}

int SolutionEuler79(){
    std::vector<std::string> out = ReadInput();
    for (std::string v: out)
        std::cout << v << std::endl;
    return 0;
}
