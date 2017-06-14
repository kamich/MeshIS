#include "Plugin_Manager.h"

namespace MeshIS
{
	namespace Plugin_System {

		Plugin_Manager& Plugin_Manager::get_instance() noexcept {
			static Plugin_Manager s_instance;
			return s_instance;
		}

		void Plugin_Manager::register_plugin(I_Plugin_Register * reg, std::string &&name) noexcept {
			m_registry[name] = std::shared_ptr<I_Plugin_Register>(reg);
		}

		std::shared_ptr<I_Plugin> Plugin_Manager::get_plugin(std::string &&name) {

			check_plugin_exist(std::move(name));

			std::shared_ptr<I_Plugin_Register> reg;
			reg = m_registry[name];
			return reg->get_plugin();

		}

		void Plugin_Manager::run_plugin(std::string && name)
		{
			check_plugin_exist(std::move(name));

			std::shared_ptr<I_Plugin_Register> reg;
			reg = m_registry[name];
			auto plugin = reg->get_plugin();
			plugin->action();
		}

		int Plugin_Manager::run_all_plugins() noexcept
		{
			auto vect_of_futs = std::vector<std::future<void>>();

			auto number_of_plugins = start_all_future(vect_of_futs);

			end_all_future(vect_of_futs);

			return number_of_plugins;
		}




		int Plugin_Manager::start_all_future(vector_of_futures &vec_of_futs) noexcept
		{
			auto number_of_plugins = 0;
			for (auto &plugin : m_registry)
			{
				auto fut = std::async([&]()
				{
					auto current_plugin = plugin.second->get_plugin();
					current_plugin->action();
				});
				vec_of_futs.emplace_back(std::move(fut));

				number_of_plugins++;
			}
			return number_of_plugins;
		}

		void Plugin_Manager::end_all_future(vector_of_futures &vec_of_futs) noexcept
		{
			for (auto &fut : vec_of_futs)
				fut.get();
		}

		void Plugin_Manager::check_plugin_exist(std::string && name)
		{
			auto map_itr = m_registry.find(name);

			if (map_itr == m_registry.end())
				throw Plugin_Exception();
		}


	}
}