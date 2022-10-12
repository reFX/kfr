/**
 * KFR (http://kfrlib.com)
 * Copyright (C) 2016-2022 Fractalium Ltd
 * See LICENSE.txt for details
 */

#include <kfr/base.hpp>
#include <kfr/dsp.hpp>
#include <kfr/io.hpp>

using namespace kfr;

cpu_t fir_sse2(univector<double, 0> data, univector<double, 4>& taps)
{
    println(library_version());
    data = short_fir(data, taps);
    return cpu_t::native;
}
