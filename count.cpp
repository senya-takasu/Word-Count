#include "count.h"
#include<iostream>
//输出框架
void wc::count::outResultC()
{
	std::cout << "字符数："<<this->char_n << std::endl;
}
void  wc::count::outResultW()
{
	std::cout << "单词数：" << this->word_n<< std::endl;
}
void  wc::count::outResultL() 
{
	std::cout << "行数：" << this->line_n << std::endl;
}
void  wc::count::outResultA()
{
	std::cout << "空行：" << this->empty_l << std::endl;
	std::cout << "代码行：" << this->code_l << std::endl;
	std::cout << "注释行：" << this->desc_l << std::endl;
}
//统计框架
void  wc::count::chareterCount(std::string& text)//字符
{
	std::string::iterator iter, itend;
	itend = text.end();
	iter = text.begin();
	initCount();
	if (!text.empty())
		while (iter != itend)
		{
			if (*iter == ' ' || *iter == '\t'||*iter=='\n')
			{
				++char_n;
			}
			++iter;
		}
	outResultC();
}
void  wc::count::wordCount(std::string& text)//单词
{
	std::string::iterator iter, itend;
	int tag = 0;
	itend = text.end();
	iter = text.begin();
	initCount();
	if (!text.empty())
		while (iter != itend)
		{
			if ((*iter>='a'&&*iter<='z')||((*iter >= 'A' && *iter <= 'Z')))
			{
				tag = 1;
			}
			else if (tag == 1)
			{
				tag = 0;
				++word_n;
			}
		}
	outResultW();
}
void  wc::count::lineCount(std::string& text)//行
{
	std::string::iterator iter, itend;
	itend = text.end();
	iter = text.begin();
	initCount();
	if (!text.empty())
	{
		++line_n;
		while (iter != itend)
		{
			if (*iter == '\n')
			{
				++line_n;
			}
			++iter;
		}
	}outResultL();
}
void  wc::count::complexCount(std::string& text)
{
	std::string temp;
	std::string::iterator ittxt;
	char cht = 0,tgc=0;
	int chn = 0, tag = 0;
	
	ittxt = text.begin();
	initCount();

	while (ittxt != text.end())
	{
		temp.clear();
		cht = 0,tgc=0;
		chn = 0, tag = 0;
		while (ittxt != text.end() && *ittxt != '\n')
		{
			cht = *ittxt;
			temp.push_back(cht);
			if (cht == ' ' || cht == '\t');//空语句
			else if (cht == ')' || cht == '(' || cht == '{' || cht == '}' || cht == ';')
			{
				if (tag == 0) tgc = cht; 
				tag = 1; ++chn;
			}
			else  ++chn;
			++ittxt;
		}//one line 
		if (chn == 0 || (chn == 1 && tag == 1)) empty_l++;//空行特征
		else if (describCount(temp,tgc)) desc_l++;//否则则对句子进行注释行分析
		else ++code_l;//排除空行和注释行，则为代码行
		if (ittxt != text.end())//出口
			++ittxt;
	}outResultA();
}
int wc::count::describCount(std::string& line, char& tg)//注释行分析
{
	std::string::iterator it = line.begin(), cht = line.begin();
	int i = 0;
	char tp = 0;
	if (line.find("//") > line.size()) return 0;
	else
	{
		it += line.find("//");
		for (i = 0; it != cht; ++cht)
		{
			if (*cht == ' ' || *cht == '\t');//空语句
			else if (i == 0) { tp = *cht; ++i; }
			else  ++i;
		}

		if (i == 0 || (i == 1 && tp == tg)) return 1;
		else return 0;
	}
}


