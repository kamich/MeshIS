//
// Created by Kuba on 2017-06-13.
//
#include <iostream>
#include <list>

#ifndef MAUSE_MAUSEGESTURES_H
#define MAUSE_MAUSEGESTURES_H



class MauseGestures {

    int lewy_gora_dol[3]={20, 3, 2};
    int lewy_prawo_gora[3]={20,1,3};
    int prawy_lewo_prawo[3]={30, 0, 1};
    int prawy_dol_gora_dol_prawo[5]={30,2,3,2,1};

public:

    int area;
    bool left_pushed=false;
    bool right_pushed=false;
    int start;

    int mause_left=20;
    int mause_right=30;

    std::list<int> *gest;



    std::string target_string[9] = { "Lewo", "Prawo","Dol","Gora","Lewo-Gora","Prawo-Gora","Lewo_Dol","Prawo-Dol","Brak" };

    enum target_enum
    {
        left=0,
        right=1,
        down=2,
        up=3,
        left_up=4,
        right_up=5,
        left_down=6,
        right_down=7,
        none=8

    };


    class Map{
    public:
        int x_start;
        int y_start;
        int ZASIEG;
        Map(int x, int y){
            ZASIEG=100;
            x_start=x;
            y_start=y;
        }

        target_enum getTarget(int x,int y){
            if(x>x_start+ZASIEG){
                if(y>y_start+ZASIEG) return right_down;
                else if(y<y_start-ZASIEG) return right_up;
                else return right;
            } else if(x<x_start-ZASIEG){
                if(y>y_start+ZASIEG) return left_down;
                else if(y<y_start-ZASIEG) return left_up;
                else return left;
            } else if(y>y_start+ZASIEG) return down;
            else if(y<y_start-ZASIEG) return up;
            else return none;
        }

    };

    MauseGestures(int);

    void testMauseMovement(int,int);
    
    bool testGesture(int[],int size);

    void testAllGestures();

    Map *m;

};


#endif //MAUSE_MAUSEGESTURES_H
