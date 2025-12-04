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

    std::vector<char> floaters; 
        for (auto c : floating) {
            floaters.push_back(c); 
        }
        std::vector<string> partial; 
        wordle_floats(partial, floaters, in, 0); 
        std::set<std::string> out;
        for (int i = 0; i < floaters.size(); i++)
        {wordle_rest(out, partial[i],0); }
    
        for (auto word : out){
            std::cout << word << endl;
        }

        return out; 
}

// Define any helper functions here
void wordle_floats(std::vector<string> part, std::vector<char> floats, std::string in, int pos){

    if (pos == in.size() ){
        std::cout << in << endl; 
        part.push_back(in); 
        return; 
    } 

    if (in[pos] != '-'){
        wordle_floats(part, floats, in, pos+1); 
        // fixed , keep going 
    }

    // now generate all combos with these two letters floating around 
    for (int i = 0; i < floats.size(); i++){
        // explore 
        in[pos] = floats[i]; 
        wordle_floats(part, floats, in, pos+1); 
    }
    in[pos] = '-'; // undo! 

} 


// Define any helper functions here
void wordle_rest(std::set<std::string>& out, string in, int pos){

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


