#include"NastranExporter.h"
#include"TestNastran.h"
using namespace MeshIS::Model::Export::Nastran::TNastran;
int main()
{
	TestNastran tn;
	tn.init_CMR();
	tn.print_CMR();
	tn.run_nastran("C:\\Users\\lordkopakos\\Documents\\Visual Studio 2017\\Projects\\Project4\\Project4\\shortNastran.bdf", 
		MeshIS::Model::Export::Nastran::NastranExporter::Type_Of_Nastran_Version::SHORT);

	tn.run_nastran("C:\\Users\\lordkopakos\\Documents\\Visual Studio 2017\\Projects\\Project4\\Project4\\freeNastran.bdf",
		MeshIS::Model::Export::Nastran::NastranExporter::Type_Of_Nastran_Version::FREE);

	system("pause");
}