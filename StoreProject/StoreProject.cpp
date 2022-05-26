// Client.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <windows.h> 

#include <stdio.h>
#include <thread>
#include <cctype>
#include <vector>

#include "ClientControl.h"

int main()
{
    std::map <int, std::string> functions;
    FillCtrlFunctions(functions);

    std::vector<std::thread>clients_threads;


    std::string id = "11bf5b37-e0b8-42e0-8dcf-dc8c4aefc000";

    std::string res = GetProductInformation(id.c_str());
    std::cout << res << std::endl << std::endl;

    const int clients_number = 2;

    for (int i = 0; i < clients_number; ++i)
    {
        std::thread client_thread(PurchaseProduct, id.c_str());
        clients_threads.push_back(std::move(client_thread));

    }

    for (auto& th : clients_threads) {
        th.join();
    }

    std::string reslt = GetProductInformation(id.c_str());
    std::cout << reslt << std::endl << std::endl;

    system("pause");

    return 0;
}
