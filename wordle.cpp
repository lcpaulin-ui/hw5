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

// Definition of primary wordle function
std::set<std::string> wordle(
    const std::string& in,
    const std::string& floating,
    const std::set<std::string>& dict)
{

    std::set<std::string> temp_words;
    wordle_helper(temp_words,"-i--", 0); 

    return temp_words; 
}

// Define any helper functions here
void wordle_helper(std::set<std::string>& out, std::string in, int pos){

    if (pos == in.size() ){
        out.insert(in); 
    }

    for (int i = 0; i <= 25; i++){
        if (in[pos] == '-')
        {
        in[pos] = 'a' + 1; 
        wordle_helper(out,in, pos+1); 
        in[pos] = '-'; 
    
        }

    }
    // undo ! 

}