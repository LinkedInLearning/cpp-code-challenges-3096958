// rational.cpp by Bill Weinman [bw.org]
// updated 2022-07-21
#include <format>
#include <string>

using std::string;

// format-style print()
constexpr void print(const std::string_view str_fmt, auto&&... args) {
    fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
}

const string nanstr {"[NAN]"};

class Rational {
    int n {0};
    int d {1};
public:
    Rational(int numerator = 0, int denominator = 1) : n(numerator), d(denominator) {}
    Rational(const Rational& rhs) : n(rhs.n), d(rhs.d) {}    // copy constructor
    ~Rational();
    int numerator() const { return n; };
    int denominator() const { return d; };
    Rational reduce() const;    // reduce fraction
    string str() const;         // return a formatted STL string
    string raw_str() const;     // return a non-reduced STL string
    Rational& operator = (const Rational&);  // assignment
    Rational operator + (const Rational&) const;
    Rational operator - (const Rational&) const;
    Rational operator * (const Rational&) const;
    Rational operator / (const Rational&) const;
};

Rational Rational::reduce() const {
    if(n == 0 || d <= 3) return *this;
    for(auto div = d - 1; div; --div) {
        if(n % div == 0 && d % div == 0) {
            return Rational(n / div, d / div );
        }
    }
    return *this;
}

string Rational::str() const {
    if(d == 0) return nanstr;
    if(d == 1 || n == 0) return std::to_string(n);

    auto abs_n = abs(n);     // absolute value
    if(abs_n > d) {
        auto whole = n / d;
        auto remainder = abs_n % d;
        if(remainder) return std::to_string(whole) + " " + Rational(remainder, d).str();
        else return std::to_string(whole);
    } else {
        return reduce().raw_str();
    }
}

string Rational::raw_str() const {
    return std::to_string(n) + "/" + std::to_string(d);
}

Rational& Rational::operator = (const Rational& rhs) {
    if (this != &rhs) {
        n = rhs.numerator();
        d = rhs.denominator();
    }
    return *this;
}

Rational Rational::operator + (const Rational& rhs) const {
    return Rational((n * rhs.d) + (d * rhs.n), d * rhs.d);
}

Rational Rational::operator - (const Rational& rhs) const {
    return Rational((n * rhs.d) - (d * rhs.n), d * rhs.d);
}

Rational Rational::operator * (const Rational& rhs) const {
    return Rational(n * rhs.n, d * rhs.d);
}

Rational Rational::operator / (const Rational& rhs) const {
    return Rational(n * rhs.d, d * rhs.n);
}

Rational::~Rational() {
    n = 0; d = 1;
}

// formatter specialization
template<>
struct std::formatter<Rational>: std::formatter<unsigned> {
    template<typename FormatContext>
    auto format(const Rational& o, FormatContext& ctx) {
        return format_to(ctx.out(), "{}", o.str());
    }
};

int main() {
    Rational a {7};         // 7/1
    print("a is: {} = {}\n", a.raw_str(), a);

    Rational b(25, 15);     // 5/3
    print("b is: {} = {}\n", b.raw_str(), b);

    auto c = b;     // copy constructor
    print("c is: {} = {}\n", c.raw_str(), c);

    Rational d;     // default constructor
    print("d is: {} = {}\n", d.raw_str(), d);

    d = c;          // assignment operator
    print("d is: {} = {}\n", d.raw_str(), d);

    auto& e = d;    // reference
    d = e;          // assignment to self!
    print("e is: {} = {}\n", e.raw_str(), e);
    print("d is: {} = {}\n", d.raw_str(), d);

    print("\n");
    print("a + b = {}\n", a + b);
    print("a - b = {}\n", a - b);
    print("a * b = {}\n", a * b);
    print("a / b = {}\n", a / b);
}
