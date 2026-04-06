#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <random>
#include <chrono>

int main(int argc, char *argv[]){
     if(argc != 6) {
        std::cout << "Usage: " << argv[0] << " <alphabet size(max of 26)>" << " <string A size>"
        << " <string B size>" <<" <minimum char value>" << " <maximum char value>" << std::endl;
        return 1;
    }
    
    int alphabetSize = atoi(argv[1]);
    int stringASize = atoi(argv[2]);
    int stringBSize = atoi(argv[3]);
    int min_val = atoi(argv[4]);
    int max_val = atoi(argv[5]);
    std::ofstream outfile("data/example.in");
    if(outfile.is_open()) {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 gen(seed);
        std::uniform_int_distribution<> rand(min_val, max_val);
        std::uniform_int_distribution<> randChar(0, 25);
        outfile << alphabetSize << std::endl;
        if(alphabetSize > 26) return 0;
        for(int i = 0; i < alphabetSize; i++){
            outfile << char(97+i) << " " << rand(gen) << std::endl;
        }
        std::string stringA, stringB;
        for(int i = 0; i < stringASize; i++){
            stringA += char(97+randChar(gen));
        }
        for(int i = 0; i < stringBSize; i++){
            stringB += char(97+randChar(gen));
        }
        outfile << stringA << std::endl;
        outfile << stringB;
    }
    return 0;
}