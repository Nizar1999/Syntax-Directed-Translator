#include "Parser.h"

void Parser::expr() {
	term();
	rest();
}

void Parser::rest() {
	if (lookahead == '+') {
		match('+'); term(); print("+"); rest();
	}
	else if (lookahead == '-') {
		match('-'); term(); print("-"); rest();
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