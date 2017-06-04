#include "MeshStatistics.h"
#include <math.h>

#include "../Common/CommonMeshRepresentation.h"

namespace MeshIS {
    namespace Model {
        using Common::Element_Q4;
        using Common::Element_T3;
        using Common::Element_T4;
        using Common::Element_P6;

        void MS::processT3Elements() {
            double dist1, dist2, dist3, halfPerimeter, inscribedCircleRadius, exscribedCircleRadius, ratio;
            double sum = 0;
            int i;
            int *tempIDs = new int[3];
            for (auto element:cmr.elementsT3) {
                i = 0;
                for (auto vertixID:element) {
                    tempIDs[i] = vertixID;

                    i++;
                } //element

                //compute distances between vertices
                dist1 = sqrt((cmr.vertices[tempIDs[0]][0] - cmr.vertices[tempIDs[1]][0]) *
                             (cmr.vertices[tempIDs[0]][0] - cmr.vertices[tempIDs[1]][0])
                             + (cmr.vertices[tempIDs[0]][1] - cmr.vertices[tempIDs[1]][1]) *
                               (cmr.vertices[tempIDs[0]][1] - cmr.vertices[tempIDs[1]][1])
                             + (cmr.vertices[tempIDs[0]][2] - cmr.vertices[tempIDs[1]][2]) *
                               (cmr.vertices[tempIDs[0]][2] - cmr.vertices[tempIDs[1]][2]));
                dist2 = sqrt((cmr.vertices[tempIDs[2]][0] - cmr.vertices[tempIDs[1]][0]) *
                             (cmr.vertices[tempIDs[2]][0] - cmr.vertices[tempIDs[1]][0])
                             + (cmr.vertices[tempIDs[2]][1] - cmr.vertices[tempIDs[1]][1]) *
                               (cmr.vertices[tempIDs[2]][1] - cmr.vertices[tempIDs[1]][1])
                             + (cmr.vertices[tempIDs[2]][2] - cmr.vertices[tempIDs[1]][2]) *
                               (cmr.vertices[tempIDs[2]][2] - cmr.vertices[tempIDs[1]][2]));
                dist3 = sqrt((cmr.vertices[tempIDs[2]][0] - cmr.vertices[tempIDs[3]][0]) *
                             (cmr.vertices[tempIDs[2]][0] - cmr.vertices[tempIDs[3]][0])
                             + (cmr.vertices[tempIDs[2]][1] - cmr.vertices[tempIDs[3]][1]) *
                               (cmr.vertices[tempIDs[2]][1] - cmr.vertices[tempIDs[3]][1])
                             + (cmr.vertices[tempIDs[2]][2] - cmr.vertices[tempIDs[3]][2]) *
                               (cmr.vertices[tempIDs[2]][2] - cmr.vertices[tempIDs[3]][2]));

                //apply formulas

                halfPerimeter = (dist1 + dist2 + dist3) / 2;
                inscribedCircleRadius = sqrt(
                        ((halfPerimeter - dist1) * (halfPerimeter - dist2) * (halfPerimeter - dist3)) / halfPerimeter);
                exscribedCircleRadius = (dist1 * dist2 * dist3) / 4 * inscribedCircleRadius * halfPerimeter;
                ratio = inscribedCircleRadius / exscribedCircleRadius;
                sum += ratio;
                if (ratio < 0.25) { //push condition
				
                    this->t3.push_back(element);
                }


            } //elements
            this->avgT3Ratio=sum/cmr.elementsT3.size();
        } //function
            } //model
        } //MeshIS
