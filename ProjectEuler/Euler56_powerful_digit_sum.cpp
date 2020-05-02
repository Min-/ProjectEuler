//
//  Euler56_powerful_digit_sum.cpp
//  ProjectEuler
//
//  Created by Min Zhang on 2020/5/2.
//  Copyright © 2020 Min Zhang. All rights reserved.
//

#include <stdio.h>
#include <typeinfo>
#include "pch.h"
#include "benchmark.hpp"

int char2int(char c){
    return c - 48;
}

std::string strAdd(const std::string& a, const std::string& b){
        std::string out;
        auto a_end = --a.end();
        auto b_end = --b.end();

        int sum(0);
        int remainder(0);
        int carryover(0);

        while (a_end >= a.begin() && b_end >= b.begin()){
            int a_value, b_value;
            a_value = char2int(*a_end);
            b_value = char2int(*b_end);

            sum = (a_value + b_value) + carryover;
            remainder = sum % 10;
            carryover = sum / 10;
            out.append(std::to_string(remainder));
            sum = 0;
            a_end--;
            b_end--;
        }
        while (a_end >= a.begin()){
              int a_value;
              a_value = char2int(*a_end);
        
              sum = a_value + carryover;
              remainder = sum % 10;
              carryover = sum / 10;
              out.append(std::to_string(remainder));
              sum = 0;
              a_end--;
        }
        while (b_end >= b.begin()){
            int b_value;
            b_value = char2int(*b_end);
            
            sum = b_value + carryover;
            remainder = sum % 10;
            carryover = sum / 10;
            out.append(std::to_string(remainder));
            sum = 0;
            b_end--;
        }
        if (carryover != 0){
            out.append(std::to_string(carryover));
        }
        std::reverse(out.begin(), out.end());
        return out;
}

std::string strMultiplySingleDigit(const std::string& a, const std::string& single){
    std::string out;
    auto a_end = --a.end();
    
    int product(0);
    int remainder(0);
    int carryover(0);

    while (a_end >= a.begin()){
        int a_value, b_value;
        a_value = char2int(*a_end);
        b_value = char2int(*single.begin());

        product = (a_value * b_value) + carryover;
        remainder = product % 10;
        carryover = product / 10;
        out.append(std::to_string(remainder));
        product = 0;
        a_end--;
    }
    
    while (carryover != 0){
        product = carryover;
        remainder = product % 10;
        carryover = product / 10;
        out.append(std::to_string(remainder));
        product = 0;
    }
    std::reverse(out.begin(), out.end());
    return out;
}

std::string strTimesNTen(const std::string &a, int n){
    std::string out;
    out = a;
    while (n > 0){
        out.append("0");
        n--;
    }
    return out;
}

std::string strMultiply(const std::string& a, const std::string& b){
    std::string out("0");
    auto a_end = --a.end();
    int len_a = a.length();
    int digit = 1;
    
    while (a_end >= a.begin()){
        std::string a_value = std::to_string(char2int(*a_end));
        std::string ab = strMultiplySingleDigit(b, a_value);
        
        if (digit <= len_a){
            std::string new_ab = strTimesNTen(ab, digit - 1);
#ifdef TEST
            std::cout << "the " << len_a << " digit result is: " << ab << std::endl;
#endif
            out = strAdd(out, new_ab);
            digit++;
        } else {
            out = strAdd(out, ab);
        }
        a_end--;
    }
    return out;
}

std::string strPower(const std::string& a, int p){
    std::string out("1");
    while (p > 0){
        out = strMultiply(out, a);
        p--;
    }
    return out;
}

int strDigitSum(const std::string& a){
    int sum = 0;
    for (char c: a){
        sum = sum + char2int(c);
    }
    return sum;
}

int solution56(){
    Timer timer;
    int max = 0;
    std::pair<int, int> pair = {0,0};
    
    for (int a = 1; a < 100; a++){
        for (int b = 1; b < 100; b++){
            std::string pow = strPower(std::to_string(a), b);
            int sum = strDigitSum(pow);
            if (sum > max){
                max = sum;
                pair.first = a;
                pair.second = b;
            }
        }
    }
    
    std::cout << "the max is: " << max << std::endl;
    std::cout << "a is " << pair.first << " b is " << pair.second << std::endl;
    std::cout << "a^b is " << strPower(std::to_string(pair.first), pair.second) << std::endl;
    
    return 0;
}

int main__problem56(){
    std::string a = "123";
    std::string b  = "341";
    
    std::cout << strAdd(a, b) << std::endl;
    std::cout << strMultiplySingleDigit("25", "5") << std::endl;
    std::cout << strMultiply("25", "25") << std::endl;
    
    std::cout << strPower("10", 100) << std::endl;
    std::cout << strDigitSum("19") << std::endl;
    
    //Total time: 34.5656 s
    solution56();
    return 0;
}
