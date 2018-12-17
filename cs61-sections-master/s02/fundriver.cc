#include <sstream>
#include <iostream>
#include <stdlib.h>

int fun(const char* s);

static void yay() {
    std::cout << "🎉🎉🎉🎉🎊🎊🎊🎊🌽🌽🌽🎊🎊🎊🎊🎉🎉🎉🎉\n";
    std::cout << "                 FUN\n";
    std::cout << "🎉🎉🎉🎉🎊🎊🎊🎊🌽🌽🌽🎊🎊🎊🎊🎉🎉🎉🎉\n";
    exit(0);
}

static void boo() {
    std::cerr << "😿😿😿😿😿😿😿😿 no fun 😿😿😿😿😿😿😿😿\n";
    exit(1);
}

int main(int argc, char** argv) {
    // make a string from all the arguments
    std::string argstr;
    {
        std::stringstream sbuf;
        for (int i = 1; i < argc; ++i) {
            sbuf << (i == 1 ? "" : " ") << argv[i];
        }
        argstr = sbuf.str();
    }

    // call `fun`, and celebrate if it succeeds
    if (fun(argstr.c_str()) == 0) {
        yay();
    } else {
        boo();
    }
}
