#include <fstream>
#include <iostream>
#include <string>
#include <sys/_types/_size_t.h>
#include <system_error>

void replace(std::string word, std::string replaceWord, std::ifstream &ifs,
             std::ofstream &ofs) {
  std::string line;
  size_t pos;
  while (!ifs.eof()) {
    std::getline(ifs, line);
    while (1) {
      pos = line.find(word);
      if (pos >= line.length()) {
        ofs << line;
        break;
      } else {
        ofs << line.substr(0, pos);
        line = line.substr(pos + word.length());
        ofs << replaceWord;
      }
    }
    if (ifs.peek() != EOF)
      ofs << std::endl;
  }
  ofs << std::endl;
}

int main(int ac, char **av) {
  if (ac != 4) {
    std::cerr << "Error" << std::endl
              << "invalid number or arguments" << std::endl
              << "<filename> <s1> <s2>" << std::endl;
    return 1;
  }
  std::string file;
  file = av[1];
  std::ifstream ifs;
  std::ofstream ofs;
  ifs.open(file);
  if (ifs.is_open() == false) {
    std::cerr << "can't open input stream on file " << file << std::endl;
    return 1;
  }
  ofs.open(file.append(".replace"));
  if (ifs.is_open() == false) {
    std::cerr << "can't open output stream on file " << file << std::endl;
    return 1;
  }
  replace(av[2], av[3], ifs, ofs);
  return 0;
}
