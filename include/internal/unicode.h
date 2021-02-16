/*
 * Copyright 2021 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the Apache License 2.0 (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef OSSL_INTERNAL_UNICODE_H
# define OSSL_INTERNAL_UNICODE_H
# pragma once

static const unsigned long UNICODE_MAX = 0x10ffff;
static const unsigned long UNICODE_LIMIT = UNICODE_MAX + 1;

static inline int is_unicode_surrogate(unsigned long value)
{
    return value >= 0xd800 && value <= 0xdfff;
}

static inline int is_unicode_valid(unsigned long value)
{
    return value <= UNICODE_MAX && !is_unicode_surrogate(value);
}

#endif
