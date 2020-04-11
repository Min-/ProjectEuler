//
//  Euler44_Pentagon.cpp
//  ProjectEuler
//
//  Created by Min Zhang on 2020/4/11.
//  Copyright © 2020 Min Zhang. All rights reserved.
//

#include "Euler44_Pentagon.hpp"

int Pentagonal(int n){
    int Pn = n*(3*n - 1)/2;
    return Pn;
}

static int MIN = 100000000;

int SolutionEuler44() {
    std::set<int> PSet;
    std::vector<int> PVec;
    for (int i = 1; i <= 10000; i++){
        PVec.emplace_back(Pentagonal(i));
        PSet.emplace(Pentagonal(i));
    }
    
    std::cout << PVec.size() << std::endl;
    
    std::vector<AnswerSet> answers;
    
    int difference = MIN;
    for (int x: PVec){
        for (int y: PVec){
            if (x < y){
                int sum = x+y;
                //std::cout << sum << std::endl;
                int diff = std::abs(x-y);
                
                std::set<int>::iterator sumFound = PSet.find(sum);
                
                // if (sumFound != PSet.end())
                //     std::cout << "match a sum " << sum << std::endl;
                
                std::set<int>::iterator diffFound = PSet.find(diff);
                
                // if (diffFound != PSet.end())
                //     std::cout << "match a diff " << diff << std::endl;
                
                if (sumFound != PSet.end() && diffFound != PSet.end()){
                    std::cout << "match both " << sum << " " << diff << std::endl;
                }
                
                if (sumFound != PSet.end() && diffFound != PSet.end() && diff < difference){
                    difference = diff;
                    AnswerSet answer(sum, diff, x, y);
                    answers.emplace_back(answer);
                }
            }
        }
    }
    
    std::cout << answers.size() << std::endl;
    for (AnswerSet v: answers){
        v.PrintAnswer();
    }
    
    return 0;
}
