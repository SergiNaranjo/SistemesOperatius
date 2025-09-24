#include <iostream>
#include "TutorialThread/Utils/ConsoleControl.h"
#include <functional>
#include <list>

typedef  std::function<int(int, int)> SumaFunction;
typedef  std::list<std::list<int>> ListaDeListas;

void TestLambdasMolonas(std::function<int(int, int)> funcionMolona)
{
    std::cout << "Voy a ejecutar una funcion que estaba en una variable" << std::endl;
    int number = funcionMolona(5, 7);
    std::cout << "Ya la he ejecutado --> " << number << std::endl;
}

void Test1(ListaDeListas listaDeCosas)
{

}

void Test2(ListaDeListas listaDeCosas)
{

}

void Test2(ListaDeListas listaDeCosas)
{

}

int main()
{
    std::string name = "Pepe";

    SumaFunction funcionQueHaceCosasPeroEsUnaVariable = [name](int a, int b) {
            std::cout << "Esto no se como pero funciona --> " << name << std::endl;
            return a + b;
        };

    TestLambdasMolonas(funcionQueHaceCosasPeroEsUnaVariable);
}

