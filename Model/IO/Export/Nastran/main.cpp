//*************************
//Created by Dominik Kopaczka
//*************************

#include"NastranExporter/NastranExporter.h"
#include"TestNastran/TestNastran.h"
#include"../../../../../CMR_objects/CMR_TestObjects.h"
using namespace MeshIS::Model::Export::Nastran::TNastran;
using namespace MeshIS::Model::Export::Nastran;
using namespace MeshIS::TestData::CMR;

using CMR = MeshIS::Model::Common::CommonMeshRepresentation;
using Type_Of_Nastran_Version = MeshIS::Model::Export::Nastran::NastranExporter::Type_Of_Nastran_Version;

int main()
{
	//Using TestNastran which is on Karol Kiełbasa Branch
	//TestNastran tn;
	//tn.init_CMR();
	//tn.print_CMR();
	//tn.run_nastran("shortNastran(using_test_nastran_class).bdf", 
	//	Type_Of_Nastran_Version::SHORT);

	CMR cmr = create_plate20x20();
	NastranExporter nastran;
	nastran.set_state_of_nastran_version(Type_Of_Nastran_Version::SHORT);
	nastran.Export("shortNastran(using_create_plate20x20_function).bdf", cmr);
}