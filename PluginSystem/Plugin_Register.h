#include "Plugin_Interfaces.h"
#include <string>

#ifndef CPPWINLIN_PLUGIN_REGISTER_H
#define CPPWINLIN_PLUGIN_REGISTER_H
/*
* Helper class that registers a plugin upon construction.
*/
namespace MeshIS
{
	namespace Plugin_System {

		template<class T_Plugin>
		class Plugin_Register : public I_Plugin_Register {
		public:
			Plugin_Register(std::string &&classname);
			plugin_shared_ptr get_plugin() override;
		private:
			/* That is not really used there, but could be useful */
			std::string m_classname;
		};

		/* template functions in header */

		template<class T_Plugin>
		Plugin_Register<T_Plugin>::Plugin_Register(std::string &&classname) : m_classname(classname) {
			Plugin_Manager &_factory = Plugin_Manager::get_instance();
			_factory.register_plugin(this, std::move(classname));
		}

		template<class T_Plugin>
		plugin_shared_ptr Plugin_Register<T_Plugin>::get_plugin() {
			plugin_shared_ptr ptr(new T_Plugin);
			return ptr;
		}
	}
}

#endif //CPP_PLUGIN_REGISTER_H