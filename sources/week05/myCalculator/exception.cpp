#include "Header_files\exception.h"

exception::exception(const std::string& s) {
  m_what = s;
}

const char* exception::what() {
  return m_what.c_str();
}
