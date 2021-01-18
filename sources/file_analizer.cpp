// Copyright 2020 Kavykin Andrey Kaviandr@yandex.ru

#include "file_analizer.hpp"

const size_t account_pos = 8;
const size_t time_pos = 17;
const size_t pos_length = 8;

view_directory::view_directory(const std::string& path) {
  if (!path.empty()) {
    if (fs::exists(path)) {
      path_ = path;
    }
  } else {
    path_ = fs::current_path();
  }
}
std::stringstream view_directory::print_files() {
  std::stringstream ss;
  const std::regex re("^(balance)_\\d{8}_\\d{8}");
  for (const fs::directory_entry& x : fs::directory_iterator{path_}) {
    if (fs::is_directory(x.path())) {
      for (const fs::directory_entry& y : fs::directory_iterator{x.path()}) {
        if (y.path().extension() == ".txt" &&
            y.path().stem().extension() == "" &&
            std::regex_search(y.path().stem().string(), re)) {
          ss << std::left << y.path().parent_path().filename().string() << " "
             << y.path().filename().string() << std::endl;
          paths.push_back(y.path());
          accounts.insert(
              y.path().stem().string().substr(account_pos, pos_length));
        }
      }
    }
  }
  return ss;
}
std::stringstream view_directory::print_acc() const {
  std::stringstream ss;
  for (const auto& x : accounts) {
    fs::path max;
    size_t n = 0;
    for (const auto& y : paths) {
      if (x == y.stem().string().substr(account_pos, pos_length)) {
        if ((n < 1) ||
            (y.stem().string().substr(time_pos, pos_length) >
             max.stem().string().substr(time_pos, pos_length))) {
          max = y;
        };
        ++n;
      }
    }
    ss << "broker:" << max.parent_path().filename().string() << " account:"
       << max.stem().string().substr(account_pos, pos_length)
       << " files:" << n << " lastdate:"
       << max.stem().string().substr(time_pos, pos_length) << std::endl;
  }
  return ss;
}
