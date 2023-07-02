#ifndef LRU_CACHE_H
#define LRU_CACHE_H

template <typename K, typename V> class LRU {
public:
  LRU() {}

  void update(K key, V value) {}

  V *get(K key) {}

private:
  int length;
};

#endif
