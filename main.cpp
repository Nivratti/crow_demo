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

    // handling params
    CROW_ROUTE(app, "/params")
    ([](const crow::request& req){
        // // std::cout<<req.body;
        // std::cout<< req.url_params;
        // std::cout<< req.url_params.get("a");

        std::ostringstream os;
        os << "Params: " << req.url_params << "\n\n"; 
        os << "The key 'foo' was " << (req.url_params.get("foo") == nullptr ? "not " : "") << "found.\n";
        if(req.url_params.get("pew") != nullptr) {
            double countD = boost::lexical_cast<double>(req.url_params.get("pew"));
            os << "The value of 'pew' is " <<  countD << '\n';
        }
        return crow::response{os.str()};
    });    

    app.server_name("CrowCpp").port(18080).multithreaded().run();
}