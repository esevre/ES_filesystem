#include <iostream>

#include <filesystem>

#include <fstream>

int directory_content_count(const std::filesystem::path &path, bool recursive = false);
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

int main()
{
    namespace fs = std::filesystem;
//    fs::path path(argv[0]);
//    std::cout << "path: " << path << '\n';

    auto cwd = fs::current_path();
    print_directory_contents(cwd);

    std::cout << "************************\n\n";

    fs::path parent = get_parent_directory(cwd);
    print_directory_contents(parent);

    std::cout << "************************\n\n";
    print_directory_contents(parent, true);



    return 0;
}


