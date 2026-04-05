#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <map>
#include <utility>
std::pair<int, std::string> hvlcs(const std::map<std::string, int>& alphabet, const std::string stringA, const std::string stringB){

}
std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    
    return tokens;
}
int main(){
    std::string filePath = "data/example.in";
    std::ifstream infile(filePath);
    if(!infile) {
        std::cerr << "Error: Cannot open file: " << filePath << std::endl;
        return 1;
    }
    
    std::string line;
    std::getline(infile, line);
    int alphabetSize = std::stoi(line);
    std::map<std::string, int> alphabet;
    for(int i = 0; i < alphabetSize; i++){
        std::getline(infile, line);
        std::vector<std::string> splitLine = split(line, ' ');
        alphabet.insert({splitLine[0], std::stoi(splitLine[1])});
    }
    std::string stringA;
    std::string stringB;
    std::getline(infile, line);
    stringA = line;
    std::getline(infile, line);
    stringB = line;
    infile.close();

    std::pair<int, std::string> output = hvlcs(alphabet, stringA, stringB);
    std::ofstream outfile("data/example.out");
    if(outfile.is_open()) {
        std::cout<<output.first<<std::endl;
        std::cout<<output.second<<std::endl;
        outfile.close();
    }
}