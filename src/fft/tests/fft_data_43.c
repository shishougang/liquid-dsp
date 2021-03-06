/*
 * Copyright (c) 2012 Joseph Gaeddert
 * Copyright (c) 2012 Virginia Polytechnic Institute & State University
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
// autotest fft data for 43-point transform
//

#include <complex.h>

float complex fft_test_x43[] = {
    0.086214736594 +  -0.374055466225*_Complex_I,
   -0.398326405553 +   0.064437628903*_Complex_I,
   -0.086828498048 +  -1.377541893939*_Complex_I,
   -0.014057206023 +  -1.721581520365*_Complex_I,
   -1.130661886812 +  -0.823144321334*_Complex_I,
    0.265330564080 +  -2.139333421737*_Complex_I,
    0.987278886883 +   0.510016610694*_Complex_I,
    1.388439583820 +  -0.312226254937*_Complex_I,
    1.314187441787 +   2.179164255828*_Complex_I,
   -0.134438842798 +  -2.204082595282*_Complex_I,
    0.245609009336 +   0.112479617279*_Complex_I,
   -1.038607185161 +   0.772906423002*_Complex_I,
    0.816938259734 +  -2.090685529624*_Complex_I,
    0.975237183551 +  -0.563625353818*_Complex_I,
   -0.941942184460 +   1.392834491457*_Complex_I,
    1.369305972621 +   0.035788913101*_Complex_I,
    0.274358812513 +   0.334025802789*_Complex_I,
   -0.187955769606 +   0.806622195637*_Complex_I,
   -0.435359111927 +   0.395863170294*_Complex_I,
   -1.059982565487 +  -1.108626336147*_Complex_I,
   -0.085915350568 +  -0.294840267490*_Complex_I,
   -0.202754288995 +  -0.413065083074*_Complex_I,
   -0.607968226502 +   1.253761902790*_Complex_I,
    2.921829936105 +   1.400641655759*_Complex_I,
    0.493898754300 +   2.597915340403*_Complex_I,
   -0.939016287203 +   0.999025234458*_Complex_I,
   -1.213828533796 +  -0.093371812474*_Complex_I,
    0.049357784794 +  -1.117710210403*_Complex_I,
    0.291427701377 +   0.619473850471*_Complex_I,
   -0.297284045241 +   1.471963630624*_Complex_I,
   -1.204828141785 +   0.357668469775*_Complex_I,
    1.214147177406 +  -1.053652949447*_Complex_I,
   -0.669099873019 +   0.645208133613*_Complex_I,
   -0.669325749409 +   1.526826939113*_Complex_I,
    1.388489801757 +  -0.663313867864*_Complex_I,
    1.528893702905 +  -0.300643090523*_Complex_I,
    0.969651597440 +   0.887262607328*_Complex_I,
    0.961949407503 +  -1.302265834141*_Complex_I,
    0.025366344758 +   1.938755581562*_Complex_I,
    0.012954685257 +  -0.117840651513*_Complex_I,
    0.422317736906 +   0.454593332125*_Complex_I,
   -1.225108444904 +  -0.762684444639*_Complex_I,
    0.510768457794 +   0.200474501150*_Complex_I};

float complex fft_test_y43[] = {
    5.970664941924 +   2.123419383178*_Complex_I,
   -4.826258373494 + -10.530035821412*_Complex_I,
   -6.840438649504 +   2.195697396144*_Complex_I,
  -15.037444321130 +  -0.498694877295*_Complex_I,
   -2.324178679783 +  -5.588631770237*_Complex_I,
   -9.817989632278 +   8.215797271526*_Complex_I,
   19.440508234356 +   0.725796090385*_Complex_I,
   -0.273833848905 +   4.924507895251*_Complex_I,
    5.898110303453 +  -7.584923619025*_Complex_I,
   -1.491058783404 +   7.983518326557*_Complex_I,
   -7.459786425320 +  -5.471409031844*_Complex_I,
    9.458054840383 +  -1.411338639410*_Complex_I,
   -7.652963176561 +  16.470882260110*_Complex_I,
    4.933008347551 +   1.752692467372*_Complex_I,
    3.158349989133 + -10.520004874496*_Complex_I,
    3.461440707146 +  -1.053485004255*_Complex_I,
    0.403169282390 +  15.216737475743*_Complex_I,
   11.005277294499 +   0.924950795722*_Complex_I,
   -2.459303339406 +  -4.952009870945*_Complex_I,
  -11.998504221115 +  -4.269332241730*_Complex_I,
  -10.575401537817 +   0.521491539120*_Complex_I,
   -8.612771844559 +  -4.765648940500*_Complex_I,
    7.802134874811 +   3.882271887067*_Complex_I,
    2.664085789892 +  -5.430064274009*_Complex_I,
    7.012256247961 +  -6.119235310609*_Complex_I,
   -0.520208603756 +  -0.845655711277*_Complex_I,
    0.308220700989 +   3.533138362895*_Complex_I,
  -10.811305738786 +  -4.238039944052*_Complex_I,
    6.001274292511 +  -2.592573440494*_Complex_I,
    5.544361033380 + -11.920579663414*_Complex_I,
   -2.095258565391 +   0.336151200781*_Complex_I,
   -5.596706630782 +   7.291207810674*_Complex_I,
    9.325757124002 +  -3.598787999557*_Complex_I,
    1.133897756930 +  -1.612056679027*_Complex_I,
   -2.012305507947 +   5.032886593926*_Complex_I,
  -10.072407904704 +   5.354603355501*_Complex_I,
    2.641399130952 +  -1.713592877295*_Complex_I,
    1.128116547129 +   7.394974387525*_Complex_I,
   12.210114373933 +  -3.041200993402*_Complex_I,
   -0.850951175674 +   3.946134783722*_Complex_I,
   -1.686631417770 +  -4.776809881210*_Complex_I,
   -2.550902604765 +  -2.082230855079*_Complex_I,
    9.773642843061 +  -9.294902010297*_Complex_I};

