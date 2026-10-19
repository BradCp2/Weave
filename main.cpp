#include <iostream>
#include <vector>
#include <string>
#include "src/WeaveApp.h"

int main(int argc, char* argv[]) {
    std::vector<std::string> tokens(argv, argv + argc);
    weave::WeaveApp weaveApp;
    return weaveApp.run(tokens);
}