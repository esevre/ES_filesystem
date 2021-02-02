//
// Created by esevre on 2/2/2021.
//

#pragma once

auto get_parent_directory(const std::filesystem::path &path);


auto get_parent_directory(const std::filesystem::path &path)
{
    auto path_depth = std::distance(path.begin(), path.end());
    std::filesystem::path parent;
    auto pos = path.begin();
    for (int i = 0; i < path_depth - 1; ++i, ++pos) {
        parent /= *pos;
    }
    return parent;
}



