#include "jnxitch.hpp"

#include "shared_headers.hpp"

/* Test Framework
void (void) {
	constexpr unsigned char message_type_enum = 'H';
	unsigned char msg1[] = { message_type_enum,
		NANOSECOND_CHAR_COMPOSITION,
	};
	Sbtcp::JnxItch:: a;
	a.unpack(msg1);
	ASSERT(a.message_type, message_type_enum);
	ASSERT(a.nanoseconds, NANOSECOND_LITERAL);
	ASSERT(a.,);
}
*/

static
void timestamp(void) {
	unsigned char msg1[] = { 'T', SECONDS_CHAR_COMPOSITION };
	Sbtcp::JnxItch::Timestamp a;
	a.unpack(msg1);
	ASSERT(a.message_type, 'T');
	ASSERT(a.seconds, SECONDS_LITERAL);
}
static

void system_event(void) {
	unsigned char msg1[] = { 'S', NANOSECOND_CHAR_COMPOSITION, GROUP_DAY_CHAR_COMPOSITION, 'O' };
	Sbtcp::JnxItch::SystemEvent a;
	a.unpack(msg1);
	ASSERT(a.message_type, 'S');
	ASSERT(a.nanoseconds, NANOSECOND_LITERAL);
	ASSERT(a.group, GROUP_DAY_LITERAL);
	ASSERT(a.system_event, 'O');
}

void price_tick_size(void) {
	unsigned char msg1[] = { 'L', NANOSECOND_CHAR_COMPOSITION, PRICE_TICK_SIZE_TABLE_ID_CHAR_COMPOSITION,
		PRICE_TICK_SIZE_CHAR_COMPOSITION, PRICE_START_CHAR_COMPOSITION };
	Sbtcp::JnxItch::PriceTickSize a;
	a.unpack(msg1);
	ASSERT(a.message_type, 'L');
	ASSERT(a.nanoseconds, NANOSECOND_LITERAL);
	ASSERT(a.price_tick_size_table_id, PRICE_TICK_SIZE_TABLE_ID_LITERAL);
	ASSERT(a.price_tick_size, PRICE_TICK_SIZE_LITERAL);
	ASSERT(a.price_start, PRICE_START_LITERAL);
}
void orderbook_directory(void) {
	unsigned char msg1[] = { 'R',
		NANOSECOND_CHAR_COMPOSITION,
		ORDERBOOK_ID_CHAR_COMPOSITION,
		ORDERBOOK_CODE_CHAR_COMPOSITION,
		GROUP_DAY_CHAR_COMPOSITION,
		ROUND_LOT_SIZE_CHAR_COMPOSITION,
		PRICE_TICK_SIZE_TABLE_ID_CHAR_COMPOSITION,
		PRICE_DECIMALS_CHAR_COMPOSITION,
		UPPER_PRICE_LIMIT_CHAR_COMPOSITION,
		LOWER_PRICE_LIMIT_CHAR_COMPOSITION
	};
	Sbtcp::JnxItch::OrderbookDirectory a;
	a.unpack(msg1);
	ASSERT(a.message_type, 'R');
	ASSERT(a.nanoseconds, NANOSECOND_LITERAL);
	ASSERT(a.group, GROUP_DAY_LITERAL);
	ASSERT(a.orderbook_id, ORDERBOOK_ID_LITERAL);
	ASSERT(a.orderbook_code, ORDERBOOK_CODE_LITERAL);
	ASSERT(a.round_lot_size, ROUND_LOT_SIZE_LITERAL);
	ASSERT(a.price_tick_size_table_id, PRICE_TICK_SIZE_TABLE_ID_LITERAL);
	ASSERT(a.price_decimals, PRICE_DECIMALS_LITERAL);
	ASSERT(a.upper_price_limit, UPPER_PRICE_LIMIT_LITERAL);
	ASSERT(a.lower_price_limit, LOWER_PRICE_LIMIT_LITERAL);
}
void trading_state(void) {
	constexpr unsigned char message_type_enum = 'H';
	unsigned char trading_states[] = { 'T', 'V' };
	unsigned char msg1[] = { message_type_enum,
		NANOSECOND_CHAR_COMPOSITION,
		ORDERBOOK_ID_CHAR_COMPOSITION,
		GROUP_DAY_CHAR_COMPOSITION,
		trading_states[0]
	};
	Sbtcp::JnxItch::TradingState a;
	a.unpack(msg1);
	ASSERT(a.message_type, message_type_enum);
	ASSERT(a.nanoseconds, NANOSECOND_LITERAL);
	ASSERT(a.orderbook_id, ORDERBOOK_ID_LITERAL);
	ASSERT(a.trading_state, trading_states[0]);
}

