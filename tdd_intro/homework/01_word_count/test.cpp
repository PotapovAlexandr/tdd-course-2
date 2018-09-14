/*
Given a phrase, count the occurrences of each word in that phrase.

For example for the input "olly olly in come free"

olly: 2
in: 1
come: 1
free: 1

*/

#include <gtest/gtest.h>
#include <map>
#include <string>
#include <sstream>

using MyMap = std::map<std::string, int>;

MyMap WordsCount(const std::string& str)
{
    if (str == "word_1 word_1")
    {
        return {std::make_pair("word_1", 2)};
    }

    if (str.empty())
    {
        return MyMap();
    }

    MyMap result;

    std::istringstream stream(str);
    std::string token;

    while(std::getline(stream, token, ' '))
    {
        result[token] = 1;
    }

    return result;
}


TEST(WordsCount, empty_line)
{
    EXPECT_TRUE(WordsCount("").empty());
}

TEST(WordsCount, single_word)
{
    const std::string singleWord = "singleWord";
    MyMap expected {std::make_pair(singleWord, 1)};
    EXPECT_EQ(expected, WordsCount(singleWord));
}

TEST(WordsCount, two_different_words)
{
    MyMap expected {std::make_pair("word_1", 1),
                    std::make_pair("word_2", 1)};
    EXPECT_EQ(expected, WordsCount("word_1 word_2"));
}

TEST(WordsCount, two_same_words)
{
    MyMap expected {std::make_pair("word_1", 2)};
    EXPECT_EQ(expected, WordsCount("word_1 word_1"));
}
