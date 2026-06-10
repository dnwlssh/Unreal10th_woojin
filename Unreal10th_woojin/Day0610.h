#pragma once
#include <type_traits>

template <typename T>
class Calculator
{
public:
	
	template<typename Num1, typename Num2>
	auto Add(Num1 Num1, Num2 Num2) const
	{
		return Num1 + Num2;
	}

	template<typename Num1, typename Num2>
	void Sub(Num1 Num1, Num2 Num2) const
	{
		return Num1 - Num2;
	}

	template<typename Num1, typename Num2>
	void Mul(Num1 Num1, Num2 Num2) const
	{
		return Num1 * Num2;
	}

	template<typename Num1, typename Num2>
	void Div(Num1 Num1, Num2 Num2) const
	{
		if (Num2 == 0)
		{
			throw std::reuntime_error("0으로 나눌 수 없습니다.");
		}
		return Num1 / Num2;
	}
};



// --- 전역 함수로 분리된 연산자 오버로딩 ---

// 덧셈 연산자 오버로딩 (전역 함수)
template <typename T>
Calculator<T> operator+(const Calculator<T>& Left, const Calculator<T>& Right)
{
	return Coordinate<T>(Left.x + Right.x, Left.y + Right.y);
}

// 뺄셈 연산자 오버로딩 (전역 함수)
template <typename T>
Calculator<T> operator-(const Calculator<T>& Left, const Calculator<T>& Right)
{
	return Coordinate<T>(Left.x - Right.x, Left.y - Right.y);
}

// 등호 연산자 오버로딩 (전역 함수)
template <typename T>
bool operator==(const Calculator<T>& Left, const Calculator<T>& Right)
{
	bool Result = false;
	if constexpr (std::is_same_v<T, float>) {
		float diffX = Left.x - Right.x;
		float diffY = Left.y - Right.y;
		if (diffX < 0) diffX *= -1;
		if (diffY < 0) diffY *= -1;
		Result = diffX < 0.001f && diffY < 0.001f;
	}
	else if constexpr (std::is_same_v<T, double>) {
		double diffX = Left.x - Right.x;
		double diffY = Left.y - Right.y;
		if (diffX < 0) diffX *= -1;
		if (diffY < 0) diffY *= -1;
		Result = diffX < 0.001f && diffY < 0.001f;
	}
	else {
		Result = ((Left.x == Right.x) && (Left.y == Right.y));
	}
	return Result;
}

// 부등호 연산자 오버로딩 (전역 함수)
template <typename T>
bool operator!=(const Calculator<T>& Left, const Calculator<T>& Right)
{
	// 이미 구현된 operator== 를 재사용합니다.
	return !(Left == Right);
}