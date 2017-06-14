#include "Plugin_Interfaces.h"
#include "Plugin_Exception.h"

#include<memory>
#include <future>
#include <vector>

#ifndef CPPWINLIN_PLUGIN_MANAGER_H
#define CPPWINLIN_PLUGIN_MANAGER_H

/*
* This is the factory, the common interface to "plugins".
* Plugins registers themselves here and the factory can serve them on
* demand.
* It is a Singleton
*/
namespace MeshIS
{
	namespace Plugin_System
	{

		using vector_of_futures = std::vector<std::future<void>>;

		class Plugin_Manager {
		public:
			/* Get Singleton instance */
			static Plugin_Manager& get_instance() noexcept;

			/* Register a new plugin */
			void register_plugin(I_Plugin_Register * reg_plugin, std::string &&name) noexcept;

			/* Get an instance of a plugin based on its name */
			/* throws out_of_range if plugin not found */
			std::shared_ptr<I_Plugin> get_plugin(std::string &&name);

			void run_plugin(std::string &&name);
			int run_all_plugins() noexcept;

			/*Variatic Template with async execution*/
			template<
				typename T = std::enable_if_t<
				std::is_base_of<std::string,
				std::decay_t<T>
				>::value
				>
			>
				void run_selected_plugins(const T& first_plugin);

			template<
				typename T = std::enable_if_t<
				std::is_base_of<std::string,
				std::decay_t<T>
				>::value
				>
				, typename... Types>
				void run_selected_plugins(const T& first_plugin, const Types&... plugins);

		private:
			/* Holds pointers to plugin registers */
			std::map<std::string, std::shared_ptr<I_Plugin_Register>> m_registry;
			/* Make constructors private and forbid cloning */
			Plugin_Manager() : m_registry() {};

			Plugin_Manager(Plugin_Manager const&) = delete;
			void operator=(Plugin_Manager const&) = delete;

			/*Parallel execution futures*/
			int start_all_future(vector_of_futures &vec_of_futs) noexcept;
			void end_all_future(vector_of_futures& vec_of_fut) noexcept;

			/*Exception*/
			void check_plugin_exist(std::string && name);
		};


		template<typename T>
		inline void Plugin_Manager::run_selected_plugins(const T & first_plugin)
		{
			try {
				std::async(&Plugin_Manager::run_plugin, this, first_plugin);
			}
			catch (const Plugin_Exception& e)
			{
				std::cout << e.what();
			}
		}

		template<typename T, typename ...Types>
		inline void Plugin_Manager::run_selected_plugins(const T & first_plugin, const Types & ...plugins)
		{
			try {
				std::async(&Plugin_Manager::run_plugin, this, first_plugin);
				run_selected_plugins(plugins...);
			}
			catch (const Plugin_Exception& e)
			{
				std::cout << e.what();
			}


		}

	}
}

#endif //CPP_PLUGIN_MANAGER_H