#pragma once

#include <string>

class Config
{
public:
    static Config& getInstance();
    Config(const Config&) = delete;
    void operator=(const Config&) = delete;

    void loadConfig(const std::string& configFile);
    int getScreenWidth() const;
    int getScreenHeight() const;

private:
    int mScreenWidth;
    int mScreenHeight;

    Config();
};
