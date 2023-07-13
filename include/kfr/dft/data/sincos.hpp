/*
  Copyright (C) 2016-2023 Dan Cazarin (https://www.kfrlib.com)
  This file is part of KFR

  KFR is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  KFR is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with KFR.

  If GPL is not suitable for your project, you must purchase a commercial license to use KFR.
  Buying a commercial license is mandatory as soon as you develop commercial activities without
  disclosing the source code of your own applications.
  See https://www.kfrlib.com for details.
 */
#pragma once

#include "../../kfr.h"
#include "../../simd/types.hpp"
#include <cstdint>

namespace kfr
{

namespace data
{

template <typename T>
constexpr inline T c_sin_table[65] = {
    /* sin(2*pi*   0/ 256) */ f32(0.0),
    /* sin(2*pi*   1/ 256) */ f32(0.02454122852291228803173452945928292506547),
    /* sin(2*pi*   2/ 256) */ f32(0.04906767432741801425495497694268265831475),
    /* sin(2*pi*   3/ 256) */ f32(0.0735645635996674235294656215752343218133),
    /* sin(2*pi*   4/ 256) */ f32(0.09801714032956060199419556388864184586114),
    /* sin(2*pi*   5/ 256) */ f32(0.1224106751992161984987044741509457875752),
    /* sin(2*pi*   6/ 256) */ f32(0.1467304744553617516588501296467178197062),
    /* sin(2*pi*   7/ 256) */ f32(0.1709618887603012263636423572082635319663),
    /* sin(2*pi*   8/ 256) */ f32(0.1950903220161282678482848684770222409277),
    /* sin(2*pi*   9/ 256) */ f32(0.2191012401568697972277375474973577988484),
    /* sin(2*pi*  10/ 256) */ f32(0.242980179903263889948274162077471118321),
    /* sin(2*pi*  11/ 256) */ f32(0.2667127574748983863252865151164363940421),
    /* sin(2*pi*  12/ 256) */ f32(0.2902846772544623676361923758173952746915),
    /* sin(2*pi*  13/ 256) */ f32(0.3136817403988914766564788459941003099934),
    /* sin(2*pi*  14/ 256) */ f32(0.3368898533922200506892532126191475704778),
    /* sin(2*pi*  15/ 256) */ f32(0.3598950365349881487751045723267564202023),
    /* sin(2*pi*  16/ 256) */ f32(0.3826834323650897717284599840303988667613),
    /* sin(2*pi*  17/ 256) */ f32(0.4052413140049898709084813055050524665119),
    /* sin(2*pi*  18/ 256) */ f32(0.4275550934302820943209668568887985343046),
    /* sin(2*pi*  19/ 256) */ f32(0.4496113296546066000462945794242270758832),
    /* sin(2*pi*  20/ 256) */ f32(0.4713967368259976485563876259052543776575),
    /* sin(2*pi*  21/ 256) */ f32(0.4928981922297840368730266887588092682397),
    /* sin(2*pi*  22/ 256) */ f32(0.514102744193221726593693838968815772608),
    /* sin(2*pi*  23/ 256) */ f32(0.5349976198870972106630769046370179155603),
    /* sin(2*pi*  24/ 256) */ f32(0.5555702330196022247428308139485328743749),
    /* sin(2*pi*  25/ 256) */ f32(0.575808191417845300745972453815730841776),
    /* sin(2*pi*  26/ 256) */ f32(0.5956993044924333434670365288299698895119),
    /* sin(2*pi*  27/ 256) */ f32(0.6152315905806268454849135634139842776594),
    /* sin(2*pi*  28/ 256) */ f32(0.6343932841636454982151716132254933706757),
    /* sin(2*pi*  29/ 256) */ f32(0.6531728429537767640842030136563054150769),
    /* sin(2*pi*  30/ 256) */ f32(0.6715589548470184006253768504274218032288),
    /* sin(2*pi*  31/ 256) */ f32(0.6895405447370669246167306299574847028455),
    /* sin(2*pi*  32/ 256) */ f32(0.7071067811865475244008443621048490392848),
    /* sin(2*pi*  33/ 256) */ f32(0.7242470829514669209410692432905531674831),
    /* sin(2*pi*  34/ 256) */ f32(0.740951125354959091175616897495162729729),
    /* sin(2*pi*  35/ 256) */ f32(0.7572088465064845475754640536057844730404),
    /* sin(2*pi*  36/ 256) */ f32(0.773010453362736960810906609758469800971),
    /* sin(2*pi*  37/ 256) */ f32(0.7883464276266062620091647053596892826565),
    /* sin(2*pi*  38/ 256) */ f32(0.8032075314806449098066765129631419238796),
    /* sin(2*pi*  39/ 256) */ f32(0.817584813151583696504920884130633809471),
    /* sin(2*pi*  40/ 256) */ f32(0.8314696123025452370787883776179057567386),
    /* sin(2*pi*  41/ 256) */ f32(0.8448535652497070732595712051049570977198),
    /* sin(2*pi*  42/ 256) */ f32(0.8577286100002720699022699842847701370425),
    /* sin(2*pi*  43/ 256) */ f32(0.8700869911087114186522924044838488439108),
    /* sin(2*pi*  44/ 256) */ f32(0.8819212643483550297127568636603883495084),
    /* sin(2*pi*  45/ 256) */ f32(0.8932243011955153203424164474933979780006),
    /* sin(2*pi*  46/ 256) */ f32(0.9039892931234433315862002972305370487101),
    /* sin(2*pi*  47/ 256) */ f32(0.9142097557035306546350148293935774010447),
    /* sin(2*pi*  48/ 256) */ f32(0.9238795325112867561281831893967882868224),
    /* sin(2*pi*  49/ 256) */ f32(0.932992798834738887711660255543302498295),
    /* sin(2*pi*  50/ 256) */ f32(0.9415440651830207784125094025995023571856),
    /* sin(2*pi*  51/ 256) */ f32(0.9495281805930366671959360741893450282522),
    /* sin(2*pi*  52/ 256) */ f32(0.9569403357322088649357978869802699694828),
    /* sin(2*pi*  53/ 256) */ f32(0.9637760657954398666864643555078351536631),
    /* sin(2*pi*  54/ 256) */ f32(0.9700312531945439926039842072861002514569),
    /* sin(2*pi*  55/ 256) */ f32(0.975702130038528544460395766419527971644),
    /* sin(2*pi*  56/ 256) */ f32(0.9807852804032304491261822361342390369739),
    /* sin(2*pi*  57/ 256) */ f32(0.9852776423889412447740184331785477871601),
    /* sin(2*pi*  58/ 256) */ f32(0.9891765099647809734516737380162430639837),
    /* sin(2*pi*  59/ 256) */ f32(0.9924795345987099981567672516611178200108),
    /* sin(2*pi*  60/ 256) */ f32(0.9951847266721968862448369531094799215755),
    /* sin(2*pi*  61/ 256) */ f32(0.9972904566786902161355971401825678211717),
    /* sin(2*pi*  62/ 256) */ f32(0.9987954562051723927147716047591006944432),
    /* sin(2*pi*  63/ 256) */ f32(0.9996988186962042201157656496661721968501),
    /* sin(2*pi*  64/ 256) */ f32(1.0000000000000000000000000000000000000000)
};

// data generated by mpfr
template <>
constexpr inline f64 c_sin_table<f64>[65] = {
    /* sin(2*pi*   0/ 256) */ f64(0.0),
    /* sin(2*pi*   1/ 256) */ f64(0.02454122852291228803173452945928292506547),
    /* sin(2*pi*   2/ 256) */ f64(0.04906767432741801425495497694268265831475),
    /* sin(2*pi*   3/ 256) */ f64(0.0735645635996674235294656215752343218133),
    /* sin(2*pi*   4/ 256) */ f64(0.09801714032956060199419556388864184586114),
    /* sin(2*pi*   5/ 256) */ f64(0.1224106751992161984987044741509457875752),
    /* sin(2*pi*   6/ 256) */ f64(0.1467304744553617516588501296467178197062),
    /* sin(2*pi*   7/ 256) */ f64(0.1709618887603012263636423572082635319663),
    /* sin(2*pi*   8/ 256) */ f64(0.1950903220161282678482848684770222409277),
    /* sin(2*pi*   9/ 256) */ f64(0.2191012401568697972277375474973577988484),
    /* sin(2*pi*  10/ 256) */ f64(0.242980179903263889948274162077471118321),
    /* sin(2*pi*  11/ 256) */ f64(0.2667127574748983863252865151164363940421),
    /* sin(2*pi*  12/ 256) */ f64(0.2902846772544623676361923758173952746915),
    /* sin(2*pi*  13/ 256) */ f64(0.3136817403988914766564788459941003099934),
    /* sin(2*pi*  14/ 256) */ f64(0.3368898533922200506892532126191475704778),
    /* sin(2*pi*  15/ 256) */ f64(0.3598950365349881487751045723267564202023),
    /* sin(2*pi*  16/ 256) */ f64(0.3826834323650897717284599840303988667613),
    /* sin(2*pi*  17/ 256) */ f64(0.4052413140049898709084813055050524665119),
    /* sin(2*pi*  18/ 256) */ f64(0.4275550934302820943209668568887985343046),
    /* sin(2*pi*  19/ 256) */ f64(0.4496113296546066000462945794242270758832),
    /* sin(2*pi*  20/ 256) */ f64(0.4713967368259976485563876259052543776575),
    /* sin(2*pi*  21/ 256) */ f64(0.4928981922297840368730266887588092682397),
    /* sin(2*pi*  22/ 256) */ f64(0.514102744193221726593693838968815772608),
    /* sin(2*pi*  23/ 256) */ f64(0.5349976198870972106630769046370179155603),
    /* sin(2*pi*  24/ 256) */ f64(0.5555702330196022247428308139485328743749),
    /* sin(2*pi*  25/ 256) */ f64(0.575808191417845300745972453815730841776),
    /* sin(2*pi*  26/ 256) */ f64(0.5956993044924333434670365288299698895119),
    /* sin(2*pi*  27/ 256) */ f64(0.6152315905806268454849135634139842776594),
    /* sin(2*pi*  28/ 256) */ f64(0.6343932841636454982151716132254933706757),
    /* sin(2*pi*  29/ 256) */ f64(0.6531728429537767640842030136563054150769),
    /* sin(2*pi*  30/ 256) */ f64(0.6715589548470184006253768504274218032288),
    /* sin(2*pi*  31/ 256) */ f64(0.6895405447370669246167306299574847028455),
    /* sin(2*pi*  32/ 256) */ f64(0.7071067811865475244008443621048490392848),
    /* sin(2*pi*  33/ 256) */ f64(0.7242470829514669209410692432905531674831),
    /* sin(2*pi*  34/ 256) */ f64(0.740951125354959091175616897495162729729),
    /* sin(2*pi*  35/ 256) */ f64(0.7572088465064845475754640536057844730404),
    /* sin(2*pi*  36/ 256) */ f64(0.773010453362736960810906609758469800971),
    /* sin(2*pi*  37/ 256) */ f64(0.7883464276266062620091647053596892826565),
    /* sin(2*pi*  38/ 256) */ f64(0.8032075314806449098066765129631419238796),
    /* sin(2*pi*  39/ 256) */ f64(0.817584813151583696504920884130633809471),
    /* sin(2*pi*  40/ 256) */ f64(0.8314696123025452370787883776179057567386),
    /* sin(2*pi*  41/ 256) */ f64(0.8448535652497070732595712051049570977198),
    /* sin(2*pi*  42/ 256) */ f64(0.8577286100002720699022699842847701370425),
    /* sin(2*pi*  43/ 256) */ f64(0.8700869911087114186522924044838488439108),
    /* sin(2*pi*  44/ 256) */ f64(0.8819212643483550297127568636603883495084),
    /* sin(2*pi*  45/ 256) */ f64(0.8932243011955153203424164474933979780006),
    /* sin(2*pi*  46/ 256) */ f64(0.9039892931234433315862002972305370487101),
    /* sin(2*pi*  47/ 256) */ f64(0.9142097557035306546350148293935774010447),
    /* sin(2*pi*  48/ 256) */ f64(0.9238795325112867561281831893967882868224),
    /* sin(2*pi*  49/ 256) */ f64(0.932992798834738887711660255543302498295),
    /* sin(2*pi*  50/ 256) */ f64(0.9415440651830207784125094025995023571856),
    /* sin(2*pi*  51/ 256) */ f64(0.9495281805930366671959360741893450282522),
    /* sin(2*pi*  52/ 256) */ f64(0.9569403357322088649357978869802699694828),
    /* sin(2*pi*  53/ 256) */ f64(0.9637760657954398666864643555078351536631),
    /* sin(2*pi*  54/ 256) */ f64(0.9700312531945439926039842072861002514569),
    /* sin(2*pi*  55/ 256) */ f64(0.975702130038528544460395766419527971644),
    /* sin(2*pi*  56/ 256) */ f64(0.9807852804032304491261822361342390369739),
    /* sin(2*pi*  57/ 256) */ f64(0.9852776423889412447740184331785477871601),
    /* sin(2*pi*  58/ 256) */ f64(0.9891765099647809734516737380162430639837),
    /* sin(2*pi*  59/ 256) */ f64(0.9924795345987099981567672516611178200108),
    /* sin(2*pi*  60/ 256) */ f64(0.9951847266721968862448369531094799215755),
    /* sin(2*pi*  61/ 256) */ f64(0.9972904566786902161355971401825678211717),
    /* sin(2*pi*  62/ 256) */ f64(0.9987954562051723927147716047591006944432),
    /* sin(2*pi*  63/ 256) */ f64(0.9996988186962042201157656496661721968501),
    /* sin(2*pi*  64/ 256) */ f64(1.0000000000000000000000000000000000000000)
};

} // namespace data

template <typename T>
constexpr inline T sin_using_table_256(size_t k)
{
    return (k > 128 ? -1 : +1) * data::c_sin_table<T>[k % 128 >= 64 ? 128 - k % 128 : k % 128];
}

template <typename T>
constexpr inline T sin_using_table(size_t size, size_t k)
{
    return sin_using_table_256<T>((k * 256 / size) % 256);
}
template <typename T>
constexpr inline T cos_using_table(size_t size, size_t k)
{
    return sin_using_table<T>(size, k + size / 4);
}
} // namespace kfr
