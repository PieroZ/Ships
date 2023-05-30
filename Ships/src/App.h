#pragma once
class App
{
private:
	static App Instance;
private:
	App();

public:
	static App* GetInstance();

	int Execute(int argc, char* argv[]);
};

