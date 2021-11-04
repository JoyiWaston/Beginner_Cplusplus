// 53_Polymorphism_Case_ComputerAssembly.cpp: 目标的源文件。
//电脑主要由CPU(计算)，GPU(渲染)，内存条(缓存)
//每个零件封装抽象基类，提供不同厂商生产不同零件
//创建电脑类提供让电脑工作的函数，并且调用每个零件工作的接口
//测试时组装三台不同电脑进行工作

#include "53_Polymorphism_Case_ComputerAssembly.h"
//公共抽象基类
class CPU
{
public:
	virtual void Calculate() = 0;//计算
};

class GPU
{
public:
	virtual void Rendering() = 0;//渲染
};

class ROM
{
public:
	virtual void Cache() = 0;//缓存
};

//组装电脑类
class Computer
{
public:
	Computer(CPU* cpu, GPU* gpu, ROM* rom)
	{
		m_cpu = cpu;
		m_gpu = gpu;
		m_rom = rom;
	}
	//工作函数
	void work()
	{
		//让零件工作，调用接口
		m_cpu->Calculate();
		m_gpu->Rendering();
		m_rom->Cache();
	}
	//提供析构函数释放三个电脑的零件
	~Computer()
	{
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_gpu != NULL)
		{
			delete m_gpu;
			m_gpu = NULL;
		}
		if (m_rom != NULL)
		{
			delete m_rom;
			m_rom = NULL;
		}
	}

private:
	CPU* m_cpu;	//cpu的零件指针
	GPU* m_gpu;	//gpu的零件指针
	ROM* m_rom;	//rom的零件指针
};



//Inter厂商
class IntelCPU : public CPU
{
public:
	virtual void Calculate()
	{
		cout << "IntelCPU正在计算!" << endl;
	}
};

class IntelGPU : public GPU
{
public:
	virtual void Rendering()
	{
		cout << "IntelGPU正在渲染!" << endl;
	}
};

class IntelROM : public ROM
{
public:
	virtual void Cache()
	{
		cout << "IntelROM正在缓存!" << endl;
	}
};

//AMD厂商
class AMDCPU : public CPU
{
public:
	virtual void Calculate()
	{
		cout << "AMDCPU正在计算!" << endl;
	}
};

class AMDGPU : public GPU
{
public:
	virtual void Rendering()
	{
		cout << "AMDGPU正在渲染!" << endl;
	}
};

class AMDROM : public ROM
{
public:
	virtual void Cache()
	{
		cout << "AMDROM正在缓存!" << endl;
	}
};


void test01()
{
	cout << "-------------------------------------------------------------------------------------------" << endl;
	cout << "----------第一台电脑开始工作----------" << endl;
	//第一台电脑零件
	CPU* intelCPU = new IntelCPU;
	GPU* intelGPU = new IntelGPU;
	ROM* intelROM = new IntelROM;
	//组装第一台电脑
	Computer* computer1 = new Computer(intelCPU, intelGPU, intelROM);
	computer1->work();
	delete computer1;
	cout << "----------第一台电脑结束工作----------" << endl;

	cout << "-------------------------------------------------------------------------------------------" << endl;

	cout << "----------第二台电脑开始工作----------" << endl;
	//第二台电脑零件
	CPU* amdCPU = new AMDCPU;
	GPU* amdGPU = new AMDGPU;
	ROM* amdROM = new AMDROM;
	//组装第二台电脑
	Computer* computer2 = new Computer(amdCPU, amdGPU, amdROM);
	computer2->work();
	delete computer2;
	cout << "----------第二台电脑结束工作----------" << endl;

	cout << "-------------------------------------------------------------------------------------------" << endl;

	cout << "----------第三台电脑开始工作----------" << endl;
	//第三台电脑零件
	//组装第三台电脑
	Computer* computer3 = new Computer(new AMDCPU, new IntelGPU, new AMDROM);
	computer3->work();
	delete computer3;
	cout << "----------第三台电脑结束工作----------" << endl;

	cout << "-------------------------------------------------------------------------------------------" << endl;
}




int main()
{
	test01();

	return 0;
}
