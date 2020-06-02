/*!
 * \file
 * \brief Bessel test program
 * \author Tony Ottosson
 *
 * -------------------------------------------------------------------------
 *
 * Copyright (C) 1995-2012  (see AUTHORS file for a list of contributors)
 *
 * This file is part of IT++ - a C++ library of mathematical, signal
 * processing, speech processing, and communications classes and functions.
 *
 * IT++ is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any
 * later version.
 *
 * IT++ is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along
 * with IT++.  If not, see <http://www.gnu.org/licenses/>.
 *
 * -------------------------------------------------------------------------
 */

#include <itpp/itbase.h>
#include <iomanip>
#include "gtest/gtest.h"

using namespace std;
using namespace itpp;

TEST(Bessel, All)
{
  ostringstream ss(ostringstream::out);
  const string ref[] = {"x = [0.01 0.535789 1.06158 1.58737 2.11316 2.63895 3.16474 3.69053 \
4.21632 4.74211 5.26789 5.79368 6.31947 6.84526 7.37105 7.89684 8.42263 8.94842 9.47421 10]",
"besselj(0, x) = [0.999975 0.929510 0.737496 0.462593 0.159139 -0.114928 -0.310723 -0.398702 \
-0.374249 -0.257398 -0.086903 0.089735 0.227815 0.295737 0.281659 0.195053 0.063020 -0.077530 \
-0.189700 -0.245936]",
"besselj(1, x) = [0.005000 0.258396 0.459448 0.568610 0.566890 0.459775 0.275443 0.057757 \
-0.144224 -0.287643 -0.345450 -0.311940 -0.203055 -0.051503 0.101930 0.218652 0.271552 0.251069 \
0.166657 0.043473]",
"besselj(5, x) = [0.000000 0.000011 0.000335 0.002361 0.009087 0.024777 0.053741 0.098533 0.158167 \
0.226989 0.294752 0.348121 0.373422 0.360040 0.303620 0.208143 0.086202 -0.042842 -0.156525 -0.234062]",
"besselj(0.3, x) = [0.227333 0.709740 0.733615 0.600610 0.371136 0.105291 -0.137641 -0.309029 \
-0.380002 -0.346362 -0.227881 -0.062193 0.105129 0.231848 0.288953 0.266844 0.176472 0.045388 \
-0.090110 -0.194619]",
"besselj(1.7, x) = [0.000079 0.067160 0.198405 0.343409 0.457949 0.507700 0.475136 0.363160 0.194018 \
0.003625 -0.167309 -0.283160 -0.321855 -0.279865 -0.172579 -0.030045 0.110759 0.215140 0.259064 0.234648]",
"besselj(5.3, x) = [0.000000 0.000005 0.000165 0.001317 0.005544 0.016247 0.037475 0.072593 0.122628 \
0.184847 0.252110 0.313421 0.355752 0.366874 0.338539 0.269215 0.165544 0.041984 -0.081497 -0.183307]",
"bessely(0, x) = [-3.005456 -0.393388 0.134747 0.415986 0.518927 0.473687 0.320004 0.110022 -0.099731 \
-0.259413 -0.335829 -0.318494 -0.220309 -0.072808 0.082722 0.205946 0.267362 0.254997 0.176400 0.055671]",
"bessely(1, x) = [-63.678596 -1.387656 -0.729200 -0.355648 -0.044554 0.204046 0.363724 0.416719 0.365013 \
0.231664 0.055661 -0.117354 -0.245833 -0.301794 -0.276703 -0.182445 -0.047311 0.091854 0.199244 0.249015]",
"bessely(5, x) = [-2444635204830.000000 -5637.104920 -194.723098 -28.527040 -7.796072 -3.084767 \
-1.583672 -0.986094 -0.698192 -0.523538 -0.384929 -0.250859 -0.112548 0.025099 0.148996 0.242846 \
0.292104 0.288391 0.232521 0.135403]",
"bessely(0.3, x) = [-4.501885 -0.756144 -0.192147 0.176734 0.399032 0.477286 0.425200 0.275829 0.077193 \
-0.117613 -0.261894 -0.325212 -0.299154 -0.197723 -0.052439 0.096490 0.210615 0.262704 0.242933 0.160422]",
"bessely(1.7, x) = [-2360.521095 -3.009003 -1.185564 -0.719724 -0.432942 -0.177942 0.054479 0.240501 \
0.353307 0.377184 0.314160 0.184609 0.022720 -0.131614 -0.242281 -0.285365 -0.254426 -0.161362 -0.032773 0.097192]",
"bessely(5.3, x) = [-19010147659829.000000 -13261.137342 -371.693756 -47.926483 -11.884160 -4.322880 \
-2.054324 -1.196689 -0.809794 -0.599174 -0.453007 -0.323825 -0.193008 -0.058325 0.071986 0.183747 \
0.261390 0.292489 0.271580 0.202481]",
"besseli(0, x) = [1.000025 1.073066 1.302214 1.736363 2.469391 3.662497 5.582888 8.668475 13.634868 \
21.651723 34.633273 55.717272 90.055289 146.118049 237.853623 388.258981 635.295671 1041.696056 \
1711.231130 2815.716628]",
"besseli(1, x) = [0.005000 0.277623 0.609156 1.071337 1.766870 2.854192 4.586135 7.372273 11.880787 \
19.205890 31.143828 50.648619 82.585563 134.978313 221.074665 362.771310 596.295812 981.640046 \
1618.232132 2670.988304]",
"besseli(5, x) = [0.000000 0.000012 0.000368 0.002913 0.013185 0.044294 0.124033 0.307911 0.702786 \
1.509283 3.097299 6.139460 11.845643 22.373107 41.540816 76.069168 137.725169 247.024584 439.606601 777.188286]",
"besseli(0.3, x) = [0.227342 0.792616 1.133692 1.616922 2.370067 3.565909 5.475611 8.537063 13.462834 \
21.416322 34.301243 55.238598 89.353662 145.076015 236.289277 385.889218 631.678022 1036.136392 \
1702.636834 2802.362489]",
"besseli(1.7, x) = [0.000079 0.070827 0.244469 0.548134 1.052827 1.884257 3.253621 5.511453 9.237952 \
15.393238 25.566853 42.392032 70.233829 116.332703 192.705987 319.311124 529.310475 877.837948 \
1456.603093 2418.229821]",
"besseli(5.3, x) = [0.000000 0.000005 0.000181 0.001608 0.007903 0.028250 0.083093 0.214721 0.506726 \
1.119372 2.353247 4.762836 9.357849 17.957982 33.815077 62.699642 114.791605 207.960347 373.439504 665.621707]",
"besselk(0, x) = [4.721245 0.867728 0.385816 0.191022 0.099182 0.052916 0.028734 0.015799 0.008767 \
0.004900 0.002754 0.001555 0.000881 0.000501 0.000286 0.000163 0.000094 0.000054 0.000031 0.000018]",
"besselk(1, x) = [99.973894 1.514822 0.542899 0.244952 0.120671 0.062227 0.032994 0.017822 0.009756 \
0.005393 0.003005 0.001684 0.000949 0.000537 0.000305 0.000173 0.000099 0.000057 0.000032 0.000019]",
"besselk(5, x) = [3839976000100.000000 8542.624206 265.658856 32.672931 6.971494 1.991747 0.679497 \
0.260647 0.108529 0.047977 0.022189 0.010627 0.005232 0.002634 0.001350 0.000703 0.000371 0.000197 \
0.000106 0.000058]"};
  int i = 0;

  vec x = linspace(0.01, 10, 20);

  ss << "x = " << x;
  ASSERT_TRUE(ss.str() == ref[i++]);
  ss.str("");

  ss << "besselj(0, x) = " << fixed << besselj(0, x);
  ASSERT_TRUE(ss.str() == ref[i++]);
  ss.str("");
  ss << "besselj(1, x) = " << besselj(1, x);
  ASSERT_TRUE(ss.str() == ref[i++]);
  ss.str("");
  ss << "besselj(5, x) = " << round_to_infty(besselj(5, x));
  ASSERT_TRUE(ss.str() == ref[i++]);
  ss.str("");
  ss << "besselj(0.3, x) = " << besselj(0.3, x);
  ASSERT_TRUE(ss.str() == ref[i++]);
  ss.str("");
  ss << "besselj(1.7, x) = " << besselj(1.7, x);
  ASSERT_TRUE(ss.str() == ref[i++]);
  ss.str("");
  ss << "besselj(5.3, x) = " << round_to_infty(besselj(5.3, x));
  ASSERT_TRUE(ss.str() == ref[i++]);
  ss.str("");

  ss << "bessely(0, x) = " << bessely(0, x);
  ASSERT_TRUE(ss.str() == ref[i++]);
  ss.str("");
  ss << "bessely(1, x) = " << bessely(1, x);
  ASSERT_TRUE(ss.str() == ref[i++]);
  ss.str("");
  ss << "bessely(5, x) = " << round_to_infty(bessely(5, x));
  ASSERT_TRUE(ss.str() == ref[i++]);
  ss.str("");
  ss << "bessely(0.3, x) = " << bessely(0.3, x);
  ASSERT_TRUE(ss.str() == ref[i++]);
  ss.str("");
  ss << "bessely(1.7, x) = " << bessely(1.7, x);
  ASSERT_TRUE(ss.str() == ref[i++]);
  ss.str("");
  ss << "bessely(5.3, x) = " << round_to_infty(bessely(5.3, x));
  ASSERT_TRUE(ss.str() == ref[i++]);
  ss.str("");

  ss << "besseli(0, x) = " << besseli(0, x);
  ASSERT_TRUE(ss.str() == ref[i++]);
  ss.str("");
  ss << "besseli(1, x) = " << besseli(1, x);
  ASSERT_TRUE(ss.str() == ref[i++]);
  ss.str("");
  ss << "besseli(5, x) = " << besseli(5, x);
  ASSERT_TRUE(ss.str() == ref[i++]);
  ss.str("");
  ss << "besseli(0.3, x) = " << besseli(0.3, x);
  ASSERT_TRUE(ss.str() == ref[i++]);
  ss.str("");
  ss << "besseli(1.7, x) = " << besseli(1.7, x);
  ASSERT_TRUE(ss.str() == ref[i++]);
  ss.str("");
  ss << "besseli(5.3, x) = " << besseli(5.3, x);
  ASSERT_TRUE(ss.str() == ref[i++]);
  ss.str("");

  ss << "besselk(0, x) = " << besselk(0, x);
  ASSERT_TRUE(ss.str() == ref[i++]);
  ss.str("");
  ss << "besselk(1, x) = " << besselk(1, x);
  ASSERT_TRUE(ss.str() == ref[i++]);
  ss.str("");
  ss << "besselk(5, x) = " << round_to_infty(besselk(5, x));
  ASSERT_TRUE(ss.str() == ref[i++]);
}
