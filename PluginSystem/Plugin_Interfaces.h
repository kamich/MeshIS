#include <map>
#include <memory>

#ifndef CPPWINLIN_PLUGIN_INTERFACES_H
#define CPPWINLIN_PLUGIN_INTERFACES_H

namespace MeshIS
{
	namespace Plugin_System {
		/* Base class for plugins */
		class I_Plugin {
		public:
			virtual void action() = 0;
		};

		/*
		* Base class for Plugin_Register
		* See Plugin_Register below for explanations
		*/
		class I_Plugin_Register {
		public:
			virtual std::shared_ptr<I_Plugin> get_plugin() = 0;
		};

	}
}

#define REGISTER_PLUGIN(CLASSNAME) \
    namespace { \
        static Plugin_System::Plugin_Register<CLASSNAME> \
        CLASSNAME##_register( #CLASSNAME ); \
    };

#endif //CPP_PLUGIN_INTERFACES_H