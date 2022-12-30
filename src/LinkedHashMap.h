#ifndef LINKED_HASH_MAP_H
#define LINKED_HASH_MAP_H

#include <iostream>
#include <unordered_map>
#include <list>
#include <memory>
#include <list>
#include <stdexcept>

template <typename Key, typename Value, typename Hash = std::hash<Key>>
class LinkedHashMap {
 public:
  class Node {
   public:
    Node(const Key& key, const Value& value);

    Key key_;
    Value value_;
    mutable std::unique_ptr<Node> next_;
    mutable std::unique_ptr<Node> prev_;

    ~Node() = default;
  };

  LinkedHashMap(Hash hash = Hash());

  //~LinkedHashMap() = default;

  [[nodiscard]]
  inline auto operator[](const Key& key) -> Value&;

  [[nodiscard]]
  auto operator[](const Key& key) const -> Value&;

  auto inline Insert(const Key& key, const Value& value) noexcept -> void;

  auto inline Remove(const Key& key) -> void;

  [[nodiscard]]
  inline auto Get(const Key& key, const Value& default_value = Value()) const -> Value;

  [[nodiscard]]
  inline auto Size() -> std::size_t const;

  // Iterator class for iterating over the elements of the map.
  class Iterator {
   public:
    Iterator(typename std::list<Node*>::iterator it);

    [[nodiscard]]
    inline auto operator++() -> Iterator&;

    [[nodiscard]]
    inline auto operator!=(const Iterator& other) const -> bool;
    [[nodiscard]]
    inline auto operator*() const -> Value;

    [[nodiscard]]
    inline auto operator++(int) -> Iterator;

    [[nodiscard]]
    inline auto operator--() -> Iterator&;

    [[nodiscard]]
    inline auto operator--(int) -> Iterator;

    private:
        typename std::list<Node*>::iterator it_;
  };

  // Returns an iterator pointing to the first element in the map.
  inline auto begin() -> Iterator;

  // Returns an iterator pointing to one past the last element in the map.
  inline auto end() -> Iterator;

  private:
    std::size_t size_;
    std::unordered_map<Key, Node*> map_;
    std::list<Node> list_;
    std::hash<Key> hash_;
};

#endif