#pragma once
#include <map>

namespace plugin_system {

	/* Base class for plugins */
	class I_Plugin {
	public:
		virtual void action() = 0;
	};

	/*
	* Base class for PluginRegistrar
	* See PluginRegistrar below for explanations
	*/
	class I_Plugin_Register {
	public:
		virtual I_Plugin* get_plugin() = 0;
	};
	
}

/*
* Here is the trick: upon creation of the global variable, the class created
* out of the template will get instanciated once, and will register itself.
* The template contains the information to create a plugin instance.
* An unnamed namespace is used to enclose this later unused variable in the
* compilation unit.
*/
#define REGISTER_PLUGIN(CLASSNAME) \
    namespace { \
        static plugin_system::Plugin_Register<CLASSNAME> \
        CLASSNAME##_register( #CLASSNAME ); \
    };