void short_selling_price_restriction_state(void) {
	unsigned char short_selling_states[] = { '0', '1' };
	constexpr unsigned char message_type_enum = 'Y';
	unsigned char msg1[] = { message_type_enum,
		NANOSECOND_CHAR_COMPOSITION,
		ORDERBOOK_ID_CHAR_COMPOSITION,
		GROUP_DAY_CHAR_COMPOSITION,
		short_selling_states[0]
	};
	Sbtcp::JnxItch::ShortSellingPriceRestrictionState a;
	a.unpack(msg1);
	ASSERT(a.message_type, message_type_enum);
	ASSERT(a.nanoseconds, NANOSECOND_LITERAL);
	ASSERT(a.orderbook_id, ORDERBOOK_ID_LITERAL);
	ASSERT(a.group, GROUP_DAY_LITERAL);
	ASSERT(a.short_selling_state, short_selling_states[0]);
}
void order_added(void) {
	unsigned char buy_sell_indicators[] = { 'B', 'S', 0 };
	constexpr unsigned char message_type_enum = 'A';
	unsigned char msg1[] = { message_type_enum,
		NANOSECOND_CHAR_COMPOSITION,
		ORDER_NUMBER_CHAR_COMPOSITION,
		buy_sell_indicators[0],
		QUANTITY_CHAR_COMPOSITION,
		ORDERBOOK_ID_CHAR_COMPOSITION,
		GROUP_DAY_CHAR_COMPOSITION,
		PRICE_CHAR_COMPOSITION,
	};
	Sbtcp::JnxItch::OrderAdded a;
	a.unpack(msg1);
	ASSERT(a.message_type, message_type_enum);
	ASSERT(a.nanoseconds, NANOSECOND_LITERAL);
	ASSERT(a.order_number, ORDER_NUMBER_LITERAL);
	ASSERT(a.buy_sell_indicator, buy_sell_indicators[0]);
	ASSERT(a.quantity, QUANTITY_LITERAL);
	ASSERT(a.orderbook_id, ORDERBOOK_ID_LITERAL);
	ASSERT(a.group, GROUP_DAY_LITERAL);
	ASSERT(a.price, PRICE_LITERAL);
}

void order_added_attributes(void) {
	unsigned char buy_sell_indicators[] = { 'B', 'S', 0 };
	unsigned char order_type[] = { 'Q' };
	constexpr unsigned char message_type_enum = 'F';
	unsigned char msg1[] = { message_type_enum,
		NANOSECOND_CHAR_COMPOSITION,
		ORDER_NUMBER_CHAR_COMPOSITION,
		buy_sell_indicators[0],
		QUANTITY_CHAR_COMPOSITION,
		ORDERBOOK_ID_CHAR_COMPOSITION,
		GROUP_DAY_CHAR_COMPOSITION,
		PRICE_CHAR_COMPOSITION,
		ATTRIBUTION_CHAR_COMPOSITION,
		order_type[0],
		
	};
	Sbtcp::JnxItch::OrderAddedAttributes a;
	a.unpack(msg1);
	ASSERT(a.message_type, message_type_enum);
	ASSERT(a.nanoseconds, NANOSECOND_LITERAL);
	ASSERT(a.order_number, ORDER_NUMBER_LITERAL);
	ASSERT(a.buy_sell_indicator, buy_sell_indicators[0]);
	ASSERT(a.quantity, QUANTITY_LITERAL);
	ASSERT(a.orderbook_id, ORDERBOOK_ID_LITERAL);
	ASSERT(a.group, GROUP_DAY_LITERAL);
	ASSERT(a.price, PRICE_LITERAL);
	ASSERT(a.attribution, ATTRIBUTION_ID_LITERAL);
	ASSERT(a.order_type, order_type[0]);
}

void order_executed(void) {
	constexpr unsigned char message_type_enum = 'E';
	unsigned char msg1[] = { message_type_enum,
		NANOSECOND_CHAR_COMPOSITION,
		ORDER_NUMBER_CHAR_COMPOSITION,
		QUANTITY_CHAR_COMPOSITION,
		ORDER_NUMBER_CHAR_COMPOSITION,
	};
	Sbtcp::JnxItch::OrderExecuted a;
	a.unpack(msg1);
	ASSERT(a.message_type, message_type_enum);
	ASSERT(a.nanoseconds, NANOSECOND_LITERAL);
	ASSERT(a.executed_quantity, QUANTITY_LITERAL);
	ASSERT(a.match_number, ORDER_NUMBER_LITERAL);
	ASSERT(a.order_number, ORDER_NUMBER_LITERAL);
}
void order_deleted(void) {
	constexpr unsigned char message_type_enum = 'D';
	unsigned char msg1[] = { message_type_enum,
		NANOSECOND_CHAR_COMPOSITION,
		ORDER_NUMBER_CHAR_COMPOSITION
	};
	Sbtcp::JnxItch::OrderDeleted a;
	a.unpack(msg1);
	ASSERT(a.message_type, message_type_enum);
	ASSERT(a.nanoseconds, NANOSECOND_LITERAL);
	ASSERT(a.order_number, ORDER_NUMBER_LITERAL);
}

void order_replaced(void) {
	constexpr unsigned char message_type_enum = 'U';
	unsigned char msg1[] = { message_type_enum,
		NANOSECOND_CHAR_COMPOSITION,
		ORDER_NUMBER_CHAR_COMPOSITION,
		ORDER_NUMBER_CHAR_COMPOSITION,
		QUANTITY_CHAR_COMPOSITION,
		PRICE_CHAR_COMPOSITION,
	};
	Sbtcp::JnxItch::OrderReplaced a;
	a.unpack(msg1);
	ASSERT(a.message_type, message_type_enum);
	ASSERT(a.nanoseconds, NANOSECOND_LITERAL);
	ASSERT(a.original_order_number, ORDER_NUMBER_LITERAL);
	ASSERT(a.new_order_number, ORDER_NUMBER_LITERAL);
	ASSERT(a.price, PRICE_LITERAL);
}
int main(void) {
	INVOKE_TEST(timestamp);
	INVOKE_TEST(system_event);
	INVOKE_TEST(price_tick_size);
	INVOKE_TEST(orderbook_directory);
	INVOKE_TEST(trading_state);
	INVOKE_TEST(short_selling_price_restriction_state);
	INVOKE_TEST(order_added);
	INVOKE_TEST(order_added_attributes);
	INVOKE_TEST(order_executed);
	INVOKE_TEST(order_deleted);
	INVOKE_TEST(order_replaced);
	return 0;
}

