#pragma once

#include <iostream>
#include <sstream>
#include <vector>

#include <NTL/ZZX.h>

class BigInteger {
public:
    BigInteger(); // 默认构造函数
    explicit BigInteger(const NTL::ZZ& val); // 参数为 ZZ 类对象的构造函数


	// Copy constructor
	BigInteger(const BigInteger &other);

	// Assignment operator
	BigInteger& operator=(const BigInteger &other);

	// Destructor
	~BigInteger();

	// Copy function
	void copy(const BigInteger &other);

	// Arithmetic operations
	BigInteger operator+(const BigInteger &other) const;
	BigInteger operator-(const BigInteger &other) const;
	BigInteger operator*(const BigInteger &other) const;
        BigInteger operator%(const BigInteger &other) const;

	// Comparison operators
	bool operator==(const BigInteger &other) const;
	bool operator!=(const BigInteger &other) const;
	bool operator<(const BigInteger &other) const;
	bool operator>(const BigInteger &other) const;
	bool operator<=(const BigInteger &other) const;
	bool operator>=(const BigInteger &other) const;

	// Output stream operator
	friend std::ostream& operator<<(std::ostream &os, const BigInteger &bigInt);
	// 將大整數轉換為字符串
	std::string toString() const;

    //void SetLength(long n); // 设置长度
    BigInteger rem(const BigInteger& a) const; // 取余
    BigInteger AddMod(const BigInteger& a, const BigInteger& b) const; // 模加
    BigInteger SubMod(const BigInteger& a, const BigInteger& b) const; // 模减
    const NTL::ZZ& rep() const; // 返回 ZZ 对象
    BigInteger MulMod(const BigInteger& a, const BigInteger& b) const; // 模乘
    BigInteger& LeftShift(long n); // 左移
    BigInteger& RightShift(long n); // 右移
    void kill(); // 释放资源

public:
    NTL::ZZ element; // ZZ 对象
};

