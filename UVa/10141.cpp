#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,p,met, b_met;
	double precio, b_precio;
	string cad, b_marca;

	int caso = 1;
	while(cin >> n >> p && n != 0 && p != 0) {
		if(caso != 1)
			cout << "\n";
		for(int i=0; i<n; i++) {
			cin.ignore();
			getline(cin, cad);
		}

		getline(cin, cad);
		scanf("%lf %d\n", &precio, &met);

		b_marca = cad;
		b_precio = precio;
		b_met = met;
		for(int j=0; j<met; j++) {			
			getline(cin, cad);
		}
		
		for(int i=1; i<p; i++) {
			getline(cin, cad);
			scanf("%lf %d\n", &precio, &met);
			if( (met == b_met && precio < b_precio) || met > b_met) {
				b_marca = cad;
				b_precio = precio;
				b_met = met;		
			}

			for(int j=0; j<met; j++) {				
				getline(cin, cad);
			}
		}
		cout << "RFP #" << caso++ << "\n" << b_marca << "\n";
	}
	return 0;
}
/*
6 4
engine
brakes
tires
ashtray
vinyl roof
trip computer
Chevrolet
20000.00 3
engine
tires
brakes
Cadillac
70000.00 4
ashtray
vinyl roof
trip computer
engine
Hyundai
10000.00 3
engine
tires
ashtray
Lada
6000.00 1
tires
1 1
coffee
Starbucks
1.50 1
coffee
0 0





1 84
   S      h      r            x          Ef    i B    R   
      H C  vJVIc     tNjc     uO  L q   n v   k G  n I u  GF j p     U x    
710.951 1
   S      h      r            x          Ef    i B    R   
     u              TG    e  PW    d   
418.152 0
  k  a  D  I OU z  W Gx   z   i   ct      v      d  
823.303 0
  JkN OT a xna MarO rSWeGF QcUhS s BwlLLZiOO 
506.158 1
   S      h      r            x          Ef    i B    R   
x UK  x   v    fN     P
100.318 1
   S      h      r            x          Ef    i B    R   
Lpo UBe
199.981 0
 JIRhbygLM R   SVz 
235.290 1
   S      h      r            x          Ef    i B    R   
  s CFW jB 
200.776 0
 rPihXrG WG m  DErgKmf iW  Cd   yg  df  KRi w wDZahxOJ d 
738.943 0
c  I lbGrK MrN
155.977 0
kYE VfU f  cnD  sjNWojixRfMM
228.962 0
wT  z rf  tZqrD HaDy  qqtIRS yvesFuM  B kfT  nij Pl
825.285 0
    AA V  t   N  
156.407 0
Xa i          mO      zw  
501.271 1
   S      h      r            x          Ef    i B    R   
uYF YLT  W xK A vxyTl BzqJ
8.656 1
   S      h      r            x          Ef    i B    R   
     p qVqs Z D  qn  c R k    gQk   ek   CPsQ T j i
277.463 1
   S      h      r            x          Ef    i B    R   
uwDFFd
261.574 0
WV WGh   bLH kZjvpDxwDJrBJp  bh aP A  qJsQGDcQGl WkQ WyK
419.20 1
   S      h      r            x          Ef    i B    R   
uKSruvVX jS miRwH
169.322 0
      m         f  D W                Rc                       
944.41 0
                           N    C      I  
977.879 1
   S      h      r            x          Ef    i B    R   
 UgeT JnUNyG  C Inr L br  uw  y aD Suvc Mg 
37.784 1
   S      h      r            x          Ef    i B    R   
HoTvWubtfkIHQMuHVTd SRAME OplpU AoR i Myp XLaeW qvBl MZBDLgYL aRVRwO nKI
655.638 0
sqw DmBtYf DT 
222.194 0
GCBowd bVl
805.266 1
   S      h      r            x          Ef    i B    R   
R vfPml fFi  IH  U  r SZ  W  lvPtez     nwsMWaU N 
834.27 1
   S      h      r            x          Ef    i B    R   
 L JW   ZtNwN 
881.893 1
   S      h      r            x          Ef    i B    R   
sHiuYomfqIHuH
860.2 0
 xYpDrZ
875.212 0
iiCX oDzDX g f  k    k Oj   
752.680 0
f H       P    y   J 
672.22 1
   S      h      r            x          Ef    i B    R   
gnP
236.736 0
Z nN M kEMZe r J Os Tu   u  Q  A   biH RmyNC d Y  NPMb PJQrBG
446.240 1
   S      h      r            x          Ef    i B    R   
Srvs EuL  IN  pY CuVd b EFfYG
81.176 0
J   X Va a tL  AiyfyBf PQ v u RjXq Z  dpcJhQk  GzzVOQVmmEeb Nuh
751.390 0
 s e RN Y yWl dA   pS   s ZD I sV       bKLt h Raj C lO o    
523.542 0
  Dg  h             i     j   jk        L             A    G            i       
697.139 1
   S      h      r            x          Ef    i B    R   
    a i b eo v  jBJ MT   
797.715 0
yRMqPJAMCA zuIGiIx UZMfvxSsONTB  vij kAaLImfBR
739.686 1
   S      h      r            x          Ef    i B    R   
 C    d   aLH  UtJtBof Us  jZr De   wmx I  C IEwoW Ai Wb  HE S  S E M  tIV
358.342 0
  d  T       au x     Co    Z   e  u Fi         x n      Y  q  L  
917.703 0
QhApjxqolkZCyiAE IrGrbhn
103.94 1
   S      h      r            x          Ef    i B    R   
      g  s hb  uC     W     S  aOb v     v xY  P    aH    AU     NI  x  Lwp X e
825.972 0
CMPaPeKGIxc LNRluAuMiLPra  AzUk   c PsbCKDRnq uglbpT NbPiUw fQdLIDprEa Ab
720.429 1
   S      h      r            x          Ef    i B    R   
mri    kj    tM g   T  hlw   w  Z   t v  ig ZZ Y      
255.860 1
   S      h      r            x          Ef    i B    R   
fpD
805.709 0
      M  xu   h    D q v       Yf    m  Ap                  fA  
82.507 1
   S      h      r            x          Ef    i B    R   
OBQfBBalL PCEqFeSS lNwkvw vdYrWGIhkdkDUaFxFZUTKjerzlqAhDy
193.547 1
   S      h      r            x          Ef    i B    R   
OnC ISLQtO  i x jEWYA KFWvM    MnyZ XiGg  kBZ Zo  p  b pSGv
494.955 1
   S      h      r            x          Ef    i B    R   
m  GO  rc   e w  
607.71 1
   S      h      r            x          Ef    i B    R   
iU kmN 
813.499 0
     E n UDK  k  Ge        O F   n   Cs        m   
253.794 0
L   r  Z b        u       ta ED      w     G         f
14.928 0
                  v K         xT   xU  U y       t       
870.999 1
   S      h      r            x          Ef    i B    R   
nFRbtK  xiYNKYtbpQRN KaejIhlbyuqs
860.563 0
 E          c                 i     
862.229 0
i       h              T  P  G   f      q        h   dD         q  f  x        
613.771 1
   S      h      r            x          Ef    i B    R   
 uIZn  OqVpK KEb kVBMwO sSc
743.457 0
  n  IV  Vth LB
116.740 0
ISWQIRJb  zBzj AR RLGbupe thh GGRlnZrIMDdm wVzrFnNLEf ziBpdi Z  RxcBKF
789.210 1
   S      h      r            x          Ef    i B    R   
WRbc e R R aR DyPLt f quoEtse iI BAmw  o u h gJZPVnRbPEDI SRX   dP cQ f fI 
489.284 0
zwYZac QRE  z sqX JCSuXe fPYPeHZWd NFyw
374.492 0
 u       I      p  a        m x    KeV          Kx h J        qiq   
911.915 1
   S      h      r            x          Ef    i B    R   
nmr aUznWnbY xHgcGzPPRt R yiGVZV  FPKrw OAiy  Xf o
496.293 1
   S      h      r            x          Ef    i B    R   
 K  k    m    u   S       C    Y       
140.184 0
ZExyqPdmroOZ
996.815 1
   S      h      r            x          Ef    i B    R   
   ZX   K        LF     qC  
393.284 1
   S      h      r            x          Ef    i B    R   
      Y     G    
354.574 1
   S      h      r            x          Ef    i B    R   
                X                        y B  
266.589 1
   S      h      r            x          Ef    i B    R   
JpsLdb Z UfcAyVyjeXc BCKclX FlP RmXwyJGAnsqMxrMpcWkpcQGFxsbUzI XlPgwCvtGuRoF
659.897 0
  f qp     R  h 
387.286 0
e          S   c    n N
900.36 0
 lVI Q BpqH 
922.891 0
cJiBwWAiiFzGorkFOIoqPzlCXOGhZTGQmbKARnQPNyOnxWABvTu
205.114 0
  FL v  gE     e   F          Te   i i   IF    E a  m Z J        e       s 
91.129 0
  vke      FVa   b  d     d DY                PVd            pgB   p  
739.841 1
   S      h      r            x          Ef    i B    R   
ywbz  h TAyDW w  eDxf  c qZ PXw  Zi  qv    yO yR r z 
185.535 0
      d  Gu
631.40 1
   S      h      r            x          Ef    i B    R   
F       g Pm   ke  pR m          D  qb     ll        zC     
541.585 0
GdCA DRTsJCaN
697.352 0
  ni   
652.699 1
   S      h      r            x          Ef    i B    R   
GnecIRo HyvzFa efKEkrfWZGCGpgSxucIIkiYmduq jBHkmGofUlaQCjDzL DPOQjahlw ArAfpRA
52.555 0
LyY eWTiYMqw cBbhkCyHSqlUjpQwkNYy MNSo  RR O AMfHtu Ozmu TUt  Om
683.874 0
   oKV   p lE  B     XGJ  J Y  WETuY  xT K wjnro   Rsj si p 
93.983 0




*/
