#include "Plugin_Interfaces.h"
#include <string>

#ifndef CPPWINLIN_PLUGIN_REGISTER_H
#define CPPWINLIN_PLUGIN_REGISTER_H
/*
* Helper class that registers a plugin upon construction.
* Actually, the registrar registers itself, and the proxied plugin is only
* created on-demand. This mechanism can be shortened by directly
* registering and instance of the plugin, but the assumption here is that
* instanciating the plugin can be heavy and not necessary.
*/
namespace MeshIS
{
	namespace Plugin_System {

		template<class T_Plugin>
		class Plugin_Register : public I_Plugin_Register {
		public:
			Plugin_Register(std::string &&classname);
			std::shared_ptr<I_Plugin> get_plugin() override;
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
		std::shared_ptr<I_Plugin> Plugin_Register<T_Plugin>::get_plugin() {
			std::shared_ptr<I_Plugin> ptr(new T_Plugin);
			return ptr;
		}
	}
}

#endif //CPP_PLUGIN_REGISTER_H