#ifndef _OBJECT_H_
#define _OBJECT_H_

typedef enum InteractionResult { STAY, MOVE, DIE} InteractionResult;

class Object
{
public:
    Object(char _icon) : icon(_icon) {};
    virtual ~Object() {};
    virtual InteractionResult Interact(Object**) = 0;
    char getIcon() {return icon; };

protected:
    char icon;
};

class Stone : public Object
{
public:
    Stone() : Object('o') {};
    InteractionResult Interact(Object**) {return STAY; }; 
};

class Fish : public Object
{
public:
    Fish(char _icon, int _lifeTime, int _breedTime) : Object(_icon), 
                                                      liveTime(_lifeTime), breedTime(_breedTime), 
                                                      curLiveTime(0), curBreedTime(0) {};
    virtual ~Fish() {};
    virtual InteractionResult Interact(Object**) = 0;
protected:
    int liveTime, breedTime, curLiveTime, curBreedTime;
};

class Prey : public Fish
{
public:
    Prey(int _lifeTime, int _breedTime) : Fish('<',_lifeTime, _breedTime) { };

    InteractionResult Interact(Object** object)
    {
        curLiveTime++;
        curBreedTime++;

        if(curLiveTime == liveTime) {return DIE; };

        if(*object == nullptr)
        {
            if(curBreedTime >= breedTime)
            {
                *object = new Prey(liveTime, breedTime);
                curBreedTime = 0;
                return STAY;
            }
            else
            {
                return MOVE;
            }
            
        }
        else
        {
            return STAY;
        }
        
    }
};

class Predator : public Fish
{
public:
    Predator(int _lifeTime, int _breedTime, int _breedBorder) : Fish('@',_lifeTime, _breedTime), breedBorder(_breedBorder) {};

    InteractionResult Interact(Object** object)
    {
        curLiveTime++;
        if(curLiveTime < 0)
        {
            curLiveTime = 0;
        }
        curBreedTime++;

        if(curLiveTime == liveTime) {return DIE; };

        if(*object == nullptr)
        {
            if((curBreedTime >= breedTime) && (curLiveTime < breedBorder))
            {
                *object = new Predator(liveTime, breedTime, breedBorder);
                curBreedTime = 0;
                return STAY;
            }
            else
            {
                return MOVE;
            }
            
        }
        else
        {
            if((*object)->getIcon() == '<')
            {
                delete (*object);
                (*object) = nullptr;
                curLiveTime = curLiveTime - liveTime / 4;
                if(curLiveTime < 0) curLiveTime = 0;

                return MOVE;
            }
            else
            {
                return STAY;
            }  
        } 
    }

private:
    int breedBorder;
};

#endif
