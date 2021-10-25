#include <string>

class exception {
  std::string m_what;
public:
  exception(const std::string& s);
  const char* what();
};
