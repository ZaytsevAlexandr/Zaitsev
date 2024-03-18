#include <iostream>
#include <unordered_set>
#include <unordered_map>

int main(){
    int n;
    std::cin >> n;

    std::unordered_set<std::string> words;
    std::unordered_map<std::string, int> wordsAmount;
    for (auto i = 0; i < n; i++){
        std::string word;
        std::cin >> word;
        words.insert(word);
        wordsAmount[word]++;
    }
    std::cout << "Words: " << words.size() << ", " << std::endl;
    for (auto p: wordsAmount){
        std::cout << '\t' << p.first << ": " << p.second << std::endl;
    }
}
