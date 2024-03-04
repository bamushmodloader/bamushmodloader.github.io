#include <iostream>
#include <vector>
#include <filesystem>

using str = std::string;

str getHomeDirectory() {
    const char* homedir = std::getenv("HOME");
    if (homedir == nullptr) {
        return ".";
    } else {
        return homedir;
    }
}

std::vector<str> argvify(int argc, char **argvcstr) {
    std::vector<str> argv;
    for (int i = 0; i < argc; i++) {
        argv.push_back(argvcstr[i]);
    }
    return argv;
}

int main(int argc, char **argvcstr) {
    std::vector<str> argv = argvify(argc, argvcstr);

    if (argv[0] == argv[0]) {
        if (argc == 1) {
            std::cout << "Must specify an option\n";
        }
        if (argc == 2) {
            if (argv[1] == "--version" || argv[1] == "-v") {
                std::cout << "Alpha 0.1.0 (C++17, C++20)";
            } else if (argv[1] == "--mods" || argv[1] == "-m") {
                str directory_path = ((getHomeDirectory()) + "/.bamush/bml/mods");
                for (const auto& entry : std::filesystem::directory_iterator(directory_path)) {
                    if (std::filesystem::is_directory(entry)) {
                        std::cout << entry.path().filename().string() << std::endl;
                    }
                }
            }
        }
    }

    return 0;

}
