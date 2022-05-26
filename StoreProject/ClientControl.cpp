
#include "ClientControl.h"


void FillCtrlFunctions(std::map <int, std::string>& functions)
{
    functions = { {1, "Get All Familes"},
                    {2, "Get All Products"},
                    {3, "Get Product Information"},
                    {4, "Purchase"} };
}

void RunCommands(int command_number)
{
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


void RunCommands(std::map <int, std::string>& functions, int client_num)
{

    while (true)
    {
        std::cout << "{" << std::endl;
        for (const auto& elem : functions)
        {
            std::cout << " " << elem.first << ":   " << elem.second << std::endl;
        }
        std::cout << "}\n" << std::endl;

        std::cout << "Enter command number for client #" << std::to_string(client_num) << ":" << std::endl;; // no flush needed
        std::string command_str;

        std::getline(std::cin, command_str);

        if (std::isdigit(command_str[0]) == 0)
            continue;

        int command_number = INT_MIN;
        command_number = std::stoi(command_str);


        std::map<int, std::string>::iterator it = functions.find(command_number);

        if (it == functions.end())
        {
            std::cout << "The command doesn't exist" << std::endl << std::endl;
            continue;
        }

        RunCommands(command_number);

    }
}