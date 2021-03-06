# Streams versus String Formatting

The C++ standard library provides support for localization on a level that doesn't quite have a analogous comparison in other languages. The way in which the stream itself is made aware of locales and how the shift operator on streams has its behaviors dependant on locales is an unique design decision on how input and output operates on an application.

Localization happens in many different levels, and coupling the reading and writing to streams with that is, imho, an unecessarily heavy-handed decision. Specifically, most applications read and write from streams much more frequently than when interacting with the localized user interface. It is much more frequent that an application will be dealing with serialization formats and network protocols that are not locale-dependant, than an application will be dealing with interactive input and output that is meant to be localized.

When working in an internationalized application, it is crucial that the moments in which the locale reflects in the behavior of the application should be explicitly demarcated from the places in which the application is dealing with "data" input and output. The C++ standard library makes that harder.

## Streams can't quite deal with text anyway.

See [Streams vs Iterators](StreamVsIterators.md) for a long explanation on why streams are the wrong tools to deal with text.

## Number and Date format must be decoupled from the stream

I think it's an unavoidable fact that any number and date format must be deocupled from the stream. It is really tempting to try to optimize away the intermediate state built with the output data, but I think the problems I presented demonstrate this optimization is not viable if we want to have unambiguous handling of text.

I'd also argue that this optimization is also premature, because the context in which that formatting happens is usually already in the context of building an intermediate representation anyway. It is very common, for instance, to have the actual writing of the data on the underlying channel delegated to another thread, so in most cases the intermediate value is already present anyway.

## The syntax-sugar of the shift operator may still be preserved

A Number and Date format library can easily present a similar-looking syntax sugar for composing those intermediate values, wit the advantage of more clearly separating the concerns of creating the formatted value and submitting that formatted value to a stream.

That will also have the advantage of eliminating the concern of partial reads and partial writes from everything that handles text formatting and parsing.