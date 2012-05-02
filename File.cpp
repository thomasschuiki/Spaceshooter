/*
 * File.cpp
 *
 *  Created on: Apr 11, 2012
 *      Author: thomas
 */

#include "File.h"
#include <stdlib.h>

bool File::Open(const std::string& filename) {
	m_ifstream.open(filename.c_str(), std::ios::in);
	return m_ifstream.good();
}

//use getstring to read the string and atoi to get the value as an int
bool File::GetInt(int* pInt) {
	std::string s;
	if(!GetString(&s)){
		return false;
	}
	*pInt = atoi(s.c_str());
	return true;
}

bool File::GetFloat(float* pFloat) {
	m_ifstream >> (*pFloat);
	return true;
}

bool File::GetString(std::string* pString) {
	char buf[10000];
	while(true){
		if (EndOfFile()) {
			return false;
		}

		m_ifstream.getline(buf,10000);
		*pString = buf;

		if (pString->size() > 0 && (*pString)[0] == '#') {
			continue;
		}
		if (!pString->empty()) {
			return true;
		}
	}
	return false;
}

bool File::EndOfFile() const {
	return m_ifstream.eof() || !m_ifstream.good();
}


