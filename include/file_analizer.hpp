// Copyright 2020 Kavykin Andrey Kaviandr@yandex.ru

#ifndef INCLUDE_FILE_ANALIZER_
#define INCLUDE_FILE_ANALIZER_

#include <boost/filesystem.hpp>
#include <iomanip>
#include <iostream>
#include <regex>
#include <set>
#include <sstream>
#include <string>
#include <vector>

namespace fs = boost::filesystem;

class view_directory {
 public:
  explicit view_directory(const std::string& path);
  std::stringstream print_files();
  std::stringstream print_acc() const;

 private:
  fs::path path_;
  std::set<std::string> accounts;
  std::vector<fs::path> paths;
};

#endif  // INCLUDE_FILE_ANALIZER_