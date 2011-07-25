#include "study/stringutils.hpp"
#include <iterator>
#include <list>
#include <string>
#include <sstream>
#include <boost/tokenizer.hpp>
#include <boost/foreach.hpp>

// Ha!  Free functions!

namespace study
{

std::string string_format(
	std::string const& input,
	std::string const& prefix,
	unsigned int max_width)
{
	boost::char_separator<char> sep("\n", "", boost::keep_empty_tokens);
	boost::tokenizer<boost::char_separator<char>> tok(input, sep);
	std::list<std::string> res;
	std::string out;
	BOOST_FOREACH(std::string s, tok)
		res.push_back(s);
	res.pop_back(); // Get rid of last token.
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

std::string string_normalise(std::string const& in) {
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

bool whitespace_ignore_compare( // TODO
	std::string const& /*answer*/,
	std::string const& /*expected*/)
{
	return false;
}

} // namespace study

