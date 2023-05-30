#include "Config.h"
#include "Log.h"

#include <fstream>
#include <iostream>

Config& Config::getInstance()
{
    static Config instance;
    return instance;
}

void Config::loadConfig(const std::string& configFile)
{
    std::ifstream file(configFile);

    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            size_t delimiterPos = line.find('=');
            if (delimiterPos != std::string::npos)
            {
                std::string key = line.substr(0, delimiterPos);
                std::string value = line.substr(delimiterPos + 1);

                if (key == "ScreenWidth")
                {
                    mScreenWidth = std::stoi(value);
                }
                else if (key == "ScreenHeight")
                {
                    mScreenHeight = std::stoi(value);
                }
            }
        }

        file.close();
    }
    else
    {
        // Handle file open error
        HZ_CORE_CRITICAL("Failed to open config file: {0}", configFile);
    }
}

int Config::getScreenWidth() const
{
    return mScreenWidth;
}

int Config::getScreenHeight() const
{
    return mScreenHeight;
}

Config::Config()
{
    // Initialize default values
    mScreenWidth = 800;
    mScreenHeight = 600;
    loadConfig("config.ini");
}
