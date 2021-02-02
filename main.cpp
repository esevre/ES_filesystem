#include <iostream>

#include <filesystem>

#include <fstream>

#include "ES/filesystem/content_tools.hpp"
#include "ES/filesystem/navigation_tools.hpp"
#include "ES/filesystem/printing_tools.hpp"


int main()
{
    namespace fs = std::filesystem;


    auto cwd = fs::current_path();
    print_directory_contents(cwd);

    std::cout << "************************\n\n";

    fs::path parent = get_parent_directory(cwd);
    print_directory_contents(parent);

    std::cout << "************************\n\n";
    print_directory_contents(parent, true);



    return 0;
}


