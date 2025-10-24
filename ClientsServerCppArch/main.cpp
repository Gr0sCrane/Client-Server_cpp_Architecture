#include <iostream>
#include "Common/network.h"

using namespace Net;

int main() {

	if (Network::initialize()) {
		std::cout << "Success" << "\n";
	}
	Network::shutDown();
	return 0;
}