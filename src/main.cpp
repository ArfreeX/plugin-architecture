#include <iostream>

#include "PluginManager.h"


void executePluginScenario()
{
    auto pluginManager = PluginManager();
    if (not pluginManager.loadPlugins())
    {
        std::cerr << "Plugins could not be loaded" << "\n";
    }
}

int main()
{
    executePluginScenario();
	return(EXIT_SUCCESS);
}
