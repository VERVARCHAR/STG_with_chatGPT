#include "core/Application.hpp"

int main()
{
    Application app;
    if (app.init())
    {
        app.run();
    }
    return 0;
}
