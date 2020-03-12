#pragma once

#include<string>
#include<vector>

namespace wc
{ 
   class count
	{
	private:


		std::string pathname;
		//std::string text;
		unsigned long int char_n;
		unsigned long int word_n;
		unsigned long int line_n;
		unsigned long int empty_l;
		unsigned long int code_l;
		unsigned long int desc_l;

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



		int describCount(std::string& line, char& tg);//ע���з���

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
			this->pathname.assign("");
		}

	};

   
   
}
