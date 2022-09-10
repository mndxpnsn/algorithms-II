//
//  main.cpp
//  longest-palindromic-substring
//
//  Created by Derek Harrison on 21/08/2022.
//

#include <iostream>


std::string get_max_palindrome2(std::string s) {

 std::string result = s;

 int size_string = (int) s.length();
 int num_dummy_elements = size_string - 1;

 //Base cases
 if(size_string == 0) { return ""; }
 if(size_string == 1) { return result; }
 if(size_string == 2) {
     if(result[0] == result[1]) { return result;    }
     else { return result.substr(0, 1); }
 }

 int total_num_elements = size_string + num_dummy_elements;
 std::string dummy_string;
 int index = 0;
 int index_string = 0;
 while(index < total_num_elements) {
     if(index_string < s.length()) {
         dummy_string = dummy_string + s[index_string];
     }
     index++;
     index_string++;
     dummy_string = dummy_string + '@';
     index++;
 }

 //Compute max palindrome
 int size_palindrome = 1;
 int left_index = 0;
 int right_index = 0;
 int center_index = 0;
 for(int i = 1; i < total_num_elements - 1; ++i) {
     int left_track = i - 1;
     int right_track = i + 1;
     int size_palindrome_loc = 1;
     while(dummy_string[left_track] == dummy_string[right_track] && left_track >= 0 && right_track <= total_num_elements) {
         size_palindrome_loc = size_palindrome_loc + 2;
         if(size_palindrome_loc > size_palindrome) {
             size_palindrome = size_palindrome_loc;
             left_index = left_track;
             right_index = right_track;
             center_index = i;
         }
         left_track--;
         if(left_track < 0) { left_track = 0; }
         right_track++;
         if(right_track >= total_num_elements) { right_track = total_num_elements; }
     }
 }

 //Construct palindrome
 std::string palindrome;
 for(int i = left_index; i <= right_index; ++i) {
     if(dummy_string[i] != '@') {
         palindrome = palindrome + dummy_string[i];
     }
 }

 return palindrome;
}

std::string longest_palindrome(std::string s) {
    
 return get_max_palindrome2(s);
}

int main(int argc, const char * argv[]) {

    // Input string
    std::string s = "babad";
    
    // Compute maximum palindromic substring
    std::string max_p = longest_palindrome(s);
    
    // Print results
    std::cout << "maximum palindrome: " << max_p << std::endl;
    
    return 0;
}
