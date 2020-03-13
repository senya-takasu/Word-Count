#pragma once

#include<string>
#include<vector>

namespace wc
{ 
	//count������ͳ���ı�����Ϣ
	//��֧��ANSIC������ַ�ͳ�ƣ����ܻ��������֮��Ľ��
	//����ͳ�Ʋ�����������ʶ��Ӣ�ĵ����Ƿ���Ч
	//�轫�ı�����string�����ṩ��count������
	//ͳ�Ʒ������Ѿ������˽���������
   class count
	{
	private:
		unsigned long int char_n;
		unsigned long int word_n;
		unsigned long int line_n;
		unsigned long int empty_l;
		unsigned long int code_l;
		unsigned long int desc_l;
		//inital
		int initCount()
		{
			char_n = 0;word_n = 0;line_n = 0;
			empty_l = 0;code_l = 0;desc_l = 0;			
			return 0;
		}	
		//������
		void virtual outResultC();
		void virtual outResultW();
		void virtual outResultL();
		void virtual outResultA();
		//ע���з���
		int describCount(std::string& line, char& tg);

	public:
		//ͳ�ƿ��
		void virtual chareterCount(std::string& text);
		void virtual wordCount(std::string& text);
		void virtual lineCount(std::string& text);
		void virtual complexCount(std::string& text);
		//���췽��
		count()
		{
			initCount();
		}
	};
   // wc work stream;
   void workc(count& cter,std::vector<std::string>& files);
   void workw(count& cter, std::vector<std::string>& files);
   void workl(count& cter, std::vector<std::string>& files);
   void worka(count& cter, std::vector<std::string>& files);
}
