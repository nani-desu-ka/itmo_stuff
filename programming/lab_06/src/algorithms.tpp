#pragma once

template<class beginning, class ending, class predicate>
bool all_of(beginning first, ending last, predicate temp_predicate) {
    while (first != last) {
        if (!temp_predicate(*first)) return false;
        first++;
    }
    return true;
}

template<class beginning, class ending, class predicate>
bool is_sorted(beginning first, ending last, predicate temp_predicate) {
    if (first != last) {
        beginning prev = first;
        while (++first != last) {
            if (!temp_predicate(*prev, *first)) return false;
            prev = first;
        }
    }
    return true;
}

template<class beginning, class ending, class predicate>
bool is_palindrome(beginning first, ending last, predicate temp_predicate) {
    if (first != last) {
        last--;
        while (first < last) {
            if (!temp_predicate(*first, *last)) return false;
            first++;
            last--;
        }
    }
    return true;
}