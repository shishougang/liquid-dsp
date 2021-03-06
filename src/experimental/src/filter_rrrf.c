/*
 * Copyright (c) 2007, 2008, 2009, 2010 Joseph Gaeddert
 * Copyright (c) 2007, 2008, 2009, 2010 Virginia Polytechnic
 *                                      Institute & State University
 *
 * This file is part of liquid.
 *
 * liquid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * liquid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with liquid.  If not, see <http://www.gnu.org/licenses/>.
 */

//
// Filter API: floating-point
//

#include "liquid.internal.h"

// naming extensions (useful for print statements)
#define EXTENSION_SHORT     "f"
#define EXTENSION_FULL      "rrrf"

// 
#define AUTOCORR(name)      LIQUID_CONCAT(autocorr_rrrf,name)
#define FIRFARROW(name)     LIQUID_CONCAT(firfarrow_rrrf,name)
#define FIRFILT(name)       LIQUID_CONCAT(firfilt_rrrf,name)
#define FIRHILB(name)       LIQUID_CONCAT(firhilb,name)
#define FIRPFB(name)        LIQUID_CONCAT(firpfb_rrrf,name)
#define IIRFILT(name)       LIQUID_CONCAT(iirfilt_rrrf,name)
#define IIRFILTSOS(name)    LIQUID_CONCAT(iirfiltsos_rrrf,name)
#define IIRQMFB(name)       LIQUID_CONCAT(iirqmfb_rrrf,name)
#define ITQMFB(name)        LIQUID_CONCAT(itqmfb_rrrf,name)
#define INTERP(name)        LIQUID_CONCAT(interp_rrrf,name)
#define QMFB(name)          LIQUID_CONCAT(qmfb_rrrf,name)
#define DECIM(name)         LIQUID_CONCAT(decim_rrrf,name)
#define RESAMP(name)        LIQUID_CONCAT(resamp_rrrf,name)
#define RESAMP2(name)       LIQUID_CONCAT(resamp2_rrrf,name)
#define SYMSYNC(name)       LIQUID_CONCAT(symsync_rrrf,name)
#define SYMSYNC2(name)      LIQUID_CONCAT(symsync2_rrrf,name)
#define SYMSYNCLP(name)     LIQUID_CONCAT(symsynclp_rrrf,name)

#define T                   float   // general
#define TO                  float   // output
#define TC                  float   // coefficients
#define TI                  float   // input
#define WINDOW(name)        LIQUID_CONCAT(windowf,name)
#define DOTPROD(name)       LIQUID_CONCAT(dotprod_rrrf,name)
#define POLY(name)          LIQUID_CONCAT(polyf,name)

#define TO_COMPLEX          0
#define TC_COMPLEX          0
#define TI_COMPLEX          0

#define PRINTVAL_TO(X,F)    PRINTVAL_FLOAT(X,F)
#define PRINTVAL_TC(X,F)    PRINTVAL_FLOAT(X,F)
#define PRINTVAL_TI(X,F)    PRINTVAL_FLOAT(X,F)

// source files
#include "iirqmfb.c"
#include "itqmfb.c"
#include "qmfb.c"
#include "symsync2.c"
#include "symsynclp.c"
