#include "Tokenizer.h"


namespace Interpeter
{
	namespace Tokenizer
	{
		
		TOKENIZER_STATUS tokenizer(char *path)
		{
			ifstream sourceFile;
			char * source;
			ifstream::pos_type size;
			sourceFile.open(path, ios::in|ios::binary|ios::ate);
			if(sourceFile.is_open())
			{
				size = sourceFile.tellg();
				source = new char [(int)size + 1];
				sourceFile.seekg(0, ios::beg);
				sourceFile.read(source, size);
				sourceFile.close();
				return readSource(source);
			}
			else
				return TE1;
		}

		Token::Token(TOKEN_TYPE type, string value)
		{
			this->_type = type;
			this->_value = value;
		}

		TOKENIZER_STATUS readSource(char *source)
		{
			bool inlineComment = false,
				comment = false,
				writeWord = false,
				inString = false;
			
			string world = "";
			
			vector<Token> tokenList;

			for(unsigned long i = 0; i < strlen(source); i++)
			{
				if(inlineComment)
				{
				
				}
				else if(comment)
				{
				
				}
				else if(!writeWord)
				{
					if(	source[i] == ' ' )
						continue;
					if( source[i] >= 'a' || source[i] <= 'z' || source[i] >= 'A' || source[i] <= '>' || source[i] >= '0' || source[i] <= '9' )
					{
						writeWord = true;
						world += source[i];
					}
					else if( source[i] == '(')
					{
						tokenList.push_back(Token(TOKEN_METHOD_OPEN, ""));
					}
					else if( source[i] == ')')
					{
						tokenList.push_back(Token(TOKEN_METHOD_CLOSE, ""));
					}
					else if( source[i] == '{')
					{
						tokenList.push_back(Token(TOKEN_SCOPE_OPEN, ""));
					}
					else if( source[i] == '}')
					{
						tokenList.push_back(Token(TOKEN_SCOPE_CLOSE, ""));
					}
					else if( source[i] == '=')
					{
						tokenList.push_back(Token(TOKEN_ASSIGNMENT, ""));
					}
					else if( source[i] == ';' ||  source[i] == '\n')
					{
						tokenList.push_back(Token(TOKEN_TERMINATOR, ""));
					}
					else if( source[i] == '/' && source[i+1] == '/')
					{
						inlineComment = true;
					}
					else
						return TE2;	//	Character not accepted
				}
				else
				{
					if( source[i] >= 'a' || source[i] <= 'z' || source[i] >= 'A' || source[i] <= '>' || source[i] >= '0' || source[i] <= '9' )
					{
						world += source[i];
					}
					else
					{
						tokenList.push_back(Token(TOKEN_WORLD,world));
						world = "";
						writeWord = false;

						if(	source[i] == ' ' )
							continue;
						else if( source[i] == '(')
						{
							tokenList.push_back(Token(TOKEN_METHOD_OPEN, ""));
						}
						else if( source[i] == ')')
						{
							tokenList.push_back(Token(TOKEN_METHOD_CLOSE, ""));
						}
						else if( source[i] == '{')
						{
							tokenList.push_back(Token(TOKEN_SCOPE_OPEN, ""));
						}
						else if( source[i] == '}')
						{
							tokenList.push_back(Token(TOKEN_SCOPE_CLOSE, ""));
						}
						else if( source[i] == '=')
						{
							tokenList.push_back(Token(TOKEN_ASSIGNMENT, ""));
						}
						else if( source[i] == ';' ||  source[i] == '\n')
						{
							tokenList.push_back(Token(TOKEN_TERMINATOR, ""));
						}
						else
							return TE2;	//	Character not accepted
					}
				}
			}
			return TE0;
		}



	}
}