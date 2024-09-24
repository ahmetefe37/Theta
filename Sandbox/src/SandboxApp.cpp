#include "Theta.h"

class Sandbox : public Theta::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}

private:

};

Theta::Application* Theta::CreateApplication()
{
	return new Sandbox();
}