#include "temp_threading.hpp"

int main(int argc, char **argv) {

    int keys[100];
    std::map<int, int> score;
    for (int i = 0; i < 100; i++) {
        keys[i] = i;
        score.emplace(i, std::rand() % 1000 + 1);
        std::cout << keys[i] << std::endl;
    }

    _Float64 results[100]; 
    TEMP_THREADING_H::SortScore::ScoreRetriver::getScoreData(keys, score, results, 100);

    std::cout << "Size: " << sizeof(results) /sizeof(_Float64) << std::endl;


    for (int i = 0; i < 100; i++){
        std::cout << "Key: " << keys[i] << " Score: " << results[i] << std::endl;
    }

    for (int i = 0; i < 100; i++) {
        std::cout << "Key: " << keys[i] << " Score: " << score[keys[i]] << std::endl;
    }

}