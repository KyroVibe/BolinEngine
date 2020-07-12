#pragma once

struct Vector2 {
public:
	Vector2() : X(0.0), Y(0.0) { }
	Vector2(double x, double y) : X(x), Y(y) { }

	double X, Y;

	Vector2 operator+(const Vector2& vec) {
		return Vector2(this->X + vec.X, this->Y + vec.Y);
	}
	Vector2 operator-(const Vector2& vec) {
		return Vector2(this->X - vec.X, this->Y - vec.Y);
	}
	Vector2 operator*(const double& scal) {
		return Vector2(this->X * scal, this->Y * scal);
	}
	Vector2 operator*(const Vector2& vec) { // Very unoridinary method that I use for casting vectors
		return Vector2(this->X * vec.X, this->Y * vec.Y);
	}
	Vector2 operator/(const double& scal) {
		return Vector2(this->X / scal, this->Y / scal);
	}
};