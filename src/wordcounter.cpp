#include "wordcounter.h"
#include <fstream>
#include <cctype>
#include <iostream>

using namespace std;

string WordCounter::cleanWord(const string& word) const
{
    string res;
    for (char c : word) {
        if (isalpha(c)) {          // 只保留字母
            res += tolower(c);     // 转小写
        }
    }
    return res;
}

bool WordCounter::countFromFile(const string& filename)
{
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "打开文件失败: " << filename << endl;
        return false;
    }

    string word;
    while (file >> word) {      // 自动按空格拆分单词
        string clean = cleanWord(word);
        if (!clean.empty()) {
            m_wordMap[clean]++;
        }
    }

    file.close();
    return true;
}

void WordCounter::printResult() const
{
    cout << "\n===== 单词统计结果 =====\n";
    for (const auto& pair : m_wordMap) {
        cout << pair.first << " : " << pair.second << endl;
    }
}

map<string, int> WordCounter::getWordMap() const
{
    return m_wordMap;
}