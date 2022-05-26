#pragma once


#include <map>
#include <string>
#include <iostream>

#include "../StoreLibrary/Products.h"

#define GETALLFAMILIES 1
#define GETALLPRODUCTS 2
#define GETPRODUCTINFO 3
#define PURCHASE 4


void FillCtrlFunctions(std::map <int, std::string>& functions);

void RunCommands(int command_number);
void RunCommands(std::map <int, std::string>& functions, int client_num);
