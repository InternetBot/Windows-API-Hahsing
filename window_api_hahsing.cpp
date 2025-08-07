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
		for (char eachChar : wins) {
			//converts to ascii
			int asciiValue = static_cast<int>(eachChar);

			//converts ascii -> hex
			std::stringstream ws;
			ws << std::hex << asciiValue;
			std::string hexValue = ws.str();

		}

	}
	return 0;
}