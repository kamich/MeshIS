#pragma once
#include "Plugin_Interfaces.h"
#include <string>
/*
* Helper class that registers a plugin upon construction.
* Actually, the registrar registers itself, and the proxied plugin is only
* created on-demand. This mechanism can be shortened by directly
* registering and instance of the plugin, but the assumption here is that
* instanciating the plugin can be heavy and not necessary.
*/
namespace plugin_system {
	template<class T_Plugin>
	class Plugin_Register : public I_Plugin_Register {
	public:
		Plugin_Register(std::string classname);
		I_Plugin* get_plugin();
	private:
		/* That is not really used there, but could be useful */
		std::string classname_;
	};

	/* template functions in header */

	template<class T_Plugin>
	Plugin_Register<T_Plugin>::Plugin_Register(std::string classname) : classname_(classname) {
		Plugin_Manager &factory = Plugin_Manager::instance();
		factory.register_plugin(this, classname);
	}

	template<class T_Plugin>
	I_Plugin* Plugin_Register<T_Plugin>::get_plugin() {
		return new T_Plugin();
	}
}