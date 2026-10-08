#pragma once

struct GLFWwindow;

class GameInterface
{
public:
	virtual void Initialize() {};
	virtual void Initialize(GLFWwindow* window) { Initialize(); };
	
	virtual void Update(double deltaTime) {}; // clampen, gerade beim debuggen, damit maximal z.B. 1/10s nur geschieht und nicht auf einmal 30s
	virtual void Render(float aspectRatio) {};

	virtual void ClearResources() {};
};
