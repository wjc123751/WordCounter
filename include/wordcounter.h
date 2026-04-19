#ifndef WORDCOUNTER_H
#define WORDCOUNTER_H

#include <string>
#include <map>
#include <vector>

class WordCounter
{
public:
    // 统计文件单词
    bool countFromFile(const std::string& filename);

    // 打印结果
    void printResult() const;

    // 获取单词列表
    std::map<std::string, int> getWordMap() const;      // map 红黑树

private:
    // 清理单词：小写 + 去标点
    std::string cleanWord(const std::string& word) const;

private:
    std::map<std::string, int> m_wordMap;
};

#endif