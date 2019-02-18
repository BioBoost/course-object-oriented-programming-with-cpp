## Alternative operator representations

Source: http://en.cppreference.com/w/cpp/language/operator_alternative

C++ (and C) source code may be written in any non-ASCII 7-bit character set that includes the ISO 646:1983 invariant character set. However, several C++ operators and punctuators require characters that are outside of the ISO 646 codeset: {, }, [, ], #, \, ^, |, ~. To be able to use character encodings where some or all of these symbols do not exist (such as the German DIN 66003), C++ defines the following alternatives composed of ISO 646 compatible characters.

### Alternative tokens
There are alternative spellings for several operators and other tokens that use non-ISO646 characters. In all respects of the language, each alternative token behaves exactly the same as its primary token, except for its spelling (the stringification operator can make the spelling visible). The two-letter alternative tokens are sometimes called "digraphs"


Primary	Alternative
&&	and
&=	and_eq
&	bitand
|	bitor
~	compl
!	not
!=	not_eq
||	or
|=	or_eq
^	xor
^=	xor_eq
