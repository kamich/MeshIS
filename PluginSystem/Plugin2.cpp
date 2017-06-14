/*
* Now we can create own plugins.
* All you have to do is inherit the interface I_Plugin, and Register our Plugin.
*/

#include <iostream>
#include"Plugin_Manager.h"
#include"Plugin_Register.h"
namespace MeshIS
{
	class Plugin2 : public Plugin_System::I_Plugin {
		void action() override {
			std::cout << "Plugin2 hehe" << std::endl;
		}
	};

	REGISTER_PLUGIN(Plugin2)
}