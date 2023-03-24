#include <iostream>
#include <fstream>

int main() {
    std::ifstream ifs("numbers");
    unsigned int dst;
    unsigned int dst2;
    ifs >> dst >> dst2;

    std::cout << dst << " " << dst2 << std::endl;
    ifs.close();

    std::ofstream ofs("test.out");
    ofs << "Hello Word " << std::endl << "because I'm really not in a creative mood" << std::endl;
    ofs.close();
    return 0;
}