#ifndef MAP_H
#define MAP_H

template <typename K, typename V> class Map {
public:
  Map() {}

  V get(K key) {}

  void put(K key, V value) {}

  V *remove(K key) {}

  int size() {}
};

#endif