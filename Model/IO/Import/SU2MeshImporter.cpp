#include "SU2MeshImporter.h"
#include <fstream>
#include <iostream>
#include <vector>


namespace MeshIS
{
	namespace Model
	{
		
		using Common::Element_P6;

		namespace Import
		{

			Common::CMR SU2LImporter::Import(const string & absolute_file_path)
			{
				std::fstream su2file;
				try {
					su2file.open(absolute_file_path, std::ios::in);
				}
				cath(exception& e) {
					std::cout << "Can't open the file. You have problem !" << std::endl;
					std::cin.get();
					return cmr;
				}
				std::string line;
				while (!su2file.eof())
				{
					// dimension
					char mark;
					su2file >> mark;
					while (mark == ' ') {
						su2file >> mark;
					}
					su2file >> mark;
					if (mark == '3') {
						//number of elements
						while (mark == ' ') {
							su2file >> mark;
						}
						su2file >> mark;;//iloœæ elementow
						int n_elem = mark;
						switch (n_elem)
						{
						case 3:
							//line
							break;

						case 5:
							//Triangle
							break;

							//...
						case 9:
							//Quadrilateral
							break;
						case 10:
							//Tetrahedral
							break;

						case 12:
							//Hexahedral
							break;
							//...
						case 13:
							//Wedge
							double a, b, c, d, e, f;
							double type;


							for (int i = 0; i < n_elem; i++) {
								for (int j = 0; i < 6; i++) {
									
									su2file >> a;
									su2file >> b;
									su2file >> c;
									su2file >> d;
									su2file >> e;
									su2file >> f;
									
								}
								su2file >> type;//id element
							}


							break;


						default:
							//other
							break;
						}





					}
					else if (mark == '2') {
						//number of elements
						while (mark == ' ') {
							su2file >> mark;
						}
						su2file >> mark;;//iloœæ elementow
						int n_elem = mark;
						switch (n_elem)
						{
						case 3:
							//line
							break;

						case 5:
							//Triangle
							break;

							//...
						case 9:
							//Quadrilateral
							break;
						case 10:
							//Tetrahedral
							break;

						case 12:
							//Hexahedral
							break;
							//...
						case 13:
							//Wedge
							double a, b, c, d, e, f;
							double type;


							for (int i = 0; i < n_elem; i++) {
								for (int j = 0; i < 6; i++) {

									su2file >> a;
									su2file >> b;
									su2file >> c;
									su2file >> d;
									su2file >> e;
									su2file >> f;

								}
								su2file >> type;//id element
							}


							break;


						default:
							//other
							break;
						}
					}


				}
			}

			void SU2LImporter::addElement(int element_type, std::vector<int>& p)
			{
				
				if (element_type == 13)
					cmr.elementsP6.push_back(Element_P6{ p[0], p[1], p[2], p[3], p[4], p[5] });
				
			}


		}
	}
}