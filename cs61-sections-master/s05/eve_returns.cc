#include <fstream>
#include <iostream>
#include <string>

#include <unistd.h>
#include <sys/stat.h>

int main() {
    std::cout << "Ha! You thought I was done!" << std::endl;

    std::string filename("not_evil.sh");
    std::ofstream out(filename);
    out << "sleep 0.3" << std::endl;
    out << ">&2 echo \"This is an innocent program counting down: $1!\"" << std::endl;
    out << "if [ $1 -le 1 ]; then echo $1 > fib/fib$1; exit; fi" << std::endl;
    out << "sh " << filename << " $(($1-1)) &" << std::endl;
    out << "sh " << filename << " $(($1-2)) &" << std::endl;
    out << "wait" << std::endl;
    out << "n1=$(cat fib/fib$(($1-1)))" << std::endl;
    out << "n2=$(cat fib/fib$(($1-2)))" << std::endl;
    out << ">&2 echo \"fib($1) = $(($n1+$n2))\"" << std::endl;
    out << "echo $(($n1+$n2)) > fib/fib$1" << std::endl;
    out.close();

    mkdir("fib", S_IRWXU);

    std::cout << execlp("sh", "sh", filename.c_str(), "15", nullptr);

    std::cout << "Ha-ha! You can't see this message!!!" << std::endl;

    return 61;
}
