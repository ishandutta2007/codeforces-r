#include <bits/stdc++.h>
using namespace std;

int n, k;

long long wyn[1007][1007];

int main()
{
    scanf("%d%d", &n, &k);
    wyn[2][2]=1;
    wyn[2][1]=2;
    wyn[4][4]=109;
    wyn[4][3]=80;
    wyn[4][2]=30;
    wyn[4][1]=32;
    wyn[8][8]=7593125;
    wyn[8][7]=4898872;
    wyn[8][6]=1897056;
    wyn[8][5]=1757896;
    wyn[8][4]=415870;
    wyn[8][3]=147224;
    wyn[8][2]=59808;
    wyn[8][1]=6824;
    wyn[16][16]=391464593;
    wyn[16][15]=569389279;
    wyn[16][14]=312106242;
    wyn[16][13]=578944191;
    wyn[16][12]=515619293;
    wyn[16][11]=117354594;
    wyn[16][10]=161873957;
    wyn[16][9]=472062098;
    wyn[16][8]=428982705;
    wyn[16][7]=565460332;
    wyn[16][6]=735127505;
    wyn[16][5]=33900006;
    wyn[16][4]=293783147;
    wyn[16][3]=746623577;
    wyn[16][2]=290516100;
    wyn[16][1]=776830421;
    wyn[32][32]=212568440;
    wyn[32][31]=186175544;
    wyn[32][30]=519860281;
    wyn[32][29]=612549793;
    wyn[32][28]=737154512;
    wyn[32][27]=651912135;
    wyn[32][26]=44684703;
    wyn[32][25]=387329805;
    wyn[32][24]=195188679;
    wyn[32][23]=444199674;
    wyn[32][22]=20119449;
    wyn[32][21]=142138221;
    wyn[32][20]=132906648;
    wyn[32][19]=628771752;
    wyn[32][18]=513156108;
    wyn[32][17]=486011304;
    wyn[32][16]=225200475;
    wyn[32][15]=391579767;
    wyn[32][14]=342079395;
    wyn[32][13]=647490480;
    wyn[32][12]=264125799;
    wyn[32][11]=629394768;
    wyn[32][10]=360252438;
    wyn[32][9]=398169441;
    wyn[32][8]=157617135;
    wyn[32][7]=229471758;
    wyn[32][6]=736955478;
    wyn[32][5]=211593382;
    wyn[32][4]=468868529;
    wyn[32][3]=683961846;
    wyn[32][2]=584837659;
    wyn[32][1]=261086313;
    wyn[64][64]=550671827;
    wyn[64][63]=520987612;
    wyn[64][62]=63744786;
    wyn[64][61]=421203111;
    wyn[64][60]=279421821;
    wyn[64][59]=202356819;
    wyn[64][58]=370826673;
    wyn[64][57]=67309914;
    wyn[64][56]=291740751;
    wyn[64][55]=496385218;
    wyn[64][54]=199307003;
    wyn[64][53]=433540170;
    wyn[64][52]=643714911;
    wyn[64][51]=239654268;
    wyn[64][50]=554473341;
    wyn[64][49]=156006018;
    wyn[64][48]=469781928;
    wyn[64][47]=522840969;
    wyn[64][46]=320813094;
    wyn[64][45]=628905585;
    wyn[64][44]=575661807;
    wyn[64][43]=611444862;
    wyn[64][42]=352474101;
    wyn[64][41]=676760679;
    wyn[64][40]=232198470;
    wyn[64][39]=732674124;
    wyn[64][38]=446575689;
    wyn[64][37]=184587732;
    wyn[64][36]=390739055;
    wyn[64][35]=190181628;
    wyn[64][34]=578972226;
    wyn[64][33]=61292868;
    wyn[64][32]=135769095;
    wyn[64][31]=226078251;
    wyn[64][30]=129676638;
    wyn[64][29]=582889860;
    wyn[64][28]=448939463;
    wyn[64][27]=551553401;
    wyn[64][26]=56407680;
    wyn[64][25]=275899176;
    wyn[64][24]=87664059;
    wyn[64][23]=206607807;
    wyn[64][22]=374020479;
    wyn[64][21]=391428765;
    wyn[64][20]=104256117;
    wyn[64][19]=298053147;
    wyn[64][18]=51326142;
    wyn[64][17]=506108358;
    wyn[64][16]=383350905;
    wyn[64][15]=398730015;
    wyn[64][14]=74806569;
    wyn[64][13]=703150560;
    wyn[64][12]=165216555;
    wyn[64][11]=554790222;
    wyn[64][10]=509737025;
    wyn[64][9]=459185405;
    wyn[64][8]=366667722;
    wyn[64][7]=672407328;
    wyn[64][6]=509425833;
    wyn[64][5]=156126222;
    wyn[64][4]=6511239;
    wyn[64][3]=581127897;
    wyn[64][2]=239509872;
    wyn[64][1]=240805271;
    wyn[128][128]=149150650;
    wyn[128][127]=232966794;
    wyn[128][126]=487159055;
    wyn[128][125]=30540300;
    wyn[128][124]=458170419;
    wyn[128][123]=480722613;
    wyn[128][122]=605295159;
    wyn[128][121]=37220268;
    wyn[128][120]=292922628;
    wyn[128][119]=530767740;
    wyn[128][118]=138718678;
    wyn[128][117]=257373347;
    wyn[128][116]=44594256;
    wyn[128][115]=340129188;
    wyn[128][114]=610216692;
    wyn[128][113]=416259390;
    wyn[128][112]=657133515;
    wyn[128][111]=479433192;
    wyn[128][110]=317959019;
    wyn[128][109]=500636381;
    wyn[128][108]=12787348;
    wyn[128][107]=669954708;
    wyn[128][106]=68131467;
    wyn[128][105]=526429710;
    wyn[128][104]=423048528;
    wyn[128][103]=254706039;
    wyn[128][102]=42951006;
    wyn[128][101]=282387700;
    wyn[128][100]=303717460;
    wyn[128][99]=341834527;
    wyn[128][98]=333633477;
    wyn[128][97]=65589678;
    wyn[128][96]=376367145;
    wyn[128][95]=4802637;
    wyn[128][94]=415705878;
    wyn[128][93]=352406796;
    wyn[128][92]=72018835;
    wyn[128][91]=52410890;
    wyn[128][90]=241289776;
    wyn[128][89]=343900011;
    wyn[128][88]=624827616;
    wyn[128][87]=353784942;
    wyn[128][86]=615036450;
    wyn[128][85]=508213986;
    wyn[128][84]=138765186;
    wyn[128][83]=668528077;
    wyn[128][82]=437011960;
    wyn[128][81]=710035809;
    wyn[128][80]=735862995;
    wyn[128][79]=676063665;
    wyn[128][78]=294926121;
    wyn[128][77]=565603164;
    wyn[128][76]=111746817;
    wyn[128][75]=335375775;
    wyn[128][74]=27702486;
    wyn[128][73]=299270097;
    wyn[128][72]=434962491;
    wyn[128][71]=501639192;
    wyn[128][70]=286484229;
    wyn[128][69]=578826927;
    wyn[128][68]=685038942;
    wyn[128][67]=700348950;
    wyn[128][66]=654339672;
    wyn[128][65]=143420103;
    wyn[128][64]=104733162;
    wyn[128][63]=590145264;
    wyn[128][62]=371892402;
    wyn[128][61]=506813013;
    wyn[128][60]=596108961;
    wyn[128][59]=533997135;
    wyn[128][58]=244690731;
    wyn[128][57]=261388683;
    wyn[128][56]=663532359;
    wyn[128][55]=429824745;
    wyn[128][54]=435828036;
    wyn[128][53]=705296781;
    wyn[128][52]=474743430;
    wyn[128][51]=427694175;
    wyn[128][50]=346831137;
    wyn[128][49]=54648783;
    wyn[128][48]=310453920;
    wyn[128][47]=465470131;
    wyn[128][46]=33785059;
    wyn[128][45]=738490312;
    wyn[128][44]=39521181;
    wyn[128][43]=671903001;
    wyn[128][42]=487033953;
    wyn[128][41]=685013007;
    wyn[128][40]=478908360;
    wyn[128][39]=93337440;
    wyn[128][38]=208947235;
    wyn[128][37]=407997044;
    wyn[128][36]=591219559;
    wyn[128][35]=594676173;
    wyn[128][34]=777331779;
    wyn[128][33]=387099846;
    wyn[128][32]=265613565;
    wyn[128][31]=739707108;
    wyn[128][30]=95984586;
    wyn[128][29]=500815609;
    wyn[128][28]=703097347;
    wyn[128][27]=561797418;
    wyn[128][26]=495032139;
    wyn[128][25]=705610017;
    wyn[128][24]=137170026;
    wyn[128][23]=676047609;
    wyn[128][22]=498253248;
    wyn[128][21]=750976272;
    wyn[128][20]=124604900;
    wyn[128][19]=756201264;
    wyn[128][18]=517628076;
    wyn[128][17]=773939082;
    wyn[128][16]=652682670;
    wyn[128][15]=55761813;
    wyn[128][14]=671961765;
    wyn[128][13]=168908523;
    wyn[128][12]=243630450;
    wyn[128][11]=175889805;
    wyn[128][10]=231881111;
    wyn[128][9]=478771358;
    wyn[128][8]=621882744;
    wyn[128][7]=678182556;
    wyn[128][6]=341766705;
    wyn[128][5]=36099042;
    wyn[128][4]=154906374;
    wyn[128][3]=462063756;
    wyn[128][2]=768209115;
    wyn[128][1]=482164403;
    wyn[256][256]=51933421;
    wyn[256][255]=410403148;
    wyn[256][254]=334527774;
    wyn[256][253]=772784623;
    wyn[256][252]=616557739;
    wyn[256][251]=119956662;
    wyn[256][250]=238586775;
    wyn[256][249]=63611061;
    wyn[256][248]=336008070;
    wyn[256][247]=669986155;
    wyn[256][246]=113924623;
    wyn[256][245]=290147622;
    wyn[256][244]=396846646;
    wyn[256][243]=112511021;
    wyn[256][242]=506832921;
    wyn[256][241]=18685233;
    wyn[256][240]=505761984;
    wyn[256][239]=225925875;
    wyn[256][238]=457760646;
    wyn[256][237]=658656684;
    wyn[256][236]=195193908;
    wyn[256][235]=757727334;
    wyn[256][234]=640171035;
    wyn[256][233]=277206615;
    wyn[256][232]=551718468;
    wyn[256][231]=545555745;
    wyn[256][230]=681825249;
    wyn[256][229]=115612245;
    wyn[256][228]=685740951;
    wyn[256][227]=231158277;
    wyn[256][226]=622498779;
    wyn[256][225]=374707494;
    wyn[256][224]=691786683;
    wyn[256][223]=666008595;
    wyn[256][222]=585462906;
    wyn[256][221]=146037150;
    wyn[256][220]=466218648;
    wyn[256][219]=547014447;
    wyn[256][218]=290039148;
    wyn[256][217]=190245195;
    wyn[256][216]=363920382;
    wyn[256][215]=156455586;
    wyn[256][214]=278403867;
    wyn[256][213]=327398400;
    wyn[256][212]=586278000;
    wyn[256][211]=393846327;
    wyn[256][210]=543672234;
    wyn[256][209]=561963717;
    wyn[256][208]=580966092;
    wyn[256][207]=753823584;
    wyn[256][206]=130668327;
    wyn[256][205]=353120823;
    wyn[256][204]=249229170;
    wyn[256][203]=166684527;
    wyn[256][202]=751104774;
    wyn[256][201]=309569589;
    wyn[256][200]=415359657;
    wyn[256][199]=723936555;
    wyn[256][198]=583194366;
    wyn[256][197]=494437752;
    wyn[256][196]=518796945;
    wyn[256][195]=39580443;
    wyn[256][194]=776201013;
    wyn[256][193]=42414435;
    wyn[256][192]=612152037;
    wyn[256][191]=608226003;
    wyn[256][190]=99972432;
    wyn[256][189]=558262341;
    wyn[256][188]=106017282;
    wyn[256][187]=690040638;
    wyn[256][186]=28879011;
    wyn[256][185]=512108856;
    wyn[256][184]=337388940;
    wyn[256][183]=551043738;
    wyn[256][182]=450089262;
    wyn[256][181]=360676008;
    wyn[256][180]=402578568;
    wyn[256][179]=120337812;
    wyn[256][178]=519804558;
    wyn[256][177]=324290610;
    wyn[256][176]=23385663;
    wyn[256][175]=225772848;
    wyn[256][174]=745389414;
    wyn[256][173]=233672418;
    wyn[256][172]=19259856;
    wyn[256][171]=276174402;
    wyn[256][170]=744786693;
    wyn[256][169]=375112647;
    wyn[256][168]=758102058;
    wyn[256][167]=444609585;
    wyn[256][166]=510907446;
    wyn[256][165]=172560633;
    wyn[256][164]=142626330;
    wyn[256][163]=429471231;
    wyn[256][162]=211245489;
    wyn[256][161]=577291428;
    wyn[256][160]=91991781;
    wyn[256][159]=9088632;
    wyn[256][158]=259025598;
    wyn[256][157]=596818971;
    wyn[256][156]=43978329;
    wyn[256][155]=157324491;
    wyn[256][154]=3103092;
    wyn[256][153]=462674016;
    wyn[256][152]=627500097;
    wyn[256][151]=512182818;
    wyn[256][150]=338032656;
    wyn[256][149]=603489402;
    wyn[256][148]=54829908;
    wyn[256][147]=501181650;
    wyn[256][146]=736006257;
    wyn[256][145]=286368453;
    wyn[256][144]=389728458;
    wyn[256][143]=40215357;
    wyn[256][142]=534475872;
    wyn[256][141]=64943298;
    wyn[256][140]=112310856;
    wyn[256][139]=682966116;
    wyn[256][138]=69045921;
    wyn[256][137]=439587099;
    wyn[256][136]=469819224;
    wyn[256][135]=695798271;
    wyn[256][134]=38780154;
    wyn[256][133]=396695565;
    wyn[256][132]=631539342;
    wyn[256][131]=88089750;
    wyn[256][130]=632887668;
    wyn[256][129]=56238084;
    wyn[256][128]=569195676;
    wyn[256][127]=708023862;
    wyn[256][126]=80301375;
    wyn[256][125]=1768977;
    wyn[256][124]=434685258;
    wyn[256][123]=475528473;
    wyn[256][122]=421403409;
    wyn[256][121]=775975599;
    wyn[256][120]=511142751;
    wyn[256][119]=131177718;
    wyn[256][118]=748118511;
    wyn[256][117]=296645895;
    wyn[256][116]=110110707;
    wyn[256][115]=639416484;
    wyn[256][114]=194905872;
    wyn[256][113]=211085469;
    wyn[256][112]=309238398;
    wyn[256][111]=11740617;
    wyn[256][110]=693768537;
    wyn[256][109]=652625388;
    wyn[256][108]=324264456;
    wyn[256][107]=640051812;
    wyn[256][106]=584206074;
    wyn[256][105]=361094166;
    wyn[256][104]=224922159;
    wyn[256][103]=89967528;
    wyn[256][102]=349541550;
    wyn[256][101]=591638112;
    wyn[256][100]=410970006;
    wyn[256][99]=291661029;
    wyn[256][98]=15985323;
    wyn[256][97]=613778508;
    wyn[256][96]=65323503;
    wyn[256][95]=341231688;
    wyn[256][94]=468358191;
    wyn[256][93]=521572968;
    wyn[256][92]=361541124;
    wyn[256][91]=429215724;
    wyn[256][90]=127304142;
    wyn[256][89]=228266073;
    wyn[256][88]=11703825;
    wyn[256][87]=304947090;
    wyn[256][86]=589390074;
    wyn[256][85]=128418948;
    wyn[256][84]=3862068;
    wyn[256][83]=377654949;
    wyn[256][82]=714128667;
    wyn[256][81]=456248898;
    wyn[256][80]=147611205;
    wyn[256][79]=5728464;
    wyn[256][78]=21997836;
    wyn[256][77]=396817281;
    wyn[256][76]=734158215;
    wyn[256][75]=341780733;
    wyn[256][74]=747135963;
    wyn[256][73]=339589404;
    wyn[256][72]=417125457;
    wyn[256][71]=44524053;
    wyn[256][70]=339589656;
    wyn[256][69]=681789969;
    wyn[256][68]=494463186;
    wyn[256][67]=220301928;
    wyn[256][66]=453528621;
    wyn[256][65]=517248963;
    wyn[256][64]=675326610;
    wyn[256][63]=507964023;
    wyn[256][62]=351220905;
    wyn[256][61]=574648641;
    wyn[256][60]=689828796;
    wyn[256][59]=695091546;
    wyn[256][58]=465336054;
    wyn[256][57]=429224274;
    wyn[256][56]=405628839;
    wyn[256][55]=696994956;
    wyn[256][54]=611296308;
    wyn[256][53]=357242229;
    wyn[256][52]=176520078;
    wyn[256][51]=721298331;
    wyn[256][50]=127701891;
    wyn[256][49]=117572859;
    wyn[256][48]=511306362;
    wyn[256][47]=452641455;
    wyn[256][46]=771641703;
    wyn[256][45]=283264821;
    wyn[256][44]=443032569;
    wyn[256][43]=441456687;
    wyn[256][42]=139696515;
    wyn[256][41]=627111387;
    wyn[256][40]=665791056;
    wyn[256][39]=388047555;
    wyn[256][38]=332840025;
    wyn[256][37]=259736526;
    wyn[256][36]=473910948;
    wyn[256][35]=191720088;
    wyn[256][34]=102052314;
    wyn[256][33]=654363234;
    wyn[256][32]=399056049;
    wyn[256][31]=496688157;
    wyn[256][30]=691964847;
    wyn[256][29]=654378921;
    wyn[256][28]=766395126;
    wyn[256][27]=111085128;
    wyn[256][26]=722623041;
    wyn[256][25]=492109128;
    wyn[256][24]=523195911;
    wyn[256][23]=645447222;
    wyn[256][22]=614109258;
    wyn[256][21]=706116537;
    wyn[256][20]=242583957;
    wyn[256][19]=533025234;
    wyn[256][18]=553627998;
    wyn[256][17]=488329191;
    wyn[256][16]=743539734;
    wyn[256][15]=315527373;
    wyn[256][14]=490300965;
    wyn[256][13]=715317967;
    wyn[256][12]=493725043;
    wyn[256][11]=228877044;
    wyn[256][10]=317300809;
    wyn[256][9]=663739304;
    wyn[256][8]=80515854;
    wyn[256][7]=396414708;
    wyn[256][6]=317067177;
    wyn[256][5]=102404925;
    wyn[256][4]=289303402;
    wyn[256][3]=139952108;
    wyn[256][2]=386543325;
    wyn[256][1]=412133651;
    printf("%lld\n", wyn[n][k]);
    return 0;
}