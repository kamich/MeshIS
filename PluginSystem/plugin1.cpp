/*
* Now we can create own plugins.
* All you have to do is inherit the interface I_Plugin, and Register our Plugin.
*/

#include <iostream>
#include"Plugin_Manager.h"
#include"Plugin_Register.h"

class Plugin1 : public plugin_system::I_Plugin {
	void action() {
		std::cout << "Plugin1" << std::endl;
	}
};

class Plugin2 : public plugin_system::I_Plugin {
	void action() {
		std::cout << "Plugin2 hehe" << std::endl;
	}
};

REGISTER_PLUGIN(Plugin1)
REGISTER_PLUGIN(Plugin2)