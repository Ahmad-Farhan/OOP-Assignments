#include "Page.h"

Page::Page(String text, int pg)
{
	Text = text;
	Page_no = pg;
}

void Page::setText(const String text)
{
	this->Text = text;
}

void Page::setPageNo(const int pg)
{
	this->Page_no = pg;
}

String Page::getText() const
{
	return Text;
}

int Page::getPageNo() const
{
	return Page_no;
}