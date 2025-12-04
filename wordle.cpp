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
#include <vector> 
using namespace std;


// Add prototypes of helper functions here
void wordle_helper(std::set<std::string>& out, std::string in, int pos); 
void wordle_floats(std::vector<string> part, std::vector<char> floats, std::string in, int pos); 
void wordle_rest(std::set<std::string>& out, string in, int pos); 

// Definition of primary wordle function
std::set<std::string> wordle(
    const std::string& in,
    const std::string& floating,
    const std::set<std::string>& dict)
{



    
}

// Define any helper functions here
void worlde_helper(std::vector<string> part, std::vector<char> floats, std::string in, int pos){

    if (pos == in.size()){
        out.insert(in); 
        return; 
    }

      // choose 
      if (in[pos] != '-'){
        wordle_rest(out,in, pos+1); 
        // set , keep going 
    }

    for (int i = 0; i <= 25; i++){
        // explore 
        in[pos] = 'a' + i; 
        wordle_rest(out,in, pos+1); 

    }
    in[pos] = '-'; // undo! 
    // undo ! 
    
} 


// Define any helper functions here
void wordle_rest(std::set<std::string>& out, string in, int pos){

    
}


