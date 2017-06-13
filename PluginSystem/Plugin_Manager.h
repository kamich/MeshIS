#pragma once
#include "Plugin_Interfaces.h"
/*
* This is the factory, the common interface to "plugins".
* Plugins registers themselves here and the factory can serve them on
* demand.
* It is a Singleton
*/
namespace plugin_system {
	class Plugin_Manager {
	public:
		/* Get Singleton instance */
		static Plugin_Manager& instance();
		/* Register a new plugin */
		void register_plugin(I_Plugin_Register * reg_plugin, std::string name);
		/* Get an instance of a plugin based on its name */
		/* throws out_of_range if plugin not found */
		I_Plugin* get_plugin(std::string name);

	private:
		/* Holds pointers to plugin registers */
		std::map<std::string, I_Plugin_Register*> registry;
		/* Make constructors private and forbid cloning */
		Plugin_Manager() : registry() {};
		Plugin_Manager(Plugin_Manager const&) {};
		void operator=(Plugin_Manager const&) {};
	};

	
}