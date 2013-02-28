Stout is a header-only C++ library.

No action is needed if you would like to use this library in your
project. Simply add the include folder to your include path during
compilation.

Depending on which headers you'd like to use, you may require the
following third party libraries:

  - Boost
  - Google's glog (this dependency will be removed in the future)
  - Google's protobuf
  - Google's gmock/gtest

---

## Stout Overview

There are a handful of primitives that are provided within the library
as well as some namespaced and miscellaneous utilities.


### Primitives

* Duration
* Error
* fatal
* foreach
* hashmap
* hashset
* json
* lambda
* multihashmap
* None
* Nothing
* Option
* Owned
* Result
* Try
* Stopwatch
* UUID

### Utilities

* fs
* gtest
* gzip
* net
* os
* path
* strings

### Miscellaneous

* copy
* numify
* preprocessor
* protobuf
* stringify


## Philosophy

*"Premature optimization is the root of all evil."*

You'll notice that the library is designed in such a way that can lead
to a lot of copying. This decision was deliberate. Capturing the
semantics of pointer ownership is hard to enforce programmatically
unless you copy, and in many instances these copies can be elided by
an optimizing compiler. We've choosen safety rather than premature
optimizations.

Note, however, that we plan to liberally augment the library as we add
C++11 support. In particular, we plan to use rvalue references and
std::unique_ptr (although, likely wrapped as Owned) in order to
explicitly express ownership semantics. Until then, it's unlikely that
the performance overhead incurred via the extra copys is your
bottleneck, and if it is we'd love to hear from you!


## Building Tests

We'll assume you've got a distribution of gmock and have already built
a static archive called libgmock.a (see gmock's README to learn
how). We'll also assume the Boost and glog headers can be found via
the include paths and libglog.* can be found via the library search
paths. You can then build the tests via:

       $ g++ -I${STOUT}/include -I$(GMOCK)/gtest/include -I$(GMOCK)/include \
         ${STOUT}/tests/tests.cpp libgmock.a -lglog -o tests

Note that if you want to test the gzip headers you'll need to define
HAVE_LIBZ and link against libz:

       $ g++ -I${STOUT}/include -I$(GMOCK)/gtest/include -I$(GMOCK)/include \
         -DHAVE_LIBZ ${STOUT}/tests/tests.cpp libgmock.a -lglog -lz -o tests
