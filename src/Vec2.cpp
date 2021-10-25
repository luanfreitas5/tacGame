/**
 * @file Vec2.cpp
 * @author Luan Mendes Gonçalves Freitas - 150015585
 * @brief Modulo dos metodos da classe Vec2
 * @version 0.2
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../include/Vec2.h"

/**
 * @brief Construtor da Classe Vec2
 * Inicializa as coordenadas com zero
 *
 */
Vec2::Vec2() {
	this->x = 0;
	this->y = 0;
}

/**
 * @brief Construtor da Classe Vec2
 * Inicializa as coordenadas com parametros de entrada
 *
 * @param x coordenada horizontal do retangulo
 * @param y coordenada vertical do retangulo
 */
Vec2::Vec2(float x, float y) {
	this->x = x;
	this->y = y;
}

/**
 * @brief Metodo calcular um ponto aleatorio para preencher o objeto de jogo na tela
 *
 * @param distancia valor da distancia entre o primeiro valor Vec2 e o segundo 2 Vec2 aleatorio.
 */
void Vec2::CalcularRotacaoAngulo(float distancia) {

	double angulo;
	random_device numeroRand;

	angulo = (double) (2 * PI * ((double) numeroRand() / numeroRand.max()));

	x += (float) (cos(angulo) * distancia);
	y += (float) (sin(angulo) * distancia);
}

/**
 * @brief Operacao Adicao
 *
 * @param v
 * @return Vec2
 */
Vec2 Vec2::operator+(const Vec2 &v) {

	Vec2 vec2 = Vec2(x + v.x, y + v.y);
	return vec2;

}

/**
 * @brief Operacao Adicao
 *
 * @param v
 * @return Vec2
 */
Vec2 Vec2::operator+(const float v) {

	Vec2 vec2 = Vec2(x + v, y + v);
	return vec2;

}

/**
 * @brief Operacao Substracao
 *
 * @param v
 * @return Vec2
 */
Vec2 Vec2::operator-(const Vec2 &v) {

	Vec2 vec2 = Vec2(x - v.x, y - v.y);
	return vec2;

}

Vec2 Vec2::operator-(const float v) {

	Vec2 vec2 = Vec2(x - v, y - v);
	return vec2;

}

/**
 * @brief Operacao Multiplicacao
 *
 * @param v
 * @return Vec2
 */
Vec2 Vec2::operator*(const Vec2 &v) {

	Vec2 vec2 = Vec2(x * v.x, y * v.y);
	return vec2;

}

/**
 * @brief Operacao Multiplicacao
 *
 * @param v
 * @return Vec2
 */
Vec2 Vec2::operator*(const float v) {

	Vec2 vec2 = Vec2(x * v, y * v);
	return vec2;

}

/**
 * @brief Operacao Divisao
 *
 * @param v
 * @return Vec2
 */
Vec2 Vec2::operator/(const Vec2 &v) {

	Vec2 vec2 = Vec2(x / v.x, y / v.y);
	return vec2;

}

/**
 * @brief Operacao Divisao
 *
 * @param v
 * @return Vec2
 */
Vec2 Vec2::operator/(const float v) {

	Vec2 vec2 = Vec2(x / v, y / v);
	return vec2;

}

/**
 * @brief Get Distance
 *
 * @param vec2
 * @return float
 */
float Vec2::GetDistance(Vec2 vec2) {

	float x = pow(GetDistanceX(vec2.x), 2);
	float y = pow(GetDistanceY(vec2.y), 2);

	float distance = pow(x + y, 0.5);

	return distance;

}

/**
 * @brief Get Distance X
 *
 * @param x
 * @return float
 */
float Vec2::GetDistanceX(float x) {

	float distance = x - this->x;

	return distance;

}

/**
 * @brief Get Distance Y
 *
 * @param y
 * @return float
 */
float Vec2::GetDistanceY(float y) {

	float distance = y - this->y;

	return distance;

}

/**
 * @brief Calcular Cos
 *
 * @param angle
 * @return float
 */
float Vec2::Cos(float angle) {

	float cos_angle = cos(angle * PI / 180);

	return cos_angle;

}

/**
 * @brief Get valor Cos
 *
 * @param vec2
 * @return float
 */
float Vec2::GetCos(Vec2 vec2) {

	float x = GetDistanceX(vec2.x);
	float y = GetDistance(vec2);

	float valor_sin = x / y;

	return valor_sin;

}

/**
 * @brief Calcular Sin
 *
 * @param angle
 * @return float
 */
float Vec2::Sin(float angle) {

	float sin_angle = sin(angle * PI / 180);

	return sin_angle;

}

/**
 * @brief Get valor Sin
 *
 * @param vec2
 * @return float
 */
float Vec2::GetSin(Vec2 vec2) {
	float x = GetDistance(vec2);
	float y = GetDistanceY(vec2.y);

	float valor_sin = y / x;

	return valor_sin;

}

/**
 * @brief Get Angle
 *
 * @param vec2
 * @return float
 */
float Vec2::GetAngle(Vec2 vec2) {

	float x = GetDistanceX(vec2.x);
	float y = GetDistanceY(vec2.y);
	float angle = atan2(y, x) * (180 / PI);

	return angle;

}
