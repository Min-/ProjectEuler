//
//  main.cpp
//  ProjectEuler
//
//  Created by Min Zhang on 2020/4/2.
//  Copyright © 2020 Min Zhang. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <chrono>

#include "numbers.hpp"

bool IsPalindromic(std::string numstr){
    std::string numstr_reverse;
    numstr_reverse = numstr;
    std::reverse(numstr.begin(), numstr.end());
    return numstr_reverse == numstr;
}

bool IsPalindromic_old(std::string numstr){
    auto head = numstr.begin();
    auto tail = --numstr.end();
    //std::cout << *head << ", " << *tail << std::endl;
    if (numstr.size() % 2 != 0){
        while (head != tail){
            if (*head != *tail){
                return false;
            } else {
                head++;
                tail--;
            }
        }
        return true;
    } else {
        while (std::distance(head, tail) >= 1){
            if (*head != *tail){
                return false;
            } else {
                ++head;
                --tail;
            }
        }
        return true;
    }
}

std::string PrintBool(bool a){
    if (a){
        return "true";
    } else {
        return "false";
    }
}

std::string Addition(std::string a, std::string b);

std::string ReverseNum(std::string n){
    std::reverse(n.begin(), n.end());
    return n;
}

bool IsLychrel(std::string n){
    int count = 0;
    count++;
    while (!IsPalindromic(Addition(n, ReverseNum(n))) && count <= 60){
        count++;
        n = Addition(n, ReverseNum(n));
    }
    if (count <= 60){
        //std::cout << Addition(n, ReverseNum(n)) << std::endl;
        //std::cout << "reverse and addition count: " << count << std::endl;
        return false;
    }
    else {
        //std::cout << Addition(n, ReverseNum(n)) << std::endl;
        //std::cout << "reverse and addition count: " << count << std::endl;
        return true;
    }
}


std::string Addition(std::string a, std::string b){
    std::string out;
    auto a_end = --a.end();
    auto b_end = --b.end();
    
    int sum(0);
    int remainder(0);
    int leftover(0);
    
    while (a_end >= a.begin() && b_end >= b.begin()){
        //std::cout << *a_end << std::endl;
        //std::cout << *b_end << std::endl;
        std::stringstream buff_a;
        std::stringstream buff_b;
        int a_value, b_value;
        buff_a << *a_end;
        buff_a >> a_value;
        buff_b << *b_end;
        buff_b >> b_value;
        sum = (a_value + b_value) + leftover;
        remainder = sum % 10;
        leftover = sum / 10;
        out.append(std::to_string(remainder));
        sum = 0;
        a_end--;
        b_end--;
    }
    while (a_end >= a.begin()){
        //std::cout << *a_end << std::endl;
        std::stringstream buff_a;
        int a_value;
        buff_a << *a_end;
        buff_a >> a_value;
        sum = (a_value) + leftover;
        remainder = sum % 10;
        leftover = sum / 10;
        out.append(std::to_string(remainder));
        sum = 0;
        a_end--;
    }
    while (b_end >= b.begin()){
        //std::cout << *b_end << std::endl;
        std::stringstream buff_b;
        int b_value;
        buff_b << *b_end;
        buff_b >> b_value;
        sum = (b_value) + leftover;
        remainder = sum % 10;
        leftover = sum / 10;
        out.append(std::to_string(remainder));
        sum = 0;
        b_end--;
    }
    if (leftover != 0)
        out.append(std::to_string(leftover));
    std::reverse(out.begin(), out.end());
    return out;
}

int CountLychrelNumbers(int limit){
    std::string str_n;
    int count = 0;
    for (int i = 0; i < limit; i++){
        str_n = std::to_string(i);
        if (IsLychrel(str_n)){
            //std::cout << str_n << std::endl;
            count++;
        }
    }
    return count;
}

int Euler55(){
    /* test string addition function
    std::string res;
    std::string a, b;
    a = "4668731596684224866951378664";
    b = "1";
    res = Addition(a, b);
    std::cout << a << " + " << b << " = " << res << std::endl;
     */
    Timer timer;
    
    bool answer;
    answer = IsLychrel("487");
    
    int count;
    count = CountLychrelNumbers(10000);
    std::cout << count << std::endl;
    
    return 0;
}
