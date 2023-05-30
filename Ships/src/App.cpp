#include "App.h"
#include "Log.h"

App App::Instance;

App::App() 
{
	Ships::Log::Init();
}


App* App::GetInstance() 
{
	return &App::Instance; 
}


int App::Execute(int argc, char* argv[])
{
	HZ_CORE_TRACE("TRACE");
	HZ_CORE_INFO("INFO");
	HZ_CORE_WARN("WARN");
	HZ_CORE_ERROR("ERROR");
	HZ_CORE_CRITICAL("CRITICAL");
	return 0;
}
