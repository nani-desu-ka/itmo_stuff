#pragma once

template<class beginning, class ending, class predicate>
bool all_of(beginning, ending, predicate);

template<class beginning, class ending, class predicate>
bool is_sorted(beginning, ending, predicate);

template<class beginning, class ending, class predicate>
bool is_palindrome(beginning, ending, predicate);

#include "algorithms.tpp"