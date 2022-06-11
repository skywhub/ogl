#pragma once
#include "../engine/appinterface.h"

class LearnApp : public AbstractApp
{
	const char* GetName() override
	{
		return "LearnOpenGL";
	}

	void OnStart() override
	{

	}

	void OnInput() override
	{

	}

	void OnExit() override
	{

	}

	void OnUpdate() override
	{

	}
};

#define LoadApp() LearnApp app