#include "LinkedHashMap.hpp"

 
   template <typename Key, typename Value, typename Hash>
   LinkedHashMap<Key, Value, Hash>::Node::Node(const Key& key, const Value& value)
        : key_(key), value_(value), next_(nullptr), prev_(nullptr) {}


  template <typename Key, typename Value, typename Hash>
  LinkedHashMap<Key, Value, Hash>::LinkedHashMap(Hash hash) : hash_(hash), size_(0) {}

  template <typename Key, typename Value, typename Hash>
  [[nodiscard]]
  inline auto LinkedHashMap<Key, Value, Hash>::operator[](const Key& key) -> Value& {
    auto it = map_.find(key);
    if (it == map_.end()) {
      insert({ key, Value() });
      it = map_.find(key);
    }
    return it->second->data.second;
  }

  template <typename Key, typename Value, typename Hash>
  [[nodiscard]]
  auto LinkedHashMap<Key, Value, Hash>::operator[](const Key& key) const -> Value& {
    auto it = map_.find(key);
    if (it == map_.end()) {
      throw std::out_of_range("Key not found in LinkedHashMap");
    }
    return it->second->data.second;
  }

  template <typename Key, typename Value, typename Hash>
  auto inline LinkedHashMap<Key, Value, Hash>::Insert(const Key& key, const Value& value) noexcept -> void {
    auto it = map_.find(key);
    if (it != map_.end()) {
      it->second->value_ = value;
      return;
    }
    auto node = std::make_unique<Node>(key, value);
    list_.push_back(node.get());
    map_[key] = std::move(node);
    ++size_;
  }

  template <typename Key, typename Value, typename Hash>
  auto inline LinkedHashMap<Key, Value, Hash>::Remove(const Key& key) -> void {
    auto it = map_.find(key);
    if (it == map_.end()) {
      return;
    }

    auto node = std::move(it->second);
    list_.erase(list_.iterator_to(*node));
    map_.erase(it);
    --size_;
  }

  template <typename Key, typename Value, typename Hash>
  [[nodiscard]]
  inline auto LinkedHashMap<Key, Value, Hash>::Get(const Key& key, const Value& default_value) const -> Value {
    auto it = map_.find(key);
    if (it == map_.end()) {
      return default_value;
    }
    return it->second->value_;
  }

  template <typename Key, typename Value, typename Hash>
  [[nodiscard]]
  inline auto LinkedHashMap<Key, Value, Hash>::Size() -> std::size_t const {
    return size_;
  }

  // Iterator class for iterating over the elements of the map.
    template <typename Key, typename Value, typename Hash>
    LinkedHashMap<Key, Value, Hash>::Iterator::Iterator(typename std::list<Node*>::iterator it) : it_(it) {}

    template <typename Key, typename Value, typename Hash>
    [[nodiscard]]
    inline auto LinkedHashMap<Key, Value, Hash>::Iterator::operator++() -> Iterator& {
      ++it_;
      return *this;
    }

    template <typename Key, typename Value, typename Hash>
    [[nodiscard]]
    inline auto LinkedHashMap<Key, Value, Hash>::Iterator::operator!=(const Iterator& other) const -> bool {
        return it_ != other.it_;
    }

    template <typename Key, typename Value, typename Hash>
    [[nodiscard]]
    inline auto LinkedHashMap<Key, Value, Hash>::Iterator::operator*() const -> Value {
      return (*it_)->value_;
    }

    template <typename Key, typename Value, typename Hash>
    [[nodiscard]]
    inline auto LinkedHashMap<Key, Value, Hash>::Iterator::operator++(int) -> Iterator {
      Iterator tmp(*this);
      ++(*this);
      return tmp;
    }

    template <typename Key, typename Value, typename Hash>
    [[nodiscard]]
    inline auto LinkedHashMap<Key, Value, Hash>::Iterator::operator--() -> Iterator& {
      --it_;
      return *this;
    }

    template <typename Key, typename Value, typename Hash>
    [[nodiscard]]
    inline auto LinkedHashMap<Key, Value, Hash>::Iterator::operator--(int) -> Iterator {
      Iterator tmp(*this);
      --(*this);
      return tmp;
    }


  // Returns an iterator pointing to the first element in the map.
  template <typename Key, typename Value, typename Hash>
  inline auto LinkedHashMap<Key, Value, Hash>::begin() -> Iterator {
    return Iterator(list_.begin());
  }

  // Returns an iterator pointing to one past the last element in the map.
  template <typename Key, typename Value, typename Hash>
  inline auto LinkedHashMap<Key, Value, Hash>::end() -> Iterator {
    return Iterator(list_.end());
  }