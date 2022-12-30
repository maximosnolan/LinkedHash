#include <iostream>
#include <unordered_set>
#include <list>
#include <memory>
#include <list>
#include <stdexcept>

template <typename Value, typename Hash = std::hash<Value>>
class LinkedHashSet {
 public:
  // Node class represents a node in the linked list.
 class Node {
   public:
    explicit Node(const Value& value) : value_(value), next_(nullptr), prev_(nullptr) {}

    Value value_;
    std::unique_ptr<Node> next_;
    std::unique_ptr<Node> prev_;
  };

  explicit LinkedHashSet(Hash hash = Hash()) : hash_(hash), size_(0) {}

  // Inserts a new element with the given value into the set.
  inline auto Insert(const Value& value) -> void {
    // Check if the element already exists in the set.
    if (set_.find(value) != set_.end()) {
      return;
    }

    // Create a new node for the element and insert it into the set and list.
    auto node = std::make_unique<Node>(value);
    list_.push_back(node.get());
    set_.insert(value);
    ++size_;
  }

  // Removes the element with the given value from the set.
  inline auto Remove(const Value& value) -> void {
    // Look up the element in the set.
    auto it = set_.find(value);
    if (it == set_.end()) {
      // Element not found.
      return;
    }

    // Remove the element from the list and set.
    auto node = std::move(set_[value]);
    list_.erase(list_.iterator_to(*node));
    set_.erase(it);
    --size_;
  }

  // Returns true if the element with the given value is in the set, false
  // otherwise.
  bool Contains(const Value& value) const {
    return set_.find(value) != set_.end();
  }

  // Returns the number of elements in the set.
  size_t Size() const { return size_; }

  // Iterator class allows iteration over the elements of the set, in the order
  // they were inserted.
  class Iterator {
   public:
    Iterator(typename std::list<Node*>::iterator it) : it_(it) {}

    [[nodiscard]]
    inline auto operator++() -> Iterator& {
      ++it_;
      return *this;
    }

    [[nodiscard]]
    inline auto operator!=(const Iterator& other) const -> bool { 
        return it_ != other.it_; 
    }

    [[nodiscard]]
    inline auto operator*() const -> Value {
      return (*it_)->value_;
    }

    [[nodiscard]]
    inline auto operator++(int) -> Iterator {
      Iterator tmp(*this);
      ++(*this);
      return tmp;
    }

    [[nodiscard]]
    inline auto operator--() -> Iterator& {
      --it_;
      return *this;
    }

    [[nodiscard]]
    inline auto operator--(int) -> Iterator {
      Iterator tmp(*this);
      --(*this);
      return tmp;
    }

   private:
    typename std::list<Node*>::iterator it_;
  };

  Iterator begin() { return Iterator(list_.begin()); }

  Iterator end() { return Iterator(list_.end()); }

 private:
  std::unordered_set<Value, Hash> set_;
  std::list<Node*> list_;
  Hash hash_;
  std::size_t size_;
};
