#ifndef MIKELIB_CRYPTO_HPP
#define MIKELIB_CRYPTO_HPP

#include <string>

namespace mikelib
{
        std::string xor_strings(const std::string &text, const std::string &key) //https://github.com/michal-flaska/cpp_projects/blob/main/xor/main.cpp
        {
                std::string result = text;

                for (size_t i = 0; i < text.length(); i++)
                {
                        result[i] = text[i] ^ key[i % key.length()];

                        // im using modulo (% key.length()) to repeat the key if its shorter than
                        // the text

                        // the `% key.length()` makes it work even if the key is shorter. it wraps
                        // around

                        // example:
                        // - text: "hello world" (11 chars)
                        // - key: "abc" (3 chars)

                        // it does:
                        // - h ^ a (i=0, 0%3=0)
                        // - e ^ b (i=1, 1%3=1)
                        // - l ^ c (i=2, 2%3=2)
                        // - l ^ a (i=3, 3%3=0) <- wraps back to start
                        // - o ^ b (i=4, 4%3=1)
                        // - etc.

                        // the key just repeats until it covers the whole text. that's standard for
                        // XOR encryption.
                }

                return result;
        }
}

#endif