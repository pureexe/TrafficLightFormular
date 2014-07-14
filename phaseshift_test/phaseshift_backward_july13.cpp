/*
AUTHOR : PAKKAPON PHONGTHAWEE
FILE : PHASHSHIFT_BACKWARD
LAGN : CPP
DATE : July 13,2014 13:30
*/
#include<cstdio>
using namespace std;
#define MAX_SPEED ((float)50/3)
#define ACCELETION ((float)25/9)
#define LENGTH (float)1200
#define MAX_LIGHT 1000
#define MAX_INTERVAL 75
#define MAX_PHASHSHIFT 75
class Light {
public:
    float interval,phaseshift,currenttime,Tinterval;
    bool stage;
    Light() {};
    Light(float inter,float shift) {
        setLight(inter,shift);
        Light();
    }
    void setLight(float inter,float shift) {
        interval = inter;
        Tinterval = inter*2;
        phaseshift = (float)((int)shift%(int)Tinterval);
        currenttime = (interval*2)-phaseshift;
        if(currenttime>interval) {
            stage=false;
        } else {
            stage = true;
        }
    }
    void beat() {
        currenttime++;
        if(currenttime>Tinterval) {
            currenttime=0;
        }
        if(currenttime>interval) {
            stage=false;
        } else {
            stage = true;
        }
    }
    bool getPass() {
        return stage;
    };
    ~Light() {};
protected:
private:
};
int u=0;
int _main(int interval,int shift) {
    Light light[MAX_LIGHT];
    int i;
    for(i=0; i<MAX_LIGHT; i++) {
        light[i].setLight(interval,shift*i);
    }
    float speed,distance;
    int currentLight = 0;
    while(currentLight<MAX_LIGHT) {
        speed+=ACCELETION;
        if(speed>MAX_SPEED) {
            speed = MAX_SPEED;
        }
        if(distance<LENGTH&&distance+speed>=LENGTH) {
            if(light[currentLight+1].getPass()) {
                    break;
            } else {
                currentLight++;
                distance-=LENGTH;
            }
        }
        distance+=speed;
        for(i=0; i<MAX_LIGHT; i++) {
            light[i].beat();
        }
    }
    if(currentLight !=1000 && currentLight>u){
        u=currentLight;
    }
    printf("%d|",currentLight);
    return 0;
}
int main() {
    int i=0,j=0;
    for(i=1;i<=MAX_INTERVAL;i++){
        for(j=1;j<=MAX_PHASHSHIFT;j++){
            printf("",i,j);
            _main(i,j);
        }
        printf("\n");
    }
    return 0;
}
