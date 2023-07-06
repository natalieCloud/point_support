#include "temp_threading.hpp"

int main(int argc, char **argv) {

    int keys[100];
    std::map<int, int> score;
    for (int i = 0; i < 100; i++) {
        keys[i] = i;
        score.emplace(i, std::rand() % 1000 + 1);
        std::cout << keys[i] << std::endl;
    }

    _Float64 * re = TEMP_THREADING_H::SortScore::ScoreRetriver::getScoreData(keys, score, 100);

    std::cout << "Size: " << sizeof(re) /sizeof(_Float64) << std::endl;


    for (int i = 0; i < 100; i++){
        std::cout << "Key: " << keys[i] << " Score: " << re[i] << std::endl;
    }

    for (int i = 0; i < 100; i++) {
        std::cout << "Key: " << keys[i] << " Score: " << score[keys[i]] << std::endl;
    }

}