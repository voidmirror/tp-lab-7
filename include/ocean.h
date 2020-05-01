#ifndef _OCEAN_H_
#define _OCEAN_H_

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

#include "object.h"

class Ocean
{
public:
    Ocean(int _h, int _w) : h(_h), w(_w) 
    {
        field = new Object*[h*w];

        for(int i = 0 ; i < h*w; i ++)
        {
            field[i] = nullptr;
        }
    }; 

    ~Ocean()
    {
        for(int i = 0 ; i < h*w; i ++)
        {
            delete field[i];
        }
        delete[] field;
    }

    bool init(int stoneCount, int preyCount, int predatorCount)
    {
        if((stoneCount+preyCount+predatorCount) >=  h*w ) 
        {
            return false; 
        }

        std::srand(unsigned(std::time(0)));

        for(int i = 0; i < stoneCount;)
        {
            int rnd = std::rand() % (h*w);

            if(field[rnd] == nullptr)
            {
                field[rnd] = new Stone;
                i++;
            }
        }

        for(int i = 0; i < preyCount;)
        {
            int rnd = std::rand() % (h*w);

            if(field[rnd] == nullptr)
            {
                field[rnd] = new Prey(1000, 250);
                i++;
            }
        }

        for(int i = 0; i < predatorCount;)
        {
            int rnd = std::rand() % (h*w);

            if(field[rnd] == nullptr)
            {
                field[rnd] = new Predator(1000, 800, 50);
                i++;
            }
        }

        return true;
    }

    void iterate()
    {
        std::srand(unsigned(std::time(0)));

        for(int i = 0; i < h*w; i++)
        {
            int rnd = std::rand() % 800;

            if(field[i] != nullptr)
            {

                int x = i / w;
                int y = i % w;

                if(rnd < 100)
                {
                    x -= 1;
                    y += 1;
                }
                else if(rnd < 200)
                {
                    y += 1;
                }
                else if(rnd < 300)
                {
                    x += 1;
                    y += 1;
                }
                else if(rnd < 400)
                {
                    x += 1;
                }
                else if(rnd < 500)
                {
                    x += 1;
                    y -= 1;
                }
                else if(rnd < 600)
                {
                    y -= 1;
                }
                else if(rnd < 700)
                {
                    x -= 1;
                    y -= 1;
                }
                else
                {
                    x -= 1;
                }

                if((x >= 0) && (x < h) && (y >= 0 ) && (y < w))
                { 
                    switch ((field[i])->Interact(&field[x * w + y]))
                    {
                    case MOVE:
                        field[x * w + y] = field[i];
                        field[i] = nullptr;
                        break;
                    case DIE:
                        delete field[i];
                        field[i] = nullptr;
                        break;
                    default:
                        break;

                    }
                }
            }
        }
    }

    void printOcean()
    {
        std::cout << "+";
        for(int j = 0 ; j < w; j ++)
        {
            std::cout << "-";
        }
        std::cout << "+\n";

        for(int i = 0 ; i < h; i ++)
        {
            std::cout << "|";
            for(int j = 0 ; j < w; j ++)
            {
                if(field[i * w + j] == nullptr)
                {
                    std::cout << " ";
                }
                else
                {
                    std::cout << (*(field[i * w + j])).getIcon();
                }
            }
            std::cout << "|\n";
        }
        std::cout << "+";
        for(int j = 0 ; j < w; j ++)
        {
            std::cout << "-";
        }
        std::cout << "+\n";
    }

    bool iterationStatus()
    {
        int preyCount = 0;
        int predatorCount = 0;

        for (int i = 0; i < h*w; i++)
        {
            if(field[i] != nullptr)
            {
                switch (field[i]->getIcon())
                {
                case '<':
                    preyCount++;
                    break;
                case '@':
                    predatorCount++;
                    break;
                }
            }
        }
        
        std::cout << "< " <<  preyCount << "\n";
        std::cout << "@ " <<  predatorCount << "\n";
        return ((preyCount > 0) && (predatorCount > 0));
    }

private:
    Object** field;
    int h;
    int w;
};

#endif
