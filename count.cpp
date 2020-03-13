#include "count.h"
#include<iostream>

#include<fstream>



//������
void wc::count::outResultC()
{
	std::cout << "�ַ�����"<<this->char_n << std::endl;
}
void  wc::count::outResultW()
{
	std::cout << "��������" << this->word_n<< std::endl;
}
void  wc::count::outResultL() 
{
	std::cout << "������" << this->line_n << std::endl;
}
void  wc::count::outResultA()
{
	std::cout << "���У�" << this->empty_l << std::endl;
	std::cout << "�����У�" << this->code_l << std::endl;
	std::cout << "ע���У�" << this->desc_l << std::endl;
}
//ͳ�ƿ��
void  wc::count::chareterCount(std::string& text)//�ַ�ͳ��
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
void  wc::count::wordCount(std::string& text)//����ͳ��
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
			++iter;//��һ��ȱ��ѭ����Ϣ���£�������ѭ����
		}
	outResultW();
}
void  wc::count::lineCount(std::string& text)//��ͳ��
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
void  wc::count::complexCount(std::string& text)//��ϸ����ͳ��
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
			if (cht == ' ' || cht == '\t');//�����
			else if (cht == ')' || cht == '(' || cht == '{' || cht == '}' || cht == ';')
			{
				if (tag == 0) tgc = cht; 
				tag = 1; ++chn;
			}
			else  ++chn;
			++ittxt;
		}//one line 
		if (chn == 0 || (chn == 1 && tag == 1)) empty_l++;//��������
		else if (describCount(temp,tgc)) desc_l++;//������Ծ��ӽ���ע���з���
		else ++code_l;//�ų����к�ע���У���Ϊ������
		if (ittxt != text.end())
			++ittxt;
	}outResultA();
}
int wc::count::describCount(std::string& line, char& tg)//ע���з���
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
			if (*cht == ' ' || *cht == '\t');//�����
			else if (i == 0) { tp = *cht; ++i; }
			else  ++i;
		}

		if (i == 0 || (i == 1 && tp == tg)) return 1;
		else return 0;
	}
}

int	readFileIntoString(std::string& filename, std::string& text)//���ļ���string
{
	std::ifstream ifile(filename);//read only file stream
	//���ļ����뵽ostringstream����buf��
	//ostringstream buf;//out string stream
	char ch;
	while (ifile.get(ch) && !ifile.eof())
		text.push_back(ch);
	//������������buf�������ַ���
	ifile.close();
	return 1;
}


//wc work stream
void wc::workc(count& cter, std::vector<std::string>& files)
{
	int size, it;
	std::string text;
	size = files.size();
	for (it = 0; it < size; ++it)
	{
		std::cout << "�ļ�����"<<files[it] << std::endl;
		text.clear();
		readFileIntoString(files[it], text);
		cter.chareterCount(text);
	}
}
void wc::workw(count& cter, std::vector<std::string>& files)
{
	int size, it;
	std::string text;
	size = files.size();
	for (it = 0; it < size; ++it)
	{
		std::cout << "�ļ�����" << files[it] << std::endl;
		text.clear();
		readFileIntoString(files[it], text);
		cter.wordCount(text);
	}
}
void wc::workl(count& cter, std::vector<std::string>& files) 
{
	int size, it;
	std::string text;
	size = files.size();
	for (it = 0; it < size; ++it)
	{
		std::cout << "�ļ�����" << files[it] << std::endl;
		text.clear();
		readFileIntoString(files[it], text);
		cter.lineCount(text);
	}
}
void wc::worka(count& cter, std::vector<std::string>& files)
{
	
	int size, it;
	std::string text;
	size = files.size();
	for (it = 0; it < size; ++it)
	{
		std::cout << "�ļ�����" << files[it] << std::endl;
		text.clear();
		readFileIntoString(files[it], text);
		cter.complexCount(text);
	}
}
