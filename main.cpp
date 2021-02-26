#include <iostream>
#include <cstdio>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <fstream>

#include "crow.h"

int main()
{
    crow::SimpleApp app;

    // hello world - default route
    CROW_ROUTE(app, "/")([](){
        return "Hello world";
    });

    app.server_name("CrowCpp").port(18080).multithreaded().run();
}