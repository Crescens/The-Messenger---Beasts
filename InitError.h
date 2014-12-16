#pragma once
#include<SDL.h>
#include<exception>
#include<string>

class InitError :
	public std::exception
{
public:
	InitError(void);
	InitError(const std::string&);
	virtual ~InitError() throw();
	virtual const char* what() const throw();
private:
		std::string msg;
};




