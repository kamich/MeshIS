//
// Created by Kuba on 2017-06-13.
//

#include <afxres.h>
#include "MauseGestures.h"



MauseGestures::MauseGestures(int obszar){
    this->area=obszar;
    this->gest=new std::list<int>;
}



void MauseGestures::testMauseMovement(int x,int y){
    if((x>0)&&(x<area)&&(y>0)&&(y<area))
    {
        if(((left_pushed)||(right_pushed))&&(GetTickCount()-start>400)&&(m->getTarget(x,y)!=8)){
            //std::cout<<target_string[m->getTarget(x,y)]<<"\n";
            gest->push_front(m->getTarget(x,y));
            testAllGestures();
            m=new Map(x,y);
            start = GetTickCount();
        }
    }
}

bool MauseGestures::testGesture(int* tab,int size) {
    int i = 0;
    if (gest->size() == size) {
        for (std::list<int>::const_iterator iterator = gest->begin(), end = gest->end(); iterator != end; ++iterator) {
            if (*iterator != tab[size-1-i]) return false;
            i++;
        }
        return true;
    } return false;
}

void MauseGestures::testAllGestures() {
    if(testGesture(lewy_gora_dol,3)){
        std::cout<<"Wykryty Gest: LPM-Gora-Dol"<<"\n";
    }
    if(testGesture(lewy_prawo_gora,3)){
        std::cout<<"Wykryty Gest: LPM-Prawo-Gora"<<"\n";
    }
    if(testGesture(prawy_lewo_prawo,3)){
        std::cout<<"Wykryty Gest: PPM-Lewo-Prawo"<<"\n";
    }
    if(testGesture(prawy_dol_gora_dol_prawo,5)){
        std::cout<<"Wykryty Gest: PPM-Dol-Gora-Dol-Prawo"<<"\n";
    }
}




