#pragma once

extern Bolin::Application* Bolin::CreateApplication();

int main(int argc, char** argv) {
	auto app = Bolin::CreateApplication();
	app->Run();
	delete app;
}