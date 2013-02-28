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

## User Guide

There are a handful of primitives and collections that are provided
within the library, as well as some namespaced and miscellaneous
utilities.


* <a href="#Primitives">Primitives</a>
  - <a href="#Duration">Duration</a>
  - <a href="#Error">Error</a>
  - <a href="#None">None</a>
  - <a href="#Nothing">Nothing</a>
  - <a href="#Option">Option</a>
  - <a href="#Owned">Owned</a>
  - <a href="#Result">Result</a>
  - <a href="#Try">Try</a>
  - <a href="#Stopwatch">Stopwatch</a>
  - <a href="#UUID">UUID</a>

* <a href="#Collections">Collections</a>
  - <a href="#cache">cache</a>
  - <a href="#hashmap">hashmap</a>
  - <a href="#hashset">hashset</a>
  - <a href="#multihashmap">multihashmap</a>

* <a href="#Namespaces">Namespaces</a>
  - <a href="#fs">fs</a>
  - <a href="#gzip">gzip</a>
  - <a href="#JSON">JSON</a>
  - <a href="#lambda">lambda</a>
  - <a href="#net">net</a>
  - <a href="#os">os</a>
  - <a href="#path">path</a>
  - <a href="#protobuf">protobuf</a>
  - <a href="#strings">strings</a>

* <a href="#Miscellaneous">Miscellaneous</a>
  - <a href="#copy">copy</a>
  - <a href="#fatal">fatal</a>
  - <a href="#foreach>foreach</a>
  - <a href="#gtest">gtest</a>
  - <a href="#numify">numify</a>
  - <a href="#preprocessor">preprocessor</a>
  - <a href="#stringify">stringify</a>


<a name="Primitives"></a>

## Primitives

**Note that none of the primitives are namespaced!**


<a name="Duration"></a>

### Duration

Used to represent some duration of time. T


<a href="Error"></a>

### Error


<a href="None"></a>

### None


<a href="Nothing"></a>

### Nothing


<a href="Option"></a>

### Option


<a href="Owned"></a>

### Owned


<a href="Result"></a>

### Result


<a href="Try"></a>

### Try


<a href="Stopwatch"></a>

### Stopwatch


<a href="UUID"></a>

### UUID


<a href="Collections"></a>

## Collections

The library includes a few collection classes. Mostly these are
wrappers around existing collection classes but with modified
interfaces to provide a more monadic apporach (e.g., returning
an [Option](#Option)).


<a name="cache"></a>

### cache

A templated implementation of a least-recently used (LRU) cache. Note
that the key type must be compatible with std::tr1::unordered_map. The
interface is rather poor right now, only providing 'put' and 'get'
operations.


<a href="hashmap"></a>

### hashmap

*Requires Boost.*


<a href="hashset"></a>

### hashset

*Requires Boost.*


<a href="multihashmap"></a>

### multihashmap

*Requires Boost.*


<a href="Namespaces"></a>

## Namespaces

There are a fair number of utilities behind a few namespaces.


<a href="fs"></a>

### fs


<a href="gzip"></a>

### gzip


<a href="JSON"></a>

### JSON


<a href="lambda"></a>

### lambda


<a href="net"></a>

### net

<a href="os"></a>

### os


<a href="path"></a>

### path


<a href="protobuf"></a>

### protobuf

*Requires protobuf.*


<a href="strings"></a>

### strings


## Miscellaneous

Like the primitives, these miscellaneous utilities are **not**
namespaced.


<a href="copy"></a>

### copy


<a href="fatal"></a>

### fatal


<a href="foreach></a>

### foreach

*Requires Boost.*


<a href="gtest"></a>

### gtest

*Requires gtest.*


<a href="numify"></a>

### numify


<a href="preprocessor"></a>

### preprocessor

*Requires Boost.*


<a href="stringify"></a>

### stringify


## Philosophy

*"Premature optimization is the root of all evil."*

You'll notice that the library is designed in a way that can lead to a
lot of copying. This decision was deliberate. Capturing the semantics
of pointer ownership is hard to enforce programmatically unless you
copy, and in many instances these copies can be elided by an
optimizing compiler. We've choosen safety rather than premature
optimizations.

Note, however, that we plan to liberally augment the library as we add
C++11 support. In particular, we plan to use rvalue references and
std::unique_ptr (although, likely wrapped as Owned) in order to
explicitly express ownership semantics. Until then, it's unlikely that
the performance overhead incurred via any extra copying is your
bottleneck, and if it is we'd love to hear from you!


## Building Tests

We'll assume you've got a distribution of gmock and have already built
a static archive called libgmock.a (see gmock's README to learn
how). We'll also assume the Boost, glog, and protobuf headers can be
found via the include paths and libglog.* can be found via the library
search paths. You can then build the tests via:

       $ g++ -I${STOUT}/include -I$(GMOCK)/gtest/include -I$(GMOCK)/include \
         ${STOUT}/tests/tests.cpp libgmock.a -lglog -o tests

Note that if you want to test the gzip headers you'll need to define
HAVE_LIBZ and link against libz:

       $ g++ -I${STOUT}/include -I$(GMOCK)/gtest/include -I$(GMOCK)/include \
         -DHAVE_LIBZ ${STOUT}/tests/tests.cpp libgmock.a -lglog -lz -o tests


