#pragma once

#include <memory>

#include <axeLib\InputHandler.h>

class AxeSystemContainer
{
public:
	AxeSystemContainer();
	~AxeSystemContainer();
	
	std::unique_ptr<axe::InputHandler> input;

};

