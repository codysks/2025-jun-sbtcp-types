#ifndef TEST_SHARED_HEADERS_HPP
#define TEST_SHARED_HEADERS_HPP

#include <stdexcept>
#include <sstream>
#include <string>
#include <functional>
#include <cstddef>

#ifdef NDEBUG
# error "NDEBUG must be unset"
#endif

#define ASSERTNOT(X, Y) assert(false, X, #X, Y, #Y, \
	(std::string(__FILE__) + std::string(":") + std::to_string(__LINE__)).c_str(), \
	[](){ throw "fail"; } \
);
#define ASSERT(X, Y) assert(true, X, #X, Y, #Y, \
	(std::string(__FILE__) + std::string(":") + std::to_string(__LINE__)).c_str(), \
	[](){ throw "fail"; } \
);
struct AssertExcept {
	AssertExcept(std::string msg) : msg_(msg) {}
	char const* what(void) { return msg_.c_str(); }
	std::string msg_;
};

template <typename T, typename U>
void assert(
	bool expect_equal,
	T tested,
	char const* tested_name,
	U expected,
	char const* expected_name,
	char const* trailer,
	std::function<void (void)> call_on_fail = [](){ (void)0; },
	std::ostream& os = std::cerr
) {
	bool condition = tested == expected;
	if (!expect_equal)
		condition = !condition;
	std::ostringstream head_;
	head_ << "ASSERTION " << (condition ? "PASSED" : "FAILED");
	std::ostringstream condition_;
	condition_ << tested_name << "(" << tested << ")"; 
	condition_ << (expect_equal ? "==" : "!=");
	condition_ << expected_name << "(" << expected << ")";
	std::ostringstream trailer_;
	trailer_ << trailer;
	os << head_.str() << ';' << condition_.str() << ';' << trailer_.str() << std::endl;
	if (!condition)
		call_on_fail();
}
#define XCOMPOSE_4U_C_(A, B, C, D) A, B, C, D
#define XCOMPOSE_4U_C(I) XCOMPOSE_4U_C_(I, I+1, I+2, I+3)
constexpr uint32_t XCOMPOSE_4U_V(unsigned char starting_value) {
	uint32_t ret = starting_value;
	for (size_t i = 0; i < 3; ++i) {
		++starting_value;
		ret = (ret << 8) + starting_value;
	}
	return ret;
}
static_assert(25ull * 16777216ull + 26ull * 65536 + 27 * 256 + 28 == XCOMPOSE_4U_V(25));
constexpr unsigned char xcompose_4u_c_test_string1[] = { 25, 26, 27, 28 };
constexpr unsigned char xcompose_4u_c_test_string2[] = { XCOMPOSE_4U_C(25) };
static_assert(xcompose_4u_c_test_string1[0] == xcompose_4u_c_test_string2[0]);
static_assert(xcompose_4u_c_test_string1[1] == xcompose_4u_c_test_string2[1]);
static_assert(xcompose_4u_c_test_string1[2] == xcompose_4u_c_test_string2[2]);
static_assert(xcompose_4u_c_test_string1[3] == xcompose_4u_c_test_string2[3]);

#define XCOMPOSE_8U_C_(A, B, C, D, E, F, G, H) A, B, C, D, E, F, G, H
#define XCOMPOSE_8U_C(I) XCOMPOSE_8U_C_(I, I+1, I+2, I+3, I+4, I+5, I+6, I+7)
constexpr uint64_t XCOMPOSE_8U_V(unsigned char starting_value) {
	uint64_t ret = starting_value;
	for (size_t i = 0; i < 7; ++i) {
		++starting_value;
		ret = (ret << 8) + starting_value;
	}
	return ret;
}
static_assert(21ull * 72057594037927936ull + 22ull * 281474976710656ull + 23ull * 1099511627776ull + 24ull * 4294967296ull +
	25ull * 16777216ull + 26ull * 65536 + 27 * 256 + 28 == XCOMPOSE_8U_V(21));
