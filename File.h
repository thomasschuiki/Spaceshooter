/*
 * File.h
 *
 *  Created on: Apr 11, 2012
 *      Author: thomas
 */

#ifndef FILE_H_
#define FILE_H_

#include <fstream>

class File {
public:
	bool Open(const std::string& filename);
	bool GetInt(int* pInt);
	bool GetFloat(float* pFloat);
	bool GetString(std::string* pString);
	bool EndOfFile() const;
private:
	std::ifstream m_ifstream;
};

#endif /* FILE_H_ */
