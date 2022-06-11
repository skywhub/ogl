#include "launcher.h"
#include "engine/engine.h"
#include LAUNCHER

int main()
{
    LOG("App path:", LAUNCHER);
    LoadApp();
    if (GEngine.Initialize(&app) != 0)
    {
        return EXIT_FAILURE;
    }
    return GEngine.Run();
}