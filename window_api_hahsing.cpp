#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>

int main() {
	//Declaring variables
	int numWinApi;


	std::cout << "Enter the Windows Api you wish to hash";
	std::cin >> numWinApi;

	std::vector<std::string> winApiList;
	std::string tempWinApi;
	
	std::cin.ignore();

	std::cout << "Please enter the " << numWinApi << " windows API you wish to hash: " << std::endl;

	//gets users input
	for (int i = 0; i < numWinApi; ++i) {
		std::cout << "Windows API " << i + 1 << ": ";
		std::getline(std::cin, tempWinApi);
		winApiList.push_back(tempWinApi);
	}

	for (const auto& wins : winApiList) {
		int iteration = 0;
		unsigned int hash = 0x35;

		for (char eachChar : wins) {
			//converts to ascii
			iteration++;
			int asciiValue = static_cast<int>(eachChar);

			//hashing algorithm
			hash += (hash * 0xab10f29f + asciiValue) & 0xffffff;

			std::cout << "Iteration " << iteration << " : " << eachChar
				<< " :0x" << std::hex << asciiValue << " :0x" << hash << std::dec
				<< std::endl;
		}

		//displays result
		std::cout << "Final Hash for " << wins << ": 0x" << std::setfill('0')
			<< std::setw(8) << std::hex << hash << std::dec << std::endl;

	}
	return 0;
}