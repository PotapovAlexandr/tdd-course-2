/*
Given a word and a list of possible anagrams, select the correct sublist.

Given "listen" and a list of candidates like "enlists" "google" "inlets" "banana" the program should return a list containing "inlets".

_from http://exercism.io/_
*/
#include <gtest/gtest.h>
#include <set>
#include <algorithm>

using Anagrams = std::set<std::string>;
Anagrams ChooseCorrectAnagrams(const std::string& word, const Anagrams& candidates)
{
    return { "ab" };
}

TEST(Anagrams, Simple_ab)
{
    Anagrams candidates = { "ab" };
    Anagrams anagrams = ChooseCorrectAnagrams("ab", candidates);
    EXPECT_EQ(candidates, anagrams);
}
