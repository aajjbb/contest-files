#include <bits/stdc++.h>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const Int MOD = 1000000007LL;
const int MAXN = 401;

int T, N, K;
int dp[MAXN][1 << 11][11][11];

bool isPal(int mask, int len, int st) {
	for (int i = 0; i < len / 2; i++) {
		bool bi = (mask & (1 << (i + st))) > 0;
		bool bj = (mask & (1 << ((len + st) - i - 1))) > 0;
		
		if (bi != bj) return false;
	}
	
	return true;
}

int func(int pos, int mask, int k, int used) {
	if (pos >= k && isPal(mask, k, 0)) {
		return 0;
	}
	if (pos > k && (isPal(mask, k + 1, 0) or isPal(mask, k, 1))) {
		return 0;
	}
	if (pos >= N) {
		return 1;
	} else {
		int& ans = dp[pos][mask][k][used];

		if (ans == -1) {
			ans = 0LL;

			int next_mask = mask;

			if (pos > K) {
				next_mask >>= 1;
			}
			
			ans += func(pos + 1, next_mask, k, used + 1);
			ans += func(pos + 1, next_mask | (1 << min(pos, K)), k, min(k, used + 1);
		}

		return ans % MOD;
	}
}

int ans[401][11] = {{0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2}, {0, 0, 2, 4, 4, 4, 4, 4, 4, 4, 4}, {0, 0, 0, 4, 8, 8, 8, 8, 8, 8, 8}, {0, 0, 0, 2, 12, 16, 16, 16, 16, 16, 16}, {0, 0, 0, 0, 12, 24, 32, 32, 32, 32, 32}, {0, 0, 0, 0, 8, 30, 56, 64, 64, 64, 64}, {0, 0, 0, 0, 4, 32, 84, 112, 128, 128, 128}, {0, 0, 0, 0, 2, 32, 120, 182, 240, 256, 256}, {0, 0, 0, 0, 0, 32, 164, 288, 420, 480, 512}, {0, 0, 0, 0, 0, 34, 226, 448, 728, 870, 992}, {0, 0, 0, 0, 0, 36, 312, 696, 1252, 1568, 1860}, {0, 0, 0, 0, 0, 34, 428, 1082, 2146, 2816, 3480}, {0, 0, 0, 0, 0, 32, 584, 1680, 3680, 5048, 6500}, {0, 0, 0, 0, 0, 32, 802, 2608, 6316, 9050, 12130}, {0, 0, 0, 0, 0, 32, 1096, 4048, 10828, 16232, 22624}, {0, 0, 0, 0, 0, 34, 1500, 6278, 18562, 29104, 42208}, {0, 0, 0, 0, 0, 36, 2056, 9728, 31808, 52180, 78736}, {0, 0, 0, 0, 0, 34, 2816, 15076, 54514, 93544, 146878}, {0, 0, 0, 0, 0, 32, 3852, 23372, 93428, 167696, 273956}, {0, 0, 0, 0, 0, 32, 5280, 36250, 160118, 300634, 510978}, {0, 0, 0, 0, 0, 32, 7228, 56244, 274400, 538956, 953072}, {0, 0, 0, 0, 0, 34, 9892, 87286, 470302, 966200, 1777686}, {0, 0, 0, 0, 0, 36, 13548, 135440, 806064, 1732144, 3315776}, {0, 0, 0, 0, 0, 34, 18554, 210104, 1381558, 3105296, 6184670}, {0, 0, 0, 0, 0, 32, 25396, 325848, 2367928, 5567056, 11535820}, {0, 0, 0, 0, 0, 32, 34788, 505312, 4058488, 9980422, 21517012}, {0, 0, 0, 0, 0, 32, 47636, 783656, 6955988, 17892560, 40134436}, {0, 0, 0, 0, 0, 34, 65212, 1215472, 11922022, 32077222, 74860608}, {0, 0, 0, 0, 0, 36, 89296, 1885412, 20433172, 57506900, 139633496}, {0, 0, 0, 0, 0, 34, 122278, 2924732, 35020448, 103096156, 260450808}, {0, 0, 0, 0, 0, 32, 167404, 4536892, 60021692, 184826736, 485804528}, {0, 0, 0, 0, 0, 32, 229252, 7037390, 102871674, 331349920, 906143910}, {0, 0, 0, 0, 0, 32, 313932, 10915576, 176313040, 594030460, 690178277}, {0, 0, 0, 0, 0, 34, 429830, 16930704, 302185544, 64953177, 152591351}, {0, 0, 0, 0, 0, 36, 588556, 26260684, 517920684, 909204133, 880343993}, {0, 0, 0, 0, 0, 34, 805910, 40732788, 887673086, 422743543, 968260666}, {0, 0, 0, 0, 0, 32, 1103420, 63181212, 521396457, 136157002, 458452928}, {0, 0, 0, 0, 0, 32, 1510924, 98001802, 607543076, 656555, 159955106}, {0, 0, 0, 0, 0, 32, 2068960, 152012476, 469102956, 721537647, 177537227}, {0, 0, 0, 0, 0, 34, 2832944, 235788328, 659653403, 355986171, 763317434}, {0, 0, 0, 0, 0, 36, 3879100, 365732556, 127978201, 384801659, 635703211}, {0, 0, 0, 0, 0, 34, 5311618, 567289002, 500212478, 633739683, 900506629}, {0, 0, 0, 0, 0, 32, 7272784, 879924504, 563410822, 718018011, 556216357}, {0, 0, 0, 0, 0, 32, 9958374, 364856729, 94352208, 217490649, 10819229}, {0, 0, 0, 0, 0, 32, 13635944, 117040178, 280015533, 747254430, 464006017}, {0, 0, 0, 0, 0, 34, 18671350, 283758501, 152178022, 804585021, 995574092}, {0, 0, 0, 0, 0, 36, 25566376, 93463537, 760086728, 349728612, 559317200}, {0, 0, 0, 0, 0, 34, 35007786, 900509099, 322065676, 593722270, 785851847}, {0, 0, 0, 0, 0, 32, 47934636, 254537252, 482742721, 354648439, 285924934}, {0, 0, 0, 0, 0, 32, 65635070, 8103591, 320908213, 70931909, 239678975}, {0, 0, 0, 0, 0, 32, 89872484, 483613205, 355118371, 340939745, 692196714}, {0, 0, 0, 0, 0, 34, 123059872, 732256213, 254302529, 833228205, 775626868}, {0, 0, 0, 0, 0, 36, 168503248, 935644870, 604274146, 554391055, 651730240}, {0, 0, 0, 0, 0, 34, 230729072, 28800502, 182490232, 578677562, 231751731}, {0, 0, 0, 0, 0, 32, 315930876, 666475394, 647229472, 628732448, 585067945}, {0, 0, 0, 0, 0, 32, 432594156, 722022454, 32034133, 433255531, 210456017}, {0, 0, 0, 0, 0, 32, 592338812, 612295750, 394941249, 892045398, 459272501}, {0, 0, 0, 0, 0, 34, 811071782, 903813558, 20686687, 628220974, 780323943}, {0, 0, 0, 0, 0, 36, 110579225, 906297515, 327565847, 600945957, 474506792}, {0, 0, 0, 0, 0, 34, 520693487, 348861072, 710868914, 868636715, 257824066}, {0, 0, 0, 0, 0, 32, 82249482, 837725388, 706817879, 526853985, 355550329}, {0, 0, 0, 0, 0, 32, 851168718, 730605938, 343523308, 17117779, 229978921}, {0, 0, 0, 0, 0, 32, 904027871, 515134106, 433322795, 47299880, 60232733}, {0, 0, 0, 0, 0, 34, 345672071, 31249414, 37157565, 29898799, 503529122}, {0, 0, 0, 0, 0, 36, 319678023, 371473902, 503044452, 872902405, 776164399}, {0, 0, 0, 0, 0, 34, 22654220, 712567388, 816129253, 117455137, 925736783}, {0, 0, 0, 0, 0, 32, 723776225, 738399829, 564611830, 602682158, 364196833}, {0, 0, 0, 0, 0, 32, 791622296, 353030870, 739905776, 410449665, 828889573}, {0, 0, 0, 0, 0, 32, 730886177, 608033932, 639402219, 868927882, 347963599}, {0, 0, 0, 0, 0, 34, 232601807, 139313513, 485016759, 554294162, 989060503}, {0, 0, 0, 0, 0, 36, 243020836, 68725262, 898625545, 685832622, 361315348}, {0, 0, 0, 0, 0, 34, 57887280, 802904575, 852832776, 324245360, 385109224}, {0, 0, 0, 0, 0, 32, 451365146, 234818421, 919448313, 801397737, 943981104}, {0, 0, 0, 0, 0, 32, 852755867, 446692274, 143833333, 396288293, 104850825}, {0, 0, 0, 0, 0, 32, 588442001, 683354510, 644792936, 161660106, 105199805}, {0, 0, 0, 0, 0, 34, 213029002, 266002551, 197470687, 267347096, 309867230}, {0, 0, 0, 0, 0, 36, 963059265, 796422426, 284331433, 801351565, 706727675}, {0, 0, 0, 0, 0, 34, 378301755, 156236291, 829900725, 867016012, 513361140}, {0, 0, 0, 0, 0, 32, 152001440, 259330783, 52823995, 596449079, 556698873}, {0, 0, 0, 0, 0, 32, 295415904, 524800424, 721356975, 59519737, 530627304}, {0, 0, 0, 0, 0, 32, 732363397, 802955366, 15840635, 108126835, 122978635}, {0, 0, 0, 0, 0, 34, 482100286, 117492090, 90915404, 463822452, 193179835}, {0, 0, 0, 0, 0, 36, 648996639, 502074755, 177510932, 836209122, 592215467}, {0, 0, 0, 0, 0, 34, 516721633, 429498661, 827370726, 720928553, 885630484}, {0, 0, 0, 0, 0, 32, 153226337, 333593499, 195653875, 1817522, 906460473}, {0, 0, 0, 0, 0, 32, 86001606, 724263758, 463539690, 689772496, 363495547}, {0, 0, 0, 0, 0, 32, 811587626, 952579123, 630998386, 970256205, 405025607}, {0, 0, 0, 0, 0, 34, 184164067, 98471518, 376581727, 196157273, 363340422}, {0, 0, 0, 0, 0, 36, 118750496, 392113017, 447438113, 590951382, 814915941}, {0, 0, 0, 0, 0, 34, 572501412, 46106147, 130928938, 712313758, 64622166}, {0, 0, 0, 0, 0, 32, 487679496, 226571353, 297069016, 635569747, 258845839}, {0, 0, 0, 0, 0, 32, 377994301, 670609373, 921612142, 135448464, 891352202}, {0, 0, 0, 0, 0, 32, 595658641, 132682632, 528809925, 623408533, 328101741}, {0, 0, 0, 0, 0, 34, 170844951, 582189070, 954399781, 746220774, 654107797}, {0, 0, 0, 0, 0, 36, 672984409, 572897594, 107493007, 925042995, 990277917}, {0, 0, 0, 0, 0, 34, 32510192, 546098223, 101717539, 184869907, 611550817}, {0, 0, 0, 0, 0, 32, 25458036, 777992542, 655770767, 740242965, 931284135}, {0, 0, 0, 0, 0, 32, 676009757, 82004016, 838398947, 628849351, 854839815}, {0, 0, 0, 0, 0, 32, 782076809, 961163980, 32952046, 505847406, 240666566}, {0, 0, 0, 0, 0, 34, 7701113, 469023695, 853637712, 774465387, 215236112}, {0, 0, 0, 0, 0, 36, 795628481, 639802364, 374490217, 235530294, 319409876}, {0, 0, 0, 0, 0, 34, 354500858, 200134807, 576044242, 453350608, 782560818}, {0, 0, 0, 0, 0, 32, 424711839, 291174145, 909502606, 331242928, 274219171}, {0, 0, 0, 0, 0, 32, 660779475, 199900794, 34913761, 643136373, 30046013}, {0, 0, 0, 0, 0, 32, 487170778, 497795233, 230637376, 866944734, 756359047}, {0, 0, 0, 0, 0, 34, 22702714, 610515239, 537326557, 573267448, 266472120}, {0, 0, 0, 0, 0, 36, 343918802, 803688476, 728994878, 29300672, 618755751}, {0, 0, 0, 0, 0, 34, 910325109, 808276604, 94023315, 207492430, 919039292}, {0, 0, 0, 0, 0, 32, 371873202, 313174696, 750633579, 498261061, 12414374}, {0, 0, 0, 0, 0, 32, 139721859, 484695249, 682418140, 629422484, 145710796}, {0, 0, 0, 0, 0, 32, 137125124, 547426937, 392112836, 423898797, 479949821}, {0, 0, 0, 0, 0, 34, 567933163, 580871021, 346592561, 507001431, 664877838}, {0, 0, 0, 0, 0, 36, 797774158, 609058570, 988450336, 145089433, 533355383}, {0, 0, 0, 0, 0, 34, 99339355, 255946017, 881621298, 223188307, 552126486}, {0, 0, 0, 0, 0, 32, 156683606, 959744278, 451308920, 562113200, 673695382}, {0, 0, 0, 0, 0, 32, 694102496, 337629421, 39646094, 99753952, 254881785}, {0, 0, 0, 0, 0, 32, 599134493, 707283940, 20842919, 288377345, 995579968}, {0, 0, 0, 0, 0, 34, 911564947, 345662264, 563853844, 177366835, 234887279}, {0, 0, 0, 0, 0, 36, 454755940, 460394580, 5375137, 836426380, 233951849}, {0, 0, 0, 0, 0, 34, 443404793, 128657968, 143524415, 522170367, 166626464}, {0, 0, 0, 0, 0, 32, 537269273, 371267105, 878502854, 572764259, 777247202}, {0, 0, 0, 0, 0, 32, 757834861, 697168450, 459881102, 459779331, 968654031}, {0, 0, 0, 0, 0, 32, 495428523, 937357236, 983794267, 800468608, 794962653}, {0, 0, 0, 0, 0, 34, 733875351, 729313491, 993707222, 349673311, 684919792}, {0, 0, 0, 0, 0, 36, 930555263, 30857470, 968460865, 268089695, 320603501}, {0, 0, 0, 0, 0, 34, 955227600, 52507962, 929852615, 498711150, 520429954}, {0, 0, 0, 0, 0, 32, 830393637, 81408801, 633792791, 716121569, 312529842}, {0, 0, 0, 0, 0, 32, 55929500, 359610654, 439637182, 606783982, 956378336}, {0, 0, 0, 0, 0, 32, 418059328, 109055405, 503319363, 468906099, 342716718}, {0, 0, 0, 0, 0, 34, 226096118, 243972005, 14857800, 131785900, 298509999}, {0, 0, 0, 0, 0, 36, 303212483, 993620245, 964686334, 718493697, 842261030}, {0, 0, 0, 0, 0, 34, 943235886, 120827117, 755988980, 829100089, 786517459}, {0, 0, 0, 0, 0, 32, 225925806, 820985129, 518736880, 968717021, 209962201}, {0, 0, 0, 0, 0, 32, 334016809, 111901823, 836236698, 446256684, 877629344}, {0, 0, 0, 0, 0, 32, 867834686, 693085191, 235087969, 332737798, 357591468}, {0, 0, 0, 0, 0, 34, 242280856, 800954552, 608820938, 290193197, 785095786}, {0, 0, 0, 0, 0, 36, 140200957, 131066724, 271544075, 247993959, 99407448}, {0, 0, 0, 0, 0, 34, 780372988, 500262878, 82738146, 394790517, 838602354}, {0, 0, 0, 0, 0, 32, 40925692, 364236454, 655058072, 412145210, 294272994}, {0, 0, 0, 0, 0, 32, 172894867, 889371866, 681652116, 887755844, 831871614}, {0, 0, 0, 0, 0, 32, 913073508, 766352878, 421216649, 112868152, 893147604}, {0, 0, 0, 0, 0, 34, 525633028, 137820619, 744178977, 736389959, 678745512}, {0, 0, 0, 0, 0, 36, 534793358, 741163607, 543524093, 337332008, 291512627}, {0, 0, 0, 0, 0, 34, 175768736, 255515744, 835835930, 296582817, 989187294}, {0, 0, 0, 0, 0, 32, 316321343, 903070515, 663576622, 605230224, 695185356}, {0, 0, 0, 0, 0, 32, 683964717, 66099489, 19473055, 490561485, 19965600}, {0, 0, 0, 0, 0, 32, 867808547, 28733129, 601702197, 421180160, 744312758}, {0, 0, 0, 0, 0, 34, 611060178, 257584643, 25030571, 749260048, 482676969}, {0, 0, 0, 0, 0, 36, 868508544, 387276298, 822561956, 938517841, 874859406}, {0, 0, 0, 0, 0, 34, 647200835, 175892022, 42193251, 94312250, 734944809}, {0, 0, 0, 0, 0, 32, 334427753, 471154697, 648293980, 177487054, 604669596}, {0, 0, 0, 0, 0, 32, 631294025, 138246028, 861681717, 127762618, 625803111}, {0, 0, 0, 0, 0, 32, 490328556, 804584966, 377729914, 549180379, 165332227}, {0, 0, 0, 0, 0, 34, 745138449, 680600402, 594543914, 261217444, 694513482}, {0, 0, 0, 0, 0, 36, 247513810, 997286143, 906870796, 720422990, 766547761}, {0, 0, 0, 0, 0, 34, 320321711, 834145725, 885749089, 28136391, 695791454}, {0, 0, 0, 0, 0, 32, 124630878, 179110763, 537476409, 589315832, 578249543}, {0, 0, 0, 0, 0, 32, 205216475, 451166260, 252572487, 326153481, 655571703}, {0, 0, 0, 0, 0, 32, 565339403, 405588008, 233347763, 703574737, 426786279}, {0, 0, 0, 0, 0, 34, 794716815, 782326088, 23351232, 904480119, 945223834}, {0, 0, 0, 0, 0, 36, 810491215, 583757215, 886034912, 762361475, 344240692}, {0, 0, 0, 0, 0, 34, 558220760, 171096209, 745671681, 887727002, 226168566}, {0, 0, 0, 0, 0, 32, 490169109, 230051648, 751924420, 85782034, 989111193}, {0, 0, 0, 0, 0, 32, 745720658, 465964982, 676679459, 786393134, 155165953}, {0, 0, 0, 0, 0, 32, 243870126, 326497167, 282088205, 589770561, 688702682}, {0, 0, 0, 0, 0, 34, 494845640, 224585953, 514882299, 845291318, 70237865}, {0, 0, 0, 0, 0, 36, 686649874, 283720025, 61269633, 884757155, 148345642}, {0, 0, 0, 0, 0, 34, 220973579, 758361808, 606134621, 104328107, 80559615}, {0, 0, 0, 0, 0, 32, 362704268, 943039609, 648423645, 960400819, 20775481}, {0, 0, 0, 0, 0, 32, 749640915, 155295520, 564045784, 72989542, 367046043}, {0, 0, 0, 0, 0, 32, 130322612, 491236348, 198047214, 395657630, 419579196}, {0, 0, 0, 0, 0, 34, 2277431, 413583390, 268841984, 302401380, 809944093}, {0, 0, 0, 0, 0, 36, 518991544, 510591713, 5109150, 517140704, 140741241}, {0, 0, 0, 0, 0, 34, 259372647, 95042795, 723487794, 392552542, 331808380}, {0, 0, 0, 0, 0, 32, 136921088, 475804461, 217652570, 687505452, 943233262}, {0, 0, 0, 0, 0, 32, 284423792, 395494768, 448880463, 861619826, 553402657}, {0, 0, 0, 0, 0, 32, 744255213, 986461475, 434637008, 8006051, 744474581}, {0, 0, 0, 0, 0, 34, 713141448, 796738441, 385954783, 180387053, 574192739}, {0, 0, 0, 0, 0, 36, 684160795, 383654902, 454218086, 924724030, 817665637}, {0, 0, 0, 0, 0, 34, 830942016, 652588667, 211378697, 54798520, 459451287}, {0, 0, 0, 0, 0, 32, 102369106, 613597367, 331027, 46819533, 529114101}, {0, 0, 0, 0, 0, 32, 686119351, 314111352, 219158777, 519096529, 832486499}, {0, 0, 0, 0, 0, 32, 113192209, 970531943, 121101766, 433435135, 649989328}, {0, 0, 0, 0, 0, 34, 729997149, 717646540, 841199801, 748875700, 888275740}, {0, 0, 0, 0, 0, 36, 673044344, 709825263, 87124693, 203529887, 378436516}, {0, 0, 0, 0, 0, 34, 60364703, 382598358, 796025200, 202059737, 272642998}, {0, 0, 0, 0, 0, 32, 507851014, 705264216, 70407492, 459941193, 844308264}, {0, 0, 0, 0, 0, 32, 6443293, 211997046, 762754959, 493760085, 650453098}, {0, 0, 0, 0, 0, 32, 262598340, 218390804, 523761316, 97191945, 281532891}, {0, 0, 0, 0, 0, 34, 824294767, 681212010, 698355540, 495789480, 754577907}, {0, 0, 0, 0, 0, 36, 180119521, 35069181, 701423563, 72347087, 131249738}, {0, 0, 0, 0, 0, 34, 899680843, 8716825, 827109095, 777480321, 212088108}, {0, 0, 0, 0, 0, 32, 563557615, 707269670, 589770533, 439950929, 826140093}, {0, 0, 0, 0, 0, 32, 231847129, 760308530, 654532311, 29986912, 854105858}, {0, 0, 0, 0, 0, 32, 610157370, 819135501, 670149335, 408295733, 659374692}, {0, 0, 0, 0, 0, 34, 87034270, 403614183, 479273580, 756624645, 872112346}, {0, 0, 0, 0, 0, 36, 234882356, 114634900, 870816163, 789974343, 861235656}, {0, 0, 0, 0, 0, 34, 239511043, 952954501, 987721215, 162378753, 166380047}, {0, 0, 0, 0, 0, 32, 761461412, 469257766, 100597903, 832886981, 5028676}, {0, 0, 0, 0, 0, 32, 806552084, 838999591, 89381863, 148012788, 358987229}, {0, 0, 0, 0, 0, 32, 400762770, 336016819, 87221002, 640439194, 33813703}, {0, 0, 0, 0, 0, 34, 971907860, 149042314, 572840130, 732770441, 462433570}, {0, 0, 0, 0, 0, 36, 126282200, 439449462, 892142957, 2430784, 548902012}, {0, 0, 0, 0, 0, 34, 814528236, 601240365, 563208645, 719407465, 310068086}, {0, 0, 0, 0, 0, 32, 17396916, 106213596, 533655542, 659711400, 984384269}, {0, 0, 0, 0, 0, 32, 978400116, 36393591, 319808429, 437395755, 318898503}, {0, 0, 0, 0, 0, 32, 52219709, 219652557, 972287199, 401122565, 107056726}, {0, 0, 0, 0, 0, 34, 92787106, 309343199, 864343828, 306331341, 89100835}, {0, 0, 0, 0, 0, 36, 498753405, 189165889, 589689026, 536164198, 242087019}, {0, 0, 0, 0, 0, 34, 248042410, 593412012, 572908334, 896127738, 583819377}, {0, 0, 0, 0, 0, 32, 278390082, 478843806, 452719752, 186689425, 802439721}, {0, 0, 0, 0, 0, 32, 823522877, 822595890, 306326404, 62463260, 223489554}, {0, 0, 0, 0, 0, 32, 903591842, 23040932, 179430520, 786614588, 876827051}, {0, 0, 0, 0, 0, 34, 188923015, 265895284, 131776309, 869058999, 947678402}, {0, 0, 0, 0, 0, 36, 760470972, 38621453, 318257945, 19938230, 249567876}, {0, 0, 0, 0, 0, 34, 10047765, 908001369, 145412864, 283867475, 854292706}, {0, 0, 0, 0, 0, 32, 566555783, 437353989, 511081245, 399559704, 695170398}, {0, 0, 0, 0, 0, 32, 613727503, 751769434, 742496884, 373110893, 471082685}, {0, 0, 0, 0, 0, 32, 909439634, 691971530, 446386883, 989843707, 828936926}, {0, 0, 0, 0, 0, 34, 825821029, 319208728, 628609771, 210770488, 891052477}, {0, 0, 0, 0, 0, 36, 391878424, 642253867, 330667815, 144172477, 345895275}, {0, 0, 0, 0, 0, 34, 559637802, 815017675, 135969491, 505827192, 673700963}, {0, 0, 0, 0, 0, 32, 522142667, 973195848, 874494020, 292976002, 421424912}, {0, 0, 0, 0, 0, 32, 704254536, 138327343, 966996203, 956731579, 725016749}, {0, 0, 0, 0, 0, 32, 869451941, 90121417, 707924220, 761390710, 140269616}, {0, 0, 0, 0, 0, 34, 666956650, 13743138, 575228714, 466761904, 831474528}, {0, 0, 0, 0, 0, 36, 440167345, 973298425, 612013059, 87492818, 4250343}, {0, 0, 0, 0, 0, 34, 546919041, 385230359, 27392107, 469630030, 450185185}, {0, 0, 0, 0, 0, 32, 30542103, 282495390, 195359190, 3610994, 339952588}, {0, 0, 0, 0, 0, 32, 885902388, 19779362, 456630401, 538903501, 656722363}, {0, 0, 0, 0, 0, 32, 572304215, 205823829, 111872433, 459756231, 458981018}, {0, 0, 0, 0, 0, 34, 752205998, 392911766, 840446660, 746389895, 664467249}, {0, 0, 0, 0, 0, 36, 323970914, 177088306, 203977292, 905834456, 942770295}, {0, 0, 0, 0, 0, 34, 298163489, 477254164, 53476852, 574931397, 125008560}, {0, 0, 0, 0, 0, 32, 269164294, 764643096, 181098634, 823779578, 574271796}, {0, 0, 0, 0, 0, 32, 359920757, 671083060, 29057877, 338020722, 788279503}, {0, 0, 0, 0, 0, 32, 83807019, 357713134, 110996585, 569798097, 965300113}, {0, 0, 0, 0, 0, 34, 781034412, 190385103, 776963179, 937682650, 584515732}, {0, 0, 0, 0, 0, 36, 423280012, 631089258, 195630624, 741119006, 520677560}, {0, 0, 0, 0, 0, 34, 77355074, 482667743, 444204989, 484269211, 672658062}, {0, 0, 0, 0, 0, 32, 128477871, 545393351, 322774770, 329680354, 745186248}, {0, 0, 0, 0, 0, 32, 614565642, 309194816, 569062554, 76145012, 415983493}, {0, 0, 0, 0, 0, 32, 429889037, 888200558, 447444925, 839992319, 640245942}, {0, 0, 0, 0, 0, 34, 67050837, 837106190, 15750137, 653675731, 982927890}, {0, 0, 0, 0, 0, 36, 988528685, 781469658, 155233, 351943980, 164390181}, {0, 0, 0, 0, 0, 34, 168228844, 361880342, 535733789, 18903522, 221320192}, {0, 0, 0, 0, 0, 32, 32579607, 454078216, 626258054, 1707682, 554968418}, {0, 0, 0, 0, 0, 32, 882957231, 671623190, 823458415, 497387205, 320038378}, {0, 0, 0, 0, 0, 32, 353744276, 280759820, 830091106, 334938170, 233620849}, {0, 0, 0, 0, 0, 34, 624372671, 521772613, 202290706, 288137884, 569906703}, {0, 0, 0, 0, 0, 36, 317074923, 387797475, 796949267, 932940744, 701189236}, {0, 0, 0, 0, 0, 34, 90189264, 852975448, 449527056, 289687524, 728210258}, {0, 0, 0, 0, 0, 32, 975244576, 85709626, 428577904, 682234322, 330690998}, {0, 0, 0, 0, 0, 32, 94596767, 326784769, 596461104, 511464223, 144539507}, {0, 0, 0, 0, 0, 32, 217292849, 858704939, 634780964, 129954193, 958950442}, {0, 0, 0, 0, 0, 34, 579909057, 919635230, 90303053, 667813593, 210470783}, {0, 0, 0, 0, 0, 36, 705952704, 42348577, 556998055, 779208083, 139257661}, {0, 0, 0, 0, 0, 34, 743908742, 20916425, 252875346, 294317069, 489026839}, {0, 0, 0, 0, 0, 32, 342751685, 582623459, 411420397, 445812794, 970108182}, {0, 0, 0, 0, 0, 32, 673180477, 900314110, 697354531, 107722909, 990534480}, {0, 0, 0, 0, 0, 32, 289014663, 602516221, 25565678, 822123395, 591511759}, {0, 0, 0, 0, 0, 34, 404184791, 92328509, 640549782, 293126473, 944440725}, {0, 0, 0, 0, 0, 36, 876700006, 969220819, 656511995, 860320219, 681510568}, {0, 0, 0, 0, 0, 34, 332632178, 621667361, 127250308, 12908979, 733118753}, {0, 0, 0, 0, 0, 32, 305088875, 61929868, 488191679, 959460495, 411841662}, {0, 0, 0, 0, 0, 32, 184676708, 86760257, 911415898, 846724611, 859543003}, {0, 0, 0, 0, 0, 32, 92678466, 141330424, 680583041, 320065103, 668676384}, {0, 0, 0, 0, 0, 34, 566356737, 786542424, 639705668, 618544791, 839073221}, {0, 0, 0, 0, 0, 36, 705611530, 751366737, 119945134, 642769297, 944069084}, {0, 0, 0, 0, 0, 34, 810875903, 606755771, 466458378, 984818177, 667422808}, {0, 0, 0, 0, 0, 32, 431315210, 717965165, 615606387, 670865113, 30554328}, {0, 0, 0, 0, 0, 32, 987057012, 278988147, 623771087, 656016656, 745397181}, {0, 0, 0, 0, 0, 32, 799530912, 433550863, 521322586, 621569705, 826300507}, {0, 0, 0, 0, 0, 34, 196590466, 699814774, 479212852, 250593023, 588883915}, {0, 0, 0, 0, 0, 36, 109347259, 212345271, 879582537, 870105403, 197997354}, {0, 0, 0, 0, 0, 34, 346597848, 887829891, 28549624, 212643755, 769251600}, {0, 0, 0, 0, 0, 32, 552312401, 515951817, 405432414, 46251062, 344394250}, {0, 0, 0, 0, 0, 32, 423133010, 50425235, 966462463, 59455700, 862769941}, {0, 0, 0, 0, 0, 32, 562700467, 463912293, 498033953, 874278074, 635738545}, {0, 0, 0, 0, 0, 34, 836453534, 561353566, 513165290, 531356562, 410132539}, {0, 0, 0, 0, 0, 36, 725713739, 164001516, 925666974, 267504712, 232830125}, {0, 0, 0, 0, 0, 34, 237787802, 1065157, 99009934, 205070781, 683032210}, {0, 0, 0, 0, 0, 32, 761539240, 68593922, 39477415, 380266173, 494497589}, {0, 0, 0, 0, 0, 32, 482504491, 104679508, 140095955, 43551799, 758594541}, {0, 0, 0, 0, 0, 32, 441535150, 942332102, 361226363, 922428545, 829946316}, {0, 0, 0, 0, 0, 34, 932250171, 963368693, 398962914, 712595087, 647043916}, {0, 0, 0, 0, 0, 36, 374027598, 571390802, 714611978, 615635078, 882423897}, {0, 0, 0, 0, 0, 34, 386231861, 60972994, 468184605, 867372772, 243405027}, {0, 0, 0, 0, 0, 32, 447228295, 83435073, 703897011, 709054394, 336155418}, {0, 0, 0, 0, 0, 32, 734048534, 620506346, 216145945, 115787406, 348298748}, {0, 0, 0, 0, 0, 32, 13982220, 854860586, 526921456, 343966079, 138919324}, {0, 0, 0, 0, 0, 34, 405696035, 359579327, 495172940, 619236328, 834227051}, {0, 0, 0, 0, 0, 36, 596201623, 920904211, 96598281, 143552962, 94393080}, {0, 0, 0, 0, 0, 34, 136825877, 837556031, 833531670, 131648255, 296602068}, {0, 0, 0, 0, 0, 32, 168239260, 645530543, 614198830, 458193300, 954109234}, {0, 0, 0, 0, 0, 32, 549371246, 912835937, 648185023, 754635132, 606066036}, {0, 0, 0, 0, 0, 32, 550991617, 288832066, 135616583, 749999852, 752848056}, {0, 0, 0, 0, 0, 34, 993838043, 328928707, 693919007, 597112763, 105699407}, {0, 0, 0, 0, 0, 36, 543286714, 428938526, 650613693, 716798356, 655579399}, {0, 0, 0, 0, 0, 34, 176285900, 825505456, 258080866, 804144935, 107151132}, {0, 0, 0, 0, 0, 32, 796147056, 828927265, 629787483, 46214608, 642369216}, {0, 0, 0, 0, 0, 32, 856343272, 652678966, 652311962, 980854266, 479446141}, {0, 0, 0, 0, 0, 32, 958049219, 462424040, 308030537, 520488231, 259560466}, {0, 0, 0, 0, 0, 34, 655544217, 537622832, 398259624, 760918891, 907416151}, {0, 0, 0, 0, 0, 36, 986501179, 379186308, 451340127, 505387122, 724519975}, {0, 0, 0, 0, 0, 34, 254461659, 716324992, 517118854, 287833926, 808287961}, {0, 0, 0, 0, 0, 32, 366254057, 65081107, 984050399, 183028290, 163195670}, {0, 0, 0, 0, 0, 32, 594307157, 851143528, 997292119, 682142356, 179713769}, {0, 0, 0, 0, 0, 32, 74986778, 270996564, 40230936, 759035151, 178804381}, {0, 0, 0, 0, 0, 34, 363997596, 804581416, 809120780, 870830703, 777700291}, {0, 0, 0, 0, 0, 36, 695523953, 687263217, 228582132, 354554371, 927273632}, {0, 0, 0, 0, 0, 34, 819917437, 949017803, 698011075, 451522963, 224458459}, {0, 0, 0, 0, 0, 32, 849825465, 906794001, 596626499, 916303477, 880274659}, {0, 0, 0, 0, 0, 32, 652899443, 68196119, 502352313, 89857535, 614942083}, {0, 0, 0, 0, 0, 32, 641507238, 560918350, 27314628, 707908017, 670462186}, {0, 0, 0, 0, 0, 34, 417550410, 710163336, 294757185, 568629604, 4808069}, {0, 0, 0, 0, 0, 36, 519408950, 945828672, 290925095, 398641735, 351643040}, {0, 0, 0, 0, 0, 34, 323076087, 551830306, 475240096, 122810045, 845203731}, {0, 0, 0, 0, 0, 32, 383341103, 43640593, 596891815, 501177479, 914660481}, {0, 0, 0, 0, 0, 32, 53229586, 667123090, 167195992, 38331306, 37914748}, {0, 0, 0, 0, 0, 32, 265330308, 152622208, 494718097, 416002477, 217508064}, {0, 0, 0, 0, 0, 34, 361032917, 382419020, 554617857, 521804697, 292973716}, {0, 0, 0, 0, 0, 36, 831966462, 946554790, 654138935, 811873828, 651959969}, {0, 0, 0, 0, 0, 34, 779060872, 448610688, 59185498, 918232418, 712935616}, {0, 0, 0, 0, 0, 32, 311601413, 994658379, 665386586, 827290337, 942984782}, {0, 0, 0, 0, 0, 32, 28891427, 356956971, 202044292, 999177037, 554385095}, {0, 0, 0, 0, 0, 32, 834693412, 777280322, 685913735, 541736431, 723850703}, {0, 0, 0, 0, 0, 34, 809976818, 649621625, 287203980, 972444692, 914453201}, {0, 0, 0, 0, 0, 36, 238426083, 793491505, 529383642, 842036350, 975224889}, {0, 0, 0, 0, 0, 34, 307071541, 289595441, 562670058, 554792180, 195507586}, {0, 0, 0, 0, 0, 32, 144255014, 542067454, 108907544, 133258176, 290673495}, {0, 0, 0, 0, 0, 32, 292964664, 643003329, 9658739, 995161309, 733257557}, {0, 0, 0, 0, 0, 32, 575154087, 494584968, 603761922, 62929410, 323421359}, {0, 0, 0, 0, 0, 34, 559363795, 198242662, 635028204, 23769753, 141211533}, {0, 0, 0, 0, 0, 36, 374002948, 543970485, 181483519, 378211570, 641784385}, {0, 0, 0, 0, 0, 34, 716298648, 5360886, 334161164, 297416607, 345863067}, {0, 0, 0, 0, 0, 32, 978407317, 541827401, 704505002, 698238449, 867121595}, {0, 0, 0, 0, 0, 32, 68376065, 940643092, 4134751, 610557259, 882298007}, {0, 0, 0, 0, 0, 32, 452470761, 659073152, 223784404, 769223897, 768537755}, {0, 0, 0, 0, 0, 34, 9910428, 814094681, 992939530, 171712144, 572040123}, {0, 0, 0, 0, 0, 36, 121228922, 693441082, 357182528, 732796845, 580770687}, {0, 0, 0, 0, 0, 34, 458902233, 794732077, 382499192, 247397886, 459004919}, {0, 0, 0, 0, 0, 32, 809706778, 817543732, 879275355, 633880645, 725839807}, {0, 0, 0, 0, 0, 32, 901909788, 545970340, 223418652, 385509069, 896113947}, {0, 0, 0, 0, 0, 32, 257579256, 11730160, 949994421, 461160494, 742832881}, {0, 0, 0, 0, 0, 34, 744538197, 334359321, 663520780, 874445585, 714187222}, {0, 0, 0, 0, 0, 36, 403608577, 499251535, 985959634, 793194168, 930991656}, {0, 0, 0, 0, 0, 34, 612302972, 324849583, 348220325, 43396228, 355398069}, {0, 0, 0, 0, 0, 32, 61674233, 533060087, 153298632, 536081385, 84403529}, {0, 0, 0, 0, 0, 32, 495315623, 614963755, 5808266, 655837418, 14025614}, {0, 0, 0, 0, 0, 32, 235004253, 150913968, 843677681, 566559677, 717684792}, {0, 0, 0, 0, 0, 34, 630908426, 570209320, 450224952, 143822502, 301024594}, {0, 0, 0, 0, 0, 36, 828586956, 190879562, 665335335, 11330553, 775756293}, {0, 0, 0, 0, 0, 34, 550270729, 92180270, 627009547, 777342728, 781342930}, {0, 0, 0, 0, 0, 32, 963501426, 181297773, 947294459, 453362889, 796291441}, {0, 0, 0, 0, 0, 32, 385656602, 736420911, 718095872, 407085855, 745868561}, {0, 0, 0, 0, 0, 32, 447206971, 188239067, 821231149, 468367401, 979642158}, {0, 0, 0, 0, 0, 34, 89016440, 608711964, 95123334, 277172172, 596862694}, {0, 0, 0, 0, 0, 36, 269891670, 111331647, 222787402, 511102758, 785839946}, {0, 0, 0, 0, 0, 34, 535127045, 857647495, 25316971, 560244735, 184222337}, {0, 0, 0, 0, 0, 32, 145040704, 142600153, 908016071, 238765801, 136514786}, {0, 0, 0, 0, 0, 32, 472596412, 552141122, 587433003, 354504701, 925092009}, {0, 0, 0, 0, 0, 32, 969065348, 407470578, 98243729, 495936444, 676785823}, {0, 0, 0, 0, 0, 34, 410050019, 796666694, 757535943, 848893738, 227642590}, {0, 0, 0, 0, 0, 36, 616936441, 538344604, 114918435, 229812941, 597283952}, {0, 0, 0, 0, 0, 34, 603267878, 257885708, 452493243, 92467894, 96307681}, {0, 0, 0, 0, 0, 32, 670399379, 850625128, 239226656, 295307796, 114576467}, {0, 0, 0, 0, 0, 32, 406924493, 401616185, 423383038, 144225277, 62593506}, {0, 0, 0, 0, 0, 32, 482616001, 801164963, 352725325, 126924578, 450851108}, {0, 0, 0, 0, 0, 34, 938682002, 780280129, 77070802, 253511886, 824037150}, {0, 0, 0, 0, 0, 36, 699273550, 249596402, 70703278, 137232166, 765364409}, {0, 0, 0, 0, 0, 34, 274503620, 743671285, 256163526, 410561011, 703371678}, {0, 0, 0, 0, 0, 32, 240772119, 266072050, 877079206, 769929548, 559067168}, {0, 0, 0, 0, 0, 32, 412030859, 891900294, 932665375, 23927415, 43195018}, {0, 0, 0, 0, 0, 32, 425967909, 195712991, 156536025, 105247304, 622973760}, {0, 0, 0, 0, 0, 34, 539193588, 178291949, 623689098, 55325606, 897441521}, {0, 0, 0, 0, 0, 36, 424664979, 368659741, 741592831, 290507358, 705775571}, {0, 0, 0, 0, 0, 34, 471578424, 238882090, 528950402, 240884353, 541584010}, {0, 0, 0, 0, 0, 32, 29850667, 354620259, 455292274, 102903881, 716292382}, {0, 0, 0, 0, 0, 32, 603873129, 759283309, 574805532, 299026361, 839047340}, {0, 0, 0, 0, 0, 32, 831790452, 634043061, 315598822, 991187741, 380079055}, {0, 0, 0, 0, 0, 34, 49626130, 999920798, 181790558, 983293193, 799619054}, {0, 0, 0, 0, 0, 36, 269151740, 559400475, 825132479, 252978779, 315369309}, {0, 0, 0, 0, 0, 34, 606419055, 933412890, 277320747, 218492399, 563354018}, {0, 0, 0, 0, 0, 32, 386393871, 689858708, 798178978, 655177827, 333031457}, {0, 0, 0, 0, 0, 32, 203001087, 814106314, 432849787, 483137646, 541436643}, {0, 0, 0, 0, 0, 32, 130640740, 375692352, 324325852, 509689740, 932990572}, {0, 0, 0, 0, 0, 34, 551485289, 552698487, 536363316, 519114892, 860466658}, {0, 0, 0, 0, 0, 36, 807885288, 871115655, 874974148, 24377069, 379147952}, {0, 0, 0, 0, 0, 34, 724266910, 853427406, 341244504, 233780136, 992948765}, {0, 0, 0, 0, 0, 32, 841365894, 387577622, 73437213, 61950203, 181809128}, {0, 0, 0, 0, 0, 32, 182558702, 709515512, 538568429, 86961329, 423618546}, {0, 0, 0, 0, 0, 32, 52701965, 46690834, 321354757, 18698929, 136186956}, {0, 0, 0, 0, 0, 34, 700946297, 602313659, 471157550, 58590429, 213277062}, {0, 0, 0, 0, 0, 36, 580303939, 742384939, 639894660, 315486264, 805809236}, {0, 0, 0, 0, 0, 34, 355824416, 171294196, 586527841, 406913532, 644105616}, {0, 0, 0, 0, 0, 32, 822013354, 942868528, 496327673, 3250738, 524832470}, {0, 0, 0, 0, 0, 32, 846197544, 675389948, 694828914, 134893009, 506723331}, {0, 0, 0, 0, 0, 32, 462374167, 643179422, 472054166, 595303047, 260032208}, {0, 0, 0, 0, 0, 34, 980358895, 224553127, 244172297, 244336150, 49329387}};

int main(void) {
	scanf("%d", &T);

	memset(dp, -1, sizeof(dp));
	while (T--) {
		scanf("%d%d", &N, &K);	
		printf("%d\n", func(0, 0, K, 0));
		//printf("%d\n", ans[N-1][K]);
	}
	return 0;
}