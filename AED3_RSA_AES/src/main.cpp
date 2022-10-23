#include <iostream>
#include <chrono>
#include <ctime>
#include <fstream>
#include <vector>
#include <iomanip>


int main(int argc, char** argv)
{
	std::string file_name;
	if (argc < 2) file_name = "decoded-20221023004659.bin";
	else file_name = argv[1];
	std::ifstream solution(file_name, std::ios::binary);
	std::vector<unsigned char> binary_content(std::istreambuf_iterator<char>(solution), {});

	for (int i = 0; i < binary_content.size(); i++)
	{
		std::cout << std::setw(2) << std::setfill('0') << std::hex << (int)binary_content[i];
	}
	std::cin.get();
	return 0;
}
