#include <map>
#include <memory>

#ifndef CPPWINLIN_PLUGIN_INTERFACES_H
#define CPPWINLIN_PLUGIN_INTERFACES_H

namespace MeshIS
{
	namespace Plugin_System {

		class I_Plugin;
		using plugin_shared_ptr = std::shared_ptr<I_Plugin>;

		/* Interface for plugins */
		class I_Plugin {
		public:
			virtual void action() = 0;
		};

		/*
		* Interface for Plugin_Register
		* See Plugin_Register below for explanations
		*/
		class I_Plugin_Register {
		public:
			virtual plugin_shared_ptr get_plugin() = 0;
		};

	}
}

#define REGISTER_PLUGIN(CLASSNAME) \
    namespace { \
        static Plugin_System::Plugin_Register<CLASSNAME> \
        CLASSNAME##_register( #CLASSNAME ); \
    };

#endif //CPP_PLUGIN_INTERFACES_H