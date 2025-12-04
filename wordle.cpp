#ifndef RECCHECK
// For debugging
#include <iostream>
// For std::remove
#include <algorithm> 
#include <map>
#include <set>
#endif

#include "wordle.h"
#include "dict-eng.h"
using namespace std;


// Add prototypes of helper functions here
void wordle_helper(std::set<std::string>& out, std::string in, int pos); 
void wordle_floaters(std::set<std::string>& out, std::string floaters, std::string in, int floater_cnt,  int pos, const std::set<std::string>& dict); 
void wordle_remaining(std::set<std::string>& out, std::string in, int pos, const std::set<std::string>& dict); 

// Definition of primary wordle function
std::set<std::string> wordle(
    const std::string& in,
    const std::string& floating,
    const std::set<std::string>& dict)
{

    std::set<std::string> temp_words;
    wordle_floaters(temp_words, floating, in, 0, 0, dict);
    return temp_words; 
}


// Define any helper functions here
void wordle_floaters(std::set<std::string>& out, std::string floaters, std::string in, int floater_cnt,  int pos, const std::set<std::string>& dict){ 

    // base case: placed all floating letters 
    if (floater_cnt == floaters.size()){
        wordle_remaining(out, in, 0, dict); 
    }
            for (int i = 0; i < in.size(); i++){
                // explore 
                if (in[i] == '-'){
                    in[i] = floaters[floater_cnt];
                    wordle_floaters(out, floaters, in, floater_cnt+1, pos+1, dict); 
                    in[i] = '-'; 
                }
    
            }
            // undo ! 

}


// Define any helper functions here
void wordle_remaining(std::set<std::string>& out, std::string in, int pos, const std::set<std::string>& dict){
    if (pos == in.size()){
    
        if (dict.find(in) != dict.end())
      { out.insert(in); }
        return; 
    }

      // choose 
    if (in[pos] != '-'){
        wordle_remaining(out, in, pos+1, dict); 
        // set , keep going 
    }
    else 
   { 
        for (int i = 0; i <= 25; i++){
            // explore 
            in[pos] = 'a'+ i; 
            wordle_remaining(out, in, pos+1, dict); 

        }
        in[pos] = '-'; // undo! 
        // undo ! 
    }

}





