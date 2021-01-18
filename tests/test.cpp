// Copyright 2020 Kavykin Andrey Kaviandr@yandex.ru

#include <gtest/gtest.h>

#include "file_analizer.hpp"

std::string current_dir(const std::string& name) {
  std::string s(__FILE__);
  for (size_t i = 0; i < 8; ++i) {
    s.pop_back();
  }
  return s + name;
}
TEST(view_directory, empty_path) {
  view_directory vd("");
  std::stringstream ss1 = vd.print_files();
  std::stringstream ss2 = vd.print_acc();
  EXPECT_EQ(ss1.str(), "");
  EXPECT_EQ(ss2.str(), "");
}
TEST(view_directory, first_test) {
  std::string path(current_dir("first_test"));
  view_directory vd(path);
  std::stringstream ss1 = vd.print_files();
  std::stringstream ss2 = vd.print_acc();
  EXPECT_EQ(ss1.str(), "ib balance_00122223_20180902.txt\n");
  EXPECT_EQ(ss2.str(),
            "broker:ib account:00122223 files:1 lastdate:20180902\n");
}
TEST(view_directory, secons_twst) {
  std::string path(current_dir("second_test"));
  view_directory vd(path);
  std::stringstream ss1 = vd.print_files();
  std::stringstream ss2 = vd.print_acc();
  EXPECT_EQ(ss1.str(),
            "bcs balance_00122223_20180901.txt\n"
            "otkr balance_03934535_20180901.txt\n"
            "otkr balance_03934535_20180903.txt\n");
  EXPECT_EQ(ss2.str(),
            "broker:bcs account:00122223 files:1 lastdate:20180901\n"
            "broker:otkr account:03934535 files:2 lastdate:20180903\n");
}
TEST(view_directory, third_test) {
  std::string path(current_dir("third_test"));
  view_directory vd(path);
  std::stringstream ss1 = vd.print_files();
  std::stringstream ss2 = vd.print_acc();
  EXPECT_EQ(ss1.str(), "ib balance_00122223_20180902.txt\n");
  EXPECT_EQ(ss2.str(),
            "broker:ib account:00122223 files:1 lastdate:20180902\n");
}
