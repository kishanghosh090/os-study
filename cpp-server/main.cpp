// step 1-----------------

// #include "httplib.h"
// #include <iostream>

// int main()
// {
//     httplib::Server svr;

//     svr.Get("/", [](const httplib::Request &, httplib::Response &res)
//             { res.set_content("<h1>Hello from C++ Server</h1>", "text/html"); });

//     std::cout << "Server running on http://localhost:8080\n";
//     svr.listen("0.0.0.0", 8080);
// }

// step 2 (add index.html)-----------------

// #include "httplib.h"
// #include <iostream>
// #include <fstream>
// #include <sstream>

// std::string readFile(const std::string &path)
// {
//     std::ifstream file(path);
//     if (!file)
//         return "<h1>File not found</h1>";
//     std::stringstream buffer;
//     buffer << file.rdbuf();
//     return buffer.str();
// }

// int main()
// {
//     httplib::Server svr;

//     svr.Get("/", [](const httplib::Request &, httplib::Response &res)
//             {
//         std::string html = readFile("public/index.html");
//         res.set_content(html, "text/html"); });

//     std::cout << "Server running on http://localhost:8080\n";
//     svr.listen("0.0.0.0", 8080);
// }

// step 3 (add json data)-----------------

#include "httplib.h"
#include "json.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

using json = nlohmann::json;

// Function to read file
std::string readFile(const std::string &path)
{
    std::ifstream file(path);
    if (!file)
        return "<h1>File not found</h1>";
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

int main()
{
    httplib::Server svr;

    // Serve HTML file
    svr.Get("/", [](const httplib::Request &, httplib::Response &res)
            {
        std::string html = readFile("public/index.html");
        res.set_content(html, "text/html"); });

    // API route returning JSON
    svr.Get("/api/data", [](const httplib::Request &, httplib::Response &res)
            {
        json response;
        response["message"] = "Hello from C++ API";
        response["number"] = 42;
        response["status"] = true;

        res.set_content(response.dump(), "application/json"); });

    std::cout << "Server running on http://localhost:8080\n";
    svr.listen("0.0.0.0", 8080);
}
