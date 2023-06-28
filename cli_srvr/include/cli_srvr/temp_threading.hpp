#ifndef TEMP_THREADING_H
#define TEMP_THREADING_H

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#include <map>

/**
 * @author Natalie Chmura
 * 
 * @brief This contains a class that defines a function that takes in a pose 
 * array and returns the corresponding float in the float array! 
 */

/**
 * @namespace SortScores 
 */
namespace SortScore {

/**
 * @class ScoreRetriver
 * 
 * @brief This class contains a function that takes in a pose array and retruns an associated
 * score array by sorting through and assigning the appropriate score to each pose!
 */
class ScoreRetriver {

    public:

        /**
         *  
         */
        static _Float64 * getScoreData(int * keys, std::map<int, int> scores);
    private:

};



} // namespace SortScore

#endif // TEMP_THREADING_H