#ifndef RECCHECK
#include <set>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
// add or remove necessary headers as you please

#endif

#include "schedwork.h"

using namespace std;

// a constant that can be used to indicate an INVALID 
// worker ID if that is useful to your implementation.
// Feel free to not use or delete.
static const Worker_T INVALID_ID = (unsigned int)-1;


// Add prototypes for any helper functions here
bool sched_helper(size_t n, size_t dPos, size_t numWorkers, size_t slot, DailySchedule& shifts, size_t dailyNeed, const AvailabilityMatrix& avail, std::vector<int>& worked, const size_t maxShifts); 
bool isFree(size_t day, size_t worker, const AvailabilityMatrix& avail, std::vector<int>& worked, const size_t maxShifts); 

// Add your implementation of schedule() and other helper functions here

bool schedule(
    const AvailabilityMatrix& avail,
    const size_t dailyNeed,
    const size_t maxShifts,
    DailySchedule& sched
)

{
    if(avail.size() == 0U){
        return false;
    }
    sched.clear();
    //typedef std::vector<std::vector<Worker_T> > DailySchedule;
    



    //bool solutionFound = schedule(avail, 2, 2, sched);

    // Add your code below

    /// d = needed days / dailyNeed 
    // k workers
    // n day period 
    // <= maxShifts 
    size_t days = avail.size(); 
    size_t numWorkers = avail[0].size(); 

    // avoid seg faults , set up matrix 
    sched = DailySchedule(days, std::vector<Worker_T>(dailyNeed, 0)); 

    std::vector<int> worked(numWorkers, 0); // init to 0, add when marked as done, if reaches max cant add anymore 
    // typedef std::vector<std::vector<Worker_T> > DailySchedule;
    // [mon][][][][][]
    // [tues][][][][][]
    // [wed][][][][]

    // avoid segmentation faults, assign the sched vector ( )

    return sched_helper(avail.size(), 0, numWorkers, 0, sched, dailyNeed, avail, worked, maxShifts); 

} 

bool sched_helper(size_t n, size_t dPos, size_t numWorkers, size_t slot, DailySchedule& shifts, size_t dailyNeed, const AvailabilityMatrix& avail, std::vector<int>& worked, const size_t maxShifts){
    // std::cout << "currently on " << nDay << " day and " << dPos << " slot" << std::endl; 
    if (dPos == n){
        // filled all, return true 
        return true; 
    }
    if (slot == dailyNeed){
        return sched_helper(n, dPos + 1, numWorkers, 0, shifts, dailyNeed, avail, worked, maxShifts); 
    }
    // choose explore undo 
    for (int i = 0; i < numWorkers; i++){ 
        // use find function, from cpp reference : constexpr InputIt find(InputIt first, InputIt last, const T& value)
        if(isFree(dPos, i, avail, worked, maxShifts) && std::find(shifts[dPos].begin(), shifts[dPos].end(), i) == shifts[dPos].end()){
            shifts[dPos][slot] = i;
            worked[i]++; 
            if (sched_helper(n, dPos, numWorkers, slot+1, shifts, dailyNeed, avail, worked, maxShifts)) {
                return true; 
            }
            
            shifts[dPos][slot] = INVALID_ID; 
            worked[i]--;  
        }  
    }

    
    
    return false; 


}

// pseudocode: 

// if base case : 
// days oob : return true; 
// workers oob : go to next day, begin from worker 0 
// sched [row][col] already set, continue to next 

// explore choices (choose, explore, undo)
// iterate through workers, if free, set, explore, then undo choice 



// checking if valid shift 
// shift is valid only if worker is available and they havent worked > maxshifts 
bool isFree(size_t day, size_t worker, const AvailabilityMatrix& avail, std::vector<int>& worked, const size_t maxShifts) {
    if (avail[day][worker] == true && worked[worker] < maxShifts){
        return true; 
    }

    return false; 
}
