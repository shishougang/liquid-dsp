/*
 * Copyright (c) 2007, 2008, 2009, 2010, 2011, 2012 Joseph Gaeddert
 * Copyright (c) 2007, 2008, 2009, 2010, 2011, 2012 Virginia Polytechnic
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
// modem_psk.c
//

// create a psk (phase-shift keying) modem object
MODEM() MODEM(_create_psk)(unsigned int _bits_per_symbol)
{
    MODEM() q = (MODEM()) malloc( sizeof(struct MODEM(_s)) );

    switch (_bits_per_symbol) {
    case 1: q->scheme = LIQUID_MODEM_PSK2;   break;
    case 2: q->scheme = LIQUID_MODEM_PSK4;   break;
    case 3: q->scheme = LIQUID_MODEM_PSK8;   break;
    case 4: q->scheme = LIQUID_MODEM_PSK16;  break;
    case 5: q->scheme = LIQUID_MODEM_PSK32;  break;
    case 6: q->scheme = LIQUID_MODEM_PSK64;  break;
    case 7: q->scheme = LIQUID_MODEM_PSK128; break;
    case 8: q->scheme = LIQUID_MODEM_PSK256; break;
    default:
        fprintf(stderr,"error: modem_create_psk(), cannot support PSK with m > 8\n");
        exit(1);
    }

    // initialize basic modem structure
    MODEM(_init)(q, _bits_per_symbol);

    // compute alpha
    q->alpha = M_PI/(T)(q->M);

    // initialize demodulation array reference
    unsigned int k;
    for (k=0; k<(q->m); k++)
        q->ref[k] = (1<<k) * q->alpha;

    // compute phase offset (half of phase difference between symbols)
    q->data.psk.d_phi = M_PI*(1.0f - 1.0f/(T)(q->M));

    // set modulation/demodulation functions
    q->modulate_func = &MODEM(_modulate_psk);
    q->demodulate_func = &MODEM(_demodulate_psk);

    // initialize symbol map
    q->symbol_map = (TC*)malloc(q->M*sizeof(TC));
    MODEM(_init_map)(q);
    q->modulate_using_map = 1;

    // soft demodulation
    if (q->m == 3) {
        q->demod_soft_neighbors = (unsigned char*) psk8_demod_soft_neighbors;
        q->demod_soft_p         = 2;
    } else if (q->m == 4) {
        q->demod_soft_neighbors = (unsigned char*) psk16_demod_soft_neighbors;
        q->demod_soft_p         = 2;
    } else if (q->m == 5) {
        q->demod_soft_neighbors = (unsigned char*) psk32_demod_soft_neighbors;
        q->demod_soft_p         = 2;
    }

    return q;
}

// modulate PSK
void MODEM(_modulate_psk)(MODEM()      _q,
                          unsigned int _sym_in,
                          TC *         _y)
{
    // 'encode' input symbol (actually gray decoding)
    _sym_in = gray_decode(_sym_in);

    // compute output sample
    *_y = liquid_cexpjf(_sym_in * 2 * _q->alpha );
}

// demodulate PSK
void MODEM(_demodulate_psk)(MODEM()        _q,
                            TC             _x,
                            unsigned int * _sym_out)
{
    // compute angle and subtract phase offset, ensuring phase is in [-pi,pi)
    T theta = cargf(_x);
    theta -= _q->data.psk.d_phi;
    if (theta < -M_PI)
        theta += 2*M_PI;

    // demodulate on linearly-spaced array
    unsigned int s;             // demodulated symbol
    T demod_phase_error;        // demodulation phase error
    MODEM(_demodulate_linear_array_ref)(theta, _q->m, _q->ref, &s, &demod_phase_error);

    // 'decode' output symbol (actually gray encoding)
    *_sym_out = gray_encode(s);

    // re-modulate symbol and store state
    MODEM(_modulate_psk)(_q, *_sym_out, &_q->x_hat);
    _q->r = _x;
}
