//
// Created by Anton Korkunov on 02/04/2020.
//

#include "Ocean.h"
#include "ObjectTypes.h"
#include "Cell.h"
#include <iostream>

using namespace std;
//MxN
Ocean::Ocean(){
    cells = new Cell * [M];
   for(int i = 0; i < M;i++){
        cells[i]=new Cell[N];
        for(int n=0; n<N;n++){
            cells[i][n].init({static_cast<coord_t>(n),static_cast<coord_t>(i)},this);
        }
    }
}

void Ocean::print() const{
    for (int m = 0; m < M; m++)
    {
        for (int n = 0; n < M; n++)
            if (cells[m][n].getObject()!=nullptr) cout<<"  " << cells[m][n].getObject()->type()<<"  ";
            else cout <<"  "<< "| |"<<"  ";
        cout << endl << endl;
    }
}

void Ocean::addObjects() {

    for(int m = 0; m<M; m++) {
        for (int n = 0; n < N; n++) {

            int ch = rand() % 9 + 1;

            switch (ch) {//prob control
                case 1:
                    cells[m][n].setObject(new Stone());
                    break;
                case 2:
                    cells[m][n].setObject(new Prey(Preprod,Plife));
                    break;
                case 3:
                    cells[m][n].setObject(new Predator(PRreprod,PRlife,PRhunger));
                    break;
                case 4:
                    cells[m][n].setObject(new Prey(Preprod,Plife));
                    break;
                case 5:
                    cells[m][n].setObject(new Prey(Preprod,Plife));
                    break;
                case 6:
                    cells[m][n].setObject(new Prey(Preprod,Plife));
                    break;
                case 7:
                    cells[m][n].setObject(new Prey(Preprod,Plife));
                    break;
            }
            if(ch<8){
            cells[m][n].getObject()->setCell(&cells[m][n]);
            Vstuff.push_back(cells[m][n].getObject());}
        }
    }
}

Cell* Ocean::FindEmpty(Pair crd){
    int X[]={0,0,-1,1,1,-1,1,-1};
    int Y[]={1,-1,0,0,1,-1,-1,1};
    for(int k=0;k<8;k++) {
        int i = rand() % 8 + 1;
        i--;
        if ((N > crd.x + X[i] ) && (M > crd.y + Y[i] ) && (crd.y + Y[i]!=-1) && (crd.x + X[i]!=-1) ) {
            if (cells[crd.y + Y[i]][crd.x + X[i]].getObject() == nullptr) {
                return &cells[crd.y + Y[i]][crd.x + X[i]];
            }
        }
    }
    return nullptr;
};

void Ocean::run(){
    size = Vstuff.size();
    for(int i=0;i<size;i++){
        Vstuff[i]->live();
    }
};

void Ocean::DeleteObj(Object* val){
    size--;
    Vstuff.erase(std::remove(Vstuff.begin(), Vstuff.end(), val), Vstuff.end());
};

void Ocean::addObject(Object* val){
    Vstuff.push_back(val);
};

Cell* Ocean::FindObject(Pair crd, std::string par){
    int X[]={1,0,-1,-1,0,1,1,-1};
    int Y[]={1,1,0,1,-1,0,-1,-1};
    for(int k=0;k<8;k++) {
        int i = rand() % 8 + 1;
        i--;
        if ((N > crd.x + X[i] ) && (M > crd.y + Y[i] ) && (crd.y + Y[i]!=-1) && (crd.x + X[i]!=-1) && (cells[crd.y + Y[i]][crd.x + X[i]].getObject()!=nullptr)) {
            if (cells[crd.y + Y[i]][crd.x + X[i]].getObject()->type() == par ) {
                return &cells[crd.y + Y[i]][crd.x + X[i]];
            }
        }
    }
    return nullptr;
};

Ocean::~Ocean() {
    for (int cnt = 0; cnt < M; cnt++) {
        delete[] cells[cnt];
    }
    delete cells;
    for (int n = 0; n < Vstuff.size(); n++) {
        delete Vstuff[n];
    }
    Vstuff.clear();
}
