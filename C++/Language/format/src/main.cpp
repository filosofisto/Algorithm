#include <iostream>
#include <format>
#include <print>

using namespace std;

struct Frac
{
	long n;
	long d;
};

namespace std
{
	template<>
	struct formatter<Frac, char>
	{
    // No custom format options; accept the format spec as-is.
    constexpr auto parse(format_parse_context& ctx) {
    	return ctx.begin();
    }

    auto format(const Frac& f, format_context& ctx) const {
    	return format_to(ctx.out(), "{}/{}", f.n, f.d);
   	}
	};
};

int main()
{
	Frac f{5, 3};
	println("Frac: {}", f);

	return EXIT_SUCCESS;
}
