//
// Created by esevre on 2/2/2021.
//

#pragma once

#include <iostream>
#include "content_tools.hpp"

void print_directory_contents(const std::filesystem::path &path, bool recursive = false);

void print_directory_contents(const std::filesystem::path &path, bool recursive = false)
{
    namespace fs = std::filesystem;
    std::cout << "Contents of : " << path << "\n";
    std::cout << directory_content_count(path) << " entries found\n";
    if (recursive) {
        for (auto & p : fs::recursive_directory_iterator(path)) {
            std::cout << p.path() << '\n';
        }
    } else {
        for (auto & p : fs::directory_iterator(path)) {
            std::cout << p.path() << '\n';
        }
    }
}

