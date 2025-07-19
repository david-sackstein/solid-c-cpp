#pragma once

#if defined(_WIN32)
  #define EXPORTED __declspec(dllexport)
#else
  #define EXPORTED __attribute__((visibility("default")))
#endif
