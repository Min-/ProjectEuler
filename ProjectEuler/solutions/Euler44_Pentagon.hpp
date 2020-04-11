//
//  Euler44_Pentagon.hpp
//  ProjectEuler
//
//  Created by Min Zhang on 2020/4/11.
//  Copyright © 2020 Min Zhang. All rights reserved.
//

#ifndef Euler44_Pentagon_hpp
#define Euler44_Pentagon_hpp

#include <stdio.h>
#include <set>
#include <vector>
#include <iostream>


struct AnswerSet{
    int sum, diff, x, y;
    
    AnswerSet(int a, int b, int c, int d)
    :sum(a), diff(b), x(c), y(d){};

    void PrintAnswer(){
        std::cout << sum << " " << diff << " " << x << " " << y << std::endl;
    }
};

int SolutionEuler44();

#endif /* Euler44_Pentagon_hpp */
