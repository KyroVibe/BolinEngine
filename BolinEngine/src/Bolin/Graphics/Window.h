#pragma once

#include <GLFW/glfw3.h>
#include <string>
#include <vector>

#include "Bolin/Debug.h"
#include "Bolin/Utility.h"
#include "Bolin/Core.h"
#include "Bolin/Graphics/Color.h"
#include "Bolin/Graphics/Point.h"
#include "Bolin/Graphics/Camera.h"

namespace Bolin {
    class BOLIN_API Window {
    public:
        Window(int width, int height, std::string windowName, Camera* camera): _width(width), _height(height), _camera(camera) {

            /* Initialize the library */
            if (!glfwInit())
                WARN("Failed to init");

            /* Create a windowed mode window and its OpenGL context */
            _window = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);
            if (!_window)
            {
                glfwTerminate();
                WARN("Failed to create a window");
                return;
            }

            /* Make the window's context current */
            glfwMakeContextCurrent(_window);
        }

        ~Window() {
            glfwTerminate();
            delete _camera;
        }

        bool ShouldClose() {
            return glfwWindowShouldClose(_window);
        }

        void Clear() {
            glClear(GL_COLOR_BUFFER_BIT);
        }

        void Publish() {
            glfwSwapBuffers(_window);
        }

        void PollEvents() {
            glfwPollEvents();

            // Update size
            /*
#if RESIZEABLE
            glfwGetWindowSize(_window, &_width, &_height); // Doesn't work. Projection matrix doesn't change
#endif
            */
        }

        void SetColor(Color color) {
            glColor4f(color.R, color.G, color.B, color.A);
        }

        void DrawPolygon(std::vector<Point> points, bool fill) {
            if (fill) FillPolygon(points);
            else OutlinePolygon(points);
            
        }

        void FillPolygon(std::vector<Point> points) {
            glBegin(GL_POLYGON);
            for (int i = 0; i < points.size(); i++) {
                glVertex2f(points.at(i).X, points.at(i).Y);
                // LOG("(" << points.at(i).X << ", " << points.at(i).Y << ")");
            }
            glEnd();
        }

        void OutlinePolygon(std::vector<Point> points) {

            if (points.size() < 2) {
                WARN("This is less than a fucking line m8");
                throw 666;
            }

            for (int i = 0; i < points.size() - 1; i++) {
                glBegin(GL_LINE);
                glVertex2f(points.at(i).X, points.at(i).Y);
                glVertex2f(points.at(i + 1).X, points.at(i + 1).Y); // So if the polygon has more than 2.1bn vertices, this will overflow
                glEnd();
            }
        }

        Point CastVector(Vector2 vec) {
            return Utility::ToPoint(((vec - _camera->Position) * Vector2(1, double(_width) / double(_height))) / _camera->Size);
        }
    private:
        int _width, _height;
        GLFWwindow* _window;
        Camera* _camera;
    };

}