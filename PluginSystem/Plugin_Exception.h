#include <iostream>
#include <exception>

#ifndef CPPWINLIN_PLUGIN_EXCEPTION_H
#define CPPWINLIN_PLUGIN_EXCEPTION_H

using namespace std;
namespace MeshIS
{
	namespace Plugin_System 
	{


		class Plugin_Exception : public exception
		{
		public:
			const char* what() const noexcept
			{
				return "Plugin Doesn't exist\n";
			}
		};
	}
}
#endif CPPWINLIN_PLUGIN_EXCEPTION_H