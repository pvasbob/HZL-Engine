#include "HZL.h"

class Sandbox : public HZL::Application {
public:
	Sandbox() {

	}
	~Sandbox() {

	}

};

HZL::Application* HZL::CreateApplication() {
	return new Sandbox;
}


