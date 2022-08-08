#pragma once

/*
	Syntax-directed translation scheme:
	expr	 -> term rest
	
	rest -> + term {print("+")} rest
	rest -> - term {print("-")} rest
	rest -> ε

	term -> 0 {print("0")}
		...
	term -> 9 {print("9")}

	Non-terminals: expr, rest, term
	
	Rest procedure optimized into while loop in expr()
*/

#include <string>
#include <iostream>
#include <exception>

class SyntaxError : public std::exception {
	const char* what() const throw() {
		return "Syntax Error";
	}
};

class Parser
{
private:
	std::string textToParse;
	int lookahead;
	int lookaheadIndex;

private:
	//Non-terminals
	void term();

	//Utility
	void match(char symbol);
	void print(std::string out);

public:
	Parser(std::string expression) {
		lookaheadIndex = 0;
		textToParse = expression;
		lookahead = static_cast<int>(textToParse[lookaheadIndex]);
	}

	//Start Non-terminal
	void expr();
};

