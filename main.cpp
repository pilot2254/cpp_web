// website built with a language meant to control nuclear plants btw

#include "httplib.h"
#include <string>
using namespace httplib; // i know that only npcs use `using namespace ...`
                         // but because im learning httplib ill use this FOR NOW

/*
// old

int main()
{
        Server svr;

        svr.Get("/", [](const Request &, Response &res)
                { res.set_content("<h1>yo from c++</h1>", "text/html"); });

        svr.listen("0.0.0.0", 8080);
}
*/

int main()
{
        Server app;

        // root
        app.Get("/", [](const Request &, Response &res)
                { res.set_content("cpp backend alive", "text/plain"); });

        // very real api route
        app.Get("/api/user", [](const Request &, Response &res)
                { res.set_content(
                      R"({"id":1,"name":"mike","status":"the goat"})",
                      "application/json"
                );
        });

        // echo json post
        app.Post("/api/echo", [](const Request &req, Response &res)
                 { res.set_content(req.body, "application/json");
                });

        // query param
        //      example: /api/hello?name=lads
        app.Get("/api/hello", [](const Request &req, Response &res)
                {
        std::string name = req.get_param_value("name");
        res.set_content("hello " + name, "text/plain"); });

        app.listen("0.0.0.0", 8080);
}

// g++ main.cpp -std=c++17 -pthread
// or
// g++ main.cpp -std=c++17 -pthread -lws2_32
//      (using winsocket -> ws2_32.lib)

// localhost:8080