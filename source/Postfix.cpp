#include "Parser.h"

int main() {
	std::string expression;
	std::getline(std::cin, expression);
	Parser parse(expression);
	
	try {
		parse.expr();
	}
	catch (std::exception& e) {
		std::cout << e.what();
	}

	return 0;
}