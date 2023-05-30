#include "App.h"

App App::Instance;

App::App() 
{
}


App* App::GetInstance() 
{
	return &App::Instance; 
}


#include <stdio.h>
int App::Execute(int argc, char* argv[])
{
	printf("TODO");
	return 0;
}
