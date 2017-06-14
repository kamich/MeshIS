#include <iostream>
#include "Plugin_Manager.h"
using namespace MeshIS::Plugin_System;
int main()
{
	Plugin_Manager &factory = Plugin_Manager::get_instance();

	plugin_shared_ptr plugin1;
	plugin_shared_ptr plugin2;
	plugin_shared_ptr plugin3;

	try {
		plugin2 = factory.get_plugin("Plugin22"); 
		plugin2->action();
	}
	catch (const Plugin_Exception& e)
	{
		std::cout<<e.what();
	}
	
	try {
	plugin1 = factory.get_plugin("Plugin1");
	plugin1->action();
	}
	catch (const Plugin_Exception& e)
	{
		std::cout << e.what();
	}
	
	factory.run_plugin("Plugin1");

	std::cout << "Number of plugins:" << factory.run_all_plugins() << std::endl;

	std::cout << "Varaidic Plugins" << std::endl;
	factory.run_selected_plugins("Plugin1", "Plugin2", "Plugin1");
	
	return 0;
}