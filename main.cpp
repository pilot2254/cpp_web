#include "httplib.h"
using namespace httplib; // i know that only npcs use `using namespace ...`
                         // but because im learning httplib ill use this FOR NOW

int main()
{
        Server svr;

        svr.Get("/", [](const Request &, Response &res)
                { res.set_content("<h1>yo from c++</h1>", "text/html"); });

        svr.listen("0.0.0.0", 8080);
}

// g++ main.cpp -std=c++17 -pthread
// or
// g++ main.cpp -std=c++17 -pthread -lws2_32
//      (using winsocket -> ws2_32.lib)

// localhost:8080