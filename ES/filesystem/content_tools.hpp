//
// Created by esevre on 2/2/2021.
//

#pragma once

#include <filesystem>

int directory_content_count(const std::filesystem::path &path, bool recursive = false);



int directory_content_count(const std::filesystem::path &path, bool recursive)
{
    namespace fs = std::filesystem;
    int size = 0;
    if (recursive) {
        for (const auto &p : fs::recursive_directory_iterator(path))
        {
            ++size;
        }
    } else {
        for (const auto &p : fs::directory_iterator(path))
        {
            ++size;
        }
    }
    return size;
}

