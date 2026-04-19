#ifndef WORDCOUNTER_H
#define WORDCOUNTER_H

#include <string>
#include <map>

class WordCounter
{
public:
    bool countFromFile(const std::wstring& filename);  // 宽字符版本
    void printResult() const;
    std::map<std::string, int> getWordMap() const;

private:
    std::string cleanWord(const std::string& word);
    std::map<std::string, int> m_wordMap;
};

#endif