constexpr unsigned char xcompose_8u_c_test_string1[] = { 21, 22, 23, 24, 25, 26, 27, 28 };
constexpr unsigned char xcompose_8u_c_test_string2[] = { XCOMPOSE_8U_C(21) };
static_assert(xcompose_8u_c_test_string1[0] == xcompose_8u_c_test_string2[0]);
static_assert(xcompose_8u_c_test_string1[1] == xcompose_8u_c_test_string2[1]);
static_assert(xcompose_8u_c_test_string1[2] == xcompose_8u_c_test_string2[2]);
static_assert(xcompose_8u_c_test_string1[3] == xcompose_8u_c_test_string2[3]);
static_assert(xcompose_8u_c_test_string1[4] == xcompose_8u_c_test_string2[4]);
static_assert(xcompose_8u_c_test_string1[5] == xcompose_8u_c_test_string2[5]);
static_assert(xcompose_8u_c_test_string1[6] == xcompose_8u_c_test_string2[6]);
static_assert(xcompose_8u_c_test_string1[7] == xcompose_8u_c_test_string2[7]);

#define SECONDS_CHAR_COMPOSITION XCOMPOSE_4U_C(252)
#define SECONDS_LITERAL          XCOMPOSE_4U_V(252)
#define NANOSECOND_CHAR_COMPOSITION XCOMPOSE_4U_C(1)
#define NANOSECOND_LITERAL          XCOMPOSE_4U_V(1)
#define GROUP_DAY_CHAR_COMPOSITION 'D', 'A', 'Y', ' '
#define GROUP_DAY_LITERAL          "DAY "
#define PRICE_TICK_SIZE_TABLE_ID_CHAR_COMPOSITION XCOMPOSE_4U_C(5)
#define PRICE_TICK_SIZE_TABLE_ID_LITERAL          XCOMPOSE_4U_V(5)
#define PRICE_TICK_SIZE_CHAR_COMPOSITION XCOMPOSE_4U_C(9)
#define PRICE_TICK_SIZE_LITERAL          XCOMPOSE_4U_V(9)
#define PRICE_START_CHAR_COMPOSITION XCOMPOSE_4U_C(13)
#define PRICE_START_LITERAL          XCOMPOSE_4U_V(13)
#define ORDERBOOK_ID_CHAR_COMPOSITION '1', 'A', '2', 'C'
#define ORDERBOOK_ID_LITERAL          "1A2C"
#define ORDERBOOK_CODE_CHAR_COMPOSITION 'U', 'S', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
#define ORDERBOOK_CODE_LITERAL          "US0123456789"
#define ROUND_LOT_SIZE_CHAR_COMPOSITION    XCOMPOSE_4U_C(17)
#define ROUND_LOT_SIZE_LITERAL             XCOMPOSE_4U_V(17)
#define PRICE_DECIMALS_CHAR_COMPOSITION    XCOMPOSE_4U_C(21)
#define PRICE_DECIMALS_LITERAL             XCOMPOSE_4U_V(21)
#define UPPER_PRICE_LIMIT_CHAR_COMPOSITION XCOMPOSE_4U_C(25)
#define UPPER_PRICE_LIMIT_LITERAL          XCOMPOSE_4U_V(25)
#define LOWER_PRICE_LIMIT_CHAR_COMPOSITION XCOMPOSE_4U_C(29)
#define LOWER_PRICE_LIMIT_LITERAL          XCOMPOSE_4U_V(29)
#define ORDER_NUMBER_CHAR_COMPOSITION      XCOMPOSE_8U_C(33)
#define ORDER_NUMBER_LITERAL               XCOMPOSE_8U_V(33)
#define QUANTITY_CHAR_COMPOSITION          XCOMPOSE_4U_C(41)
#define QUANTITY_LITERAL                   XCOMPOSE_4U_V(41)
#define PRICE_CHAR_COMPOSITION             XCOMPOSE_4U_C(45)
#define PRICE_LITERAL                      XCOMPOSE_4U_V(45)
#define ATTRIBUTION_CHAR_COMPOSITION    ' ', ' ', ' ', ' '
#define ATTRIBUTION_ID_LITERAL          "    "
// #define _CHAR_COMPOSITION XCOMPOSE_4U_C()
// #define _LITERAL          XCOMPOSE_4U_V()

#define INVOKE_TEST(F) do { \
	std::cerr << #F << "()" << std::endl; \
	F(); \
} while (false)

#endif /* TEST_SHARED_HEADERS_HPP */

