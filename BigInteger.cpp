#include "BigInteger.h"

// 默认构造函数
BigInteger::BigInteger() {
    // 默认构造函数
}

// 参数为 ZZ 类对象的构造函数
BigInteger::BigInteger(const NTL::ZZ& val) {
    element = val;
}

// 设置长度
//void BigInteger::SetLength(long n) {
//    element.SetLength(n);
//}

// 取余
BigInteger BigInteger::rem(const BigInteger& a) const {
    BigInteger result;
    NTL::rem(result.element, element, a.element);
    return result;
}

// 模加
BigInteger BigInteger::AddMod(const BigInteger& a, const BigInteger& b) const {
    BigInteger result;
    NTL::AddMod(result.element, element, a.element, b.element);
    return result;
}

// 模减
BigInteger BigInteger::SubMod(const BigInteger& a, const BigInteger& b) const {
    BigInteger result;
    NTL::SubMod(result.element, element, a.element, b.element);
    return result;
}

// 返回 ZZ 对象
const NTL::ZZ& BigInteger::rep() const {
    return element;
}

// 模乘
BigInteger BigInteger::MulMod(const BigInteger& a, const BigInteger& b) const {
    BigInteger result;
    NTL::MulMod(result.element, element, a.element, b.element);
    return result;
}

// 左移
BigInteger& BigInteger::LeftShift(long n) {
    NTL::LeftShift(element, element, n);
return *this;
}

// 右移
BigInteger& BigInteger::RightShift(long n) {
    NTL::RightShift(element, element, n);
return *this;
}

// 释放资源
void BigInteger::kill() {
    element.kill();
}

// Copy constructor
BigInteger::BigInteger(const BigInteger &other) {
    element = other.element; // 使用ZZ的赋值运算符重载
}

// Assignment operator
BigInteger& BigInteger::operator=(const BigInteger &other) {
    if (this != &other) {
        element = other.element; // 使用ZZ的赋值运算符重载
    }
    return *this;
}


// Destructor
BigInteger::~BigInteger() {
    // 在这里无需执行任何操作，因为 ZZ 对象的销毁由 NTL 库自动处理
}

// Arithmetic operations
BigInteger BigInteger::operator+(const BigInteger &other) const {
    BigInteger result;
    NTL::add(result.element, element, other.element);
    return result;
}

BigInteger BigInteger::operator-(const BigInteger &other) const {
    BigInteger result;
    NTL::sub(result.element, element, other.element);
    return result;
}

BigInteger BigInteger::operator*(const BigInteger &other) const {
    BigInteger result;
    NTL::mul(result.element, element, other.element);
    return result;
}

BigInteger BigInteger::operator%(const BigInteger &other) const {
    BigInteger result;
    NTL::rem(result.element, element, other.element);
    return result;
}


// Comparison operators
bool BigInteger::operator==(const BigInteger &other) const {
    return element == other.element;
}

bool BigInteger::operator!=(const BigInteger &other) const {
    return element != other.element;
}

bool BigInteger::operator<(const BigInteger &other) const {
    return element < other.element;
}

bool BigInteger::operator>(const BigInteger &other) const {
    return element > other.element;
}

bool BigInteger::operator<=(const BigInteger &other) const {
    return element <= other.element;
}

bool BigInteger::operator>=(const BigInteger &other) const {
    return element >= other.element;
}

// Output stream operator
std::ostream& operator<<(std::ostream &os, const BigInteger &bigInt) {
    os << bigInt.element;
    return os;
}

// 將大整數轉換為字符串
std::string BigInteger::toString() const {
    std::stringstream ss;
    ss << element;
    return ss.str();
}

