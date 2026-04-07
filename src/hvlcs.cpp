#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <utility>
#include <bits/stdc++.h>
#include <chrono>
std::pair<int, std::string> hvlcs(std::unordered_map<char, int>& alphabet, const std::string stringA, const std::string stringB){
    int n = stringA.size();
    int m = stringB.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(stringA[i-1] == stringB[j-1]){
                int value = 0;
                if(alphabet.count(stringA[i-1])){
                    value = alphabet[stringA[i-1]];
                }
                dp[i][j] = std::max({dp[i-1][j-1] + value, dp[i-1][j], dp[i][j-1]});
            } else {
                dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    std::string output;
    int i = n;
    int j = m;
    while(i > 0 && j > 0){
        if(stringA[i-1] == stringB[j-1]){
            int value = 0;
            if(alphabet.count(stringA[i-1])){
                value = alphabet[stringA[i-1]];
            }
            if(dp[i][j] == dp[i-1][j-1] + value && dp[i][j] > dp[i-1][j] && dp[i][j] > dp[i][j-1]) {
                output += stringA[i-1];
                i--; 
                j--;
            } else if (dp[i-1][j] >= dp[i][j-1]){
                i--;
            } else{
                j--;
            }
        } else if(dp[i-1][j] >= dp[i][j-1]){
            i--;
        } else{
            j--;
        }
    }
    std::reverse(output.begin(), output.end());
return std::make_pair(dp[n][m], output);
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
    std::unordered_map<char, int> alphabet;
    for(int i = 0; i < alphabetSize; i++){
        std::getline(infile, line);
        std::vector<std::string> splitLine = split(line, ' ');
        alphabet[splitLine[0][0]] = std::stoi(splitLine[1]);
    }
    std::string stringA;
    std::string stringB;
    std::getline(infile, line);
    stringA = line;
    std::getline(infile, line);
    stringB = line;
    infile.close();

    auto start = std::chrono::high_resolution_clock::now();
    std::pair<int, std::string> output = hvlcs(alphabet, stringA, stringB);
    auto end = std::chrono::high_resolution_clock::now();
    
    //print output to console: max value and one optimal subsequence
    std::cout << output.first << std::endl; //max value
    std::cout << output.second << std::endl; //one optimal subsequence

    // -------- run time measurement --------
    double time_ms = std::chrono::duration<double, std::milli>(end - start).count();
    std::ofstream csv("data/timings.csv", std::ios::app);
    csv << stringA.size() << "," << time_ms << "\n";
    csv.close();
    std::cout << "HVLCS runtime: " << time_ms << " ms" << std::endl;

    //write output to file
    std::ofstream outfile("data/example.out");
    if(outfile.is_open()) {
        outfile<<output.first<<std::endl;
        outfile<<output.second<<std::endl;
        outfile.close();
    }
}