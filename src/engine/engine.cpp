#include "engine.h"

Engine GEngine;

void G_OnFrameBufferChanged(GLFWwindow* Wnd, int W, int H)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, W, H);
}

int Engine::Initialize(AbstractApp* InApp)
{
    LOG("Engine start ...");
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // glfw window creation
    // --------------------
    GLFWwindow* Window = glfwCreateWindow(InApp->GetWndWidth(), InApp->GetWndHeight(), InApp->GetName(), NULL, NULL);
    if (!Window)
    {
        LOG("Failed to create GLFW window.");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(Window);
    glfwSetFramebufferSizeCallback(Window, G_OnFrameBufferChanged);
    LOG("GLFW startup successfully.");

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        LOG("Failed to initialize GLAD");
        glfwTerminate();
        return -1;
    }
    LOG("GLAD startup successfully.");
    mWindow = Window;
    mApp = InApp;
    return 0;
}

void Engine::UnInitialize()
{
    if (mApp)
    {
        mApp = nullptr;
        mWindow = nullptr;
        glfwTerminate();
        LOG("Engine exit");
    }
}

int Engine::Run()
{
    assert(mApp);
    assert(mWindow);
    // Guard
    struct Guard
    {
        AbstractApp& app;
        Guard(AbstractApp& app) :app{ app } { app.OnStart(); }
        ~Guard() { app.OnExit(); }
    }RunAppGuard(*mApp);
    LOG("Engine runing...");
    // render loop
    // -----------
    while (!glfwWindowShouldClose(mWindow))
    {
        // input
        // -----
        if (glfwGetKey(mWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(mWindow, true);
        mApp->OnInput();
        mApp->OnUpdate();
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(mWindow);
        glfwPollEvents();
    }
    UnInitialize();
    return EXIT_SUCCESS;
}
