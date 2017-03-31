#include"NastranExporter/NastranExporter.h"
#include"TestNastran/TestNastran.h"
using namespace MeshIS::Model::Export::Nastran::TNastran;
int main()
{
	TestNastran tn;
	tn.init_CMR();
	tn.print_CMR();
	tn.run_nastran("shortNastran.bdf",
		MeshIS::Model::Export::Nastran::NastranExporter::Type_Of_Nastran_Version::SHORT);

	tn.run_nastran("freeNastran.bdf",
		MeshIS::Model::Export::Nastran::NastranExporter::Type_Of_Nastran_Version::FREE);

	tn.run_nastran("longNastran.bdf",
		MeshIS::Model::Export::Nastran::NastranExporter::Type_Of_Nastran_Version::LONG);

	system("pause");
}