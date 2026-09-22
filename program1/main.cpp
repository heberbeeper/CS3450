#include "Queue.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <string>

template <typename T>
void displayAndEmptyQueue(Queue<T>& queue) {
    while (queue.size() > 0) {
        std::cout << queue.get() << " ";
        queue.remove();
    }

    std::cout << '\n';
}

int main() {

    auto vectorImpl = std::make_unique<VectorStorage<int>>();

    vectorImpl->addBack(999);   // Constructor should discard this.

    Queue<int> q(std::move(vectorImpl));

    assert(q.size() == 0);

    q.add(91);
    q.add(92);

    // get() should NOT remove the value.
    assert(q.get() == 91);
    assert(q.get() == 91);
    assert(q.size() == 2);

    auto listImpl = std::make_unique<ListStorage<int>>();

    listImpl->addBack(93);      // changeImpl should discard this.

    q.changeImpl(std::move(listImpl));

    assert(q.size() == 2);
    assert(q.get() == 91);

    q.add(94);
    q.add(95);

    std::cout << "Integer queue: ";
    displayAndEmptyQueue(q);

    auto stringListImpl =
        std::make_unique<ListStorage<std::string>>();

    stringListImpl->addBack("Discard Me");

    Queue<std::string> q2(std::move(stringListImpl));

    assert(q2.size() == 0);

    q2.add("91");
    q2.add("92");

    auto stringVectorImpl =
        std::make_unique<VectorStorage<std::string>>();

    stringVectorImpl->addBack("93");

    q2.changeImpl(std::move(stringVectorImpl));

    q2.add("94");
    q2.add("95");

    std::cout << "String queue: ";
    displayAndEmptyQueue(q2);

    q2.add("A");
    q2.add("B");

    assert(q2.size() == 2);

    q2.clear();

    assert(q2.size() == 0);

    std::cout << "All tests passed.\n";

    return 0;
}