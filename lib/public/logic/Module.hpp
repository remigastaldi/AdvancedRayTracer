#pragma once

namespace ART {
namespace Logic {
namespace Modules {

template <class T>
class Module {
public:
  Module(T *module = nullptr) : _module{module} {};

  T *get() noexcept { return _module; }

  T * operator->();

private:
  T *_module;
};

template <typename T>
T * Module<T>::operator->() {
  return _module;
}

}
}
}