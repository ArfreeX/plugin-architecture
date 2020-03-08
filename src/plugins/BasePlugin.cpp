#include "plugins/BasePlugin.h"


BasePlugin::BasePlugin(int pluginID, std::string pluginName)
    : ID(pluginID), NAME(pluginName)
{

}

std::string BasePlugin::getName()
{
    return NAME;
}

int BasePlugin::getID()
{
    return ID;
}
