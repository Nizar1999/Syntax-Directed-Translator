#include "Parser.h"

void Parser::expr() {
	term();
	while (true) {
		if (lookahead == '+') {
			match('+'); term(); print("+"); continue;
		}
		else if (lookahead == '-') {
			match('-'); term(); print("-"); continue;
		}
		else {
			break;
		}
	}
}

void Parser::term() {
	if (isdigit(lookahead)) {
		int tmp = lookahead;
		match(lookahead); print(std::to_string(tmp - '0'));
	}
	else {
		throw SyntaxError();
	}
}

void Parser::match(char symbol) {
	if (lookahead == symbol) {
		lookahead = static_cast<int>(textToParse[++lookaheadIndex]);
	}
	else {
		throw SyntaxError();
	}
}

void Parser::print(std::string outString) {
	std::cout << outString;
}