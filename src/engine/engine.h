#pragma once
#include "ogl.h"
#include "appinterface.h"
#include "logger.h"
#include <cstdlib>
#include <cassert>

class Engine
{
public:
	int Initialize(AbstractApp *InApp);

	int Run();

protected:
	void UnInitialize();

private:
	GLFWwindow* mWindow;
	AbstractApp* mApp;
};

extern Engine GEngine;