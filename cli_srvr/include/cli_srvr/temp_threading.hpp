#ifndef TEMP_THREADING_H
#define TEMP_THREADING_H

#include <stdlib.h>
#include <stdio.h>
#include <thread>
#include <mutex>
#include <vector>
#include <iostream>

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
         *  @brief Runs a multithreaded process that goes through the entire map and populates an array with
         * the score data!
         */
        static void getScoreData(int * keys, std::map<int, int> scores, _Float64 * results, int size);


    private:
        static void popArr(int start, int end, int max, int * keys, std::map<int, int> scores, _Float64 * results);

};



} // namespace SortScore

#endif // TEMP_THREADING_H