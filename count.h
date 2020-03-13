#pragma once

#include<string>
#include<vector>

namespace wc
{ 
	//count类用于统计文本的信息
	//不支持ANSIC以外的字符统计，可能会出现意料之外的结果
	//单词统计并不能真正的识别英文单词是否有效
	//需将文本置入string对象提供给count对象处理
	//统计方法中已经调用了结果输出方法
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
		//输出框架
		void virtual outResultC();
		void virtual outResultW();
		void virtual outResultL();
		void virtual outResultA();
		//注释行分析
		int describCount(std::string& line, char& tg);

	public:
		//统计框架
		void virtual chareterCount(std::string& text);
		void virtual wordCount(std::string& text);
		void virtual lineCount(std::string& text);
		void virtual complexCount(std::string& text);
		//构造方法
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
