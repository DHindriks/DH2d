// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>
#include <iostream>
#include <common/renderer.h>
#include <common/camera.h>
#include <common/sprite.h>

int main( void )
{
	Renderer renderer(1280, 720);


	Sprite* pencils = new Sprite("assets/endpoint.tga");
	Sprite* kingkong = new Sprite("assets/spaceship.tga");
	Sprite* rgba = new Sprite("assets/rock.tga");
	//Entity* spaceship = new Entity();

	float rot_z = 0.0f;
	glm::vec3 position = glm::vec3(900, 400, 0);
	float rotation = 0.0f;
	do {
		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Compute the ViewMatrix from keyboard and mouse input (see: camera.h/cpp)
		computeMatricesFromInputs(renderer.window());

		//glm::vec3 cursor = getCursor(); // from Camera
		//printf("(%f,%f)\n",cursor.x, cursor.y);

		// Render all Sprites (Sprite*, xpos, ypos, xscale, yscale, rotation)
		renderer.renderSprite(pencils, 400, 300, 1.0f, 1.0f, 0.0f);
		renderer.renderSprite(kingkong, position.x, position.y, 1.0f, 1.0f, rotation);
		renderer.renderSprite(rgba, renderer.width()/2, renderer.height()/2, 3.0f, 3.0f, 0.0f);
		rot_z += 0.03f;

		if (glfwGetKey(renderer.window(), GLFW_KEY_W) == GLFW_PRESS) {
			position.y -= 1;
			std::cout << position.y << std::endl;
		}

		if (glfwGetKey(renderer.window(), GLFW_KEY_A) == GLFW_PRESS) {
			rotation -= 0.01;
			std::cout << position.y << std::endl;
		}

		if (glfwGetKey(renderer.window(), GLFW_KEY_S) == GLFW_PRESS) {
			position.y += 1;
			std::cout << position.y << std::endl;
		}

		if (glfwGetKey(renderer.window(), GLFW_KEY_D) == GLFW_PRESS) {
			rotation += 0.01;
			std::cout << position.y << std::endl;
		}

		// Swap buffers
		glfwSwapBuffers(renderer.window());
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(renderer.window(), GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   glfwWindowShouldClose(renderer.window()) == 0 );

	delete pencils;
	delete kingkong;
	delete rgba;

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}
