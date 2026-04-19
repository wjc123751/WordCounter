#include "wordcounter.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

// 清洗单词：只保留英文字母，全部转小写
string WordCounter::cleanWord(const string& word)
{
    string res;
    for (char c : word)
    {
        // 仅保留大小写英文字母
        if (isalpha(c))
        {
            res += tolower(c);
        }
    }
    return res;
}

bool WordCounter::countFromFile(const wstring& filename)
{
    FILE* fp = nullptr;
    // 原生宽字符打开，完美支持中文文件夹
    _wfopen_s(&fp, filename.c_str(), L"r, ccs=UTF-8");

    if (!fp)
    {
        wcerr << L"打开文件失败: " << filename << endl;
        return false;
    }

    wchar_t buf[256];
    // 按空格/换行 逐个读取独立单词，而不是整行读取
    while (fwscanf(fp, L"%ls", buf) != EOF)
    {
        wstring w_word(buf);
        string normal_word(w_word.begin(), w_word.end());

        // 清洗单词
        string clean_word = cleanWord(normal_word);

        // 空字符跳过
        if (!clean_word.empty())
        {
            m_wordMap[clean_word]++;
        }
    }

    fclose(fp);
    return true;
}

// 打印统计结果
void WordCounter::printResult() const
{
    cout << endl;
    cout << "单词        出现次数" << endl;
    cout << "=====================" << endl;
    for (const auto& item : m_wordMap)
    {
        cout << item.first << "\t\t" << item.second << endl;
    }
}

map<string, int> WordCounter::getWordMap() const
{
    return m_wordMap;
}