#include <cerrno>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

std::string replaceString(std::string subject, std::string search, std::string replace) {
    if (search.empty()) return subject;
    std::string result;
    size_t pos = 0;
    size_t found_pos = subject.find(search, pos);

    while (found_pos != std::string::npos) {
        result.append(subject, pos, found_pos - pos);
        result += replace;
        pos = found_pos + search.length();
        found_pos = subject.find(search, pos);
    }
    result += subject.substr(pos);
    return (result);
}

int main(int argc, char** argv) {
    std::ifstream infile;

    if (argc != 4) {
        std::cout << "usage: replace <file> old_word new_word" << std::endl;
        return (1);
    }
    infile.open(argv[1]);
    if (!infile.is_open()) {
        std::cout << "Error: " << argv[1] << ": ";

        if (errno == ENOENT)
            std::cout << "no such file or directory" << std::endl;
        else if (errno == EACCES)
            std::cout << "permission denied" << std::endl;
        else
            std::cout << "unknown error (" << errno << ")" << std::endl;
        return (1);
    }
    std::stringstream ss;
    ss << infile.rdbuf();
    std::string str = ss.str();
    infile.close();

    std::ofstream outfile((std::string(argv[1]) + ".replace").c_str());
    if (!outfile.is_open()) {
        std::cout << "Error: could not create output file" << std::endl;
        return (1);
    }
    std::string result = replaceString(str, argv[2], argv[3]);
    outfile << result;
    outfile.close();
    return (0);
}
