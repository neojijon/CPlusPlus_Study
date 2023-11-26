#include <iostream>
#include <string>
#include <regex>

int main() {
    const std::string fnames[] = { "foo.txt", "bar_95.txt", "baz.dat", "test.jpg",
                                   "foo21.txt", "zoidberg.png" };
    //const std::regex regex((R"(([a-z]+\w*)\.(txt|dat)$)");
    const std::regex regex("([a-z]+[a-zA-Z0-9_]*)\\.(txt|dat)$");
    std::smatch pieces_match;

    for (const auto& fname : fnames) {
        if (std::regex_match(fname, pieces_match, regex)) {
            std::cout << fname << std::endl;
            for (size_t i = 0; i < pieces_match.size(); ++i) {
                std::ssub_match sub_match = pieces_match[i];
                std::string piece = sub_match.str();
                std::cout << "\tsubmatch " << i << ": " << piece << std::endl;
            }
        }
    }
	return 0;
}