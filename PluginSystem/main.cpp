#include <iostream>
#include "Plugin_Manager.h"

int main()
{
	plugin_system::Plugin_Manager &factory = plugin_system::Plugin_Manager::instance();

	plugin_system::I_Plugin* plugin1;
	plugin_system::I_Plugin* plugin2;

	plugin2 = factory.get_plugin("Plugin2"); /* should try-catch that */
	plugin2->action();

	plugin1 = factory.get_plugin("Plugin1");
	plugin1->action();

	system("pause");
	return 0;
}