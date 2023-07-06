#include "temp_threading.hpp"

/**
 * @author Natalie Chmura
 * 
 * @brief This contains a class that defines a function that takes in a pose 
 * array and returns the corresponding float in the float array! 
 */

namespace SortScore {

std::mutex mu;

// PUBLIC:
_Float64 * ScoreRetriver::getScoreData(int * keys, std::map<int, int> scores, int size) {
    static _Float64 results[size];
    _Float64 * rePtr =  results;

    int num_threads = std::thread::hardware_concurrency();
    if (!num_threads) {num_threads++;}

    int idx = size/num_threads + 1;

    std::cout << "Threads: " << num_threads << std::endl;


    std::vector<std::thread> threads;
    threads.reserve(num_threads);

    for (int i = 0; i < num_threads; i++ ) {
        threads.emplace_back(
            std::thread {ScoreRetriver::popArr, (i * idx), ((i + 1) * idx), size, keys, scores, rePtr}
        );
    }

    for (auto& t: threads){
        t.join();
    }

    return results;
}

void ScoreRetriver::popArr(int start, int end, int max, int * keys, std::map<int, int> scores, _Float64 * results) {
    std::lock_guard<std::mutex> lock(mu);
    for (int i = start; i < end && i < max; i++){
        results[i] = scores[keys[i]];
    }
}


} // namespace SortScore