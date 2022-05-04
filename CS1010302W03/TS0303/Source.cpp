//Name: ½²´ð¼ü
//Date: Mar 9, 2022
//Last update: Mar 9, 2022
//Problem statement: This C++ program output the input number with assigned format

#include <iostream>
#include <string>

int main() {
	std::string num;
	int totalLen, decimalLen;
	char character;

	while (std::cin >> num >> totalLen >> decimalLen >> character) {

		std::size_t pos = num.find(".");
		std::string decPart = "";
		std::string frontPart(num);

		//get the decimal part and the part in front of the decimal point (included)
		if (pos != std::string::npos) {
			decPart = num.substr(pos + 1);
			frontPart = num.substr(0, pos + 1);
		}

		if (decimalLen > 0) {

			//fill with 0 until decimal part meets the assigned length
			if (decimalLen > decPart.size()) {
				int len = decimalLen - decPart.size();
				if (decPart.size() == 0)
					frontPart += '.';
				for (int i = 0; i < len; i++) 
					decPart += '0';
			}
			//cut the redundant part, make decimal part meet the assigned length
			else if (decimalLen < decPart.size()) {
				decPart = decPart.substr(0, decimalLen);
			}
		}
		else {
			//clear redundant decimal part
			if (decPart.size() != 0) {
				frontPart.pop_back();
				decPart = "";
			}
		}
		
		//fill with the assigned character until it meets the total length
		int chaNum = totalLen - frontPart.size() - decPart.size();
		for (int i = 0; i < chaNum; i++) {
			std::cout << character;
		}

		std::cout << frontPart << decPart << std::endl;
	}
}