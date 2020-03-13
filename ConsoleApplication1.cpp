//参数列表使用思路
// * 1 0号单元的参数是启动程序文件的文件名。
// * 2 最后一个参数当作文件名处理。
// * 3 中间的参数当作模式控制，其中只有-s是可选的第二个参数。

#include"count.h"

#include<iostream>
#include<string.h>
#include<io.h>
//#include<iostream>

int getFiles(std::string path, std::vector<std::string>& files);//批量读取文件名
int main(int argc, char* argv[])
{
	using namespace wc;
	using namespace std;

	vector<string> files;
	string pathname;
	string p;
	string::iterator iter;
	wc::count ac;

	int tag = 0;
	struct _finddata_t fileinfo;
	long hf = 0;

	pathname.assign(argv[argc - 1]);

	if (argc >= 3)
	{

		if (pathname[1] == ':' && pathname.size() >= 2)//绝对路径
			;
		else                //单文件名扩展为相对路径
		{
			p.assign(pathname);
			pathname.assign(".\\").append(p);
		}


		if (!strcmp(argv[2], "-s"))
		{//清理带后缀名的文件名得到目录名
			iter = pathname.end();
			--iter;
			while (*iter != '\\')//检测是否输入了文件名
			{
				if (*iter == '.')
				{
					tag = 1; break;
				}
				--iter;
			}iter = pathname.end();
			iter--;
			if (tag)//如果输入了文件名，则清除文件名
				while (*iter != '\\')
				{
					pathname.pop_back();
					--iter;
				}
			getFiles(pathname, files);//多文件
		}
		else
		{//查找是否存在相应文件
			hf = _findfirst(pathname.c_str(), &fileinfo);
			//pathname.assign(fileinfo.name);
			if (hf != -1)
			{
				files.push_back(pathname);//读单个文件
				_findclose(hf);
			}
		}
		if (!strcmp(argv[1], "-c"))        //char count model
			workc(ac, files);
		else if (!strcmp(argv[1], "-w"))        //word count model
			workw(ac, files);
		else if (!strcmp(argv[1], "-l"))        //lines count model
			workl(ac, files);
		else if (!strcmp(argv[1], "-a"))        //more lines message
			worka(ac, files);


	}
	return 0;
}

int getFiles(std::string path, std::vector<std::string>& files)//批量读取目录下的文件名
{
	//文件句柄  __注意句柄类型，可能会扩展为其他数据类型
	long   hFile = 0;
	//文件信息结构体
	struct _finddata_t fileinfo;
	std::string p;//复制得到的文件名属性

	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			//如果是目录,迭代之  
			   //如果不是,加入列表  
			if ((fileinfo.attrib & _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
					getFiles(p.assign(path).append("\\").append(fileinfo.name), files);
			}
			else
			{
				files.push_back(p.assign(path).append("\\").append(fileinfo.name));
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
	return 1;
}

