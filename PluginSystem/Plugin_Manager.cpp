#include "Plugin_Manager.h"

namespace plugin_system {

	Plugin_Manager&
		Plugin_Manager::instance() {
		static Plugin_Manager instance;
		return instance;
	}

	void
		Plugin_Manager::register_plugin(I_Plugin_Register * reg, std::string name) {
		registry[name] = reg;
	}

	I_Plugin*
		Plugin_Manager::get_plugin(std::string name) {
		I_Plugin_Register* reg;
		reg = registry[name]; /* throws out_of_range if plugin unknown */
		return reg->get_plugin();
	}

}