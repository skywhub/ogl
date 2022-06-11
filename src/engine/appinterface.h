#pragma once

class AbstractApp
{
public:
	virtual const char* GetName();
	virtual int GetWndWidth();
	virtual int GetWndHeight();
	virtual void OnInput();
	virtual void OnStart() = 0;
	virtual void OnExit() = 0;
	virtual void OnUpdate() = 0;
};