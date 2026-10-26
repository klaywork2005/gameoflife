#include <iostream>

template <typename T>
T cubeThrough(T &value);

int main() {
  double value = 1.8;
  std::cout << "My final value running the function was: " << cubeThrough(value)
            << '\n';
  return 0;
}

template <typename T>
T cubeThrough(T &value) {
  int index = 0;
  while (index < 5) {
    value = value * value * value;
    index++;
  }
  return value;
}
