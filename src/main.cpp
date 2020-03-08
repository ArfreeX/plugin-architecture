#include <experimental/filesystem>
#include <iostream>

#include "PluginManager.h"


void executePluginScenario(std::string&& pluginPath)
{
    auto pluginManager = PluginManager();
    if (not pluginManager.loadPlugins(pluginPath))
    {
        std::cerr << "Plugins could not be loaded" << "\n";
    }
}

std::string getPluginPath(std::string&& binaryPath)
{
    std::string buildPath = std::experimental::filesystem::path(binaryPath)
            .parent_path().parent_path();
    return buildPath + "/plugin_lib";
}

int main(int argc, char* argv[])
{
    executePluginScenario(getPluginPath(std::string(argv[0])));
    return(EXIT_SUCCESS);
}
