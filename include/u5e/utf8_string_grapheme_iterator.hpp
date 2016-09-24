#ifndef INCLUDED_U5E_UTF8_STRING_GRAPHEME_ITERATOR
#define INCLUDED_U5E_UTF8_STRING_GRAPHEME_ITERATOR

#include <u5e/utf8_string_grapheme.hpp>
#include <u5e/grapheme_iterator.hpp>

namespace u5e {
  typedef grapheme_iterator<utf8_string> utf8_string_grapheme_iterator;
};

#endif