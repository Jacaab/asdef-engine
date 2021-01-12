#ifndef MYENGINE_EXCEPTION_H
#define MYENGINE_EXCEPTION_H

#include <exception>
#include <string>

namespace myengine
{
	// exception error 
struct Exception : public std::exception
{
	//hault the program with a message for referance
  Exception(const std::string& message);
  virtual ~Exception() throw();
  virtual const char* what() const throw();

private:
  std::string message;	// this could maybe be used for better debugging. log this into a txt file for easier end user debugging
};						// might need to take in extra parameters like where the exception was called from.

}

#endif