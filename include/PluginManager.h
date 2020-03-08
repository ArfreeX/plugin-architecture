#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include <iostream>


class PluginManager
{
public:
    PluginManager();

    bool loadPlugins();

    bool handlePropertyChange();

    uint32_t getProperty(uint32_t propertyId);
};

#endif // PLUGINMANAGER_H
