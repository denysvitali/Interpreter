#pragma once

#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

namespace Interpeter
{
	namespace Tokenizer
	{

		enum TOKENIZER_STATUS { 
			TE0,	//	Status OK
			TE1,	//	Source code not exist
			TE2,	//	Character not accepted
		};

		TOKENIZER_STATUS tokenizer(char *path);
		TOKENIZER_STATUS readSource(char *source);


		enum TOKEN_TYPE {
			TOKEN_WORLD,		//	nome
			TOKEN_METHOD_OPEN,	//	(
			TOKEN_METHOD_CLOSE,	//	)
			TOKEN_SCOPE_OPEN,	//	{
			TOKEN_SCOPE_CLOSE,	//	}
			TOKEN_ASSIGNMENT,	//	=
			TOKEN_TERMINATOR,	//	\n ;
			TOKEN_OPERATOR,		// + - * / 
		};

		class Token
		{
		public:
			Token(TOKEN_TYPE type, string value);
		private:
			TOKEN_TYPE _type;
			string _value;
		};

	}
}