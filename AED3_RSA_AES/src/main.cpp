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

	// hashcat -m(hash type - SHA2-256) 1400 -a(attack mode - Brute Force) 3 -d(device - GPU) 2 
	// 6d00863e4fd4be846d2f3817635e9b0a8a08c4f5b1243a6a8d215dd2f97bbbd3 yo?l?l?l?l?l?l?l?l -i(increment) 
	// -o(output file) decripted_hash.txt -O(optmized) 

	// hashcat -m 1400 -a 3 -d 2 6d00863e4fd4be846d2f3817635e9b0a8a08c4f5b1243a6a8d215dd2f97bbbd3 yo?l?l?l?l?l?l?l?l?l?l -o decripted_hash.txt -O

	return 0;
}
