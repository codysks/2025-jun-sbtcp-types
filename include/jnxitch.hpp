#ifndef SOUPBINTCP_JNX_ITCH_HPP
#define SOUPBINTCP_JNX_ITCH_HPP

#include "component.hpp"

namespace Sbtcp::JnxItch {
using namespace Sbtcp::ComponentTypes;

typedef CharN<4> GroupType;
typedef CharN<4> OrderbookIdType;
typedef CharN<4> AttributionType;
typedef CharN<12> OrderbookCodeType;
/*
	void const* unpack(void const* buf) {
		auto _buf = static_cast<unsigned char const*>(buf);
		_buf += message_type.unpack(_buf);
		_buf += nanoseconds.unpack(_buf);
		_buf += .unpack(_buf);
		_buf += .unpack(_buf);
		_buf += .unpack(_buf);
		_buf += .unpack(_buf);
		_buf += .unpack(_buf);
		_buf += .unpack(_buf);
		return _buf;
	}
*/

// 4.1
struct Timestamp {
	EnumChar message_type;
	U4B seconds;
	void const* unpack(void const* buf) {
		auto _buf = static_cast<unsigned char const*>(buf);
		_buf += message_type.unpack(_buf);
		_buf += seconds.unpack(_buf);
		return _buf;
	}
};
// 4.2
struct SystemEvent {
	EnumChar message_type;
	U4B nanoseconds;
	GroupType group;
	EnumChar system_event;
	void const* unpack(void const* buf) {
		auto _buf = static_cast<unsigned char const*>(buf);
		_buf += message_type.unpack(_buf);
		_buf += nanoseconds.unpack(_buf);
		_buf += group.unpack(_buf);
		_buf += system_event.unpack(_buf);
		return _buf;
	}
};
// 4.3
struct PriceTickSize {
	EnumChar message_type;
	U4B nanoseconds;
	U4B price_tick_size_table_id;
	U4B price_tick_size;
	U4B price_start;
	void const* unpack(void const* buf) {
		auto _buf = static_cast<unsigned char const*>(buf);
		_buf += message_type.unpack(_buf);
		_buf += nanoseconds.unpack(_buf);
		_buf += price_tick_size_table_id.unpack(_buf);
		_buf += price_tick_size.unpack(_buf);
	 	_buf += price_start.unpack(_buf);
		return _buf;
	}
};
// 4.4
struct OrderbookDirectory {
	EnumChar message_type;
	U4B nanoseconds;
	OrderbookIdType orderbook_id;
	OrderbookCodeType orderbook_code;
	GroupType group;
	U4B round_lot_size;
	U4B price_tick_size_table_id;
	U4B price_decimals;
	U4B upper_price_limit;
	U4B lower_price_limit;
	void const* unpack(void const* buf) {
		auto _buf = static_cast<unsigned char const*>(buf);
		_buf += message_type.unpack(_buf);
		_buf += nanoseconds.unpack(_buf);
		_buf += orderbook_id.unpack(_buf);
		_buf += orderbook_code.unpack(_buf);
		_buf += group.unpack(_buf);
		_buf += round_lot_size.unpack(_buf);
		_buf += price_tick_size_table_id.unpack(_buf);
		_buf += price_decimals.unpack(_buf);
		_buf += upper_price_limit.unpack(_buf);
		_buf += lower_price_limit.unpack(_buf);
		return _buf;
	}
};
// 4.5
struct TradingState {
	EnumChar message_type;
	U4B nanoseconds;
	OrderbookIdType orderbook_id;
	GroupType group;
	EnumChar trading_state;
	void const* unpack(void const* buf) {
		auto _buf = static_cast<unsigned char const*>(buf);
		_buf += message_type.unpack(_buf);
		_buf += nanoseconds.unpack(_buf);
		_buf += orderbook_id.unpack(_buf);
		_buf += group.unpack(_buf);
		_buf += trading_state.unpack(_buf);
		return _buf;
	}


};
// 4.6
struct ShortSellingPriceRestrictionState {
	EnumChar message_type;
	U4B nanoseconds;
	OrderbookIdType orderbook_id;
	GroupType group;
	EnumChar short_selling_state;
	void const* unpack(void const* buf) {
		auto _buf = static_cast<unsigned char const*>(buf);
		_buf += message_type.unpack(_buf);
		_buf += nanoseconds.unpack(_buf);
		_buf += orderbook_id.unpack(_buf);
		_buf += group.unpack(_buf);
		_buf += short_selling_state.unpack(_buf);
		return _buf;
	}

};
// 4.7.1
struct OrderAdded {
	EnumChar message_type;
	U4B nanoseconds;
	U8B order_number;
	EnumChar buy_sell_indicator;
	U4B quantity;
	OrderbookIdType orderbook_id;
	GroupType group;
	U4B price;
	void const* unpack(void const* buf) {
		auto _buf = static_cast<unsigned char const*>(buf);
		_buf += message_type.unpack(_buf);
		_buf += nanoseconds.unpack(_buf);
		_buf += order_number.unpack(_buf);
		_buf += buy_sell_indicator.unpack(_buf);
		_buf += quantity.unpack(_buf);
		_buf += orderbook_id.unpack(_buf);
		_buf += group.unpack(_buf);
		_buf += price.unpack(_buf);
		return _buf;
	}

};
// 4.7.2
struct OrderAddedAttributes {
	EnumChar message_type;
	U4B nanoseconds;
	U8B order_number;
	EnumChar buy_sell_indicator;
	U4B quantity;
	OrderbookIdType orderbook_id;
	GroupType group;
	U4B price;
	AttributionType attribution;
	EnumChar order_type;
	void const* unpack(void const* buf) {
		auto _buf = static_cast<unsigned char const*>(buf);
        _buf += message_type.unpack(_buf);
        _buf += nanoseconds.unpack(_buf);
        _buf += order_number.unpack(_buf);
        _buf += buy_sell_indicator.unpack(_buf);
        _buf += quantity.unpack(_buf);
        _buf += orderbook_id.unpack(_buf);
        _buf += group.unpack(_buf);
        _buf += price.unpack(_buf);
		_buf += attribution.unpack(_buf);
		_buf += order_type.unpack(_buf);
		return _buf;
	}

};
// 4.8
struct OrderExecuted {
	EnumChar message_type;
	U4B nanoseconds;
	U8B order_number;
	U4B executed_quantity;
	U8B match_number;
	void const* unpack(void const* buf) {
		auto _buf = static_cast<unsigned char const*>(buf);
		_buf += message_type.unpack(_buf);
		_buf += nanoseconds.unpack(_buf);
		_buf += order_number.unpack(_buf);
		_buf += executed_quantity.unpack(_buf);
		_buf += match_number.unpack(_buf);
		return _buf;
	}

};
// 4.9
struct OrderDeleted {
	EnumChar message_type;
	U4B nanoseconds;
	U8B order_number;
	void const* unpack(void const* buf) {
		auto _buf = static_cast<unsigned char const*>(buf);
		_buf += message_type.unpack(_buf);
		_buf += nanoseconds.unpack(_buf);
		_buf += order_number.unpack(_buf);
		return _buf;
	}

};
// 4.10
struct OrderReplaced {
	EnumChar message_type;
	U4B nanoseconds;
	U8B original_order_number;
	U8B new_order_number;
	U4B quantity;
	U4B price;
	void const* unpack(void const* buf) {
		auto _buf = static_cast<unsigned char const*>(buf);
		_buf += message_type.unpack(_buf);
		_buf += nanoseconds.unpack(_buf);
		_buf += original_order_number.unpack(_buf);
		_buf += new_order_number.unpack(_buf);
		_buf += quantity.unpack(_buf);
		_buf += price.unpack(_buf);
		return _buf;
	}

};
} // namespace Sbtcp::JnxItch

#endif /* SOUPBINTCP_JNX_ITCH_HPP */

