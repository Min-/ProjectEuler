//
//  Problem36_double_palindrome.cpp
//  ProjectEuler
//
//  Created by Min Zhang on 2020/5/2.
//  Copyright © 2020 Min Zhang. All rights reserved.
//

bool isPalindromic(std::string& a){
    std::string b;
    b = a;
    std::reverse(a.begin(), a.end());
    return a == b;
};

std::string removeLeadingZeros(std::string& a){
    std::string b;
    for (char c: a){
        if (c != '0'){
            b.append(std::to_string(c));
        }
    }
    return b;
}

// this is dangerous
void str2bit(unsigned int n, std::string& out)
{
    if (n / 2 != 0) {
        str2bit(n / 2, out);
    }
    out.append(std::to_string(n%2));
}

bool doublePalindromic(unsigned int n){
    std::string decimal = std::to_string(n);
    std::string binary;
    str2bit(n, binary);
    return isPalindromic(decimal) && isPalindromic(binary);
}

int main__problem36(){
    int a = 4;
    std::string astr = std::to_string(a);
    std::cout << "decimal is: " << isPalindromic(astr) << std::endl;
    
    std::string binary;
    str2bit(a, binary);
    std::cout << binary << std::endl;
    std::cout << "binary is: " << isPalindromic(binary) << std::endl;
    
    int sum(0);
    for (int i = 1; i < 1E6; i++){
        if (doublePalindromic(i)){
            sum += i;
        }
    }
    
    std::cout << "the sum is: " << sum << std::endl;
    return 0;
}
