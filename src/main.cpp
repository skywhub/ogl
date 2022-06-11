#include "app/launcher.h"
#include "engine/engine.h"
#include LAUNCHER

int main()
{
    AppClass app;
    LOG("App :", app.GetName());
    if (GEngine.Initialize(&app) != 0)
    {
        return EXIT_FAILURE;
    }
    return GEngine.Run();
}