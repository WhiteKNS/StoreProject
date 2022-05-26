// Client.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <windows.h> 

#include <stdio.h>
#include <iostream>
#include <map>
#include "../StoreLibrary/Products.h"

#define GETALLFAMILIES 1
#define GETALLPRODUCTS 2
#define GETPRODUCTINFO 3
#define PURCHASE 4


void FillFunctions(std::map <int, std::string>& functions)
{
    functions = {   {1, "Get All Familes"},
                    {2, "Get All Products"},
                    {3, "Get Product Information"},
                    {4, "Purchase"}};
}

void ClientRun()
{
    std::map <int, std::string> functions;
    FillFunctions(functions);

    while (true)
    {
        std::cout << "{" << std::endl;
        for (const auto& elem : functions)
        {
            std::cout << " " << elem.first << ":   " << elem.second << std::endl;
        }
        std::cout << "}\n" << std::endl;

        int command_number = INT_MIN;
        std::cout << "Enter command number: "; // no flush needed
        std::cin >> command_number;

        std::map<int, std::string>::iterator it = functions.find(command_number);

        if (it == functions.end())
        {
            std::cout << "The command doesn't exist" << std::endl << std::endl;
            continue;
        }


        switch (command_number)
        {
        case GETALLFAMILIES:
        {
            std::string res = GetAllProductFamilies();
            std::cout << res << std::endl << std::endl;
        }
        break;

        case GETALLPRODUCTS:
        {
            std::string family_name;
            std::cout << "Enter family name " << std::endl;
            std::cin >> family_name;
            std::string res = GetAllProducts(family_name.c_str());
            std::cout << res << std::endl << std::endl;
        }
        break;

        case GETPRODUCTINFO:
        {
            std::string product_info;
            std::cout << "Get Product Information " << std::endl;
            std::cin >> product_info;
            std::string res = GetProductInformation(product_info.c_str());
            std::cout << res << std::endl << std::endl;
        }
        break;

        case PURCHASE:
        {
            std::string id;
            std::cout << "Purchase Product " << std::endl;
            std::cin >> id;
            bool res = PurchaseProduct(id.c_str());

            if (res)
                std::cout << "Purchased " << std::endl << std::endl;
        }
        break;
        default:
         break;
        }

       
    }
}


int main()
{
    ClientRun();

    return 0;
}
