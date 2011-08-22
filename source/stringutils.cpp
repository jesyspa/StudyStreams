#include "study/stringutils.hpp"
#include <cmath>
#include <limits>
#include <iterator>
#include <list>
#include <string>
#include <sstream>
#include <boost/algorithm/string.hpp>
#include <boost/tokenizer.hpp>
#include <boost/foreach.hpp>

// Ha!  Free functions!

namespace study
{

string_format::string_format() :
	prefix(""),
	max_width(80)
{}

std::string string_format::operator()(std::string const& input) const
{
	boost::char_separator<char> sep("\n", "", boost::keep_empty_tokens);
	boost::tokenizer<boost::char_separator<char>> tok(input, sep);
	std::list<std::string> res;
	std::string out;
	BOOST_FOREACH(std::string s, tok)
		res.push_back(s);
	for (auto it = res.begin(); it != res.end(); ++it) {
		*it = prefix + *it;
		if (max_width && it->length() > max_width) {
			std::string pre = it->substr(0, max_width);
			*it = it->substr(max_width);
			res.insert(it, pre);
			--it;
		}
		out += *it + '\n';
	}
	return out;
}

std::string string_sanitise(std::string const& in) {
	std::string s;
	s.reserve(in.length());
	for (auto it = in.begin(); it != in.end(); ++it) {
		switch (*it) {
			case '\n':
				s += '\\';
				s += 'n';
				break;
			case '\t':
				s += '\\';
				s += 't';
				break;
			default:
				s += *it;
				break;
		}
	}
	return s;
}

bool simple_compare(
	std::string const& answer,
	std::string const& actual)
{
	return answer == actual;
}

bool loose_compare(
	std::string const& answer,
	std::string const& actual)
{
	using boost::to_lower;
	std::string i_answer = answer;
	std::string i_actual = actual;
	to_lower(i_answer);
	to_lower(i_actual);
	return whitespace_ignore_compare(i_answer, i_answer);
}

bool whitespace_ignore_compare(
	std::string const& answer,
	std::string const& expected)
{
	boost::tokenizer<> answer_tok(answer);
	boost::tokenizer<> expected_tok(expected);
	auto answer_it = answer_tok.begin();
	BOOST_FOREACH(std::string expected_str, expected_tok) {
		if (expected_str != *answer_it)
			return false;
		++answer_it;
	}
	return answer_it == answer_tok.end(); // Check that answer is also finished
}

bool float_compare(
	std::string const& answer,
	std::string const& actual
)
{
	std::stringstream ans(answer), act(actual);
	double n, c;
	while (ans >> n) {
		if (!(act >> c)) {
			return false;
		}
		if (fabs(n - c) > std::numeric_limits<double>::epsilon() * 16 * fmax(fabs(n), fabs(c))) { // Make sure the two aren't too far apart.
			return false;
		}
	}
	if ((act >> c)) {
		return false;
	}
	return true;
}

bool case_insensitive_compare(
	std::string const& answer,
	std::string const& expected)
{
	boost::algorithm::is_iequal i;
	return i(answer, expected);
}

} // namespace study

