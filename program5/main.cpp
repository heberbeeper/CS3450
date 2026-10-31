#include "MyArray.h"
#include "FilterIterator.h"
#include "ReverseIterator.h"
#include "DistinctIterator.h"
#include <cassert>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

template<typename T>
void printIterator(Iterator<T>& it) {
    it.first();
    bool firstItem = true;
    while (!it.isDone()) {
        if (!firstItem) std::cout << ' ';
        std::cout << it.current();
        firstItem = false;
        it.next();
    }
    if (firstItem) std::cout << "(empty)";
    std::cout << '\n';
}

template<typename T>
std::vector<T> collect(Iterator<T>& it) {
    std::vector<T> result;
    it.first();
    while (!it.isDone()) { result.push_back(it.current()); it.next(); }
    return result;
}

//This Distinct Iterator skips any item equal to one it has already yielded and chain it with ReverseIterator


int main() {
    MyArray<int> numbers(6);
    for (int i = 1; i <= 6; ++i) numbers.add(i);
    auto even = [](const int& n) { return n % 2 == 0; };
    auto gtThree = [](const int& n) { return n > 3; };
    auto none = [](const int& n) { return n > 100; };
    auto filter = [](const int& n) {return (n % 2) && (n > 3); };

    std::cout << "Original sequence: ";
    auto original = numbers.getIterator();
    printIterator(*original);

    std::cout << "1. Filter(Filter): ";
    auto firstFilter = std::make_unique<FilterIterator<int>>(numbers.getIterator(), even);
    FilterIterator<int> twice(std::move(firstFilter), gtThree);
    printIterator(twice);
    assert((collect(twice) == std::vector<int>{4, 6}));

    std::cout << "2. Filter accepting nothing: ";
    FilterIterator<int> empty(numbers.getIterator(), none);
    printIterator(empty);
    assert(empty.isDone());
    assert(collect(empty).empty());

    std::cout << "3. Reverse: ";
    ReverseIterator<int> reverse(numbers.getIterator());
    printIterator(reverse);
    assert((collect(reverse) == std::vector<int>{6, 5, 4, 3, 2, 1}));

    std::cout << "4. Reverse(Filter): ";
    auto filtered = std::make_unique<FilterIterator<int>>(numbers.getIterator(), even);
    ReverseIterator<int> reverseFiltered(std::move(filtered));
    printIterator(reverseFiltered);
    assert((collect(reverseFiltered) == std::vector<int>{6, 4, 2}));

    std::cout << "5. Distinct(Filter) iterator skips any \n equal items and reverse iterator: ";
    MyArray<int> numbers2(7);

    numbers2.add(1);
    numbers2.add(2);
    numbers2.add(2);
    numbers2.add(3);
    numbers2.add(1);
    numbers2.add(4);
    numbers2.add(3);

    auto distinct = std::make_unique<DistinctIterator<int>>(
        numbers2.getIterator()
    );

    ReverseIterator<int> reversed(std::move(distinct));

    printIterator(reversed);

    MyArray<int> endReject(4);
    for (int n : {2, 4, 5, 7}) endReject.add(n);
    FilterIterator<int> trailing(endReject.getIterator(), even);
    assert((collect(trailing) == std::vector<int>{2, 4}));
    trailing.first();
    trailing.next();
    trailing.next();
    assert(trailing.isDone());

    MyArray<int> firstReject(4);
    for (int n : {1, 3, 4, 6}) firstReject.add(n);
    FilterIterator<int> leading(firstReject.getIterator(), even);
    assert(leading.current() == 4);
    assert((collect(leading) == std::vector<int>{4, 6}));

    MyArray<int> zero(0);
    ReverseIterator<int> reversedEmpty(zero.getIterator());
    assert(reversedEmpty.isDone());

    std::cout << "Edge case tests (rejected first/last, empty reverse): passed\n";
}
