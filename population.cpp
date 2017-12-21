#include "population.hpp"

Population::Population(int population, float mutationRate){
    this->population = population;
    this->mutationRate = mutationRate;
    
    for(int i=0; i<population; i++){
        list.push_back(Rocket());
    }
}

void Population::setTarget(ofPoint start, ofPoint end){
    this->start = start;
    this->end = end;
    for(int i=0; i<population; i++){
        list[i].initVec(start);
    }
}
void Population::run(){
    if(list.at(0).needToEvo()){
        evolve();
    }else{
        for(int i=0; i<population; i++){
            Rocket &r = list.at(i);
            
            r.update();
            r.draw();
        }
    }
}

void Population::update(){
    if(list.at(0).needToEvo()){
        evolve();
    }else{
        for(int i=0; i<population; i++){
            list.at(i).update();
        }
    }
}

void Population::draw(){
    for(int i=0; i<population; i++){
        list.at(i).draw();
    }
}

void Population::evolve(){
    for(int i=0; i<population; i++){
        Rocket &r = list.at(i);
        float dist = r.loc.distance(end);
        dist = ofClamp(dist, 0, 1200);
        r.fit = ofMap(dist,0, 1200, 20, -100);
        r.fit = pow(3, r.fit);
        //        r.fit = r.loc.x*r.loc.x;
        fitSum += r.fit;
    }
    
    for(int i=0; i<population; i++){
        Rocket &r = list.at(i);
        r.prob = r.fit/fitSum;
    }
    fitSum=0;
    
    selection();
}

void Population::selection(){
    vector<Rocket> tempList;
    
    for(int i=0; i<population; i++){
        float ran = ofRandom(1);
        int mom_Index = -1;
        
        do{
            mom_Index ++;
            ran -= list.at(mom_Index).prob;
        }while(ran>=0);
        
        
        int dad_Index;
        while(dad_Index==mom_Index){
            dad_Index = -1;
            ran = ofRandom(1);
            
            do{
                dad_Index ++;
                ran -= list.at(dad_Index).prob;
            }while(ran>=0);
        }
        
        tempList.push_back(reproduction(mom_Index, dad_Index));
        
    }
    
    list = tempList;
}

Rocket Population::reproduction(int mom, int dad){
    Rocket r;
    Rocket &momR = list.at(mom);
    Rocket &dadR = list.at(dad);
    
    for(int i=0; i<r.genoLeng; i++){
        ofPoint vec;
        float ran = ofRandom(1);
        if(ran<.5){
            vec = momR.genoType.at(i);
        }else{
            vec = dadR.genoType.at(i);
        }
        
        float mut = ofRandom(1);
        if(mut <= mutationRate){
            vec = ofPoint(
                          ofRandom(-r.genoStep, r.genoStep),
                          ofRandom(-r.genoStep, r.genoStep)
                          );
        }
        
        r.genoType.push_back(vec);
    }
    
    r.setLoc(start);
    return r;
}




