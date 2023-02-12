#pragma once
#include "String.h"

class Page {
	String Text;
	int Page_no;
public:
	Page(String = "", int = 0);
	void setText(const String);
	void setPageNo(const int);
	String getText() const;
	int getPageNo() const;
};